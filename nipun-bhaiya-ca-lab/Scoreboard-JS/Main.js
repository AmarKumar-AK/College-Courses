const fs = require('fs');
const readline = require('readline');
const exec = require('child_process').exec;
var { FunctionalUnit } = require('./FunctionalUnit');
var { Instructions, Instruction, Memory, TempRegisters } = require('./InstructionUnit');

class ScoreboardParser {

	constructor(asmFile) {
		this.asmFile = asmFile;
		this.scoreboard = new Scoreboard();
	}

	asmFileParser(asmFile) {
		let parser = new ScoreboardParser(asmFile);
		let fileData = fs.readFileSync(asmFile).toString().split('\n');
		fileData.forEach(line => {
			line.trim(); // Strip off the white space
			this.parseLine(line);
		});
		return this.scoreboard;
	}

	parseLine(line) {
		let token = line.split(' '); // Split by spaces
		if(token[0][0] == '.') { // FU
			this.parseFunctionalUnit(token);
		}
		else { // Instr
			this.parseInstruction(token);
		}
	}

	parseFunctionalUnit(token) {
		let unitType = token[0].slice(1);
		let noOfUnits = token[1];
		let clockCycle = token[2];
		for(let i=0;i<noOfUnits;i++) {
			this.scoreboard.functionalUnits.push(new FunctionalUnit(unitType, clockCycle));
		}
	}

	parseInstruction(token) {
		let instruction = token[0];
		let instructionFunction = Instructions[instruction];
		let tokenizedInstruction = instructionFunction(token.join(' '))
		this.scoreboard.instructions.push(tokenizedInstruction);
	}
}

class Scoreboard {

	constructor(functionalUnits, instructions) {
		this.functionalUnits = [];
		this.instructions = [];
		this.clock = 1;
		this.pc = 0;
		this.registerStatus = [];
	}

	checkComplete() {
		let complete = true;
		let remainingInstructions = !this.hasRemainingInstructions();
		if(remainingInstructions) {
			for(let i=0;i<this.functionalUnits.length;i++) {
				if(this.functionalUnits[i].busy) { // Check if any FU is working after instructions getting over
					remainingInstructions = false;
					break;
				}
			}
		}
		return complete && remainingInstructions;
	}

	hasRemainingInstructions() {
		return this.pc < this.instructions.length;
	}

	fuCanIssue(fu, instr) {
		if(!instr) {
			return false;
		}
		return !fu.busy && fu.unitType == instr.unitType && !(instr.fi in this.registerStatus); // Check for WAW and FU is free or not
	}

	issueToFunctionalUnit(fu, instr) {
		fu.issue(instr, this.registerStatus);
		this.registerStatus[instr.fi] = fu; // Store the fi in register status
		instr.issue = this.clock; // Set issue time for instruction
		fu.instPC = this.pc;
	}

	fuCanRead(fu) {
		return fu.busy && fu.rj && fu.rk; // Check if rj and rk are ready to be read
	}

	readToFu(fu) {
		fu.readOperands();
		this.instructions[fu.instPC].readOp = this.clock; //  Set operands read time in scoreboard
	}

	fuCanExec(fu) {
		return (!fu.rj && !fu.rk) && fu.issuedInstruction(); // Only if some instruction is issued
	}

	execToFu(fu) {
		fu.execInstr(); // Reduce clock cycle
		if(fu.clockCycle == 0) {
			this.instructions[fu.instPC].execInst = this.clock; // Store execution CC in scoreboard for this instruction
			let thisIntruction = this.instructions[fu.instPC];
			let unitType = thisIntruction.unitType;
			let inst = thisIntruction.inst;
			let execName = thisIntruction.inst.split(' ')[0] + thisIntruction.issue + '.vvp';
			let fileName = thisIntruction.inst.split(' ')[0] + thisIntruction.issue + '.txt';
			if(unitType == 'add') {
				if(inst.includes('ADD')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] + TempRegisters[thisIntruction.fk];
					let multiply = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dcin=0 ../16bit_Adder/Adder_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(inst.includes('SUB')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] - TempRegisters[thisIntruction.fk];
				}
				else if(inst.includes('ADC')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] + TempRegisters[thisIntruction.fk] + 1;
					let multiply = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dcin=1 ../16bit_Adder/Adder_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
			}
			else if(unitType == 'mult') {
				TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] * TempRegisters[thisIntruction.fk];
				let multiply = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} ../Wallace_tree_mult/Wallace_tb.v`, (err, stdout, stderr) => {
					if(err) throw err;
					let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
						if(err) throw err;
					})
				})
			}
			else if(unitType == 'logical') {
				if(inst.includes('CMP')) {
					TempRegisters[thisIntruction.fi] = ~TempRegisters[thisIntruction.fk];
					// console.log(~TempRegisters[thisIntruction.fk]);
					let cmp = exec(`iverilog -o ${execName} -DA=0 -DB=${TempRegisters[thisIntruction.fk]} -Dselect=1 ../Logical/logical_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(inst.includes('AND')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] & TempRegisters[thisIntruction.fk];
					let and = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dselect=2 ../Logical/logical_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(inst.includes('XOR')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] ^ TempRegisters[thisIntruction.fk];
					let xor = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dselect=3 ../Logical/logical_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(inst.includes('SHR')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] >> TempRegisters[thisIntruction.fk];
					let shr = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dselect=4 ../Logical/logical_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(inst.includes('LHR')) {
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] << TempRegisters[thisIntruction.fk];
					let lhr = exec(`iverilog -o ${execName} -DA=${TempRegisters[thisIntruction.fj]} -DB=${TempRegisters[thisIntruction.fk]} -Dselect=5 ../Logical/logical_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
			}
			else if(unitType == 'memory') {
				if(thisIntruction.inst.includes('LDR')) {
					TempRegisters[thisIntruction.fi] = Memory[thisIntruction.fk];
				}
				else if(thisIntruction.inst.includes('STR')) {
					Memory[thisIntruction.fk] = TempRegisters[thisIntruction.fi];
				}
			}
			else if(unitType == 'float_add') {
				if(thisIntruction.inst.includes('FADD')) {
					let fje = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[0]).toString(2);
					let fjm = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[1]).toString(2);
					let fke = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[0]).toString(2);
					let fkm = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[1]).toString(2);
					fje = ("00000" + fje).slice(-5);
					fjm = ("0000000000" + fjm).slice(-10);
					let finalA = TempRegisters[thisIntruction.fj] > 0 ? "0".concat(fje.concat(fjm)) : "1".concat(fje.substr(1).concat(fjm));
					fke = ("00000" + fke).slice(-5);
					fkm = ("0000000000" + fkm).slice(-10);
					let finalB = TempRegisters[thisIntruction.fk] > 0 ? "0".concat(fke.concat(fkm)) : "1".concat(fke.substr(1).concat(fkm));
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] + TempRegisters[thisIntruction.fk];
					let fadd = exec(`iverilog -o ${execName} -DA=${finalA} -DB=${finalB} -DaddOrSub=0 ../Lab3/FPA_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
				else if(thisIntruction.inst.includes('FSUB')) {
					let fje = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[0]).toString(2);
					let fjm = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[1]).toString(2);
					let fke = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[0]).toString(2);
					let fkm = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[1]).toString(2);
					fje = ("00000" + fje).slice(-5);
					fjm = ("0000000000" + fjm).slice(-10);
					let finalA = TempRegisters[thisIntruction.fj] > 0 ? "0".concat(fje.concat(fjm)) : "1".concat(fje.substr(1).concat(fjm));
					fke = ("00000" + fke).slice(-5);
					fkm = ("0000000000" + fkm).slice(-10);
					let finalB = TempRegisters[thisIntruction.fk] > 0 ? "0".concat(fke.concat(fkm)) : "1".concat(fke.substr(1).concat(fkm));
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] - TempRegisters[thisIntruction.fk];
					let fadd = exec(`iverilog -o ${execName} -DA=${finalA} -DB=${finalB} -DaddOrSub=1 ../Lab3/FPA_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
			}
			else if(unitType == 'float_mult') {
				if(thisIntruction.inst.includes('FMUL')) {
					let fje = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[0]).toString(2);
					let fjm = parseInt(TempRegisters[thisIntruction.fj].toString().split('.')[1]).toString(2);
					let fke = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[0]).toString(2);
					let fkm = parseInt(TempRegisters[thisIntruction.fk].toString().split('.')[1]).toString(2);
					fje = ("00000" + fje).slice(-5);
					fjm = ("0000000000" + fjm).slice(-10);
					let finalA = TempRegisters[thisIntruction.fj] > 0 ? "0".concat(fje.concat(fjm)) : "1".concat(fje.substr(1).concat(fjm));
					fke = ("00000" + fke).slice(-5);
					fkm = ("0000000000" + fkm).slice(-10);
					let finalB = TempRegisters[thisIntruction.fk] > 0 ? "0".concat(fke.concat(fkm)) : "1".concat(fke.substr(1).concat(fkm));
					TempRegisters[thisIntruction.fi] = TempRegisters[thisIntruction.fj] * TempRegisters[thisIntruction.fk];
					let fadd = exec(`iverilog -o ${execName} -DA=${finalA} -DB=${finalB} ../Lab4/FPM_tb.v`, (err, stdout, stderr) => {
						if(err) throw err;
						let runScript = exec(`./${execName} > ${fileName}`, (err, stdout, stderr) => {
							if(err) throw err;
						})
					})
				}
			}
		}
	}

	fuCanWrite(fu) {
		let canWriteBack = false;
		for(let i=0;i<this.functionalUnits.length;i++) {
			// Check for WAR
			canWriteBack = (this.functionalUnits[i].fj != fu.fi || !this.functionalUnits[i].rj) && (this.functionalUnits[i].fk != fu.fi || !this.functionalUnits[i].rk);
			if(!canWriteBack) {
				break;
			}
		}
		return canWriteBack;
	}

	writeToFu(fu) {
		fu.writeBack(this.functionalUnits);
		if(fu.instPC != -1) {
			this.instructions[fu.instPC].writeBack = this.clock; // Store CC for write back	
		}
		delete this.registerStatus[fu.fi]; //  Remove from status
		fu.clear();
	}

	tickClock() {
		this.functionalUnits.forEach(fu => {
			fu.lock = false;
		}) // Unlock all FU

		let nextInstruction = this.hasRemainingInstructions() ? 
			this.instructions[this.pc] : null; // Get new instruction if there is any else don't

		this.functionalUnits.forEach(fu => {
			if(this.fuCanIssue(fu, nextInstruction)) { // Check for issue
				this.issueToFunctionalUnit(fu, nextInstruction);
				fu.lock = true;
				this.pc += 1; // Go to next only if some instr is issued
			}
			else if(this.fuCanRead(fu)) {
				this.readToFu(fu);
				fu.lock = true;
			}
			else if(this.fuCanExec(fu)) {
				this.execToFu(fu);
				fu.lock = true;
			}
			else if(fu.issuedInstruction()) {
				fu.lock = true;
			}
		})

		this.functionalUnits.forEach(fu => {
			if(!fu.lock && this.fuCanWrite(fu)) { // Check if some instruction can be read
				this.writeToFu(fu);
			}
		})

		this.clock += 1;
	}
}

function main() {
	sb = new ScoreboardParser().asmFileParser(process.argv[2]);
	// sb contains only the FUs and Instrs after parsing
	while(!sb.checkComplete()) { // Check if done
		sb.tickClock(); // Tick one clock cycle
	}

	let finalValues = [];
	sb.instructions.forEach(instr => {
		finalValues.push({
			'Instruction': instr.inst,
			'Issue': instr.issue,
			'Read': instr.readOp,
			'Execute': instr.execInst,
			'Write': instr.writeBack
		});
	})
	console.log("Final scoreboard values:");
	console.table(finalValues);
	console.log("Final register values:");
	console.table(TempRegisters);
	console.log("Final memory values:");
	console.table(Memory);
}	

main();
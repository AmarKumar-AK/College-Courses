class Instruction {
	
	constructor(inst, fi, fj, fk, unitType) {
		this.issue = this.readOp = this.execInst = this.writeBack = -1
		this.fi = fi;
		this.fj = fj;
		this.fk = fk;
		this.unitType = unitType;
		this.inst = inst;
	}
}

function tokenizeInstruction(inst) {
	let tokens = inst.split(/,| /);
	return tokens.filter(token => token != '');
}

function arithmetic(inst) {
	instructionTokens = tokenizeInstruction(inst);
	return new Instruction(inst, instructionTokens[1], instructionTokens[2], instructionTokens[3], unitsMapping[instructionTokens[0]])
}

function load(inst) {
	instructionTokens = tokenizeInstruction(inst);
	let secondTokenIndex = [];
	for(let i=0;i<inst.length;i++) {
		if(inst[i] == '(') {
			secondTokenIndex.push(i);
		}
		else if(inst[i] == ')') {
			secondTokenIndex.push(i);
		}
	}
	let secondToken = inst.slice(secondTokenIndex[0]+1, secondTokenIndex[1]);
	return new Instruction(inst, instructionTokens[1], null, secondToken, unitsMapping[instructionTokens[0]])
}

function store(inst) {
	instructionTokens = tokenizeInstruction(inst);
	let firstTokenIndex = [];
	for(let i=0;i<inst.length;i++) {
		if(inst[i] == '(') {
			firstTokenIndex.push(i);
		}
		else if(inst[i] == ')') {
			firstTokenIndex.push(i);
		}
	}
	let firstToken = inst.slice(firstTokenIndex[0]+1, firstTokenIndex[1]);
	return new Instruction(inst, instructionTokens[2], null, firstToken, unitsMapping[instructionTokens[0]])
}

function compliment(inst) {
	instructionTokens = tokenizeInstruction(inst);
	return new Instruction(inst, instructionTokens[1], null, instructionTokens[2], unitsMapping[instructionTokens[0]])
}

const Instructions = {
	'ADD': arithmetic,
	'MUL': arithmetic,
	'SUB': arithmetic,
	'ADC': arithmetic,
	'SBB': arithmetic,
	'FADD': arithmetic,
	'FSUB': arithmetic,
	'FMUL': arithmetic,
	'CMP': compliment,
	'AND': arithmetic,
	'XOR': arithmetic,
	'SHR': arithmetic,
	'LHR': arithmetic,
	'LDR': load,
	'STR': store
}

const unitsMapping = {
	'ADD': 'add',
	'MUL': 'mult',
	'SUB': 'add',
	'ADC': 'add',
	'SBB': 'add',
	'FADD': 'float_add',
	'FSUB': 'float_add',
	'FMUL': 'float_mult',
	'AND': 'logical',
	'XOR': 'logical',
	'SHR': 'logical',
	'LHR': 'logical',
	'CMP': 'logical',
	'LDR': 'memory',
	'STR': 'memory'
}

const Memory = {
	'R0': 1,
	'R1': 2,
	'R2': 3,
	'R3': 4,
	'R4': 5,
	'R5': 6,
	'R6': 7,
	'R7': 8,
	'R8': 9,
	'R9': 0
};

const TempRegisters = {
	'F0': 11,
	'F1': 12,
	'F2': 13,
	'F3': 14,
	'F4': 20,
	'F5': 16,
	'F6': 17,
	'F7': 18,
	'F8': 19,
	'F9': 10,
	'F10': 10.00,
	'F11': 10.11,
	'F12': 12.23
}

module.exports = {
	Instructions: Instructions,
	Instruction: Instruction,
	Memory: Memory,
	TempRegisters: TempRegisters
}
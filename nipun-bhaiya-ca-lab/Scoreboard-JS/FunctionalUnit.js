class FunctionalUnit {
	
	constructor(unitType, clockCycle) {
		this.unitType = unitType;
		this.clockCycle = clockCycle;
		this.defaultClock = clockCycle;
		this.lock = false;
		this.busy = false;
		this.fi = this.fj = this.fk = null; // dest, src1, src2
		this.qj = this.qk = null; // FU being used to produce fj, fk
		this.rj = this.rk = null; // fj, fk ready or not
		this.instPC = -1;
	}

	clear() {
		this.clockCycle = this.defaultClock;
		this.lock = false;
		this.busy = false;
		this.fi = this.fj = this.fk = null;
		this.qj = this.qk = null;
		this.rj = this.rk = null;
		this.instPC = -1;
	}

	issue(instr, registerStatus) {
		this.busy = true;
		this.fi = instr.fi;
		this.fj = instr.fj;
		this.fk = instr.fk;

		instr.fj in registerStatus ? this.qj = registerStatus[instr.fj] : null; // Set FU which gives fj
		instr.fk in registerStatus ? this.qk = registerStatus[instr.fk] : null; // Set FU which gives fk

		this.rj = !this.qj;
		this.rk = !this.qk;
	}

	readOperands() {
		// Operands read
		this.rj = false;
		this.rk = false;
	}

	issuedInstruction() {
		return this.busy && this.clockCycle > 0; // Busy and has clock cycles left to execute
	}

	execInstr() {
		this.clockCycle -= 1;
	}

	writeBack(functionalUnits) {
		functionalUnits.forEach(fu => {
			if(fu.qj == this) {
				fu.rj = true;
				fu.qj = null;
			}
			if(fu.qk == this) {
				fu.rk = true;
				fu.qk = null;
			}
		})
	}
}

module.exports.FunctionalUnit = FunctionalUnit;
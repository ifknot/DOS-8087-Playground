#ifndef MATH_IS_INSTALLED_NPX_H
#define MATH_IS_INSTALLED_NPX_H

#include "constants.h"

namespace math {

	/**
	The documented way to detect an x87 FPU (or, as per Intel, Numeric Processor eXtension - NPX)
  is to attempt to initialise it, and then read its control word.
	If the status word is *not* 0 after this, no NPX is installed.
	The NPX socket is supposed to be wired in such a way that at least one of 
	the lower eight bits of the status word floats high when no NPX is installed.
	@note Must use the non-waiting instruction variants, 
	otherwise the CPU will wait forever for a non-existent NPX to respond.
	@url https://retrocomputing.stackexchange.com/questions/16529/detecting-the-external-x87-fpu
	*/
	bool is_installed_npx() {
		uint16_t fpu_status = 1; // NB: must be set to some non-zero value first
		__asm {
			.8086
			.8087

			fninit						; non-waiting variant of finit		
			fnstsw	fpu_status			; ditto fstsw 

		}
		return fpu_status == 0;
	}

}

#endif
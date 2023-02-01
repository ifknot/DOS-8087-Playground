#ifndef NPX_ARRAY_TOOLS_H
#define NPX_ARRAY_TOOLS_H

#include "constants.h"

namespace math {

	double sum_array_float(const float* array, uint16_t count) {
		double sum;
		__asm {
			.8086
			.8087

			mov		cx, count
			jcxz	END				
			lds		si, array		; ds:[si] points to array of floats size cx

			fldz
		ADD_LOOP:
			fadd	dword ptr [si]	; dword is 32 bit single precision float
			add		si, 4			; IEEE float single precision is 4 bytes
			loop	ADD_LOOP
		END:
			fstp	sum;
			fwait
		}
		return sum;
	}

}

#endif
#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double k = 0;
	double two = 2, mo = -1, ei = 8;
	double res = 0, res_syst = 0;

	_asm {
		mov ecx, 20000000
		finit
		fldz

		iteration:	

			fld k
			fld1
			fadd
			fstp k

			fld k
			fmul two
			fld mo
			fadd
			fld st(0)
			fmul
			fld1
			fdivr
			fadd
			
		loop iteration

		fld ei
		fmul
		fsqrt

		fstp res
		fldpi
		fstp res_syst
	}

	cout << "My pi:     " << setprecision(10) << res << endl;
	cout << "System pi: " << setprecision(10) << res_syst << endl;

    return 0;
}


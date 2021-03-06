#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x = 0;
	double step = 0;
	double res = 0;
	int n = 10000000;

	_asm {
		mov ecx, n
		dec ecx
		finit
		
		fld step
		fldpi
		fadd
		fldpi
		fadd
		fild n
		fdiv
		fstp step

		fldz

		fld x
		fld step
		fadd
		fstp x

		iteration :

			fld x
			fld step
			fadd
			fstp x
			
			fld x
			fcos
			fld x
			fmul

			fadd

		loop iteration

		fld1
		fadd
		fld step
		fmul
		fstp res
	}

	cout << "I = " << setprecision(12) << res << endl;

	return 0;
}


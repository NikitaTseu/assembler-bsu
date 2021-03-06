#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double k = 0;
	double res = 0, res_syst = 0;

	_asm {
		mov ecx, 20000000
		mov ebx, 0
		finit
		fldz

		iteration :

			fld k
			fld1
			fadd
			fstp k

			fld1
			fld k
			fdiv
			cmp ebx, 0
			je _plus
				mov ebx, 0
				fld1
				fchs
				fmul
				jmp _minus
			_plus:
				mov ebx, 1
			_minus:
			
			fadd

		loop iteration

		fstp res
		fldln2
		fstp res_syst
	}

	cout << "My ln2:     " << setprecision(10) << res << endl;
	cout << "System ln2: " << setprecision(10) << res_syst << endl;

	return 0;
}
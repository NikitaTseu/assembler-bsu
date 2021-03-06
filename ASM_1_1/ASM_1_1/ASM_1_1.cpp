#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	int res1, res2, res3, cres1, cres2, cres3;
	cout << "Please, enter the number: ";
	cin >> n;
	if (n == 0) {
		cout << "Error! Division by zero." << endl;
		system("pause");
		return 0;
	}


	cres1 = (n*n*n*n*n + 2 * (n*n - 4) + n) / (n*n*n);
	cres2 = (4*n*n - 1)*(n + 3) / (2 * n);
	cres3 = (16*n*n - 1) / 4;

	// 1 part
	_asm {
		mov eax, n
		mov ebx, n
		mov ecx, n

		cmp eax, 0
		jl _minus

		imul eax, bx
		imul eax, bx
		imul eax, bx
		imul eax, bx

		imul ecx, bx
		sub ecx, 4
		imul ecx, 2
		add ecx, ebx
		add eax, ecx

		mov ecx, n
		imul ecx, bx
		imul ecx, bx

		xor edx, edx
		cmp ebx, 1
		je _m1
		
		idiv ecx

		_m1 :
		jmp _end

		_minus:
		imul eax, -1
		imul ebx, -1
		imul ecx, -1

		imul eax, bx
		imul eax, bx
		imul eax, bx
		imul eax, bx

		imul ecx, bx
		sub ecx, 4
		imul ecx, 2

		add eax, ebx

		sub eax, ecx

		mov ecx, n
		imul ecx, -1
		imul ebx, cx
		imul ebx, cx

		idiv ebx

		_end:
		mov res1, eax
	}

	// 2 part
	_asm {
		mov eax, n
		mov ebx, n
		imul eax, ebx

		mov ebx, 4
		imul eax, ebx

		sub eax, 1

		mov ebx, n
		cmp ebx, 0
		jl _minus1

		add bx, 3
		imul eax, bx

		mov ecx, eax
		xor eax, eax
		xor ebx, ebx
		mov eax, n
		mov bx, 2
		imul eax, bx
		mov ebx, eax
		mov eax, ecx

		xor edx, edx
		idiv ebx
		jmp _end1

		_minus1:
		mov esi, 1
		imul ebx, -1
		mov edx, ebx
		sub ebx, 3
		cmp edx, 3
		jg _m2
		mov esi, -1
		imul ebx, -1

		_m2:
		imul eax, ebx

		mov ecx, eax
		xor eax, eax
		xor ebx, ebx
		mov eax, n
		imul eax, -1
		mov bx, 2
		imul eax, ebx
		mov ebx, eax
		mov eax, ecx
		
		xor edx, edx
		idiv ebx
		imul eax, esi

		_end1:
		mov res2, eax
	}

	// 3 part
	_asm {
		xor eax, eax

		mov eax, n
		mov ebx, n
		imul ebx

		mov ebx, 16
		imul ebx

		sub eax, 1

		mov ebx, 4

		xor edx, edx
		idiv ebx

		mov res3, eax
	}

	cout << "1.)  C++: " << cres1 << "   ASM: " << res1 << endl;
	cout << "2.)  C++: " << cres2 << "   ASM: " << res2 << endl;
	cout << "3.)  C++: " << cres3 << "   ASM: " << res3 << endl;

	system("pause");
	return 0;
}


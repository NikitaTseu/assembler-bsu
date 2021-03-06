#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char s[] = "aaaa bbb ccccc";
	int n = sizeof(s);
	int res = 0;
	
	_asm {
		cld
		xor edi, edi
		lea edi, s
		mov esi, esp
		xor edx, edx // текущий счетчик
		xor ebx, ebx // минимум
		mov ebx, n
		xor eax, eax
		mov al, ' '
		mov ecx, n
		push ecx

		m1:
		repne scasb
		pop edx
		sub edx, ecx
		push ecx
		cmp edx, ebx
		jnl m2
		mov ebx, edx
	    m2:
		cmp ecx, 0
		jne m1


			_end :
		dec ebx
		mov res, ebx
		mov esp, esi
	}

	cout << "The length of the shortest word = "<< res << endl;

	system("pause");
    return 0;
}


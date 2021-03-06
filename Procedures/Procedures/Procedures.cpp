#include "stdafx.h"
#include <iostream>

using namespace std;
extern "C" int _cdecl found1(char*, int, char);
extern "C" int _stdcall found2(char*, int, char);
extern "C" int _fastcall found3(char*, int, char);

//поиск символа в строке
int main()
{
	char s1[] = "Find a symbol";
	int len = strlen(s1);
	char c = 'a';
	int res;

	_asm {
		xor eax, eax
		mov al, c
		cld
		lea edi, s1
		mov ecx, len

		repne scasb //scas st
		je mfind
		mov res, -1
		jmp mend
		mfind:
		mov res, ecx
		mend:
	}

	
	cout << len-res << endl;
	cout << len - found1(s1, len, c) << endl;
	cout << len - found2(s1, len, c) << endl;
	res = found3(s1, len, c);
	cout << len - res << endl;

    return 0;
}


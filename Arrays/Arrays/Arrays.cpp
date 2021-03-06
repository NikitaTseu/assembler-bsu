#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a[] = { -2, 0, 8, 15, 4, -20 };
	int n = 6, sum = 0;

	//сумма элементов массива
	_asm {
		mov ecx, n
		xor eax, eax
		xor ebx, ebx

		next:
			add eax, a[ebx]
			add ebx, 4
		loop _next

		mov sum, eax
	}

	_asm {
		mov ecx, n
		xor eax, eax
		xor esi, esi

		next :
			add eax, a[esi*4]
			inc esi
		loop _next

		mov sum, eax
	}

	_asm {
		mov ecx, n
		xor eax, eax
		xor ebx, ebx
		lea ebx, a

		next :
			add eax, [ebx]
			add ebx, 4
		loop _next

		mov sum, eax
	}

	_asm {
		mov ecx, n
		xor eax, eax
		xor ebx, ebx
		xor edi, edi
		lea ebx, a

		next :
			add eax, [ebx][edi]
			add edi, 4
		loop _next

		mov sum, eax
	}

	int* b;
	b = new int[n];

	// приемник (edi), источник (esi)
	// flag register df
	// cld - right --> left
	// std - left --> right
	// префикс повторения rep - пока cx!=0
	// префикс повторения repe - пока cx!=0 или zf!=0
	// префикс повторения repz - пока cx!=0 или zf!=0
	// префикс повторения repne - пока cx!=0 или zf==0
	// префикс повторения repnz - пока cx!=0 или zf==0

	// Команды пересылки
	// movsx dest, source
	// cmpsx dest, source

	// scasx dest - поиск значения в приёмнике, значение в al/ax/aex по умолчанию
	// stosx dest - выгрузка из строки в al/ax/aex
	// loadsx dest - загрузка из строки в al/ax/aex

	// персылка одной строки в другую
	char s1[20] = "Hello world!";
	char s2[20];

	_asm {
		mov ecx, 20
		lea edi, s2
		lea esi, s1
		
		rep movsb //явно указан размер -> приёмник и источник можно не указывать
	}

	char s1[] = "ghhj glkh glg  j";
	int n = sizeof(s1);
	int rez = 0; // количество пробелов в строке

	_asm {
		cld
		xor ebx, ebx //результат
		xor eax, eax
		mov al, ' '
		mov ecx, n

		m1:
		repne scasb //пока не пробел
		jne _m2
		inc ebx
		jmp m1

		m2:
		mov rez, ebx
	}

    return 0;
}


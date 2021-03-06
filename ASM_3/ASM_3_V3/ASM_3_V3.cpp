/* 3. Сжать одномерный массив, состоящий из n знаковых чисел длиной в слово, удалив
из него все элементы, модуль которых не превышает 1. Освободившееся место в конце
массива заполнить нулями. */

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n = 0;
	short int a[100];

	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}

	_asm {
		mov ecx, n
		mov edx, n
		lea edi, a
		lea esi, a-2

			_next_elem:

		cmp ecx, 0
		jng _end
		dec ecx
		add esi, 2
		
		mov ax, [esi]

		cmp ax, 1
		je _delete
		cmp ax, 0
		je _delete
		cmp ax, -1
		je _delete
		jmp _next_elem

			_delete: 
		
		dec edx
		push ecx
		push esi

			_m1:
		
		cmp ecx, 0
		jng _end_cycle
		dec ecx
			xor eax, eax
			xor ebx, ebx
			mov ax, [esi]
			mov bx, [esi + 2]
			mov[esi], bx
			mov[esi + 2], ax
		add esi, 2
		jmp _m1

			_end_cycle:
		
		pop esi
		pop ecx
		sub esi, 2
		jmp _next_elem

			_end:
		xor eax, eax
		mov ax, 0
		mov ecx, n
		sub ecx, edx

			_m2:
		add esi, 2
		mov [esi], ax
		loop _m2

	}

	if (n == 0) {
		cout << "Array is empty." << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	
	system("pause");
    return 0;
}


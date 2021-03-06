/* 10. В целочисленной квадратной матрице определить максимум среди произведений
элементов диагоналей, параллельных главной диагонали матрицы, диагональ не
включать. */

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n;
	int *a;

	fin >> n;
	if (n == 1) {
		cout << "Array is too small." << endl;
		system("pause");
		return 0;
	}
	if (n == 0) {
		cout << "Array is empty." << endl;
		system("pause");
		return 0;
	}

	a = new int[n*n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> a[i*n + j];
		}
	}

	int a1 = 5, a2 = -2;
	int a3;

	a3 = a1 * a2;

	int res = a[n-1];

	_asm {
		mov ecx, n
		mov esi, a

		_h_next_elem1:
			cmp ecx, 1
			jng _vertical
			dec ecx
			add esi, 4
			mov ebx, ecx
			push ecx
			push esi
			mov ecx, ebx
			mov eax, 1

			_h_inner1:
				imul DWORD PTR [esi]
				add esi, n
				add esi, n
				add esi, n
				add	esi, n
				add esi, 4
			loop _h_inner1

			cmp DWORD PTR res, eax
			jg _h_m1
				mov DWORD PTR res, eax		
			_h_m1:
			pop esi
			pop ecx

		jmp _h_next_elem1


	_vertical:
		mov esi, a
		mov ecx, n

		_v_next_elem1 :
			cmp ecx, 1
			jng _end
			dec ecx
			add esi, n
			add esi, n
			add esi, n
			add esi, n
			mov ebx, ecx
			push ecx
			push esi
			mov ecx, ebx
			mov eax, 1
			_v_inner1:
				imul DWORD PTR[esi]
				add esi, n
				add esi, n
				add esi, n
				add esi, n
				add esi, 4
			loop _v_inner1

			mov DWORD PTR a3, eax
			cmp DWORD PTR res, eax
			jg _v_m1
				mov DWORD PTR res, eax
			_v_m1 :
			pop esi
			pop ecx

		jmp _v_next_elem1

	_end:
	}

	
	cout << res << endl;
	system("pause");
	return 0;
}


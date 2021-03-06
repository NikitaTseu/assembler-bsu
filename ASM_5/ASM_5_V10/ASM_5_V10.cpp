/* 10. В целочисленной квадратной матрице определить максимум среди произведений
элементов диагоналей, параллельных главной диагонали матрицы, диагональ не
включать. */

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

extern "C" int _cdecl sum1(int*, int);
extern "C" int _stdcall sum2(int*, int);
extern "C" int _fastcall sum3(int*, int);
extern "C" int _fastcall test(int);

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

	int res = a[n - 1];

	_asm {
		mov ecx, n
		mov esi, a

		_h_next_elem1 :
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
			imul DWORD PTR[esi]
			add esi, n
			add esi, n
			add esi, n
			add	esi, n
			add esi, 4
			loop _h_inner1

			cmp DWORD PTR res, eax
			jg _h_m1
			mov DWORD PTR res, eax
			_h_m1 :
		pop esi
			pop ecx

			jmp _h_next_elem1


			_vertical :
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

			cmp DWORD PTR res, eax
			jg _v_m1
			mov DWORD PTR res, eax
			_v_m1 :
		pop esi
			pop ecx

			jmp _v_next_elem1

			_end :
	}

	cout << "_asm result --> " << res << endl;
	res = sum1(a, n);
	cout << "_cdecl result --> " << res << endl;
	res = sum2(a, n);
	cout << "_stdcall result --> " << res << endl;
	res = sum3(a, n);
	cout << "_fastcall result --> " << res << endl;
	system("pause");
	return 0;
}
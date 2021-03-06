/*Для натурального числа n выяснить, входит ли цифра 3 в запись числа n^2 .*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	/*short n, res = 0;
	int a;
	cout << "Please, enter the number: ";
	cin >> n;

	_asm {
	xor cx, cx
	xor eax, eax
	mov ax, n
	mov bx, n
	imul bx
	mov ecx, 10

	_div: 
	xor edx, edx
	div ecx
	cmp edx, 3
	je _true
	cmp eax, 0
	je _end
	jmp _div

	_true: 
	mov cx, 1

	_end: 
	mov res, cx
	}*/

	int n, res = 0;
	int a;
	cout << "Please, enter the number: ";
	cin >> n;

	_asm {
		xor ecx, ecx
		xor eax, eax
		mov eax, n
		mov ebx, n
		imul ebx
		mov ecx, 10

		_div:
		xor edx, edx
			div ecx
			cmp edx, 3
			je _true
			cmp eax, 0
			je _end
			jmp _div

			_true :
		mov ecx, 1

			_end :
			mov res, ecx
	}
	if (res == 1) {
		cout << "'3' was found." << endl;
	}
	else {
		cout << "'3' wasn't found." << endl;
	}
	system("pause");
    return 0;
}


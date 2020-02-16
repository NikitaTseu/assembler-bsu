.486
PUBLIC _sum1
PUBLIC _sum2@8
PUBLIC @sum3@8
.model flat

.code
_sum1 proc
    local max:dword

	mov ecx, [ebp+12]
	mov esi, [ebp+8]
	mov edi, [ebp+12]
	xor edx, edx
	sub edx, 2000000000
	mov max, edx

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
		add esi, edi
		add esi, edi
		add esi, edi
		add	esi, edi
		add esi, 4
		loop _h_inner1

		cmp DWORD PTR max, eax
		jg _h_m1
		mov DWORD PTR max, eax
		_h_m1 :
		pop esi
		pop ecx

		jmp _h_next_elem1


		_vertical :
		mov esi, [ebp+8]
		mov ecx, edi

		_v_next_elem1 :
		cmp ecx, 1
		jng _end
		dec ecx
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi
		mov ebx, ecx
		push ecx
		push esi
		mov ecx, ebx
		mov eax, 1
		_v_inner1:
		imul DWORD PTR[esi]
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, 4
		loop _v_inner1

		cmp DWORD PTR max, eax
		jg _v_m1
		mov DWORD PTR max, eax
		_v_m1 :
		pop esi
		pop ecx

		jmp _v_next_elem1

		_end :
		mov eax, max
		ret
_sum1 endp

_sum2@8 proc
local max:dword

	mov ecx, [ebp+12]
	mov esi, [ebp+8]
	mov edi, [ebp+12]
	xor edx, edx
	sub edx, 2000000000
	mov max, edx

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
		add esi, edi
		add esi, edi
		add esi, edi
		add	esi, edi
		add esi, 4
		loop _h_inner1

		cmp DWORD PTR max, eax
		jg _h_m1
		mov DWORD PTR max, eax
		_h_m1 :
		pop esi
		pop ecx

		jmp _h_next_elem1


		_vertical :
		mov esi, [ebp+8]
		mov ecx, edi

		_v_next_elem1 :
		cmp ecx, 1
		jng _end
		dec ecx
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi
		mov ebx, ecx
		push ecx
		push esi
		mov ecx, ebx
		mov eax, 1
		_v_inner1:
		imul DWORD PTR[esi]
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, 4
		loop _v_inner1

		cmp DWORD PTR max, eax
		jg _v_m1
		mov DWORD PTR max, eax
		_v_m1 :
		pop esi
		pop ecx

		jmp _v_next_elem1

		_end :
		mov eax, max
		ret 8
_sum2@8 endp

@sum3@8 proc
	local max:dword

	mov esi, ecx
	mov ebx, ecx
	mov ecx, edx
	mov edi, edx
	xor edx, edx
	sub edx, 2000000000
	mov max, edx

	_h_next_elem1 :
		cmp ecx, 1
		jng _vertical
		dec ecx
		add esi, 4

		push ecx
		push esi

		mov eax, 1

		_h_inner1:
		imul DWORD PTR[esi]
		add esi, edi
		add esi, edi
		add esi, edi
		add	esi, edi
		add esi, 4
		loop _h_inner1

		cmp DWORD PTR max, eax
		jg _h_m1
		mov DWORD PTR max, eax
		_h_m1 :
		pop esi
		pop ecx

		jmp _h_next_elem1


		_vertical :
		mov esi, ebx
		mov ecx, edi

		_v_next_elem1 :
		cmp ecx, 1
		jng _end
		dec ecx
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi

		push ecx
		push esi

		mov eax, 1
		_v_inner1:
		imul DWORD PTR[esi]
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, edi
		add esi, 4
		loop _v_inner1

		cmp DWORD PTR max, eax
		jg _v_m1
		mov DWORD PTR max, eax
		_v_m1 :
		pop esi
		pop ecx

		jmp _v_next_elem1

		_end :
		mov eax, max
		ret
@sum3@8 endp
end
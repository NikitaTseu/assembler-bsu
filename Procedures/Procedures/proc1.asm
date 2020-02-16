.486
PUBLIC _found1
PUBLIC _found2@12
PUBLIC @found3@12
.model flat

.code
_found1 proc
	push ebp
	mov ebp, esp
	xor eax, eax
	mov al, byte ptr [ebp+16]
	cld
	mov edi, [ebp+8]
	mov ecx, [ebp+12]

	repne scasb
	je mfind
	mov eax, -1
	jmp mend
	mfind:
	mov eax, ecx
	mend:
	pop ebp
	ret
_found1 endp

_found2@12 proc
	push ebp
	mov ebp, esp
	xor eax, eax
	mov al, byte ptr [ebp+16]
	cld
	mov edi, [ebp+8]
	mov ecx, [ebp+12]

	repne scasb
	je mfind
	mov eax, -1
	jmp mend
	mfind:
	mov eax, ecx
	mend:
	pop ebp
	ret 12
_found2@12 endp


@found3@12 proc
	push ebp
	mov ebp, esp
	xor eax, eax
	mov al, byte ptr [ebp+8]
	cld
	mov edi, ecx
	mov ecx, edx

	repne scasb
	je mfind
	mov eax, -1
	jmp mend
	mfind:
	mov eax, ecx
	mend:
	pop ebp
	ret 4
@found3@12 endp
end
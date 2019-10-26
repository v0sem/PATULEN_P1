segment .data
	err_div0 db "Error al dividir entre 0",0
	err_ior db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_m resb 1
	_v resb 4
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	mov eax, 0
	push dword eax
	pop dword eax
	mov dword [_m], eax
while1:
	mov eax, _m
	push dword eax
	mov eax, 4
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jle near true1
	mov dword eax, 0
	push dword eax
	jmp near next1
true1:
	mov dword eax,1
	push dword eax
next1:
	pop dword eax
	cmp eax, 0
	je near endwhile1
	mov eax, _m
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	mov eax, _m
	push dword eax
	mov eax, 10
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	imul ebx
	push dword eax
	mov eax, _m
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	cmp eax, 0
	jl near fin_IOR
	cmp eax, 3
	jg near fin_IOR
	mov dword edx, _v
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
	mov eax, _m
	push dword eax
	mov eax, 1
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov dword [_m], eax
	jmp near while1
endwhile1:
	jmp near fin
fin_DIV0:
	push dword err_div0
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin_IOR:
	push dword err_ior
	call print_string
	add esp, 4
	call print_endofline
	jmp near fin
fin:
	mov esp, [__esp]
	ret

segment .data
	err_div0 db "Error al dividir entre 0",0
	err_ior db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
	_j resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword _x
	call scan_int
	add esp, 4
	push dword _z
	call scan_int
	add esp, 4
	mov eax, _x
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	neg eax
	push dword eax
	pop dword eax
	mov dword [_j], eax
	mov eax, _j
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, _z
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	sub eax, ebx
	push dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 2
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword edx, 0
	cmp ebx, edx
	je near fin_DIV0
	idiv ebx
	push dword eax
	pop dword eax
	mov dword [_y], eax
	mov eax, _y
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, _y
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	mov dword ebx, [ebx]
	imul ebx
	push dword eax
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
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

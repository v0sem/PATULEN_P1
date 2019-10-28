segment .data
	err_div0 db "Error al dividir entre 0",0
	err_ior db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_b1 resb 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword _b1
	call scan_boolean
	add esp, 4
	mov eax, _b1
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	mov dword ecx, 0
	cmp ecx, eax
	je near no0
	mov dword ecx, 0
	push dword ecx
	jmp near next0
no0:
	mov dword ecx, 1
	push dword ecx
next0:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _b1
	push dword eax
	pop dword eax
	mov dword eax, [eax]
	mov dword ecx, 0
	cmp ecx, eax
	je near no1
	mov dword ecx, 0
	push dword ecx
	jmp near next1
no1:
	mov dword ecx, 1
	push dword ecx
next1:
	pop dword eax
	mov dword ecx, 0
	cmp ecx, eax
	je near no2
	mov dword ecx, 0
	push dword ecx
	jmp near next2
no2:
	mov dword ecx, 1
	push dword ecx
next2:
	push dword eax
	call print_boolean
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

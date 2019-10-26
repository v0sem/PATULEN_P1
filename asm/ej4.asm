segment .data
	err_div0 db "Error al dividir entre 0",0
	err_ior db "Indice de vector fuera de rango", 0
segment .bss
	__esp resd 1
	_b1 resb 1
	_x resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean, print_endofline, print_blank, print_string, alfa_malloc, alfa_free, ld_float
main:
	mov dword [__esp], esp
	push dword _b1
	call scan_boolean
	add esp, 4
	push dword _x
	call scan_int
	add esp, 4
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jg near true0
	mov dword eax, 0
	push dword eax
	jmp near next0
true0:
	mov dword eax,1
	push dword eax
next0:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jge near true1
	mov dword eax, 0
	push dword eax
	jmp near next1
true1:
	mov dword eax,1
	push dword eax
next1:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jl near true2
	mov dword eax, 0
	push dword eax
	jmp near next2
true2:
	mov dword eax,1
	push dword eax
next2:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jle near true3
	mov dword eax, 0
	push dword eax
	jmp near next3
true3:
	mov dword eax,1
	push dword eax
next3:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jz near true4
	mov dword eax, 0
	push dword eax
	jmp near next4
true4:
	mov dword eax,1
	push dword eax
next4:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _x
	push dword eax
	mov eax, 3
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	cmp eax,ebx
	jnz near true5
	mov dword eax, 0
	push dword eax
	jmp near next5
true5:
	mov dword eax,1
	push dword eax
next5:
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _b1
	push dword eax
	mov eax, 0
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	and eax, ebx
	push dword eax
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
	mov eax, _b1
	push dword eax
	mov eax, 1
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword eax, [eax]
	or eax, ebx
	push dword eax
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

.model flat
.486
.stack
.code

_bit_set PROC
	mov eax, [esp+4]
	mov edx, [esp+8]

	cmp edx, 32
	jle L1
	add eax, 4
	sub edx, 32
L1:
	bts [eax], edx
	ret
_bit_set ENDP

_bit_reset PROC
	mov eax, [esp+4]
	mov edx, [esp+8]

	cmp edx, 32
	jle L2
	add eax, 4
	sub edx, 32
L2:
	btr [eax], edx
	ret
_bit_reset ENDP

_bit_scan_forward_intrin PROC
	mov edx, [esp+4]
    bsf eax, edx
    jnz L4
    mov edx, [esp+8]
    bsf eax, edx
    jnz L3
    xor eax, eax
    dec eax
    ret
L3:
    add eax, 32
L4:
    ret
_bit_scan_forward_intrin ENDP

_bit_scan_reverse_intrin PROC
	mov edx, [esp+8]
    bsf eax, edx
    jnz L5
    mov edx, [esp+4]
    bsf eax, edx
    jnz L6
    xor eax, eax
    dec eax
    ret
L5:
    add eax, 32
L6:
    ret
_bit_scan_reverse_intrin ENDP

_bswap64_intrin PROC
	mov edx, [esp+4]
	mov eax, [esp+8]
	bswap edx
	bswap eax
	ret
_bswap64_intrin ENDP

END
.code

bit_set PROC
    bts [rcx], rdx
    ret
bit_set ENDP

bit_reset PROC
    btr [rcx], rdx 
    ret
bit_reset ENDP

bit_scan_forward_intrin PROC
	bsf rax, rcx
	jnz L1
	xor rax, rax
	dec rax
L1:
    ret
bit_scan_forward_intrin ENDP

bit_scan_reverse_intrin PROC
	bsr rax, rcx
	jnz L2
	xor rax, rax
	dec rax
L2:
	ret
bit_scan_reverse_intrin ENDP

bswap64_intrin PROC
	bswap rcx
	mov rax, rcx
	ret
bswap64_intrin ENDP

END

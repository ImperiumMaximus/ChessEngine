#include <x86/gas/assembly.h>

DEFINE_FUNCTION(bit_set)
    /* &value */
    mov 4(%esp), %eax

    /* pos */
    mov 8(%esp), %edx

    cmpl $32, %edx
    jle 1f
    addl $4, %eax
    subl $32, %edx
1:
    bts %edx, (%eax)
    ret
END_FUNCTION(bit_set)

DEFINE_FUNCTION(bit_reset)
    /* &value */
    mov 4(%esp), %eax

    /* pos */
    mov 8(%esp), %edx

    cmpl $32, %edx
    jle 1f
    addl $4, %eax
    subl $32, %edx
1:
    btr %edx, (%eax)
    ret
END_FUNCTION(bit_reset)

DEFINE_FUNCTION(bit_scan_forward_intrin)
    mov 4(%esp), %edx
    bsf %edx, %eax
    jnz 2f
    mov 8(%esp), %edx
    bsf %edx, %eax
    jnz 1f
    xor %eax, %eax
    dec %eax
    ret
1:
    addl $32, %eax
2:
    ret
END_FUNCTION(bit_scan_forward_intrin)

DEFINE_FUNCTION(bit_scan_reverse_intrin)
    mov 8(%esp), %edx
    bsr %edx, %eax
    jnz 1f
    mov 4(%esp), %edx
    bsr %edx, %eax
    jnz 2f
    xor %eax, %eax
    dec %eax
    ret
1:
    addl $32, %eax
2:
    ret
END_FUNCTION(bit_scan_reverse_intrin)

#include <x86/gas/assembly.h>

DEFINE_FUNCTION(bit_set)
    bts %rsi, (%rdi)
    ret
END_FUNCTION(bit_set)

DEFINE_FUNCTION(bit_reset)
    btr %rsi, (%rdi)
    ret
END_FUNCTION(bit_reset)

DEFINE_FUNCTION(bit_scan_forward_intrin)
    bsf %rdi, %rax
    jnz 1f
    xor %rax, %rax
    dec %rax
1:
    ret
END_FUNCTION(bit_scan_forward_intrin)

DEFINE_FUNCTION(bit_scan_reverse_intrin)
    bsr %rdi, %rax
    jnz 1f
    xor %rax, %rax
    dec %rax
1:
    ret
END_FUNCTION(bit_scan_reverse_intrin)

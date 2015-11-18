#ifndef __CPU_H__
#define __CPU_H__

#include <stdbool.h>

void arch_setup(void);
bool arch_cpu_has_fast_bitscan(void);

#endif/* __CPU_H__ */

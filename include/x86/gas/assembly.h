#ifndef __GAS_ASSEMBLY_H__
#define __GAS_ASSEMBLY_H__

#define DEFINE_FUNCTION(name) \
    .global name; \
    .type name,@function; \
    name:
#define END_FUNCTION(name) \
    .size name, . - name;

#define GLUE2(a, b) a##b
#define GLUE(a, b) GLUE2(a, b)

#endif /* __GAS_ASSEMBLY_H__ */

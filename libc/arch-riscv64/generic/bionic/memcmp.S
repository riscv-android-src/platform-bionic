// Prototype: int memcmp (const char *s1, const char *s2, int n).

#include <private/bionic_asm.h>

ENTRY(memcmp_generic)
        addi    a2, a2, -8
        bltz    a2, .L_less_than_8
        ld      a4, 0(a0)
        ld      a5, 0(a1)
        sub     t1, a4, a5
        bnez    t1, .L_ret

        addi    a2, a2, -8
        bgtz    a2, .L_more_than_16

        add     a0, a0, a2
        add     a1, a1, a2
        ld      a4, 8(a0)
        ld      a5, 8(a1)
        sub     t1, a4, a5
        j       .L_ret
.L_more_than_16:
        ld      a4, 8(a0)
        ld      a5, 8(a1)
        sub     t1, a4, a5
        bnez    t1, .L_ret

        addi    a2, a2, -16
        addi    a0, a0, 16
        addi    a1, a1, 16
        bltz    a2, .L_last_bytes

        addi    a3, a2, -96
        bltz    a3, .L_loop16

        andi    a3, a0, 15
        add     a2, a2, a3
        sub     a0, a0, a3
        sub     a1, a1, a3
.L_loop16:
        ld      a4, 0(a0)
        ld      a5, 0(a1)
        addi    a2, a2, -16
        ld      a6, 8(a0)
        ld      a7, 8(a1)
        addi    a0, a0, 16
        addi    a1, a1, 16
        sltz    t1, a2
        sub     t2, a4, a5
        sub     t3, a6, a7
        or      t1, t1, t2
        or      t1, t1, t3
        beqz    t1, .L_loop16

        sub     t1, a4, a5
        bnez    t1, .L_ret
        sub     t1, a6, a7
        mv      a4, a6
        mv      a5, a7
        bnez    t1, .L_ret

.L_last_bytes:
        add     a0, a0, a2
        add     a1, a1, a2
        ld      a4, 0(a0)
        ld      a5, 0(a1)
        sub     t1, a4, a5
        bnez    t1, .L_ret
        ld      a4, 8(a0)
        ld      a5, 8(a1)
        sub     t1, a4, a5
.L_ret:
        li      t2, 0
.L_ret_loop:
        srl     a6, a4, t2
        andi    a6, a6, 0xff
        srl     a7, a5, t2
        andi    a7, a7, 0xff
        sub     a0, a6, a7
        bnez    a0, .L_ret_val
        addi    t2, t2, 8
        addi    t3, t2, -64
        bltz    t3, .L_ret_loop
.L_ret_val:
        ret

.L_less_than_8:
        addi    a2, a2, 4
        bltz    a2, .L_less_than_4
        lw      a4, 0(a0)
        lw      a5, 0(a1)
        sub     t1, a4, a5
        bnez    t1, .L_ret
        addi    a0, a0, 4
        addi    a1, a1, 4
        addi    a2, a2, -4
.L_less_than_4:
        addi    a2, a2, 4
        beqz    a2, .L_ret_0
.L_byte_loop:
        lbu     a4, 0(a0)
        lbu     a5, 0(a1)
        addi    a0, a0, 1
        addi    a1, a1, 1
        addi    a2, a2, -1
        sub     t1, a4, a5
        bnez    t1, .L_ret_valb
        bgtz    a2, .L_byte_loop
.L_ret_valb:
        mv      a0, t1
        ret
.L_ret_0:
        li      a0, 0
        ret
END(memcmp_generic)

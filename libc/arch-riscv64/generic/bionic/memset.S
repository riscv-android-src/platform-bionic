// Prototype: void *memcpy (void *dst, const void *src, size_t count).

#include <private/bionic_asm.h>

#  define LABLE_ALIGN   \
        .balignl 16, 0x00000013

ENTRY(memset_generic)
        /* Test if len less than 8 bytes.  */
        mv      t6, a0
        sltiu   a4, a2, 8
        li      t3, 1
        bnez    a4, .L_set_by_byte

        andi    a4, a0, 7
        li      t5, 8
        /* Test if dest is not 4 bytes aligned.  */
        bnez    a4, .L_dest_not_aligned
        /* Hardware can handle unaligned access directly.  */
.L_dest_aligned:
#if defined(__riscv_xthead)
        extu    a1, a1, 7, 0
#else
        slli    a1, a1, 56
        srli    a1, a1, 56
#endif
        slli    a3, a1, 8
        or      a1, a1, a3
        slli    a3, a1, 16
        or      a1, a1, a3
        slli    a3, a1, 32
        or      a3, a3, a1

        /* If dest is aligned, then copy.  */
        srli    t4, a2, 6
        /* Test if len less than 64 bytes.  */
        beqz    t4, .L_len_less_64bytes
        andi    a2, a2, 63

.L_len_larger_64bytes:
#if defined(__riscv_xthead)
        mv      a1, a3
        sdd     a1, a3, 0(a0)
        sdd     a1, a3, 16(a0)
        sdd     a1, a3, 32(a0)
        sub     t4, t4, t3
        sdd     a1, a3, 48(a0)
#else
        sd      a3, 0(a0)
        sd      a3, 8(a0)
        sd      a3, 16(a0)
        sd      a3, 24(a0)
        sd      a3, 32(a0)
        sd      a3, 40(a0)
        sd      a3, 48(a0)
        sub     t4, t4, t3
        sd      a3, 56(a0)
#endif

        addi    a0, a0, 64
        bnez    t4, .L_len_larger_64bytes

.L_len_less_64bytes:
        srli    t4, a2, 2
        beqz    t4, .L_set_by_byte
        andi    a2, a2, 3
.L_len_less_64bytes_loop:
        sub     t4, t4, t3
        sw      a3, 0(a0)
        addi    a0, a0, 4
        bnez    t4, .L_len_less_64bytes_loop

        /* Test if len less than 4 bytes.  */
.L_set_by_byte:
        andi    t4, a2, 7
        beqz    t4, .L_return
.L_set_by_byte_loop:
        sub     t4, t4, t3
        sb      a1, 0(a0)
        addi    a0, a0, 1
        bnez    t4, .L_set_by_byte_loop

.L_return:
        mv      a0, t6
        ret

        /* If dest is not aligned, just set some bytes makes the dest
           align.  */
.L_dest_not_aligned:
        sub     a4, t5, a4
        mv      t5, a4
.L_dest_not_aligned_loop:
        /* Makes the dest align.  */
        sub     a4, a4, t3
        sb      a1, 0(a0)
        addi    a0, a0, 1
        bnez    a4, .L_dest_not_aligned_loop
        sub     a2, a2, t5
        sltiu   a4, a2, 8
        bnez    a4, .L_set_by_byte
        /* Check whether the src is aligned.  */
        j               .L_dest_aligned
END(memset_generic)

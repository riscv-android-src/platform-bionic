// Prototype: void *memcpy (void *dst, const void *src, size_t count).

#include <private/bionic_asm.h>

#  define LABLE_ALIGN   \
        .balignw 16, 0x00000013

ENTRY(memcpy_generic)
.L_to_memcpy:
        /* Test if len less than 8 bytes.  */
        mv      t6, a0
        sltiu   a3, a2, 8
        li      t3, 1
        bnez    a3, .L_copy_by_byte

        andi    a3, a0, 7
        li      t5, 8
	/* Test if dest is not 8 bytes aligned.  */
        bnez    a3, .L_dest_not_aligned
.L_dest_aligned:
        /* If dest is aligned, then copy.  */
        srli    t4, a2, 6
        /* Test if len less than 64 bytes.  */
        beqz    t4, .L_len_less_64bytes
	andi    a2, a2, 63

	LABLE_ALIGN
.L_len_larger_64bytes:
#if defined(__riscv_xthead)
	ldd	a4, a5, 0(a1)
	sdd	a4, a5, 0(a0)
	ldd	a6, a7, 16(a1)
	sdd	a6, a7, 16(a0)
	ldd	a4, a5, 32(a1)
	sdd	a4, a5, 32(a0)
	ldd	a6, a7, 48(a1)
	sub	t4, t4, t3
        addi    a1, a1, 64
	sdd	a6, a7, 48(a0)
#else
        ld      a4, 0(a1)
        sd      a4, 0(a0)
        ld      a5, 8(a1)
        sd      a5, 8(a0)
        ld      a6, 16(a1)
        sd      a6, 16(a0)
        ld      a7, 24(a1)
        sd      a7, 24(a0)
        ld      a4, 32(a1)
        sd      a4, 32(a0)
        ld      a5, 40(a1)
        sd      a5, 40(a0)
        ld      a6, 48(a1)
        sd      a6, 48(a0)
        ld      a7, 56(a1)
        sub     t4, t4, t3
        addi    a1, a1, 64
        sd      a7, 56(a0)
#endif
        addi    a0, a0, 64
	bnez	t4, .L_len_larger_64bytes

.L_len_less_64bytes:
	srli    t4, a2, 2
        beqz    t4, .L_copy_by_byte
        andi    a2, a2, 3
.L_len_less_64bytes_loop:
        lw      a4, 0(a1)
	sub	t4, t4, t3
        addi    a1, a1, 4
        sw      a4, 0(a0)
        addi    a0, a0, 4
	bnez    t4, .L_len_less_64bytes_loop

        /* Copy tail.  */
.L_copy_by_byte:
        andi    t4, a2, 7
        beqz    t4, .L_return
.L_copy_by_byte_loop:
        lb      a4, 0(a1)
	sub	t4, t4, t3
        addi    a1, a1, 1
        sb      a4, 0(a0)
        addi    a0, a0, 1
	bnez	t4, .L_copy_by_byte_loop

.L_return:
        mv      a0, t6
        ret

        /* If dest is not aligned, just copying some bytes makes the dest
           align.  */
.L_dest_not_aligned:
        sub     a3, t5, a3
        mv      t5, a3
.L_dest_not_aligned_loop:
        /* Makes the dest align.  */
        lb      a4, 0(a1)
	sub	a3, a3, t3
        addi    a1, a1, 1
        sb      a4, 0(a0)
        addi    a0, a0, 1
	bnez	a3, .L_dest_not_aligned_loop
        sub     a2, a2, t5
	sltiu	a3, a2, 8
        bnez    a3, .L_copy_by_byte
        /* Check whether the src is aligned.  */
        j		.L_dest_aligned
END(memcpy_generic)

ENTRY(memmove_generic)
	sub	a3, a0, a1
	bgeu	a3, a2, .L_to_memcpy

	mv	t6, a0
	add	a0, a0, a2
	add	a1, a1, a2

	/* Test if len less than 8 bytes.  */
	sltiu	a3, a2, 8
  	li      t3, 1
    	li      t2, 4
	bnez	a3, .L_copy_by_byte_m

	andi	t5, a0, 7
	/* Test if dest is not 8 bytes aligned.  */
	bnez	t5, .L_dest_not_aligned_m
.L_dest_aligned_m:
	/* If dest is aligned, then copy.  */
	srli	t4, a2, 6
	/* Test if len less than 64 bytes.  */
	beqz	t4, .L_len_less_64bytes_m
	andi	a2, a2, 63
    	li      t1, 64

	/* len > 64 bytes */
	LABLE_ALIGN
.L_len_larger_64bytes_m:
	sub	a1, a1, t1
	sub	a0, a0, t1
#if defined(__riscv_xthead)
	ldd	a6, a7, 48(a1)
	sub	t4, t4, t3
	sdd	a6, a7, 48(a0)
	ldd	a4, a5, 32(a1)
	sdd	a4, a5, 32(a0)
	ldd	a6, a7, 16(a1)
	sdd	a6, a7, 16(a0)
	ldd	a4, a5, 0(a1)
	sdd	a4, a5, 0(a0)
#else
        ld      a7, 56(a1)
        sd      a7, 56(a0)
        ld      a6, 48(a1)
        sd      a6, 48(a0)
        ld      a5, 40(a1)
        sd      a5, 40(a0)
        ld      a4, 32(a1)
        sd      a4, 32(a0)
	ld      a7, 24(a1)
	sd      a7, 24(a0)
	ld      a6, 16(a1)
	sd      a6, 16(a0)
	ld      a5, 8(a1)
	sd      a5, 8(a0)
	ld      a3, 0(a1)
	sd      a3, 0(a0)
        sub     t4, t4, t3
#endif
	bnez	t4,.L_len_larger_64bytes_m

.L_len_less_64bytes_m:
	srli    t4, a2, 2
	beqz	t4, .L_copy_by_byte_m
	andi    a2, a2, 3
.L_len_less_64bytes_loop_m:
	sub	a1, a1, t2
	sub	a0, a0, t2
	lw	a3, 0(a1)
	sub     t4, t4, t3
	sw	a3, 0(a0)
	bnez    t4, .L_len_less_64bytes_loop_m

	/* Copy tail.  */
.L_copy_by_byte_m:
	andi    t4, a2, 7
	beqz	t4, .L_return_m
.L_copy_by_byte_loop_m:
	sub	a1, a1, t3
	sub	a0, a0, t3
	lb	a3, 0(a1)
	sub     t4, t4, t3
	sb	a3, 0(a0)
	bnez    t4, .L_copy_by_byte_loop_m

.L_return_m:
	mv	a0, t6
	ret

	/* If dest is not aligned, just copying some bytes makes the dest
	   align.  */
.L_dest_not_aligned_m:
	sub	a2, a2, t5
.L_dest_not_aligned_loop_m:
	sub	a1, a1, t3
	sub	a0, a0, t3
	/* Makes the dest align.  */
	lb	a3, 0(a1)
	sub     t5, t5, t3
	sb	a3, 0(a0)
	bnez	t5, .L_dest_not_aligned_loop_m
	sltiu   a3, a2, 8
	bnez    a3, .L_copy_by_byte_m
	/* Check whether the src is aligned.  */
	j	.L_dest_aligned_m
END(memmove_generic)

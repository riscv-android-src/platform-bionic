/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_ASM_RISCV_BITSPERLONG_H
#define _UAPI_ASM_RISCV_BITSPERLONG_H
// genseccomp.py to generate the syscall without __SIZEOF_POINTER__ dfined
//#define __BITS_PER_LONG (__SIZEOF_POINTER__ * 8)
#define __BITS_PER_LONG 64
#include <asm-generic/bitsperlong.h>
#endif

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
#ifndef __VS_DRM_H__
#define __VS_DRM_H__
#include "drm.h"
enum drm_vs_degamma_mode {
  VS_DEGAMMA_DISABLE = 0,
  VS_DEGAMMA_BT709 = 1,
  VS_DEGAMMA_BT2020 = 2,
};
enum drm_vs_sync_dc_mode {
  VS_SINGLE_DC = 0,
  VS_MULTI_DC_PRIMARY = 1,
  VS_MULTI_DC_SECONDARY = 2,
};
enum drm_vs_mmu_prefetch_mode {
  VS_MMU_PREFETCH_DISABLE = 0,
  VS_MMU_PREFETCH_ENABLE = 1,
};
struct drm_vs_watermark {
  __u32 watermark;
  __u8 qos_low;
  __u8 qos_high;
};
struct drm_vs_color_mgmt {
  __u32 colorkey;
  __u32 colorkey_high;
  __u32 clear_value;
  bool clear_enable;
  bool transparency;
};
struct drm_vs_roi {
  bool enable;
  __u16 roi_x;
  __u16 roi_y;
  __u16 roi_w;
  __u16 roi_h;
};
#endif

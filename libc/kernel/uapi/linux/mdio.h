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
#ifndef _UAPI__LINUX_MDIO_H__
#define _UAPI__LINUX_MDIO_H__
#include <linux/types.h>
#include <linux/mii.h>
#define MDIO_MMD_PMAPMD 1
#define MDIO_MMD_WIS 2
#define MDIO_MMD_PCS 3
#define MDIO_MMD_PHYXS 4
#define MDIO_MMD_DTEXS 5
#define MDIO_MMD_TC 6
#define MDIO_MMD_AN 7
#define MDIO_MMD_C22EXT 29
#define MDIO_MMD_VEND1 30
#define MDIO_MMD_VEND2 31
#define MDIO_CTRL1 MII_BMCR
#define MDIO_STAT1 MII_BMSR
#define MDIO_DEVID1 MII_PHYSID1
#define MDIO_DEVID2 MII_PHYSID2
#define MDIO_SPEED 4
#define MDIO_DEVS1 5
#define MDIO_DEVS2 6
#define MDIO_CTRL2 7
#define MDIO_STAT2 8
#define MDIO_PMA_TXDIS 9
#define MDIO_PMA_RXDET 10
#define MDIO_PMA_EXTABLE 11
#define MDIO_PKGID1 14
#define MDIO_PKGID2 15
#define MDIO_AN_ADVERTISE 16
#define MDIO_AN_LPA 19
#define MDIO_PCS_EEE_ABLE 20
#define MDIO_PCS_EEE_ABLE2 21
#define MDIO_PMA_NG_EXTABLE 21
#define MDIO_PCS_EEE_WK_ERR 22
#define MDIO_PHYXS_LNSTAT 24
#define MDIO_AN_EEE_ADV 60
#define MDIO_AN_EEE_LPABLE 61
#define MDIO_AN_EEE_ADV2 62
#define MDIO_AN_EEE_LPABLE2 63
#define MDIO_PMA_10GBT_SWAPPOL 130
#define MDIO_PMA_10GBT_TXPWR 131
#define MDIO_PMA_10GBT_SNR 133
#define MDIO_PMA_10GBR_FECABLE 170
#define MDIO_PCS_10GBX_STAT1 24
#define MDIO_PCS_10GBRT_STAT1 32
#define MDIO_PCS_10GBRT_STAT2 33
#define MDIO_AN_10GBT_CTRL 32
#define MDIO_AN_10GBT_STAT 33
#define MDIO_PMA_LASI_RXCTRL 0x9000
#define MDIO_PMA_LASI_TXCTRL 0x9001
#define MDIO_PMA_LASI_CTRL 0x9002
#define MDIO_PMA_LASI_RXSTAT 0x9003
#define MDIO_PMA_LASI_TXSTAT 0x9004
#define MDIO_PMA_LASI_STAT 0x9005
#define MDIO_CTRL1_SPEEDSELEXT (BMCR_SPEED1000 | BMCR_SPEED100)
#define MDIO_CTRL1_SPEEDSEL (MDIO_CTRL1_SPEEDSELEXT | 0x003c)
#define MDIO_CTRL1_FULLDPLX BMCR_FULLDPLX
#define MDIO_CTRL1_LPOWER BMCR_PDOWN
#define MDIO_CTRL1_RESET BMCR_RESET
#define MDIO_PMA_CTRL1_LOOPBACK 0x0001
#define MDIO_PMA_CTRL1_SPEED1000 BMCR_SPEED1000
#define MDIO_PMA_CTRL1_SPEED100 BMCR_SPEED100
#define MDIO_PCS_CTRL1_LOOPBACK BMCR_LOOPBACK
#define MDIO_PHYXS_CTRL1_LOOPBACK BMCR_LOOPBACK
#define MDIO_AN_CTRL1_RESTART BMCR_ANRESTART
#define MDIO_AN_CTRL1_ENABLE BMCR_ANENABLE
#define MDIO_AN_CTRL1_XNP 0x2000
#define MDIO_PCS_CTRL1_CLKSTOP_EN 0x400
#define MDIO_CTRL1_SPEED10G (MDIO_CTRL1_SPEEDSELEXT | 0x00)
#define MDIO_CTRL1_SPEED10P2B (MDIO_CTRL1_SPEEDSELEXT | 0x04)
#define MDIO_CTRL1_SPEED2_5G (MDIO_CTRL1_SPEEDSELEXT | 0x18)
#define MDIO_CTRL1_SPEED5G (MDIO_CTRL1_SPEEDSELEXT | 0x1c)
#define MDIO_STAT1_LPOWERABLE 0x0002
#define MDIO_STAT1_LSTATUS BMSR_LSTATUS
#define MDIO_STAT1_FAULT 0x0080
#define MDIO_AN_STAT1_LPABLE 0x0001
#define MDIO_AN_STAT1_ABLE BMSR_ANEGCAPABLE
#define MDIO_AN_STAT1_RFAULT BMSR_RFAULT
#define MDIO_AN_STAT1_COMPLETE BMSR_ANEGCOMPLETE
#define MDIO_AN_STAT1_PAGE 0x0040
#define MDIO_AN_STAT1_XNP 0x0080
#define MDIO_SPEED_10G 0x0001
#define MDIO_PMA_SPEED_2B 0x0002
#define MDIO_PMA_SPEED_10P 0x0004
#define MDIO_PMA_SPEED_1000 0x0010
#define MDIO_PMA_SPEED_100 0x0020
#define MDIO_PMA_SPEED_10 0x0040
#define MDIO_PCS_SPEED_10P2B 0x0002
#define MDIO_PCS_SPEED_2_5G 0x0040
#define MDIO_PCS_SPEED_5G 0x0080
#define MDIO_DEVS_PRESENT(devad) (1 << (devad))
#define MDIO_DEVS_C22PRESENT MDIO_DEVS_PRESENT(0)
#define MDIO_DEVS_PMAPMD MDIO_DEVS_PRESENT(MDIO_MMD_PMAPMD)
#define MDIO_DEVS_WIS MDIO_DEVS_PRESENT(MDIO_MMD_WIS)
#define MDIO_DEVS_PCS MDIO_DEVS_PRESENT(MDIO_MMD_PCS)
#define MDIO_DEVS_PHYXS MDIO_DEVS_PRESENT(MDIO_MMD_PHYXS)
#define MDIO_DEVS_DTEXS MDIO_DEVS_PRESENT(MDIO_MMD_DTEXS)
#define MDIO_DEVS_TC MDIO_DEVS_PRESENT(MDIO_MMD_TC)
#define MDIO_DEVS_AN MDIO_DEVS_PRESENT(MDIO_MMD_AN)
#define MDIO_DEVS_C22EXT MDIO_DEVS_PRESENT(MDIO_MMD_C22EXT)
#define MDIO_DEVS_VEND1 MDIO_DEVS_PRESENT(MDIO_MMD_VEND1)
#define MDIO_DEVS_VEND2 MDIO_DEVS_PRESENT(MDIO_MMD_VEND2)
#define MDIO_PMA_CTRL2_TYPE 0x000f
#define MDIO_PMA_CTRL2_10GBCX4 0x0000
#define MDIO_PMA_CTRL2_10GBEW 0x0001
#define MDIO_PMA_CTRL2_10GBLW 0x0002
#define MDIO_PMA_CTRL2_10GBSW 0x0003
#define MDIO_PMA_CTRL2_10GBLX4 0x0004
#define MDIO_PMA_CTRL2_10GBER 0x0005
#define MDIO_PMA_CTRL2_10GBLR 0x0006
#define MDIO_PMA_CTRL2_10GBSR 0x0007
#define MDIO_PMA_CTRL2_10GBLRM 0x0008
#define MDIO_PMA_CTRL2_10GBT 0x0009
#define MDIO_PMA_CTRL2_10GBKX4 0x000a
#define MDIO_PMA_CTRL2_10GBKR 0x000b
#define MDIO_PMA_CTRL2_1000BT 0x000c
#define MDIO_PMA_CTRL2_1000BKX 0x000d
#define MDIO_PMA_CTRL2_100BTX 0x000e
#define MDIO_PMA_CTRL2_10BT 0x000f
#define MDIO_PMA_CTRL2_2_5GBT 0x0030
#define MDIO_PMA_CTRL2_5GBT 0x0031
#define MDIO_PCS_CTRL2_TYPE 0x0003
#define MDIO_PCS_CTRL2_10GBR 0x0000
#define MDIO_PCS_CTRL2_10GBX 0x0001
#define MDIO_PCS_CTRL2_10GBW 0x0002
#define MDIO_PCS_CTRL2_10GBT 0x0003
#define MDIO_STAT2_RXFAULT 0x0400
#define MDIO_STAT2_TXFAULT 0x0800
#define MDIO_STAT2_DEVPRST 0xc000
#define MDIO_STAT2_DEVPRST_VAL 0x8000
#define MDIO_PMA_STAT2_LBABLE 0x0001
#define MDIO_PMA_STAT2_10GBEW 0x0002
#define MDIO_PMA_STAT2_10GBLW 0x0004
#define MDIO_PMA_STAT2_10GBSW 0x0008
#define MDIO_PMA_STAT2_10GBLX4 0x0010
#define MDIO_PMA_STAT2_10GBER 0x0020
#define MDIO_PMA_STAT2_10GBLR 0x0040
#define MDIO_PMA_STAT2_10GBSR 0x0080
#define MDIO_PMD_STAT2_TXDISAB 0x0100
#define MDIO_PMA_STAT2_EXTABLE 0x0200
#define MDIO_PMA_STAT2_RXFLTABLE 0x1000
#define MDIO_PMA_STAT2_TXFLTABLE 0x2000
#define MDIO_PCS_STAT2_10GBR 0x0001
#define MDIO_PCS_STAT2_10GBX 0x0002
#define MDIO_PCS_STAT2_10GBW 0x0004
#define MDIO_PCS_STAT2_RXFLTABLE 0x1000
#define MDIO_PCS_STAT2_TXFLTABLE 0x2000
#define MDIO_PMD_TXDIS_GLOBAL 0x0001
#define MDIO_PMD_TXDIS_0 0x0002
#define MDIO_PMD_TXDIS_1 0x0004
#define MDIO_PMD_TXDIS_2 0x0008
#define MDIO_PMD_TXDIS_3 0x0010
#define MDIO_PMD_RXDET_GLOBAL 0x0001
#define MDIO_PMD_RXDET_0 0x0002
#define MDIO_PMD_RXDET_1 0x0004
#define MDIO_PMD_RXDET_2 0x0008
#define MDIO_PMD_RXDET_3 0x0010
#define MDIO_PMA_EXTABLE_10GCX4 0x0001
#define MDIO_PMA_EXTABLE_10GBLRM 0x0002
#define MDIO_PMA_EXTABLE_10GBT 0x0004
#define MDIO_PMA_EXTABLE_10GBKX4 0x0008
#define MDIO_PMA_EXTABLE_10GBKR 0x0010
#define MDIO_PMA_EXTABLE_1000BT 0x0020
#define MDIO_PMA_EXTABLE_1000BKX 0x0040
#define MDIO_PMA_EXTABLE_100BTX 0x0080
#define MDIO_PMA_EXTABLE_10BT 0x0100
#define MDIO_PMA_EXTABLE_NBT 0x4000
#define MDIO_PHYXS_LNSTAT_SYNC0 0x0001
#define MDIO_PHYXS_LNSTAT_SYNC1 0x0002
#define MDIO_PHYXS_LNSTAT_SYNC2 0x0004
#define MDIO_PHYXS_LNSTAT_SYNC3 0x0008
#define MDIO_PHYXS_LNSTAT_ALIGN 0x1000
#define MDIO_PMA_10GBT_SWAPPOL_ABNX 0x0001
#define MDIO_PMA_10GBT_SWAPPOL_CDNX 0x0002
#define MDIO_PMA_10GBT_SWAPPOL_AREV 0x0100
#define MDIO_PMA_10GBT_SWAPPOL_BREV 0x0200
#define MDIO_PMA_10GBT_SWAPPOL_CREV 0x0400
#define MDIO_PMA_10GBT_SWAPPOL_DREV 0x0800
#define MDIO_PMA_10GBT_TXPWR_SHORT 0x0001
#define MDIO_PMA_10GBT_SNR_BIAS 0x8000
#define MDIO_PMA_10GBT_SNR_MAX 127
#define MDIO_PMA_10GBR_FECABLE_ABLE 0x0001
#define MDIO_PMA_10GBR_FECABLE_ERRABLE 0x0002
#define MDIO_PCS_10GBRT_STAT1_BLKLK 0x0001
#define MDIO_PCS_10GBRT_STAT2_ERR 0x00ff
#define MDIO_PCS_10GBRT_STAT2_BER 0x3f00
#define MDIO_AN_10GBT_CTRL_ADV2_5G 0x0080
#define MDIO_AN_10GBT_CTRL_ADV5G 0x0100
#define MDIO_AN_10GBT_CTRL_ADV10G 0x1000
#define MDIO_AN_10GBT_STAT_LP2_5G 0x0020
#define MDIO_AN_10GBT_STAT_LP5G 0x0040
#define MDIO_AN_10GBT_STAT_LPTRR 0x0200
#define MDIO_AN_10GBT_STAT_LPLTABLE 0x0400
#define MDIO_AN_10GBT_STAT_LP10G 0x0800
#define MDIO_AN_10GBT_STAT_REMOK 0x1000
#define MDIO_AN_10GBT_STAT_LOCOK 0x2000
#define MDIO_AN_10GBT_STAT_MS 0x4000
#define MDIO_AN_10GBT_STAT_MSFLT 0x8000
#define MDIO_AN_EEE_ADV_100TX 0x0002
#define MDIO_AN_EEE_ADV_1000T 0x0004
#define MDIO_EEE_100TX MDIO_AN_EEE_ADV_100TX
#define MDIO_EEE_1000T MDIO_AN_EEE_ADV_1000T
#define MDIO_EEE_10GT 0x0008
#define MDIO_EEE_1000KX 0x0010
#define MDIO_EEE_10GKX4 0x0020
#define MDIO_EEE_10GKR 0x0040
#define MDIO_EEE_40GR_FW 0x0100
#define MDIO_EEE_40GR_DS 0x0200
#define MDIO_EEE_100GR_FW 0x1000
#define MDIO_EEE_100GR_DS 0x2000
#define MDIO_EEE_2_5GT 0x0001
#define MDIO_EEE_5GT 0x0002
#define MDIO_PMA_NG_EXTABLE_2_5GBT 0x0001
#define MDIO_PMA_NG_EXTABLE_5GBT 0x0002
#define MDIO_PMA_LASI_RX_PHYXSLFLT 0x0001
#define MDIO_PMA_LASI_RX_PCSLFLT 0x0008
#define MDIO_PMA_LASI_RX_PMALFLT 0x0010
#define MDIO_PMA_LASI_RX_OPTICPOWERFLT 0x0020
#define MDIO_PMA_LASI_RX_WISLFLT 0x0200
#define MDIO_PMA_LASI_TX_PHYXSLFLT 0x0001
#define MDIO_PMA_LASI_TX_PCSLFLT 0x0008
#define MDIO_PMA_LASI_TX_PMALFLT 0x0010
#define MDIO_PMA_LASI_TX_LASERPOWERFLT 0x0080
#define MDIO_PMA_LASI_TX_LASERTEMPFLT 0x0100
#define MDIO_PMA_LASI_TX_LASERBICURRFLT 0x0200
#define MDIO_PMA_LASI_LSALARM 0x0001
#define MDIO_PMA_LASI_TXALARM 0x0002
#define MDIO_PMA_LASI_RXALARM 0x0004
#define MDIO_PHY_ID_C45 0x8000
#define MDIO_PHY_ID_PRTAD 0x03e0
#define MDIO_PHY_ID_DEVAD 0x001f
#define MDIO_PHY_ID_C45_MASK (MDIO_PHY_ID_C45 | MDIO_PHY_ID_PRTAD | MDIO_PHY_ID_DEVAD)
#define MDIO_USXGMII_EEE_CLK_STP 0x0080
#define MDIO_USXGMII_EEE 0x0100
#define MDIO_USXGMII_SPD_MASK 0x0e00
#define MDIO_USXGMII_FULL_DUPLEX 0x1000
#define MDIO_USXGMII_DPX_SPD_MASK 0x1e00
#define MDIO_USXGMII_10 0x0000
#define MDIO_USXGMII_10HALF 0x0000
#define MDIO_USXGMII_10FULL 0x1000
#define MDIO_USXGMII_100 0x0200
#define MDIO_USXGMII_100HALF 0x0200
#define MDIO_USXGMII_100FULL 0x1200
#define MDIO_USXGMII_1000 0x0400
#define MDIO_USXGMII_1000HALF 0x0400
#define MDIO_USXGMII_1000FULL 0x1400
#define MDIO_USXGMII_10G 0x0600
#define MDIO_USXGMII_10GHALF 0x0600
#define MDIO_USXGMII_10GFULL 0x1600
#define MDIO_USXGMII_2500 0x0800
#define MDIO_USXGMII_2500HALF 0x0800
#define MDIO_USXGMII_2500FULL 0x1800
#define MDIO_USXGMII_5000 0x0a00
#define MDIO_USXGMII_5000HALF 0x0a00
#define MDIO_USXGMII_5000FULL 0x1a00
#define MDIO_USXGMII_LINK 0x8000
#endif

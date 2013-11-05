/*
 * (C) Copyright 2012 Xilinx
 *
 * Configuration settings for the Xilinx Zynq ZC702 and ZC706 boards
 * See zynq_common.h for Zynq common configs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_ZYNQ_ZC706_H
#define __CONFIG_ZYNQ_ZC706_H

#define PHYS_SDRAM_1_SIZE (1024 * 1024 * 1024)

#define CONFIG_ZYNQ_SERIAL_UART1

#define CONFIG_SYS_NO_FLASH

#define CONFIG_ZYNQ_SDHCI0

#undef CONFIG_SYS_TEXT_BASE
#include <configs/zynq_common.h>
#include <configs/ezynq/ezynq_MT41J256M8HX15E.h>  /* should be before zed_ezynq.h as it overwrites DDR3L with DDR3 */
#include <configs/ezynq/ezynq_XC7Z045_2FFG900C.h>
#include <configs/ezynq/ezynq_zc706.h>

#define CONFIG_CMD_MEMTEST
//#undef CONFIG_EZYNQ_BOOT_DEBUG 
#undef CONFIG_EZYNQ_LED_DEBUG

/* twice slower */
#undef CONFIG_ZYNQ_SERIAL_CLOCK0
/*#define CONFIG_ZYNQ_SERIAL_CLOCK0	25000000*/
#define CONFIG_ZYNQ_SERIAL_CLOCK0	1000000 * (CONFIG_EZYNQ_CLK_UART_MHZ)
#undef CONFIG_ZYNQ_SERIAL_CLOCK1
/*#define CONFIG_ZYNQ_SERIAL_CLOCK1	25000000*/
#define CONFIG_ZYNQ_SERIAL_CLOCK1	1000000 * (CONFIG_EZYNQ_CLK_UART_MHZ)

#undef CONFIG_BOOTDELAY
#undef CONFIG_SYS_PROMPT
#undef CONFIG_SYS_SDRAM_BASE
#undef CONFIG_ENV_SIZE
#undef CONFIG_SYS_TEXT_BASE

#define CONFIG_BOOTDELAY	-1 /* -1 to Disable autoboot */
#define CONFIG_SYS_PROMPT		"ezynq> "


#define CONFIG_SYS_SDRAM_BASE		0x00000000 /* Physical start address of SDRAM. _Must_ be 0 here. */
#define CONFIG_ENV_SIZE		        1400
#define CONFIG_SYS_TEXT_BASE		0x00000000

#if 0
  #define CONFIG_SYS_TEXT_BASE		0x04000000 /*with 0x04000000 - does not get to the low_Level_init? */
#else
  //#define CONFIG_SYS_TEXT_BASE		0x00000000 //0x04000000 with 0x04000000 - does not get to the low_Level_init?
#endif
/*
#define CONFIG_EZYNQ_SKIP_DDR
*/
#define CONFIG_EZYNQ_SKIP_CLK

//undefs

/* undefs */
/*#undef CONFIG_FS_FAT */
/* #undef CONFIG_SUPPORT_VFAT */
/* #undef CONFIG_CMD_FAT */
/* http://lists.denx.de/pipermail/u-boot/2003-October/002631.html */
#undef CONFIG_CMD_LOADB
#undef CONFIG_CMD_LOADS
#undef CONFIG_ZLIB
#undef CONFIG_GZIP
/* CONFIG_FS_FAT=y */

/* disable PL*/
#undef CONFIG_FPGA
#undef CONFIG_FPGA_XILINX
#undef CONFIG_FPGA_ZYNQPL
#undef CONFIG_CMD_FPGA

#undef CONFIG_CMD_EXT2

#undef CONFIG_CMD_CACHE

// #undef DEBUG
#undef CONFIG_AUTO_COMPLETE
#undef CONFIG_SYS_LONGHELP

/* redefine env settings*/
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS	\
	"ethaddr=00:0a:35:00:01:22\0"	\
	"kernel_image=uImage\0"	\
	"ramdisk_image=uramdisk.image.gz\0"	\
 	"devicetree_image=devicetree.dtb\0"	\
	"bitstream_image=system.bit.bin\0"	\
	"loadbit_addr=0x100000\0"	\
	"kernel_size=0x500000\0"	\
	"devicetree_size=0x20000\0"	\
	"ramdisk_size=0x5E0000\0"	\
	"fdt_high=0x20000000\0"	\
	"initrd_high=0x20000000\0"	\
	"mmc_loadbit_fat=echo Loading bitstream from SD/MMC/eMMC to RAM.. && " \
		"mmcinfo && " \
		"fatload mmc 0 ${loadbit_addr} ${bitstream_image} && " \
		"fpga load 0 ${loadbit_addr} ${filesize}\0" \
	"sdboot=echo Copying Linux from SD to RAM... && " \
		"mmcinfo && " \
		"fatload mmc 0 0x3000000 ${kernel_image} && " \
		"fatload mmc 0 0x2A00000 ${devicetree_image} && " \
		"fatload mmc 0 0x2000000 ${ramdisk_image} && " \
		"bootm 0x3000000 0x2000000 0x2A00000\0" \
	"nandboot=echo Copying Linux from NAND flash to RAM... && " \
		"nand read 0x3000000 0x100000 ${kernel_size} && " \
		"nand read 0x2A00000 0x600000 ${devicetree_size} && " \
		"echo Copying ramdisk... && " \
		"nand read 0x2000000 0x620000 ${ramdisk_size} && " \
		"bootm 0x3000000 0x2000000 0x2A00000\0"
/*  */

#endif /* __CONFIG_ZYNQ_ZC706_H */
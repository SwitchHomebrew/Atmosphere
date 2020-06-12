/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours.hpp>

#define APB_MISC_PP_CONFIG_CTL (0x024)

#define APB_MISC_GP_ASDBGREG   (0x810)

#define APB_MISC_SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG0_0 (0xc00)
#define APB_MISC_SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG0_0 (0xc00)
#define APB_MISC_SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG1_0 (0xc04)
#define APB_MISC_SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG2_0 (0xc08)

#define APB_MISC_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (APB_MISC, NAME)
#define APB_MISC_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (APB_MISC, NAME, VALUE)
#define APB_MISC_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (APB_MISC, NAME, ENUM)
#define APB_MISC_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(APB_MISC, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

#define DEFINE_APB_MISC_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (APB_MISC, NAME, __OFFSET__, __WIDTH__)
#define DEFINE_APB_MISC_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (APB_MISC, NAME, __OFFSET__, ZERO, ONE)
#define DEFINE_APB_MISC_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (APB_MISC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
#define DEFINE_APB_MISC_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(APB_MISC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
#define DEFINE_APB_MISC_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (APB_MISC, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)

DEFINE_APB_MISC_REG_BIT_ENUM(PP_CONFIG_CTL_JTAG, 6, DISABLE, ENABLE);
DEFINE_APB_MISC_REG_BIT_ENUM(PP_CONFIG_CTL_TBE,  7, DISABLE, ENABLE);

DEFINE_APB_MISC_REG(GP_ASDBGREG_CFG2TMC_RAM_SVOP_PDP, 24, 2);

#define DEFINE_SLAVE_SECURITY_REG(RINDEX, INDEX, NAME) DEFINE_APB_MISC_REG_BIT_ENUM(SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG##RINDEX##_##NAME##_SECURITY_EN, INDEX, DISABLE, ENABLE)

DEFINE_SLAVE_SECURITY_REG(0, 29, STM);
DEFINE_SLAVE_SECURITY_REG(0, 24, CEC);
DEFINE_SLAVE_SECURITY_REG(0, 23, ATOMICS);
DEFINE_SLAVE_SECURITY_REG(0, 22, LA);
DEFINE_SLAVE_SECURITY_REG(0, 21, HDA);
DEFINE_SLAVE_SECURITY_REG(0, 20, SATA);
DEFINE_SLAVE_SECURITY_REG(0, 16, KFUSE);
DEFINE_SLAVE_SECURITY_REG(0, 15, FUSE);
DEFINE_SLAVE_SECURITY_REG(0, 14, SE);
DEFINE_SLAVE_SECURITY_REG(0, 13, PMC);
DEFINE_SLAVE_SECURITY_REG(0, 11, RTC);
DEFINE_SLAVE_SECURITY_REG(0, 10, CSITE);
DEFINE_SLAVE_SECURITY_REG(0,  9, QSPI);
DEFINE_SLAVE_SECURITY_REG(0,  8, PWM);
DEFINE_SLAVE_SECURITY_REG(0,  6, DTV);
DEFINE_SLAVE_SECURITY_REG(0,  4, APE);
DEFINE_SLAVE_SECURITY_REG(0,  3, PINMUX_AUX);
DEFINE_SLAVE_SECURITY_REG(0,  2, SATA_AUX);
DEFINE_SLAVE_SECURITY_REG(0,  1, MISC_REGS);

DEFINE_SLAVE_SECURITY_REG(1, 31, I2C6);
DEFINE_SLAVE_SECURITY_REG(1, 30, DVC);
DEFINE_SLAVE_SECURITY_REG(1, 29, I2C4);
DEFINE_SLAVE_SECURITY_REG(1, 28, I2C3);
DEFINE_SLAVE_SECURITY_REG(1, 27, I2C2);
DEFINE_SLAVE_SECURITY_REG(1, 26, I2C1);
DEFINE_SLAVE_SECURITY_REG(1, 25, SPI6);
DEFINE_SLAVE_SECURITY_REG(1, 24, SPI5);
DEFINE_SLAVE_SECURITY_REG(1, 23, SPI4);
DEFINE_SLAVE_SECURITY_REG(1, 22, SPI3);
DEFINE_SLAVE_SECURITY_REG(1, 21, SPI2);
DEFINE_SLAVE_SECURITY_REG(1, 20, SPI1);
DEFINE_SLAVE_SECURITY_REG(1, 15, UART_D);
DEFINE_SLAVE_SECURITY_REG(1, 14, UART_C);
DEFINE_SLAVE_SECURITY_REG(1, 13, UART_B);
DEFINE_SLAVE_SECURITY_REG(1, 12, UART_A);
DEFINE_SLAVE_SECURITY_REG(1, 11, EMCB);
DEFINE_SLAVE_SECURITY_REG(1, 10, MCB);
DEFINE_SLAVE_SECURITY_REG(1,  9, EMC1);
DEFINE_SLAVE_SECURITY_REG(1,  8, MC1);
DEFINE_SLAVE_SECURITY_REG(1,  5, EMC0);
DEFINE_SLAVE_SECURITY_REG(1,  4, MC0);

DEFINE_SLAVE_SECURITY_REG(2, 21, FEK);
DEFINE_SLAVE_SECURITY_REG(2, 20, PKA1);
DEFINE_SLAVE_SECURITY_REG(2, 19, SE2);
DEFINE_SLAVE_SECURITY_REG(2, 16, DVFS);
DEFINE_SLAVE_SECURITY_REG(2, 15, MIPI_CAL);
DEFINE_SLAVE_SECURITY_REG(2, 14, XUSB_PADCTL);
DEFINE_SLAVE_SECURITY_REG(2, 13, XUSB_DEV);
DEFINE_SLAVE_SECURITY_REG(2, 12, XUSB_HOST);
DEFINE_SLAVE_SECURITY_REG(2, 11, APB2JTAG);
DEFINE_SLAVE_SECURITY_REG(2, 10, SOC_THERM);
DEFINE_SLAVE_SECURITY_REG(2,  9, DP2);
DEFINE_SLAVE_SECURITY_REG(2,  8, DDS);
DEFINE_SLAVE_SECURITY_REG(2,  7, MIPIBIF);
DEFINE_SLAVE_SECURITY_REG(2,  3, SDMMC4);
DEFINE_SLAVE_SECURITY_REG(2,  2, SDMMC3);
DEFINE_SLAVE_SECURITY_REG(2,  1, SDMMC2);
DEFINE_SLAVE_SECURITY_REG(2,  0, SDMMC1);

#undef DEFINE_SLAVE_SECURITY_REG

#define SLAVE_SECURITY_REG_BITS_ENUM(RINDEX, NAME, ENUM) APB_MISC_REG_BITS_ENUM(SECURE_REGS_APB_SLAVE_SECURITY_ENABLE_REG##RINDEX##_##NAME##_SECURITY_EN, ENUM)
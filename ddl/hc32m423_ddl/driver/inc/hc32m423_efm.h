/**
 *******************************************************************************
 * @file  hc32m423_efm.h
 * @brief This file contains all the functions prototypes of the EFM driver
 *        library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2020-02-06       Heqb          First version
 @endverbatim
 *******************************************************************************
 * Copyright (C) 2016, Huada Semiconductor Co., Ltd. All rights reserved.
 *
 * This software is owned and published by:
 * Huada Semiconductor Co., Ltd. ("HDSC").
 *
 * BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
 * BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 *
 * This software contains source code for use with HDSC
 * components. This software is licensed by HDSC to be adapted only
 * for use in systems utilizing HDSC components. HDSC shall not be
 * responsible for misuse or illegal use of this software for devices not
 * supported herein. HDSC is providing this software "AS IS" and will
 * not be responsible for issues arising from incorrect user implementation
 * of the software.
 *
 * Disclaimer:
 * HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 * REGARDING THE SOFTWARE (INCLUDING ANY ACCOMPANYING WRITTEN MATERIALS),
 * ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
 * WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
 * WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
 * WARRANTY OF NONINFRINGEMENT.
 * HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
 * NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
 * LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
 * INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
 * SAVINGS OR PROFITS,
 * EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 * INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
 * FROM, THE SOFTWARE.
 *
 * This software may be replicated in part or whole for the licensed use,
 * with the restriction that this Disclaimer and Copyright notice must be
 * included with each copy of this software, whether used in part or whole,
 * at all times.
 *******************************************************************************
 */
#ifndef __HC32M423_EFM_H__
#define __HC32M423_EFM_H__

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_common.h"
#include "ddl_config.h"

/**
 * @addtogroup HC32M423_DDL_Driver
 * @{
 */

/**
 * @addtogroup DDL_EFM
 * @{
 */

#if (DDL_EFM_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup EFM_Global_Types EFM Global Types
 * @{
 */

/**
 * @brief EFM windows protect address definition
 */
typedef struct
{
    uint32_t            u32StartAddr;      /*!< The protect start address.     */
    uint32_t            u32EndAddr;        /*!< The protect end address.       */
} stc_efm_win_protect_addr_t;

/**
 * @brief EFM configure structure
 */
typedef struct
{
    uint32_t            u32Latency;     /*!< Specifies the efm latency.
                                            This parameter can be a value of @ref EFM_Latency.              */

    uint32_t            u32CacheRst;    /*!< Specifies the data cache reset on or off.
                                            This parameter can be a value of @ref EFM_CacheRst_State.       */

    uint32_t            u32InsCache;    /*!< Specifies the instruction cache on or off.
                                            This parameter can be a value of @ref EFM_InsCache_State.       */

    uint32_t            u32DataCache;   /*!< Specifies the data cache on or off.
                                            This parameter can be a value of @ref EFM_DataCache_State.        */

    uint32_t            u32BusState;    /*!< Specifies the bus state busy or release while program & erase.
                                            This parameter can be a value of @ref EFM_Bus_State.            */
} stc_efm_cfg_t;

/**
 * @brief EFM unique ID definition
 */
typedef struct
{
    uint32_t            u32UniqueID0;      /*!< unique ID 0.       */
    uint32_t            u32UniqueID1;      /*!< unique ID 1.       */
    uint32_t            u32UniqueID2;      /*!< unique ID 2.       */
    uint32_t            u32UniqueID3;      /*!< unique ID 3.       */
} stc_efm_unique_id_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup EFM_Global_Macros EFM Global Macros
 * @{
 */
#define EFM_TIMEOUT                 (0x1000U)

/**
 * @defgroup EFM_Address EFM address area
 * @{
 */
#define EFM_START_ADDR              (0x00000000UL)
#define EFM_END_ADDR                (0x0001FFFFUL)
/**
 * @}
 */

/**
 * @defgroup EFM_Sector_Address EFM Sector Address
 * @{
 */
#define EFM_SECTOR0_ADRR            (0x00000000UL)
#define EFM_SECTOR1_ADRR            (0x00000200UL)
#define EFM_SECTOR2_ADRR            (0x00000400UL)
#define EFM_SECTOR3_ADRR            (0x00000600UL)
#define EFM_SECTOR4_ADRR            (0x00000800UL)
#define EFM_SECTOR5_ADRR            (0x00000A00UL)
#define EFM_SECTOR6_ADRR            (0x00000C00UL)
#define EFM_SECTOR7_ADRR            (0x00000E00UL)
#define EFM_SECTOR8_ADRR            (0x00001000UL)
#define EFM_SECTOR9_ADRR            (0x00001200UL)
#define EFM_SECTOR10_ADRR           (0x00001400UL)
#define EFM_SECTOR11_ADRR           (0x00001600UL)
#define EFM_SECTOR12_ADRR           (0x00001800UL)
#define EFM_SECTOR13_ADRR           (0x00001A00UL)
#define EFM_SECTOR14_ADRR           (0x00001C00UL)
#define EFM_SECTOR15_ADRR           (0x00001E00UL)
#define EFM_SECTOR16_ADRR           (0x00002000UL)
#define EFM_SECTOR17_ADRR           (0x00002200UL)
#define EFM_SECTOR18_ADRR           (0x00002400UL)
#define EFM_SECTOR19_ADRR           (0x00002600UL)
#define EFM_SECTOR20_ADRR           (0x00002800UL)
#define EFM_SECTOR21_ADRR           (0x00002A00UL)
#define EFM_SECTOR22_ADRR           (0x00002C00UL)
#define EFM_SECTOR23_ADRR           (0x00002E00UL)
#define EFM_SECTOR24_ADRR           (0x00003000UL)
#define EFM_SECTOR25_ADRR           (0x00003200UL)
#define EFM_SECTOR26_ADRR           (0x00003400UL)
#define EFM_SECTOR27_ADRR           (0x00003600UL)
#define EFM_SECTOR28_ADRR           (0x00003800UL)
#define EFM_SECTOR29_ADRR           (0x00003A00UL)
#define EFM_SECTOR30_ADRR           (0x00003C00UL)
#define EFM_SECTOR31_ADRR           (0x00003E00UL)
#define EFM_SECTOR32_ADRR           (0x00004000UL)
#define EFM_SECTOR33_ADRR           (0x00004200UL)
#define EFM_SECTOR34_ADRR           (0x00004400UL)
#define EFM_SECTOR35_ADRR           (0x00004600UL)
#define EFM_SECTOR36_ADRR           (0x00004800UL)
#define EFM_SECTOR37_ADRR           (0x00004A00UL)
#define EFM_SECTOR38_ADRR           (0x00004C00UL)
#define EFM_SECTOR39_ADRR           (0x00004E00UL)
#define EFM_SECTOR40_ADRR           (0x00005000UL)
#define EFM_SECTOR41_ADRR           (0x00005200UL)
#define EFM_SECTOR42_ADRR           (0x00005400UL)
#define EFM_SECTOR43_ADRR           (0x00005600UL)
#define EFM_SECTOR44_ADRR           (0x00005800UL)
#define EFM_SECTOR45_ADRR           (0x00005A00UL)
#define EFM_SECTOR46_ADRR           (0x00005C00UL)
#define EFM_SECTOR47_ADRR           (0x00005E00UL)
#define EFM_SECTOR48_ADRR           (0x00006000UL)
#define EFM_SECTOR49_ADRR           (0x00006200UL)
#define EFM_SECTOR50_ADRR           (0x00006400UL)
#define EFM_SECTOR51_ADRR           (0x00006600UL)
#define EFM_SECTOR52_ADRR           (0x00006800UL)
#define EFM_SECTOR53_ADRR           (0x00006A00UL)
#define EFM_SECTOR54_ADRR           (0x00006C00UL)
#define EFM_SECTOR55_ADRR           (0x00006E00UL)
#define EFM_SECTOR56_ADRR           (0x00007000UL)
#define EFM_SECTOR57_ADRR           (0x00007200UL)
#define EFM_SECTOR58_ADRR           (0x00007400UL)
#define EFM_SECTOR59_ADRR           (0x00007600UL)
#define EFM_SECTOR60_ADRR           (0x00007800UL)
#define EFM_SECTOR61_ADRR           (0x00007A00UL)
#define EFM_SECTOR62_ADRR           (0x00007C00UL)
#define EFM_SECTOR63_ADRR           (0x00007E00UL)
#define EFM_SECTOR64_ADRR           (0x00008000UL)
#define EFM_SECTOR65_ADRR           (0x00008200UL)
#define EFM_SECTOR66_ADRR           (0x00008400UL)
#define EFM_SECTOR67_ADRR           (0x00008600UL)
#define EFM_SECTOR68_ADRR           (0x00008800UL)
#define EFM_SECTOR69_ADRR           (0x00008A00UL)
#define EFM_SECTOR70_ADRR           (0x00008C00UL)
#define EFM_SECTOR71_ADRR           (0x00008E00UL)
#define EFM_SECTOR72_ADRR           (0x00009000UL)
#define EFM_SECTOR73_ADRR           (0x00009200UL)
#define EFM_SECTOR74_ADRR           (0x00009400UL)
#define EFM_SECTOR75_ADRR           (0x00009600UL)
#define EFM_SECTOR76_ADRR           (0x00009800UL)
#define EFM_SECTOR77_ADRR           (0x00009A00UL)
#define EFM_SECTOR78_ADRR           (0x00009C00UL)
#define EFM_SECTOR79_ADRR           (0x00009E00UL)
#define EFM_SECTOR80_ADRR           (0x0000A000UL)
#define EFM_SECTOR81_ADRR           (0x0000A200UL)
#define EFM_SECTOR82_ADRR           (0x0000A400UL)
#define EFM_SECTOR83_ADRR           (0x0000A600UL)
#define EFM_SECTOR84_ADRR           (0x0000A800UL)
#define EFM_SECTOR85_ADRR           (0x0000AA00UL)
#define EFM_SECTOR86_ADRR           (0x0000AC00UL)
#define EFM_SECTOR87_ADRR           (0x0000AE00UL)
#define EFM_SECTOR88_ADRR           (0x0000B000UL)
#define EFM_SECTOR89_ADRR           (0x0000B200UL)
#define EFM_SECTOR90_ADRR           (0x0000B400UL)
#define EFM_SECTOR91_ADRR           (0x0000B600UL)
#define EFM_SECTOR92_ADRR           (0x0000B800UL)
#define EFM_SECTOR93_ADRR           (0x0000BA00UL)
#define EFM_SECTOR94_ADRR           (0x0000BC00UL)
#define EFM_SECTOR95_ADRR           (0x0000BE00UL)
#define EFM_SECTOR96_ADRR           (0x0000C000UL)
#define EFM_SECTOR97_ADRR           (0x0000C200UL)
#define EFM_SECTOR98_ADRR           (0x0000C400UL)
#define EFM_SECTOR99_ADRR           (0x0000C600UL)
#define EFM_SECTOR100_ADRR          (0x0000C800UL)
#define EFM_SECTOR101_ADRR          (0x0000CA00UL)
#define EFM_SECTOR102_ADRR          (0x0000CC00UL)
#define EFM_SECTOR103_ADRR          (0x0000CE00UL)
#define EFM_SECTOR104_ADRR          (0x0000D000UL)
#define EFM_SECTOR105_ADRR          (0x0000D200UL)
#define EFM_SECTOR106_ADRR          (0x0000D400UL)
#define EFM_SECTOR107_ADRR          (0x0000D600UL)
#define EFM_SECTOR108_ADRR          (0x0000D800UL)
#define EFM_SECTOR109_ADRR          (0x0000DA00UL)
#define EFM_SECTOR110_ADRR          (0x0000DC00UL)
#define EFM_SECTOR111_ADRR          (0x0000DE00UL)
#define EFM_SECTOR112_ADRR          (0x0000E000UL)
#define EFM_SECTOR113_ADRR          (0x0000E200UL)
#define EFM_SECTOR114_ADRR          (0x0000E400UL)
#define EFM_SECTOR115_ADRR          (0x0000E600UL)
#define EFM_SECTOR116_ADRR          (0x0000E800UL)
#define EFM_SECTOR117_ADRR          (0x0000EA00UL)
#define EFM_SECTOR118_ADRR          (0x0000EC00UL)
#define EFM_SECTOR119_ADRR          (0x0000EE00UL)
#define EFM_SECTOR120_ADRR          (0x0000F000UL)
#define EFM_SECTOR121_ADRR          (0x0000F200UL)
#define EFM_SECTOR122_ADRR          (0x0000F400UL)
#define EFM_SECTOR123_ADRR          (0x0000F600UL)
#define EFM_SECTOR124_ADRR          (0x0000F800UL)
#define EFM_SECTOR125_ADRR          (0x0000FA00UL)
#define EFM_SECTOR126_ADRR          (0x0000FC00UL)
#define EFM_SECTOR127_ADRR          (0x0000FE00UL)
#define EFM_SECTOR128_ADRR          (0x00010000UL)
#define EFM_SECTOR129_ADRR          (0x00010200UL)
#define EFM_SECTOR130_ADRR          (0x00010400UL)
#define EFM_SECTOR131_ADRR          (0x00010600UL)
#define EFM_SECTOR132_ADRR          (0x00010800UL)
#define EFM_SECTOR133_ADRR          (0x00010A00UL)
#define EFM_SECTOR134_ADRR          (0x00010C00UL)
#define EFM_SECTOR135_ADRR          (0x00010E00UL)
#define EFM_SECTOR136_ADRR          (0x00011000UL)
#define EFM_SECTOR137_ADRR          (0x00011200UL)
#define EFM_SECTOR138_ADRR          (0x00011400UL)
#define EFM_SECTOR139_ADRR          (0x00011600UL)
#define EFM_SECTOR140_ADRR          (0x00011800UL)
#define EFM_SECTOR141_ADRR          (0x00011A00UL)
#define EFM_SECTOR142_ADRR          (0x00011C00UL)
#define EFM_SECTOR143_ADRR          (0x00011E00UL)
#define EFM_SECTOR144_ADRR          (0x00012000UL)
#define EFM_SECTOR145_ADRR          (0x00012200UL)
#define EFM_SECTOR146_ADRR          (0x00012400UL)
#define EFM_SECTOR147_ADRR          (0x00012600UL)
#define EFM_SECTOR148_ADRR          (0x00012800UL)
#define EFM_SECTOR149_ADRR          (0x00012A00UL)
#define EFM_SECTOR150_ADRR          (0x00012C00UL)
#define EFM_SECTOR151_ADRR          (0x00012E00UL)
#define EFM_SECTOR152_ADRR          (0x00013000UL)
#define EFM_SECTOR153_ADRR          (0x00013200UL)
#define EFM_SECTOR154_ADRR          (0x00013400UL)
#define EFM_SECTOR155_ADRR          (0x00013600UL)
#define EFM_SECTOR156_ADRR          (0x00013800UL)
#define EFM_SECTOR157_ADRR          (0x00013A00UL)
#define EFM_SECTOR158_ADRR          (0x00013C00UL)
#define EFM_SECTOR159_ADRR          (0x00013E00UL)
#define EFM_SECTOR160_ADRR          (0x00014000UL)
#define EFM_SECTOR161_ADRR          (0x00014200UL)
#define EFM_SECTOR162_ADRR          (0x00014400UL)
#define EFM_SECTOR163_ADRR          (0x00014600UL)
#define EFM_SECTOR164_ADRR          (0x00014800UL)
#define EFM_SECTOR165_ADRR          (0x00014A00UL)
#define EFM_SECTOR166_ADRR          (0x00014C00UL)
#define EFM_SECTOR167_ADRR          (0x00014E00UL)
#define EFM_SECTOR168_ADRR          (0x00015000UL)
#define EFM_SECTOR169_ADRR          (0x00015200UL)
#define EFM_SECTOR170_ADRR          (0x00015400UL)
#define EFM_SECTOR171_ADRR          (0x00015600UL)
#define EFM_SECTOR172_ADRR          (0x00015800UL)
#define EFM_SECTOR173_ADRR          (0x00015A00UL)
#define EFM_SECTOR174_ADRR          (0x00015C00UL)
#define EFM_SECTOR175_ADRR          (0x00015E00UL)
#define EFM_SECTOR176_ADRR          (0x00016000UL)
#define EFM_SECTOR177_ADRR          (0x00016200UL)
#define EFM_SECTOR178_ADRR          (0x00016400UL)
#define EFM_SECTOR179_ADRR          (0x00016600UL)
#define EFM_SECTOR180_ADRR          (0x00016800UL)
#define EFM_SECTOR181_ADRR          (0x00016A00UL)
#define EFM_SECTOR182_ADRR          (0x00016C00UL)
#define EFM_SECTOR183_ADRR          (0x00016E00UL)
#define EFM_SECTOR184_ADRR          (0x00017000UL)
#define EFM_SECTOR185_ADRR          (0x00017200UL)
#define EFM_SECTOR186_ADRR          (0x00017400UL)
#define EFM_SECTOR187_ADRR          (0x00017600UL)
#define EFM_SECTOR188_ADRR          (0x00017800UL)
#define EFM_SECTOR189_ADRR          (0x00017A00UL)
#define EFM_SECTOR190_ADRR          (0x00017C00UL)
#define EFM_SECTOR191_ADRR          (0x00017E00UL)
#define EFM_SECTOR192_ADRR          (0x00018000UL)
#define EFM_SECTOR193_ADRR          (0x00018200UL)
#define EFM_SECTOR194_ADRR          (0x00018400UL)
#define EFM_SECTOR195_ADRR          (0x00018600UL)
#define EFM_SECTOR196_ADRR          (0x00018800UL)
#define EFM_SECTOR197_ADRR          (0x00018A00UL)
#define EFM_SECTOR198_ADRR          (0x00018C00UL)
#define EFM_SECTOR199_ADRR          (0x00018E00UL)
#define EFM_SECTOR200_ADRR          (0x00019000UL)
#define EFM_SECTOR201_ADRR          (0x00019200UL)
#define EFM_SECTOR202_ADRR          (0x00019400UL)
#define EFM_SECTOR203_ADRR          (0x00019600UL)
#define EFM_SECTOR204_ADRR          (0x00019800UL)
#define EFM_SECTOR205_ADRR          (0x00019A00UL)
#define EFM_SECTOR206_ADRR          (0x00019C00UL)
#define EFM_SECTOR207_ADRR          (0x00019E00UL)
#define EFM_SECTOR208_ADRR          (0x0001A000UL)
#define EFM_SECTOR209_ADRR          (0x0001A200UL)
#define EFM_SECTOR210_ADRR          (0x0001A400UL)
#define EFM_SECTOR211_ADRR          (0x0001A600UL)
#define EFM_SECTOR212_ADRR          (0x0001A800UL)
#define EFM_SECTOR213_ADRR          (0x0001AA00UL)
#define EFM_SECTOR214_ADRR          (0x0001AC00UL)
#define EFM_SECTOR215_ADRR          (0x0001AE00UL)
#define EFM_SECTOR216_ADRR          (0x0001B000UL)
#define EFM_SECTOR217_ADRR          (0x0001B200UL)
#define EFM_SECTOR218_ADRR          (0x0001B400UL)
#define EFM_SECTOR219_ADRR          (0x0001B600UL)
#define EFM_SECTOR220_ADRR          (0x0001B800UL)
#define EFM_SECTOR221_ADRR          (0x0001BA00UL)
#define EFM_SECTOR222_ADRR          (0x0001BC00UL)
#define EFM_SECTOR223_ADRR          (0x0001BE00UL)
#define EFM_SECTOR224_ADRR          (0x0001C000UL)
#define EFM_SECTOR225_ADRR          (0x0001C200UL)
#define EFM_SECTOR226_ADRR          (0x0001C400UL)
#define EFM_SECTOR227_ADRR          (0x0001C600UL)
#define EFM_SECTOR228_ADRR          (0x0001C800UL)
#define EFM_SECTOR229_ADRR          (0x0001CA00UL)
#define EFM_SECTOR230_ADRR          (0x0001CC00UL)
#define EFM_SECTOR231_ADRR          (0x0001CE00UL)
#define EFM_SECTOR232_ADRR          (0x0001D000UL)
#define EFM_SECTOR233_ADRR          (0x0001D200UL)
#define EFM_SECTOR234_ADRR          (0x0001D400UL)
#define EFM_SECTOR235_ADRR          (0x0001D600UL)
#define EFM_SECTOR236_ADRR          (0x0001D800UL)
#define EFM_SECTOR237_ADRR          (0x0001DA00UL)
#define EFM_SECTOR238_ADRR          (0x0001DC00UL)
#define EFM_SECTOR239_ADRR          (0x0001DE00UL)
#define EFM_SECTOR240_ADRR          (0x0001E000UL)
#define EFM_SECTOR241_ADRR          (0x0001E200UL)
#define EFM_SECTOR242_ADRR          (0x0001E400UL)
#define EFM_SECTOR243_ADRR          (0x0001E600UL)
#define EFM_SECTOR244_ADRR          (0x0001E800UL)
#define EFM_SECTOR245_ADRR          (0x0001EA00UL)
#define EFM_SECTOR246_ADRR          (0x0001EC00UL)
#define EFM_SECTOR247_ADRR          (0x0001EE00UL)
#define EFM_SECTOR248_ADRR          (0x0001F000UL)
#define EFM_SECTOR249_ADRR          (0x0001F200UL)
#define EFM_SECTOR250_ADRR          (0x0001F400UL)
#define EFM_SECTOR251_ADRR          (0x0001F600UL)
#define EFM_SECTOR252_ADRR          (0x0001F800UL)
#define EFM_SECTOR253_ADRR          (0x0001FA00UL)
#define EFM_SECTOR254_ADRR          (0x0001FC00UL)
#define EFM_SECTOR255_ADRR          (0x0001FE00UL)
/**
 * @}
 */

/**
 * @defgroup EFM_State EFM State
 * @{
 */
#define EFM_ON                      (0x00000000UL)
#define EFM_OFF                     (EFM_FSTP_FSTP)
/**
 * @}
 */

/**
 * @defgroup EFM_Latency EFM latency value
 * @{
 */
#define EFM_LATENCY_0               (0x00000000UL)
#define EFM_LATENCY_1               (0x00000001UL)
#define EFM_LATENCY_2               (0x00000002UL)
#define EFM_LATENCY_3               (0x00000003UL)
#define EFM_LATENCY_4               (0x00000004UL)
#define EFM_LATENCY_5               (0x00000005UL)
#define EFM_LATENCY_6               (0x00000006UL)
#define EFM_LATENCY_7               (0x00000007UL)
/**
 * @}
 */

/**
 * @defgroup EFM_CacheRst_State EFM data cache reset state
 * @{
 */
#define EFM_CACHERST_ON             (EFM_FRMC_CRST)
#define EFM_CACHERST_OFF            (0x00000000UL)
/**
 * @}
 */

/**
 * @defgroup EFM_InsCache_State EFM instruction cache state
 * @{
 */
#define EFM_INSCACHE_ON             (EFM_FRMC_ICHE)
#define EFM_INSCACHE_OFF            (0x00000000UL)
/**
 * @}
 */

/**
 * @defgroup EFM_DataCache_State EFM data cache state
 * @{
 */
#define EFM_DATACACHE_ON              (EFM_FRMC_DCHE)
#define EFM_DATACACHE_OFF             (0x00000000UL)
/**
 * @}
 */

/**
 * @defgroup EFM_Bus_State EFM Bus state while flash program or erase
 * @{
 */
#define EFM_BUS_BUSY                (0x00000000UL)
#define EFM_BUS_RELEASE             (EFM_FWMC_BUSHLDCTL)
/**
 * @}
 */

/**
 * @defgroup EFM_Mode_definition EFM program or erase mode definition
 * @{
 */
#define EFM_MODE_PROGRAMSINGLE      (0x00000010UL)         /*!< Program single at a specified address          */
#define EFM_MODE_PROGRAMREADBACK    (0x00000020UL)         /*!< Program and read back at a specified address   */
#define EFM_MODE_PROGRAMSEQUENCE    (0x00000030UL)         /*!< Program sequence at sequence address           */
#define EFM_MODE_ERASESECTOR        (0x00000040UL)         /*!< Sector erase                                   */
#define EFM_MODE_ERASECHIP          (0x00000050UL)         /*!< Chip erase                                     */
#define EFM_MODE_READONLY           (0x00000000UL)         /*!< Read only                                      */
#define EFM_MODE_READONLY1          (0x00000060UL)         /*!< Read only                                      */
#define EFM_MODE_READONLY2          (0x00000070UL)         /*!< Read only                                      */
/**
 * @}
 */

/**
 * @defgroup EFM_Flag_definition EFM Flag definition
 * @{
 */
#define EFM_FLAG_PEWERR             (EFM_FSR_PEWERR)          /*!< EFM Programming/erase error flag.              */
#define EFM_FLAG_PEPRTERR           (EFM_FSR_PEPRTERR)        /*!< EFM Programming/erase protect area error flag. */
#define EFM_FLAG_PGMISMTCHERR       (EFM_FSR_PGMISMTCH)       /*!< EFM Programming  miss match error flag         */
#define EFM_FLAG_OPTEND             (EFM_FSR_OPTEND)          /*!< EFM End of Operation flag.                     */
#define EFM_FLAG_COLERR             (EFM_FSR_RDCOLERR)        /*!< EFM Read collide error flag.                   */
#define EFM_FLAG_RDY                (EFM_FSR_RDY)             /*!< EFM ready flag.                                */

#define EFM_FLAG_CLR_PEWERRCLR      (EFM_FSCLR_PEWERRCLR)     /*!< EFM Programming/erase error flag.              */
#define EFM_FLAG_CLR_PEPRTERRCLR    (EFM_FSCLR_PEPRTERRCLR)   /*!< EFM Programming/erase protect area error flag. */
#define EFM_FLAG_CLR_PGMISMTCHCLR   (EFM_FSCLR_PGMISMTCHCLR)  /*!< EFM Programming  miss match error flag         */
#define EFM_FLAG_CLR_OPTENDCLR      (EFM_FSCLR_OPTENDCLR)     /*!< EFM End of Operation flag.                     */
#define EFM_FLAG_CLR_COLERRCLR      (EFM_FSCLR_RDCOLERRCLR)   /*!< EFM Read collide error flag.                   */

/**
 * @}
 */

/**
 * @defgroup EFM_Interrupt_definition EFM Interrupt definition
 * @{
 */
#define EFM_INT_EOP                 (EFM_FITE_OPTENDITE)      /*!< End of EFM Operation Interrupt source      */
#define EFM_INT_PEERR               (EFM_FITE_PEERRITE)       /*!< Program/erase error Interrupt source       */
#define EFM_INT_RDCOLERR            (EFM_FITE_RDCOLERRITE)    /*!< Read collide error Interrupt source        */
/**
 * @}
 */

/**
 * @defgroup EFM_Keys EFM Keys
 * @{
 */
#define EFM_KEY1                    (0x00000123UL)
#define EFM_KEY2                    (0x00003210UL)
/**
 * @}
 */

/**
 * @defgroup EFM_State EFM State
 * @{
 */
#define EFM_LOCK                    (0x00000000UL)
#define EFM_UNLOCK                  (0x00000001UL)
/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/*******************************************************************************
  Global function prototypes (definition in C source)
 ******************************************************************************/
/**
 * @addtogroup EFM_Global_Functions
 * @{
 */

void EFM_Unlock(void);
void EFM_Lock(void);

void EFM_Cmd(en_functional_state_t enNewState);
void EFM_SetLatency(uint32_t u32Latency);
void EFM_SetBusState(uint32_t u32State);
void EFM_CacheCmd(en_functional_state_t enNewState);
void EFM_DataCacheRstCmd(en_functional_state_t enNewState);
void EFM_InstructionCacheCmd(en_functional_state_t enNewState);
void EFM_SetWinProtectAddr(stc_efm_win_protect_addr_t stcAddr);
void EFM_InterruptCmd(uint32_t u32EfmInt, en_functional_state_t enNewState);

en_result_t EFM_StrucInit(stc_efm_cfg_t *pstcEfmCfg);
en_result_t EFM_Config(const stc_efm_cfg_t *pstcEfmCfg);

void EFM_SetOperateMode(uint32_t u32PeMode);
en_result_t EFM_ProgramWord(uint32_t u32Addr, uint32_t u32Data);
en_result_t EFM_ProgramHalfWord(uint32_t u32Addr, uint16_t u16Data);
en_result_t EFM_ProgramByte(uint32_t u32Addr, uint8_t u8Data);
en_result_t EFM_ProgramWordRB(uint32_t u32Addr, uint32_t u32Data);
en_result_t EFM_ProgramHalfWordRB(uint32_t u32Addr, uint16_t u16Data);
en_result_t EFM_ProgramByteRB(uint32_t u32Addr, uint8_t u8Data);
en_result_t EFM_SequenceProgram(uint32_t u32Addr, uint32_t u32Len, void *pBuf);
en_result_t EFM_SectorErase(uint32_t u32Addr);
en_result_t EFM_ChipErase(void);

void EFM_ClearFlag(uint32_t u32Flag);
en_flag_status_t EFM_GetFlagStatus(uint32_t u32Flag);
stc_efm_unique_id_t EFM_ReadUID(void);
/**
 * @}
 */

#endif /* DDL_EFM_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32M423_EFM_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

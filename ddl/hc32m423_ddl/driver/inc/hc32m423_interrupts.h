/**
 *******************************************************************************
 * @file  hc32m423_interrupts.h
 * @brief This file contains all the functions prototypes of the interrupt driver
 *        library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2019-06-21       Zhangxl         First version
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
#ifndef __HC32M423_INTERRUPTS_H__
#define __HC32M423_INTERRUPTS_H__

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
 * @addtogroup DDL_INTERRUPTS
 * @{
 */

#if (DDL_INTERRUPTS_ENABLE == DDL_ON) || (DDL_EXINT_NMI_ENABLE == DDL_ON) ||    \
    (DDL_EKEY_ENABLE == DDL_ON)

/*******************************************************************************
 * Global type definitions ('typedef')
 ******************************************************************************/
/**
 * @defgroup INTC_Global_Types INTC Global Types
 * @{
 */
/**
 * @brief  Interrupt registration structure definition
 */
typedef struct
{
    en_int_src_t    enIntSrc;   /*!< Peripheral interrupt number,
                                     can be any value except INT_PORT_EIRQ0~7 @ref en_int_src_t         */
    IRQn_Type       enIRQn;     /*!< Peripheral IRQ type, can be Int008_IRQn~Int023_IRQn @ref IRQn_Type */
    func_ptr_t      pfnCallback;/*!< Callback function for corresponding peripheral IRQ                 */
}stc_irq_regi_config_t;

/**
 * @brief  NMI initialize configuration structure definition
 */
typedef struct
{
    uint8_t     u8NmiFE;        /*!< NMI pin filter function, @ref NMI_FilterClock_Sel for details          */
    uint8_t     u8NmiFClk;      /*!< NMI pin filter clock  division, @ref NMI_FilterClock_Div for details   */
    uint8_t     u8NmiTigger;    /*!< NMI pin trigger edge, @ref NMI_Trigger_Sel for details                 */
    uint8_t     u8NmiSrc;       /*!< NMI trigger source, @ref NMI_TriggerSrc_Sel for details                */
    func_ptr_t  pfnNmiCallback; /*!< NMI Callback function pointers                                         */
}stc_nmi_config_t;

/**
 * @brief  EXINT initialize configuration structure definition
 */
typedef struct
{
    uint16_t    u16ExIntCh;     /*!< ExInt CH.0~9 @ref EXINT_Channel_Sel                                */
    uint8_t     u8ExIntFE;      /*!< ExInt filter clock, @ref EXINT_FilterClock_Sel for details         */
    uint8_t     u8ExIntFClk;    /*!< ExInt filter clock division, @ref EXINT_FilterClock_Div for details*/
    uint8_t     u8ExIntLvl;     /*!< ExInt trigger edge, @ref EXINT_Trigger_Sel for details             */
}stc_exint_config_t;

/**
 * @}
 */

/*******************************************************************************
 * Global pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup INTC_Global_Macros INTC Global Macros
 * @{
 */
/**
 * @defgroup INTC_DefaultPriority_Sel Interrupt default priority level
 * Possible values are 0 (high priority) to 3 (low priority)
 * @{
 */
#define DDL_IRQ_PRIORITY_DEFAULT    (3U)
/**
 * @}
 */

/**
 * @defgroup INTC_Priority_Sel Interrupt priority level 00 ~ 03
 * @{
 */
#define DDL_IRQ_PRIORITY_00         (0U)
#define DDL_IRQ_PRIORITY_01         (1U)
#define DDL_IRQ_PRIORITY_02         (2U)
#define DDL_IRQ_PRIORITY_03         (3U)
/**
 * @}
 */

/**
 * @defgroup INTC_Bit_mask definition Bit Mask
 * @{
 */
#define     BIT_MASK_00             (uint32_t)(1UL << 0U)
#define     BIT_MASK_01             (uint32_t)(1UL << 1U)
#define     BIT_MASK_02             (uint32_t)(1UL << 2U)
#define     BIT_MASK_03             (uint32_t)(1UL << 3U)
#define     BIT_MASK_04             (uint32_t)(1UL << 4U)
#define     BIT_MASK_05             (uint32_t)(1UL << 5U)
#define     BIT_MASK_06             (uint32_t)(1UL << 6U)
#define     BIT_MASK_07             (uint32_t)(1UL << 7U)
#define     BIT_MASK_08             (uint32_t)(1UL << 8U)
#define     BIT_MASK_09             (uint32_t)(1UL << 9U)
#define     BIT_MASK_10             (uint32_t)(1UL << 10U)
#define     BIT_MASK_11             (uint32_t)(1UL << 11U)
#define     BIT_MASK_12             (uint32_t)(1UL << 12U)
#define     BIT_MASK_13             (uint32_t)(1UL << 13U)
#define     BIT_MASK_14             (uint32_t)(1UL << 14U)
#define     BIT_MASK_15             (uint32_t)(1UL << 15U)
#define     BIT_MASK_16             (uint32_t)(1UL << 16U)
#define     BIT_MASK_17             (uint32_t)(1UL << 17U)
#define     BIT_MASK_18             (uint32_t)(1UL << 18U)
#define     BIT_MASK_19             (uint32_t)(1UL << 19U)
#define     BIT_MASK_20             (uint32_t)(1UL << 20U)
#define     BIT_MASK_21             (uint32_t)(1UL << 21U)
#define     BIT_MASK_22             (uint32_t)(1UL << 22U)
#define     BIT_MASK_23             (uint32_t)(1UL << 23U)
#define     BIT_MASK_24             (uint32_t)(1UL << 24U)
#define     BIT_MASK_25             (uint32_t)(1UL << 25U)
#define     BIT_MASK_26             (uint32_t)(1UL << 26U)
#define     BIT_MASK_27             (uint32_t)(1UL << 27U)
#define     BIT_MASK_28             (uint32_t)(1UL << 28U)
#define     BIT_MASK_29             (uint32_t)(1UL << 29U)
#define     BIT_MASK_30             (uint32_t)(1UL << 30U)
#define     BIT_MASK_31             (uint32_t)(1UL << 31U)
/**
 * @}
 */

/**
 * @defgroup INTC_Register_Protect INTC Registers Protect Code
 * @{
 */
#define INTC_REG_UNPROTECT          ((uint8_t)0xA5U)
#define INTC_REG_PROTECT            ((uint8_t)0x00U)
/**
 * @}
 */

/**
 * @defgroup NMI_FilterClock_Sel NMI pin filter selection
 * @{
 */
#define NMI_FILTER_OFF              (uint8_t)(0U << INTC_NMICR_NMIFEN_POS)
#define NMI_FILTER_ON               (uint8_t)(1U << INTC_NMICR_NMIFEN_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_FilterClock_Div NMI pin filter sampling clock division selection
 * @{
 */
#define NMI_FCLK_HCLK_DIV1          (uint8_t)(0U << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV8          (uint8_t)(1U << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV32         (uint8_t)(2U << INTC_NMICR_NMIFCLK_POS)
#define NMI_FCLK_HCLK_DIV64         (uint8_t)(3U << INTC_NMICR_NMIFCLK_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_Trigger_Sel NMI pin trigger method selection
 * @{
 */
#define NMI_TRIGGER_FALLING         (uint8_t)(0U << INTC_NMICR_NMITRG_POS)
#define NMI_TRIGGER_RISING          (uint8_t)(1U << INTC_NMICR_NMITRG_POS)
/**
 * @}
 */

/**
 * @defgroup NMI_TriggerSrc_Sel NMI trigger source selection
 * @{
 */
#define NMI_SRC_NMI_PIN             (uint8_t)(1U << INTC_NMIER_NMIEN_POS)
#define NMI_SRC_XTAL_STP            (uint8_t)(1U << INTC_NMIER_XTALSTPEN_POS)
#define NMI_SRC_SWDT                (uint8_t)(1U << INTC_NMIER_SWDTEN_POS)
#define NMI_SRC_LVD                 (uint8_t)(1U << INTC_NMIER_PVDEN_POS)
#define NMI_SRC_MASK                (NMI_SRC_NMI_PIN | NMI_SRC_XTAL_STP |       \
                                    NMI_SRC_SWDT | NMI_SRC_LVD)
/**
 * @}
 */

/**
 * @defgroup MNI_Register_Msk NMI register mask
 * @{
 */
#define INTC_NMICR_MASK     (uint8_t)(INTC_NMICR_NMITRG | INTC_NMICR_NMIFCLK   |\
                            INTC_NMICR_NMIFEN)
#define INTC_NMIER_MASK     (uint8_t)(INTC_NMIER_NMIEN  | INTC_NMIER_XTALSTPEN |\
                            INTC_NMIER_SWDTEN  | INTC_NMIER_PVDEN)
#define INTC_NMIFR_MASK     (uint8_t)(INTC_NMIFR_NMIF   | INTC_NMIFR_XTALSTPF  |\
                            INTC_NMIFR_SWDTF   | INTC_NMIFR_PVDF)
#define INTC_NMICLR_MASK    (uint8_t)(INTC_NMICLR_NMICL | INTC_NMICLR_XTALSTPCL|\
                            INTC_NMICLR_SWDTCL | INTC_NMICLR_PVDCL)
/**
 * @}
 */

/**
 * @defgroup EXINT_Channel_Sel External interrupt channel selection
 * @{
 */
#define EXINT_CH00                  (uint16_t)(1UL << 0U)
#define EXINT_CH01                  (uint16_t)(1UL << 1U)
#define EXINT_CH02                  (uint16_t)(1UL << 2U)
#define EXINT_CH03                  (uint16_t)(1UL << 3U)
#define EXINT_CH04                  (uint16_t)(1UL << 4U)
#define EXINT_CH05                  (uint16_t)(1UL << 5U)
#define EXINT_CH06                  (uint16_t)(1UL << 6U)
#define EXINT_CH07                  (uint16_t)(1UL << 7U)
#define EXINT_CH_MASK   (EXINT_CH00 | EXINT_CH01 | EXINT_CH02 | EXINT_CH03 |    \
                         EXINT_CH04 | EXINT_CH05 | EXINT_CH06 | EXINT_CH07)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterClock_Sel External interrupt filter function selection
 * @{
 */
#define EXINT_FILTER_OFF            (uint8_t)(0U << INTC_EIRQCR_EIRQFEN_POS)
#define EXINT_FILTER_ON             (uint8_t)(1U << INTC_EIRQCR_EIRQFEN_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_FilterClock_Div External interrupt filtersampling  clock division selection
 * @{
 */
#define EXINT_FCLK_HCLK_DIV1        (uint8_t)(0U << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV8        (uint8_t)(1U << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV32       (uint8_t)(2U << INTC_EIRQCR_EIRQFCLK_POS)
#define EXINT_FCLK_HCLK_DIV64       (uint8_t)(3U << INTC_EIRQCR_EIRQFCLK_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_Trigger_Sel External interrupt trigger method selection
 * @{
 */
#define EXINT_TRIGGER_LOW           (uint8_t)(0U << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_RISING        (uint8_t)(1U << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_FALLING       (uint8_t)(2U << INTC_EIRQCR_EIRQTRG_POS)
#define EXINT_TRIGGER_BOTH          (uint8_t)(3U << INTC_EIRQCR_EIRQTRG_POS)
/**
 * @}
 */

/**
 * @defgroup EXINT_Register_Msk EXINT register mask
 * @{
 */
#define INTC_EIRQF_MASK             (INTC_EIRQFR_EIRQF)
#define INTC_EIRQCLR_MASK           (INTC_EIRQCLR_EIRQCL)
/**
 * @}
 */

/**
 * @defgroup INTC_EKEY_Channel INTC EKEY channel selection
 * @{
 */
#define INTC_EKEY0                  (uint8_t)(1U << INTC_EKEYCR_EKEY0EN_POS)
#define INTC_EKEY1                  (uint8_t)(1U << INTC_EKEYCR_EKEY1EN_POS)
#define INTC_EKEY2                  (uint8_t)(1U << INTC_EKEYCR_EKEY2EN_POS)
#define INTC_EKEY3                  (uint8_t)(1U << INTC_EKEYCR_EKEY3EN_POS)
#define INTC_EKEY4                  (uint8_t)(1U << INTC_EKEYCR_EKEY4EN_POS)
#define INTC_EKEY5                  (uint8_t)(1U << INTC_EKEYCR_EKEY5EN_POS)
#define INTC_EKEY_MASK              (INTC_EKEY0 | INTC_EKEY1 | INTC_EKEY2 |     \
                                     INTC_EKEY3 | INTC_EKEY4 | INTC_EKEY5)
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
 * @addtogroup INTC_Global_Functions
 * @{
 */

/**
 * @brief  AOS software trigger.
 * @param  None
 * @retval None
 */
__STATIC_INLINE void AOS_SW_Trigger(void)
{
    WRITE_REG32(bM0P_AOS->INTC_STRGCR_b.STRG, Set);
}

/**
 * @brief  INTC lock, register write disable
 * @param  None
 * @retval None
 */
__STATIC_INLINE void INTC_Lock(void)
{
    WRITE_REG32(M0P_INTC->FPRCR, INTC_REG_PROTECT);
}

/**
 * @brief  INTC unlock, register write enable
 * @param  None
 * @retval None
 */
__STATIC_INLINE void INTC_Unlock(void)
{
    WRITE_REG32(M0P_INTC->FPRCR, INTC_REG_UNPROTECT);
}

en_result_t INTC_IrqRegistration(const stc_irq_regi_config_t *pstcIrqRegiConfig);
void INTC_IrqResign(IRQn_Type enIRQn);
en_result_t INTC_ShareIrqCmd(en_int_src_t enIntSrc, en_functional_state_t enNewState);
void INTC_WakeupSrcCmd(uint32_t u32WakeupSrc, en_functional_state_t enNewState);
void INTC_EventCmd(uint8_t u8Event, en_functional_state_t enNewState);

en_result_t NMI_Init(const stc_nmi_config_t *pstcNmiConfig);
en_result_t NMI_StructInit(stc_nmi_config_t *pstcNmiConfig);
en_flag_status_t NMI_GetNmiSrc(uint8_t u8NmiSrc);
void NMI_ClrNmiSrc(uint8_t u8NmiSrc);

en_result_t EXINT_Init(const stc_exint_config_t *pstcExIntConfig);
en_result_t EXINT_StructInit(stc_exint_config_t *pstcExintConfig);
en_flag_status_t EXINT_GetExIntSrc(uint16_t u16ExIntCh);
void EXINT_ClrExIntSrc(uint16_t u16ExIntCh);

void INTC_EKeyCmd(uint8_t u8EKey, en_functional_state_t enNewState);

__WEAKDEF void NMI_IrqHandler(void);
__WEAKDEF void HardFault_IrqHandler(void);
__WEAKDEF void MemManage_IrqHandler(void);
__WEAKDEF void BusFault_IrqHandler(void);
__WEAKDEF void UsageFault_IrqHandler(void);
__WEAKDEF void SVC_IrqHandler(void);
__WEAKDEF void DebugMon_IrqHandler(void);
__WEAKDEF void PendSV_IrqHandler(void);
__WEAKDEF void SysTick_IrqHandler(void);

__WEAKDEF void EXINT00_IrqHandler(void);
__WEAKDEF void EXINT01_IrqHandler(void);
__WEAKDEF void EXINT02_IrqHandler(void);
__WEAKDEF void EXINT03_IrqHandler(void);
__WEAKDEF void EXINT04_IrqHandler(void);
__WEAKDEF void EXINT05_IrqHandler(void);
__WEAKDEF void EXINT06_IrqHandler(void);
__WEAKDEF void EXINT07_IrqHandler(void);
__WEAKDEF void DMA_Tc0_IrqHandler(void);
__WEAKDEF void DMA_Tc1_IrqHandler(void);
__WEAKDEF void DMA_Tc2_IrqHandler(void);
__WEAKDEF void DMA_Tc3_IrqHandler(void);
__WEAKDEF void DMA_Btc0_IrqHandler(void);
__WEAKDEF void DMA_Btc1_IrqHandler(void);
__WEAKDEF void DMA_Btc2_IrqHandler(void);
__WEAKDEF void DMA_Btc3_IrqHandler(void);
__WEAKDEF void DMA_Err_IrqHandler(void);
__WEAKDEF void EFM_PgmEraseErr_IrqHandler(void);
__WEAKDEF void EFM_ColErr_IrqHandler(void);
__WEAKDEF void EFM_OpEnd_IrqHandler(void);
__WEAKDEF void DCU_IrqHandler(void);
__WEAKDEF void TIMER0_1_CmpA_IrqHandler(void);
__WEAKDEF void TIMER0_1_CmpB_IrqHandler(void);
__WEAKDEF void TIMER0_2_CmpA_IrqHandler(void);
__WEAKDEF void TIMER0_2_CmpB_IrqHandler(void);
__WEAKDEF void CLK_XtalStop_IrqHandler(void);
__WEAKDEF void SWDT_IrqHandler(void);
__WEAKDEF void TIMERA_1_Ovf_IrqHandler(void);
__WEAKDEF void TIMERA_1_Udf_IrqHandler(void);
__WEAKDEF void TIMERA_1_Cmp_IrqHandler(void);
__WEAKDEF void TIMERA_2_Ovf_IrqHandler(void);
__WEAKDEF void TIMERA_2_Udf_IrqHandler(void);
__WEAKDEF void TIMERA_2_Cmp_IrqHandler(void);
__WEAKDEF void TIMERA_3_Ovf_IrqHandler(void);
__WEAKDEF void TIMERA_3_Udf_IrqHandler(void);
__WEAKDEF void TIMERA_3_Cmp_IrqHandler(void);
__WEAKDEF void TIMERA_4_Ovf_IrqHandler(void);
__WEAKDEF void TIMERA_4_Udf_IrqHandler(void);
__WEAKDEF void TIMERA_4_Cmp_IrqHandler(void);
__WEAKDEF void TIMERB_Ovf_IrqHandler(void);
__WEAKDEF void TIMERB_Udf_IrqHandler(void);
__WEAKDEF void TIMERB_Cmp_IrqHandler(void);
__WEAKDEF void USART_1_RxErr_IrqHandler(void);
__WEAKDEF void USART_1_RxEnd_IrqHandler(void);
__WEAKDEF void USART_1_TxEmpty_IrqHandler(void);
__WEAKDEF void USART_1_TxEnd_IrqHandler(void);
__WEAKDEF void USART_2_RxErr_IrqHandler(void);
__WEAKDEF void USART_2_RxEnd_IrqHandler(void);
__WEAKDEF void USART_2_TxEmpty_IrqHandler(void);
__WEAKDEF void USART_2_TxEnd_IrqHandler(void);
__WEAKDEF void USART_3_RxErr_IrqHandler(void);
__WEAKDEF void USART_3_RxEnd_IrqHandler(void);
__WEAKDEF void USART_3_TxEmpty_IrqHandler(void);
__WEAKDEF void USART_3_TxEnd_IrqHandler(void);
__WEAKDEF void USART_4_RxErr_IrqHandler(void);
__WEAKDEF void USART_4_RxEnd_IrqHandler(void);
__WEAKDEF void USART_4_TxEmpty_IrqHandler(void);
__WEAKDEF void USART_4_TxEnd_IrqHandler(void);
__WEAKDEF void SPI_RxEnd_IrqHandler(void);
__WEAKDEF void SPI_TxEmpty_IrqHandler(void);
__WEAKDEF void SPI_Idle_IrqHandler(void);
__WEAKDEF void SPI_Err_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpUH_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpUL_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpVH_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpVL_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpWH_IrqHandler(void);
__WEAKDEF void TIMER4_GCmpWL_IrqHandler(void);
__WEAKDEF void TIMER4_Ovf_IrqHandler(void);
__WEAKDEF void TIMER4_Udf_IrqHandler(void);
__WEAKDEF void TIMER4_ReloadU_IrqHandler(void);
__WEAKDEF void TIMER4_ReloadV_IrqHandler(void);
__WEAKDEF void TIMER4_ReloadW_IrqHandler(void);
__WEAKDEF void EMB_GR0_IrqHandler(void);
__WEAKDEF void CMP_1_IrqHandler(void);
__WEAKDEF void CMP_2_IrqHandler(void);
__WEAKDEF void CMP_3_IrqHandler(void);
__WEAKDEF void I2C_RxEnd_IrqHandler(void);
__WEAKDEF void I2C_TxEnd_IrqHandler(void);
__WEAKDEF void I2C_TxEmpty_IrqHandler(void);
__WEAKDEF void I2C_Err_IrqHandler(void);
__WEAKDEF void USART_1_WKUP_IrqHandler(void);
__WEAKDEF void PWR_Lvd1_IrqHandler(void);
__WEAKDEF void PWR_Lvd2_IrqHandler(void);
__WEAKDEF void FCM_Err_IrqHandler(void);
__WEAKDEF void FCM_End_IrqHandler(void);
__WEAKDEF void FCM_Ovf_IrqHandler(void);
__WEAKDEF void WDT_IrqHandler(void);
__WEAKDEF void CTC_Err_IrqHandler(void);
__WEAKDEF void ADC_SeqA_IrqHandler(void);
__WEAKDEF void ADC_SeqB_IrqHandler(void);
__WEAKDEF void ADC_ChCmp_IrqHandler(void);
__WEAKDEF void ADC_SeqCmp_IrqHandler(void);


/**
 * @}
 */

#endif /* DDL_INTERRUPTS_ENABLE */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HC32M423_INTERRUPTS_H__ */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

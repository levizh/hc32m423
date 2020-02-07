/**
 *******************************************************************************
 * @file  timerb/timerb_input_capture/source/main.c
 * @brief This example demonstrates TIMERB input capture function.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2020-02-07       Hongjh          First version
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

/*******************************************************************************
 * Include files
 ******************************************************************************/
#include "hc32_ddl.h"

/**
 * @addtogroup HC32M423_DDL_Examples
 * @{
 */

/**
 * @addtogroup TIMERB_Input_Capture
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
/**
 * @brief  Buffer structure definition
 */
typedef struct
{
    uint16_t u16Capacity;
    uint16_t u16Index;
    uint16_t au16Buf[50];
} stc_buffer_t;

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/* EXINT channel/IRQn definition */
#define EXINT_CH                            (EXINT_CH01)      /* P21: INTP1 */
#define EXINT_INT                           (INT_PORT_EIRQ1)
#define EXINT_IRQn                          (Int000_IRQn)

/* EXINT Port/Pin definition */
#define EXINT_PORT                          (GPIO_PORT_2)
#define EXINT_PIN                           (GPIO_PIN_1)

/* Green LED Port/Pin definition */
#define LED_G_PORT                          (GPIO_PORT_7)
#define LED_G_PIN                           (GPIO_PIN_0)
#define LED_G_ON()                          (GPIO_ResetPins(LED_G_PORT, LED_G_PIN))

/* TIMERB unit & interrupt number & counter period definition */
#define TIMERB_UNIT                         (M4_TMRB)
#define TIMERB_UNIT_PERIOD_VALUE            (SystemCoreClock/512UL)
#define TIMERB_UNIT_CMP_INT                 (INT_TMRB_CMP)
#define TIMERB_UNIT_CMP_IRQn                (Int001_IRQn)

/* TIMERB input capture channel definition */
#define TIMERB_IC_ODD_CH                    (TIMERB_CH1)
#define TIMERB_IC_ODD_CH_FLAG               (TIMERB_FLAG_CMP1)
#define TIMERB_IC_ODD_CH_INT_CMP            (TIMERB_IT_CMP1)

#define TIMERB_IC_EVEN_CH                   (TIMERB_CH2)
#define TIMERB_IC_EVEN_CH_FLAG              (TIMERB_FLAG_CMP2)
#define TIMERB_IC_EVEN_CH_INT_CMP           (TIMERB_IT_CMP2)

/* TIMERB output compare unit & counter period/compare value definition */
#define TIMERB_OC_CH                        (TIMERB_CH3)
#define TIMERB_OC_CH_COMPARE_VALUE          (TIMERB_UNIT_PERIOD_VALUE/2UL)

/* TIMERB TIMB_t_PWM1 Port/Pin definition */
#define TIMERB_IC_ODD_CH_PWM_PORT           (GPIO_PORT_1)     /* P15: TIMB_1_PWM1 */
#define TIMERB_IC_ODD_CH_PWM_PIN            (GPIO_PIN_5)
#define TIMERB_IC_ODD_CH_PWM_GPIO_FUNC      (GPIO_FUNC_3_TIMB)

#define TIMERB_IC_EVEN_CH_PWM_PORT          (GPIO_PORT_1)     /* P16: TIMB_1_PWM2 */
#define TIMERB_IC_EVEN_CH_PWM_PIN           (GPIO_PIN_6)
#define TIMERB_IC_EVEN_CH_PWM_GPIO_FUNC     (GPIO_FUNC_3_TIMB)

#define TIMERB_OC_CH_PWM_PORT               (GPIO_PORT_0)     /* P62: TIMB_1_PWM3 */
#define TIMERB_OC_CH_PWM_PIN                (GPIO_PIN_2)
#define TIMERB_OC_CH_PWM_GPIO_FUNC          (GPIO_FUNC_3_TIMB)

/* Function clock gate definition */
#define FUNCTION_CLK_GATE                   (CLK_FCG_TIMB | CLK_FCG_AOS)

/* Buffer size definition */
#define TIMERB_IC_CMPBUF_SIZE               (50U)

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static void SystemClockConfig(void);
static void LedConfig(void);
static void ExintIrqCallback(void);
static void TimerbOcConfig(void);
static void TimerbIcCmpIrqCallback(void);
static void BufferWrite(stc_buffer_t *pstcBuffer, uint16_t u16Data);

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static stc_timerb_init_t m_stcTimerbInit = {
    .u16PeriodVal = 0U,
    .u16CntDir = TIMERB_CNT_UP,
    .u16ClkDiv = TIMERB_CLKDIV_DIV512,
    .u16CntMode = TIMERB_SAWTOOTH_WAVE,
    .u16OverflowAction = TIMERB_OVERFLOW_COUNT,
};

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/

/**
 * @brief  Configure system clock.
 * @param  None
 * @retval None
 */
static void SystemClockConfig(void)
{
    /* Configure the system clock to HRC32MHz. */
    CLK_HRCInit(CLK_HRC_ON, CLK_HRCFREQ_32);
}

/**
 * @brief  Configure RGB LED.
 * @param  None
 * @retval None
 */
static void LedConfig(void)
{
    stc_gpio_init_t stcGpioInit = {0};

    stcGpioInit.u16PinDir = PIN_DIR_OUT;
    stcGpioInit.u16PinState = PIN_STATE_SET;
    GPIO_Init(LED_G_PORT, LED_G_PIN, &stcGpioInit);
}

/**
 * @brief  External interrupt ISR
 * @param  None
 * @retval None
 */
static void ExintIrqCallback(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH))
   {
        EXINT_ClrExIntSrc(EXINT_CH);
        LED_G_ON();
   }
}

/**
 * @brief  Configure TIMERB output compare.
 * @param  None
 * @retval None
 */
static void TimerbOcConfig(void)
{
    stc_timerb_oc_init_t stcTimerbOcInit = {
        .u16CompareVal = 0U,
        .u16PortOutputState = TIMERB_OC_PORT_OUTPUT_ENABLE,
        .u16StartCntOutput = TIMERB_OC_STARTCNT_OUTPUT_HIGH,
        .u16StopCntOutput = TIMERB_OC_STOPCNT_OUTPUT_HIGH,
        .u16CompareMatchOutput = TIMERB_OC_CMPMATCH_OUTPUT_INVERTED,
        .u16PeriodMatchOutput = TIMERB_OC_PERIODMATCH_OUTPUT_INVERTED,
    };

    /* Configure TIM_<t>_PWM. */
    GPIO_SetFunc(TIMERB_OC_CH_PWM_PORT, TIMERB_OC_CH_PWM_PIN, TIMERB_OC_CH_PWM_GPIO_FUNC);

    /* Initialize TIMERB output compare function . */
    stcTimerbOcInit.u16CompareVal = (uint16_t)TIMERB_OC_CH_COMPARE_VALUE;
    TIMERB_OC_Init(TIMERB_UNIT, TIMERB_OC_CH, &stcTimerbOcInit);
}

/**
 * @brief  TIMERB unit compare match IRQ callback
 * @param  None
 * @retval None
 */
static void TimerbIcCmpIrqCallback(void)
{
    static stc_buffer_t m_stcEvenUnitCmpBuf= {
        .u16Index = 0U,
        .u16Capacity = TIMERB_IC_CMPBUF_SIZE,
    };

    static stc_buffer_t m_stcOddUnitCmpBuf = {
        .u16Index = 0U,
        .u16Capacity = TIMERB_IC_CMPBUF_SIZE,
    };

    if (Set == TIMERB_GetFlag(TIMERB_UNIT, TIMERB_IC_ODD_CH_FLAG))
    {
        BufferWrite(&m_stcOddUnitCmpBuf, TIMERB_GetCompare(TIMERB_UNIT, TIMERB_IC_ODD_CH));
        TIMERB_ClearFlag(TIMERB_UNIT, TIMERB_IC_ODD_CH_FLAG);
    }

    if (Set == TIMERB_GetFlag(TIMERB_UNIT, TIMERB_IC_EVEN_CH_FLAG))
    {
        BufferWrite(&m_stcEvenUnitCmpBuf, TIMERB_GetCompare(TIMERB_UNIT, TIMERB_IC_EVEN_CH));
        TIMERB_ClearFlag(TIMERB_UNIT, TIMERB_IC_EVEN_CH_FLAG);
    }
}

/**
 * @brief  Push data into buffer.
 * @param  [in] pstcBuffer              Pointer to a @ref stc_buffer_t structure
 * @param  [in] u16Data                 Data to write into buffer
 * @retval None
 */
static void BufferWrite(stc_buffer_t *pstcBuffer, uint16_t u16Data)
{
    if (pstcBuffer->u16Index >= pstcBuffer->u16Capacity)
    {
        pstcBuffer->u16Index = 0U;
    }

    pstcBuffer->au16Buf[pstcBuffer->u16Index++] = u16Data;
}

/**
 * @brief  Main function of TIMERB input capture project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    stc_gpio_init_t stcGpioInit;
    stc_exint_config_t stcExIntInit;
    stc_irq_regi_config_t stcIrqRegiConf;
    stc_timerb_ic_init_t stcTimerbIcInit = {
        .u16CaptureCondition = TIMERB_IC_FALLING,
        .u16NoiseFilterClkDiv = TIMERB_IC_NOFICLKDIV_NONE,
    };

    /* Configure system clock. */
    SystemClockConfig();

    /* Configure RGB LED. */
    LedConfig();

    /* External interrupt port initialize */
    GPIO_StructInit(&stcGpioInit);
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(EXINT_PORT, EXINT_PIN, &stcGpioInit);

    /* EXINT Channel 0 (SW2) configure */
    EXINT_StructInit(&stcExIntInit);
    stcExIntInit.u32ExIntCh     = EXINT_CH;
    stcExIntInit.u32ExIntFAE    = EXINT_FILTER_A_ON;
    stcExIntInit.u32ExIntFAClk  = EXINT_FACLK_HCLK_DIV8;
    stcExIntInit.u32ExIntFBE    = EXINT_FILTER_B_ON;
    stcExIntInit.u32ExIntFBTime = NMI_EXINT_FBTIM_2US;
    stcExIntInit.u32ExIntLvl    = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = EXINT_IRQn;
    stcIrqRegiConf.enIntSrc = EXINT_INT;
    stcIrqRegiConf.pfnCallback = &ExintIrqCallback;
    INTC_IrqSignIn(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Configure TIM_<t>_PWM. */
    GPIO_SetFunc(TIMERB_IC_ODD_CH_PWM_PORT, TIMERB_IC_ODD_CH_PWM_PIN, TIMERB_IC_ODD_CH_PWM_GPIO_FUNC);
    GPIO_SetFunc(TIMERB_IC_EVEN_CH_PWM_PORT, TIMERB_IC_EVEN_CH_PWM_PIN, TIMERB_IC_EVEN_CH_PWM_GPIO_FUNC);

    /* Enable peripheral clock */
    CLK_FcgPeriphClockCmd(FUNCTION_CLK_GATE, Enable);

    /* Configure TIMERB output compare function. */
    TimerbOcConfig();

    /* Initialize TIMERB unit. */
    m_stcTimerbInit.u16PeriodVal = TIMERB_UNIT_PERIOD_VALUE;
    TIMERB_Init(TIMERB_UNIT, &m_stcTimerbInit);

    /* Initialize TIMERB odd unit input capture function. */
    TIMERB_IC_Init(TIMERB_UNIT, TIMERB_IC_ODD_CH, &stcTimerbIcInit);
    TIMERB_IntCmd(TIMERB_UNIT, TIMERB_IC_ODD_CH_INT_CMP, Enable);

    /* Initialize TIMERB even unit input capture function. */
    TIMERB_IC_Init(TIMERB_UNIT, TIMERB_IC_EVEN_CH, &stcTimerbIcInit);
    TIMERB_IntCmd(TIMERB_UNIT, TIMERB_IC_EVEN_CH_INT_CMP, Enable);

    /* Register IRQ handler && configure NVIC. */
    stcIrqRegiConf.enIRQn = TIMERB_UNIT_CMP_IRQn;
    stcIrqRegiConf.enIntSrc = TIMERB_UNIT_CMP_INT;
    stcIrqRegiConf.pfnCallback = &TimerbIcCmpIrqCallback;
    INTC_IrqSignIn(&stcIrqRegiConf);
    NVIC_ClearPendingIRQ(stcIrqRegiConf.enIRQn);
    NVIC_SetPriority(stcIrqRegiConf.enIRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(stcIrqRegiConf.enIRQn);

    /* Set trigger source. */
    TIMERB_SetTriggerSrc(EVT_PORT_EIRQ1);

    /* Start TIMERB start count condition. */
    TIMERB_SetHwStartCondition(TIMERB_UNIT, TIMERB_HWSTART_TIMB_EVT);

    while (1)
    {
    }
}

/**
 * @}
 */

/**
 * @}
 */

/*******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

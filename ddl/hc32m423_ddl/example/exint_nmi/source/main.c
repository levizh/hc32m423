/**
 *******************************************************************************
 * @file  exint_nmi/source/main.c
 * @brief Main program EXINT_NMI for the Device Driver Library.
 @verbatim
   Change Logs:
   Date             Author          Notes
   2020-02-05       Zhangxl         First version
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
 * @addtogroup EXINT_NMI
 * @{
 */

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define EXINT2_PORT     (GPIO_PORT_0)
#define EXINT2_PIN      (GPIO_PIN_0)
#define EXINT4_PORT     (GPIO_PORT_0)
#define EXINT4_PIN      (GPIO_PIN_1)
#define EXINT5_PORT     (GPIO_PORT_0)
#define EXINT5_PIN      (GPIO_PIN_2)

#define LED_R_PORT      (GPIO_PORT_0)
#define LED_G_PORT      (GPIO_PORT_0)
#define LED_B_PORT      (GPIO_PORT_0)

#define LED_R_PIN       (GPIO_PIN_0)
#define LED_G_PIN       (GPIO_PIN_1)
#define LED_B_PIN       (GPIO_PIN_2)

#define LED_R_ON()      (GPIO_ResetPins(LED_R_PORT, LED_R_PIN))
#define LED_G_ON()      (GPIO_ResetPins(LED_G_PORT, LED_G_PIN))
#define LED_B_ON()      (GPIO_ResetPins(LED_B_PORT, LED_B_PIN))

#define LED_R_OFF()     (GPIO_SetPins(LED_R_PORT, LED_R_PIN))
#define LED_G_OFF()     (GPIO_SetPins(LED_G_PORT, LED_G_PIN))
#define LED_B_OFF()     (GPIO_SetPins(LED_B_PORT, LED_B_PIN))

#define LED_R_TOGGLE()  (GPIO_TogglePins(LED_R_PORT, LED_R_PIN))
#define LED_G_TOGGLE()  (GPIO_TogglePins(LED_G_PORT, LED_G_PIN))
#define LED_B_TOGGLE()  (GPIO_TogglePins(LED_B_PORT, LED_B_PIN))
#define LED_RGB_TOGGLE()                                                        \
                        {LED_R_TOGGLE();LED_G_TOGGLE();LED_B_TOGGLE();}

#define LED_RGB_ON()    {LED_R_ON();LED_G_ON();LED_B_ON();}
#define LED_RGB_OFF()   {LED_R_OFF();LED_G_OFF();LED_B_OFF();}

/*******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/

/*******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/*******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/

/*******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 * @brief  External interrupt Ch.2 ISR
 * @param  None
 * @retval None
 */
void EXINT02_SWINT10_IrqHandler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH02))
   {
        EXINT_ClrExIntSrc(EXINT_CH02);
        LED_R_TOGGLE();
   }
}

/**
 * @brief  External interrupt Ch.4 ISR
 * @param  None
 * @retval None
 */
void EXINT04_SWINT12_IrqHandler(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH04))
   {
        EXINT_ClrExIntSrc(EXINT_CH04);
        LED_G_TOGGLE();
   }
}

/**
 * @brief  External interrupt Ch.5 callback function
 * @param  None
 * @retval None
 */
void EXINT05_IrqCallback(void)
{
   if (Set == EXINT_GetExIntSrc(EXINT_CH05))
   {
        EXINT_ClrExIntSrc(EXINT_CH05);
        LED_G_OFF();
        LED_B_TOGGLE();
   }
}

/**
 * @brief  Software interrupt Ch.14 callback function
 * @param  None
 * @retval None
 */
void EXINT06_SWINT14_IrqHandler(void)
{
    INTC_SWICmd(INTC_SWIER_SWIE14, Disable);
    LED_G_OFF();
    LED_R_TOGGLE();
}

/**
 * @brief  NMI IRQ callback function
 * @param  None
 * @retval None
 */
void NMI_IrqCallback(void)
{
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_NMIFR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_NMIFR);
        LED_RGB_TOGGLE();
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_SWDTFR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_SWDTFR);
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_PVD1FR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_PVD1FR);
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_PVD2FR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_PVD2FR);
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_XTALSTPFR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_XTALSTPFR);
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_REPFR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_REPFR);
    }
    if (Set == NMI_GetNmiSrc(INTC_NMIFR_WDTFR))
    {
        NMI_ClrNmiSrc(INTC_NMIFR_WDTFR);
    }
}

/**
 * @brief  Main function of EXINT_NMI project
 * @param  None
 * @retval int32_t return value, if needed
 */
int32_t main(void)
{
    uint8_t u8Ret;
    stc_irq_regi_config_t stcIrqRegister;
    stc_gpio_init_t stcGpioInit;
    stc_nmi_config_t stcNmiInit;
    stc_exint_config_t stcExIntInit;

    /* RGB LED initialize */
    GPIO_StructInit(&stcGpioInit);
    GPIO_Init(LED_R_PORT, LED_R_PIN, &stcGpioInit);
    GPIO_Init(LED_G_PORT, LED_G_PIN, &stcGpioInit);
    GPIO_Init(LED_B_PORT, LED_B_PIN, &stcGpioInit);

    /* "Turn off" LED before set to output */
    LED_RGB_OFF();

    /* Output enable */
    GPIO_OE(LED_R_PORT, LED_R_PIN, Enable);
    GPIO_OE(LED_G_PORT, LED_G_PIN, Enable);
    GPIO_OE(LED_B_PORT, LED_B_PIN, Enable);

    /* Software interrupt Ch.14 */
    /* NVIC configure */
    NVIC_ClearPendingIRQ(SwInt10_IRQn);
    NVIC_SetPriority(SwInt10_IRQn, DDL_IRQ_PRIORITY_15);
    NVIC_EnableIRQ(SwInt10_IRQn);
    /* Software interrupt will occur once enable */
    INTC_SWICmd(INTC_SWIER_SWIE14, Enable);

    /* External interrupt Ch.1 & Ch.2 & Ch.8 initialize */
    stcGpioInit.u16ExInt = PIN_EXINT_ON;
    GPIO_Init(EXINT2_PORT, EXINT2_PIN, &stcGpioInit);
    GPIO_Init(EXINT4_PORT, EXINT4_PIN, &stcGpioInit);
    GPIO_Init(EXINT5_PORT, EXINT5_PIN, &stcGpioInit);

    EXINT_StructInit(&stcExIntInit);

    /* EXINT Channel 2 (SW1) configure *///todo
    stcExIntInit.u32ExIntCh     = EXINT_CH02;
    stcExIntInit.u32ExIntFAE    = EXINT_FILTER_A_ON;
    stcExIntInit.u32ExIntFAClk  = EXINT_FACLK_HCLK_DIV8;
    stcExIntInit.u32ExIntFBE    = EXINT_FILTER_B_ON;
    stcExIntInit.u32ExIntFBTime = NMI_EXINT_FBTIM_2US;
    stcExIntInit.u32ExIntLvl    = EXINT_TRIGGER_FALLING;
    EXINT_Init(&stcExIntInit);

    /* EXINT Channel 1 (SW2) and Channel 8 (P147) configure *///todo
    stcExIntInit.u32ExIntCh     = EXINT_CH02;
    stcExIntInit.u32ExIntFAE    = EXINT_FILTER_A_ON;
    stcExIntInit.u32ExIntFAClk  = EXINT_FACLK_HCLK_DIV8;
    stcExIntInit.u32ExIntFBE    = EXINT_FILTER_B_ON;
    stcExIntInit.u32ExIntFBTime = NMI_EXINT_FBTIM_2US;
    stcExIntInit.u32ExIntLvl    = EXINT_TRIGGER_RISING;
    EXINT_Init(&stcExIntInit);

    /* Set IRQ handler 0 as the external interrupt Channel 5 entry */
    stcIrqRegister.enIRQn       = Int000_IRQn;
    stcIrqRegister.enIntSrc     = INT_PORT_EIRQ5;
    stcIrqRegister.pfnCallback  = &EXINT05_IrqCallback;
    u8Ret = INTC_IrqSignIn(&stcIrqRegister);
    if (Ok != u8Ret)
    {
        // check parameter
        while(1)
        {
            ;
        }
    }
    /* NVIC configure */
    /* EXINT2, fixed entry */
    NVIC_ClearPendingIRQ(ExInt2_IRQn);
    NVIC_SetPriority(ExInt1_IRQn, DDL_IRQ_PRIORITY_14);
    NVIC_EnableIRQ(ExInt1_IRQn);

    /* EXINT4, fixed entry */
    NVIC_ClearPendingIRQ(ExInt4_IRQn);
    NVIC_SetPriority(ExInt2_IRQn, DDL_IRQ_PRIORITY_15);
    NVIC_EnableIRQ(ExInt2_IRQn);

    /* IRQ000 for EXINT5 */
    NVIC_ClearPendingIRQ(Int000_IRQn);
    NVIC_SetPriority(Int000_IRQn, DDL_IRQ_PRIORITY_03);
    NVIC_EnableIRQ(Int000_IRQn);

    /* NMI Pin interrupt configure */
    NMI_StructInit(&stcNmiInit);
    stcNmiInit.u32NmiFAE         = NMI_FILTER_A_ON;
    stcNmiInit.u32NmiFAClk       = NMI_FACLK_HCLK_DIV64;
    stcNmiInit.u32NmiFBE         = NMI_FILTER_B_ON;
    stcNmiInit.u32NmiFBTime      = NMI_EXINT_FBTIM_2US;
    stcNmiInit.u32NmiTigger      = NMI_TRIGGER_RISING;
    stcNmiInit.u32NmiSrc         = NMI_SRC_NMI_PIN;
    stcNmiInit.pfnNmiCallback   = &NMI_IrqCallback;
    NMI_Init(&stcNmiInit);

    while (1)
    {
        ;// wait SW1/2/NMI key pressed
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

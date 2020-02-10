/**
 *******************************************************************************
 * @file  hc32m423_timer0.c
 * @brief This file provides firmware functions to manage the TIMER0
 *        (TIMER0).
 @verbatim
   Change Logs:
   Date             Author          Notes
   2020-02-03       Heqb          First version
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
#include "hc32m423_timer0.h"
#include "hc32m423_utility.h"

/**
 * @addtogroup HC32M423_DDL_Driver
 * @{
 */

/**
 * @defgroup DDL_TIMER0 TIMER0
 * @brief TIMER0 Driver Library
 * @{
 */

#if (DDL_TIMER0_ENABLE == DDL_ON)

/*******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/*******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
/**
 * @defgroup TIMER0_Local_Macros TIMER0 Local Macros
 * @{
 */

/**
 * @defgroup TIMER0_Check_Parameters_Validity TIMER0 Check Parameters Validity
 * @{
 */
#define IS_VALID_UNIT(x)                                                       \
(   ((x) == M4_TMR01)                              ||                          \
    ((x) == M4_TMR02))

#define IS_VALID_CHANNEL(x)                                                    \
(   ((x) == TIMER0_ChannelA)                       ||                          \
    ((x) == TIMER0_ChannelB))

#define IS_VALID_CLK_DIVISION(x)                                               \
(   ((x) == TIMER0_CLK_DIV1)                       ||                          \
    ((x) == TIMER0_CLK_DIV2)                       ||                          \
    ((x) == TIMER0_CLK_DIV4)                       ||                          \
    ((x) == TIMER0_CLK_DIV8)                       ||                          \
    ((x) == TIMER0_CLK_DIV16)                      ||                          \
    ((x) == TIMER0_CLK_DIV32)                      ||                          \
    ((x) == TIMER0_CLK_DIV64)                      ||                          \
    ((x) == TIMER0_CLK_DIV128)                     ||                          \
    ((x) == TIMER0_CLK_DIV256)                     ||                          \
    ((x) == TIMER0_CLK_DIV512)                     ||                          \
    ((x) == TIMER0_CLK_DIV1024))

#define IS_VALID_CLK_SRC(x)                                                    \
(   ((x) == TIMER0_CLK_SRC_HCLK)                   ||                          \
    ((x) == TIMER0_CLK_SRC_INTHWTRIG))

#define IS_VALID_HWTRG_FUNC(x)                                                 \
(   ((x) == TIMER0_BT_HWTRG_FUNC_START)            ||                          \
    ((x) == TIMER0_BT_HWTRG_FUNC_CLEAR)            ||                          \
    ((x) == TIMER0_BT_HWTRG_FUNC_STOP)             ||                          \
    ((x) == TIMER0_BT_HWTRG_FUNC_NONE))

#define IS_VALID_TMR0_FUNC(x)                                                  \
(   ((x) == TIMER0_FUNC_CMP)                       ||                          \
    ((x) == TIMER0_FUNC_CAPTURE))

/**
 * @}
 */

/**
 * @}
 */

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
 * @defgroup TIMER0_Local_Functions TIMER0 Local Functions
 * @{
 */

#define TIMER0_CHB_POS                  (16U)

/**
 * @defgroup TIMER0_Global_Functions TIMER0 Global Functions
 * @{
 */

/**
 * @brief  Timer0 peripheral initialization stucture clear
 * @param  [in] pstcInitStruct    Timer0 function structure
 *   @arg  See the structure definition for @ref stc_tim0_init_t
 * @retval Ok: Success
 * @retval ErrorInvalidParameter: Parameter error
 */
en_result_t TIMER0_StructInit(stc_tim0_init_t* pstcInitStruct)
{
    en_result_t enRet = ErrorInvalidParameter;
    
    if (pstcInitStruct != NULL)
    {
        pstcInitStruct->u32ClockDivision = TIMER0_CLK_DIV1;
        pstcInitStruct->u32ClockSource = TIMER0_CLK_SRC_HCLK;
        pstcInitStruct->u32Tmr0Func = TIMER0_FUNC_CMP;
        pstcInitStruct->u16CmpValue = 0xFFFFU;
        pstcInitStruct->u32HwTrigFunc = TIMER0_BT_HWTRG_FUNC_NONE;
        enRet = Ok;
    }

    return enRet;
}

/**
 * @brief  Timer0 peripheral function initialize
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4P_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4P_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @param  [in] pstcTmr0Init     TIMER0 function base parameter structure
 *   @arg  See the structure definition for @ref stc_tim0_init_t
 * @retval Ok: Success
 *         ErrorInvalidParameter: Parameter error
 * @note   In capture mode, don't need configure member u32HwTrigFunc and u16CmpValue
 */
en_result_t TIMER0_Init(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel,
                              const stc_tim0_init_t* pstcTmr0Init)
{
    en_result_t enRet = ErrorInvalidParameter;
    uint32_t u32temp = 0U;
    if (pstcTmr0Init != NULL)
    {
        enRet = Ok;
        DDL_ASSERT(IS_VALID_UNIT(TMR0x));
        DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
        DDL_ASSERT(IS_VALID_CLK_DIVISION(pstcTmr0Init->u32ClockDivision));
        DDL_ASSERT(IS_VALID_CLK_SRC(pstcTmr0Init->u32ClockSource));
        DDL_ASSERT(IS_VALID_TMR0_FUNC(pstcTmr0Init->u32Tmr0Func));
        DDL_ASSERT(IS_VALID_HWTRG_FUNC(pstcTmr0Init->u32HwTrigFunc));
        u32temp = pstcTmr0Init->u32ClockDivision \
                  | pstcTmr0Init->u32ClockSource \
                  | pstcTmr0Init->u32HwTrigFunc  \
                  | pstcTmr0Init->u32Tmr0Func;
        /* Configure register to default value, TIMER0 enter synchronous mode */
        TIMER0_DeInit(TMR0x);

        if(u8Channel == TIMER0_ChannelA)
        {
            /* Set timer0_CHA compare value */
            TMR0x->CMPAR = pstcTmr0Init->u16CmpValue;
            /* Configure clock division, clock source, function mode, Hardware trigger function */
            TMR0x->BCONR = u32temp;
        }
        else
        {
            /* Set timer0_CHB compare value */
            TMR0x->CMPBR = pstcTmr0Init->u16CmpValue;
            /* Configure clock division, clock source, function mode, Hardware trigger function */
            TMR0x->BCONR = u32temp << TIMER0_CHB_POS;
        }
    }
    return enRet;
}

/**
 * @brief  Get Timer0 status flag
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 *
 * @retval Set                   Flag is set
 *         Reset                 Flag is reset
 */
en_flag_status_t TIMER0_GetFlag(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel)
{
    uint8_t enRet = 0U;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    switch (u8Channel)
    {
    case TIMER0_ChannelA:
        enRet = TMR0x->STFLR & TMR0_STFLR_CMFA;
        break;
    case TIMER0_ChannelB:
        enRet = TMR0x->STFLR & TMR0_STFLR_CMFB;
        break;
    default:
        break;
    }
    return (en_flag_status_t)enRet;
}

/**
 * @brief  Clear Timer0 status flag
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 *
 * @retval Ok: Success
 */
en_result_t TIMER0_ClearFlag(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel)
{
    en_result_t enRet = Ok;

    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    /*Clear the Flag*/
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            CLEAR_BIT(TMR0x->STFLR, TMR0_STFLR_CMFA);
            break;
        case TIMER0_ChannelB:
            CLEAR_BIT(TMR0x->STFLR, TMR0_STFLR_CMFB);
            break;
        default:
            break;
    }
    return enRet;
}

/**
 * @brief  Command the timer0 function
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @param  [in] enNewState       Disable or Enable the function
 *
 * @retval Ok: Success
 */
en_result_t TIMER0_Cmd(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel,
                                en_functional_state_t enNewState)
{
    en_result_t enRet = Ok;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewState));
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            MODIFY_REG32(TMR0x->BCONR, TMR0_BCONR_CSTA, enNewState);
            break;
        case TIMER0_ChannelB:
            MODIFY_REG32(TMR0x->BCONR, TMR0_BCONR_CSTB, enNewState<<TIMER0_CHB_POS);
            break;
        default:
            break;
    }
    return enRet;
}

/**
 * @brief  Timer0 interrupt function command
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @param  [in] enNewState       Disable or Enable the function
 *
 * @retval Ok: Success
 */
en_result_t TIMER0_IntCmd(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel,
                        en_functional_state_t enNewState)
{
    en_result_t enRet = Ok;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    DDL_ASSERT(IS_FUNCTIONAL_STATE(enNewState));

    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            MODIFY_REG32(TMR0x->BCONR, TMR0_BCONR_INTENA, \
                        enNewState << TMR0_BCONR_INTENA_POS);
            break;
        case TIMER0_ChannelB:
            MODIFY_REG32(TMR0x->BCONR, TMR0_BCONR_INTENB, \
                        enNewState << TMR0_BCONR_INTENB_POS);
            break;
        default:
            break;
    }

    return enRet;
}

/**
 * @brief  Get Timer0 counter register
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @retval The counter register data
 * @note   Macksure timer0 function is disable in asynchronous mode
 */
uint16_t TIMER0_GetCntReg(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel)
{
    int16_t u16CntVal = 0U;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            u16CntVal = TMR0x->CNTAR & 0xFFFFU;
            break;
        case TIMER0_ChannelB:
            u16CntVal = TMR0x->CNTBR & 0xFFFFU;
            break;
        default:
            break;
    }
    return u16CntVal;
}

/**
 * @brief  Write Timer0 counter register
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @param  [in] u16Value         The data to write to the counter register
 *
 * @retval Ok: Success
 * @note   Setting the count requires stop timer0
 */
en_result_t TIMER0_WriteCntReg(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel,
                                                       uint16_t u16Value)
{
    en_result_t enRet = Ok;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            TMR0x->CNTAR = (uint32_t)u16Value;
            break;
        case TIMER0_ChannelB:
            TMR0x->CNTBR = (uint32_t)u16Value;
            break;
        default:
            break;
    }
    return enRet;
}

/**
 * @brief  Get Timer0 base compare count register
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 *
 * @retval The compare register data
 */
uint16_t TIMER0_GetCmpReg(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel)
{
    uint16_t u16CmpVal = 0U;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            u16CmpVal = TMR0x->CMPAR & 0xFFFFU;
            break;
        case TIMER0_ChannelB:
            u16CmpVal = TMR0x->CMPBR & 0xFFFFU;
            break;
        default:
            break;
    }
    return u16CmpVal;
}

/**
 * @brief  Write Timer0 compare count register
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] u8Channel        TIMER0_ChannelA or TIMER0_ChannelB
 * @param  [in] u16Value         The data to write to the compare register
 *
 * @retval Ok: Success
 */
en_result_t TIMER0_WriteCmpReg(M4_TMR0_TypeDef* TMR0x, uint8_t u8Channel,
                                                       uint16_t u16Value)
{
    en_result_t enRet = Ok;
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    DDL_ASSERT(IS_VALID_CHANNEL(u8Channel));
    switch (u8Channel)
    {
        case TIMER0_ChannelA:
            TMR0x->CMPAR = (uint32_t)u16Value;
            break;
        case TIMER0_ChannelB:
            TMR0x->CMPBR = (uint32_t)u16Value;
            break;
        default:
            break;
    }
    return enRet;
}

/**
 * @brief  De-Initialize TIMER0 function
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 *
 * @retval None
 */
void TIMER0_DeInit(M4_TMR0_TypeDef* TMR0x)
{
    TMR0x->BCONR = 0x00000000UL;
    TMR0x->CMPAR = 0x0000FFFFUL;
    TMR0x->CNTAR = 0x00000000UL;
    TMR0x->STFLR = 0x00000000UL;
}

/**
 * @brief  Set external trigger source for Timer0
 * @param  [in] TMR0x            Pointer to TIMER0 instance register base.
 * This parameter can be a value of the following:
 *  @arg M4_TMR01               TIMER0 unit 1 instance register base
 *  @arg M4_TMR02               TIMER0 unit 2 instance register base
 * @param  [in] enEvent        External event source, @ref en_event_src_t
 *
 * @retval None
 */
void TIMER0_SetTriggerSrc(M4_TMR0_TypeDef* TMR0x, en_event_src_t enEvent)
{
    DDL_ASSERT(IS_VALID_UNIT(TMR0x));
    if(TMR0x == M4_TMR01)
    {
        M4_AOS->TMR00_HTSSR = enEvent;
    }
    else
    {
        M4_AOS->TMR01_HTSSR = enEvent;
    }
}

/**
 * @}
 */

#endif /* DDL_TIMER0_ENABLE */

/**
 * @}
 */

/**
* @}
*/

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

;*******************************************************************************
; Copyright (C) 2016, Huada Semiconductor Co.,Ltd All rights reserved.
;
; This software is owned and published by:
; Huada Semiconductor Co.,Ltd ("HDSC").
;
; BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
; BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
;
; This software contains source code for use with HDSC
; components. This software is licensed by HDSC to be adapted only
; for use in systems utilizing HDSC components. HDSC shall not be
; responsible for misuse or illegal use of this software for devices not
; supported herein. HDSC is providing this software "AS IS" and will
; not be responsible for issues arising from incorrect user implementation
; of the software.
;
; Disclaimer:
; HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
; REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
; ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
; WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
; WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
; WARRANTY OF NONINFRINGEMENT.
; HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
; NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
; LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
; LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
; INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
; INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
; SAVINGS OR PROFITS,
; EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
; YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
; INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
; FROM, THE SOFTWARE.
;
; This software may be replicated in part or whole for the licensed use,
; with the restriction that this Disclaimer and Copyright notice must be
; included with each copy of this software, whether used in part or whole,
; at all times.
;/
;/*****************************************************************************/
;/*  Startup for IAR                                                          */
;/*  Version     V1.0                                                         */
;/*  Date        2020-02-01                                                   */
;/*  Target-mcu  HC32M423                                                     */
;/*****************************************************************************/


                MODULE  ?cstartup

                ;; Forward declaration of sections.
                SECTION CSTACK:DATA:NOROOT(3)

                SECTION .intvec:CODE:NOROOT(2)

                EXTERN  __iar_program_start
                EXTERN  SystemInit
                PUBLIC  __vector_table

                SECTION .intvec:CODE:NOROOT(2)
                DATA
__vector_table
                DCD     sfe(CSTACK)               ; Top of Stack
                DCD     Reset_Handler             ; Reset
                DCD     NMI_Handler               ; NMI
                DCD     HardFault_Handler         ; Hard Fault
                DCD     MemManage_Handler         ; MemManage Fault
                DCD     BusFault_Handler          ; Bus Fault
                DCD     UsageFault_Handler        ; Usage Fault
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall
                DCD     DebugMon_Handler          ; Debug Monitor
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV
                DCD     SysTick_Handler           ; SysTick

; Numbered IRQ handler vectors

; Note: renaming to device dependent ISR function names are done in
;      (section "IRQ name definition for all type MCUs")
                DCD     IRQ000_Handler
                DCD     IRQ001_Handler
                DCD     IRQ002_Handler
                DCD     IRQ003_Handler
                DCD     IRQ004_Handler
                DCD     IRQ005_Handler
                DCD     IRQ006_Handler
                DCD     IRQ007_Handler
                DCD     EXINT00_Handler
                DCD     EXINT01_Handler
                DCD     EXINT02_Handler
                DCD     EXINT03_Handler
                DCD     EXINT04_Handler
                DCD     EXINT05_Handler
                DCD     EXINT06_Handler
                DCD     EXINT07_Handler
                DCD     DMA_Tc0_Handler
                DCD     DMA_Tc1_Handler
                DCD     DMA_Tc2_Handler
                DCD     DMA_Tc3_Handler
                DCD     DMA_Btc0_Handler
                DCD     DMA_Btc1_Handler
                DCD     DMA_Btc2_Handler
                DCD     DMA_Btc3_Handler
                DCD     DMA_Err_Handler
                DCD     EFM_PgmEraseErr_Handler
                DCD     EFM_ColErr_Handler
                DCD     EFM_OpEnd_Handler
                DCD     DCU_Handler
                DCD     TIMER0_1_CmpA_Handler
                DCD     TIMER0_1_CmpB_Handler
                DCD     TIMER0_2_CmpA_Handler
                DCD     TIMER0_2_CmpB_Handler
                DCD     CLK_XtalStop_Handler
                DCD     SWDT_Handler
                DCD     TIMERA_1_Ovf_Handler
                DCD     TIMERA_1_Udf_Handler
                DCD     TIMERA_1_Cmp_Handler
                DCD     TIMERA_2_Ovf_Handler
                DCD     TIMERA_2_Udf_Handler
                DCD     TIMERA_2_Cmp_Handler
                DCD     TIMERA_3_Ovf_Handler
                DCD     TIMERA_3_Udf_Handler
                DCD     TIMERA_3_Cmp_Handler
                DCD     TIMERA_4_Ovf_Handler
                DCD     TIMERA_4_Udf_Handler
                DCD     TIMERA_4_Cmp_Handler
                DCD     TIMERB_Ovf_Handler
                DCD     TIMERB_Udf_Handler
                DCD     TIMERB_Cmp_Handler
                DCD     USART_1_RxErr_Handler
                DCD     USART_1_RxEnd_Handler
                DCD     USART_1_TxEmpty_Handler
                DCD     USART_1_TxEnd_Handler
                DCD     USART_2_RxErr_Handler
                DCD     USART_2_RxEnd_Handler
                DCD     USART_2_TxEmpty_Handler
                DCD     USART_2_TxEnd_Handler
                DCD     USART_3_RxErr_Handler
                DCD     USART_3_RxEnd_Handler
                DCD     USART_3_TxEmpty_Handler
                DCD     USART_3_TxEnd_Handler
                DCD     USART_4_RxErr_Handler
                DCD     USART_4_RxEnd_Handler
                DCD     USART_4_TxEmpty_Handler
                DCD     USART_4_TxEnd_Handler
                DCD     SPI_RxEnd_Handler
                DCD     SPI_TxEmpty_Handler
                DCD     SPI_Idle_Handler
                DCD     SPI_Err_Handler
                DCD     TIMER4_GCmpUH_Handler
                DCD     TIMER4_GCmpUL_Handler
                DCD     TIMER4_GCmpVH_Handler
                DCD     TIMER4_GCmpVL_Handler
                DCD     TIMER4_GCmpWH_Handler
                DCD     TIMER4_GCmpWL_Handler
                DCD     TIMER4_Ovf_Handler
                DCD     TIMER4_Udf_Handler
                DCD     TIMER4_ReloadU_Handler
                DCD     TIMER4_ReloadV_Handler
                DCD     TIMER4_ReloadW_Handler
                DCD     EMB_GR0_Handler
                DCD     CMP_1_Handler
                DCD     CMP_2_Handler
                DCD     CMP_3_Handler
                DCD     I2C_RxEnd_Handler
                DCD     I2C_TxEnd_Handler
                DCD     I2C_TxEmpty_Handler
                DCD     I2C_Err_Handler
                DCD     USART_1_WKUP_Handler
                DCD     PWR_Lvd1_Handler
                DCD     PWR_Lvd2_Handler
                DCD     FCM_Err_Handler
                DCD     FCM_End_Handler
                DCD     FCM_Ovf_Handler
                DCD     WDT_Handler
                DCD     CTC_Err_Handler
                DCD     ADC_SeqA_Handler
                DCD     ADC_SeqB_Handler
                DCD     ADC_ChCmp_Handler
                DCD     ADC_SeqCmp_Handler


                THUMB
; Dummy Exception Handlers (infinite loops which can be modified)

                PUBWEAK Reset_Handler
                SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
;                LDR     R2, =0x40014020 ; PWC_FPRC
;                LDR     R0, =0xA502
;                STR     R0, [R2]        ; PWC_FPRC = 0xA502
;
;                MOVS    R0, #1
;                LDR     R1, =0x42280190 ; PWC_RAMCR_RPERDIS
;                STRB    R0, [R1]        ; PWC_RAMCR_RPERDIS = 1
;
;                LDR     R0, =0xA500
;                STR     R0, [R2]        ; PWC_FPRC = 0xA500

                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__iar_program_start
                BX      R0

                PUBWEAK NMI_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
                B       NMI_Handler

                PUBWEAK HardFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
                B       HardFault_Handler

                PUBWEAK MemManage_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
MemManage_Handler
                B       MemManage_Handler

                PUBWEAK BusFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
BusFault_Handler
                B       BusFault_Handler

                PUBWEAK UsageFault_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
UsageFault_Handler
                B       UsageFault_Handler

                PUBWEAK SVC_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
                B       SVC_Handler

                PUBWEAK DebugMon_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DebugMon_Handler
                B       DebugMon_Handler

                PUBWEAK PendSV_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
                B       PendSV_Handler

                PUBWEAK SysTick_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
                B       SysTick_Handler

                PUBWEAK IRQ000_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ000_Handler
                B       IRQ000_Handler

                PUBWEAK IRQ001_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ001_Handler
                B       IRQ001_Handler

                PUBWEAK IRQ002_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ002_Handler
                B       IRQ002_Handler

                PUBWEAK IRQ003_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ003_Handler
                B       IRQ003_Handler

                PUBWEAK IRQ004_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ004_Handler
                B       IRQ004_Handler

                PUBWEAK IRQ005_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ005_Handler
                B       IRQ005_Handler

                PUBWEAK IRQ006_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ006_Handler
                B       IRQ006_Handler

                PUBWEAK IRQ007_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ007_Handler
                B       IRQ007_Handler

                PUBWEAK EXINT00_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT00_Handler
                B       EXINT00_Handler

                PUBWEAK EXINT01_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT01_Handler
                B       EXINT01_Handler

                PUBWEAK EXINT02_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT02_Handler
                B       EXINT02_Handler

                PUBWEAK EXINT03_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT03_Handler
                B       EXINT03_Handler

                PUBWEAK EXINT04_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT04_Handler
                B       EXINT04_Handler

                PUBWEAK EXINT05_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT05_Handler
                B       EXINT05_Handler

                PUBWEAK EXINT06_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT06_Handler
                B       EXINT06_Handler

                PUBWEAK EXINT07_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT07_Handler
                B       EXINT07_Handler

                PUBWEAK DMA_Tc0_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc0_Handler
                B       DMA_Tc0_Handler

                PUBWEAK DMA_Tc1_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc1_Handler
                B       DMA_Tc1_Handler

                PUBWEAK DMA_Tc2_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc2_Handler
                B       DMA_Tc2_Handler

                PUBWEAK DMA_Tc3_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc3_Handler
                B       DMA_Tc3_Handler

                PUBWEAK DMA_Btc0_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc0_Handler
                B       DMA_Btc0_Handler

                PUBWEAK DMA_Btc1_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc1_Handler
                B       DMA_Btc1_Handler

                PUBWEAK DMA_Btc2_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc2_Handler
                B       DMA_Btc2_Handler

                PUBWEAK DMA_Btc3_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc3_Handler
                B       DMA_Btc3_Handler

                PUBWEAK DMA_Err_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Err_Handler
                B       DMA_Err_Handler

                PUBWEAK EFM_PgmEraseErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_PgmEraseErr_Handler
                B       EFM_PgmEraseErr_Handler

                PUBWEAK EFM_ColErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_ColErr_Handler
                B       EFM_ColErr_Handler

                PUBWEAK EFM_OpEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_OpEnd_Handler
                B       EFM_OpEnd_Handler

                PUBWEAK DCU_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
DCU_Handler
                B       DCU_Handler

                PUBWEAK TIMER0_1_CmpA_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_1_CmpA_Handler
                B       TIMER0_1_CmpA_Handler

                PUBWEAK TIMER0_1_CmpB_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_1_CmpB_Handler
                B       TIMER0_1_CmpB_Handler

                PUBWEAK TIMER0_2_CmpA_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_2_CmpA_Handler
                B       TIMER0_2_CmpA_Handler

                PUBWEAK TIMER0_2_CmpB_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_2_CmpB_Handler
                B       TIMER0_2_CmpB_Handler

                PUBWEAK CLK_XtalStop_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
CLK_XtalStop_Handler
                B       CLK_XtalStop_Handler

                PUBWEAK SWDT_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SWDT_Handler
                B       SWDT_Handler

                PUBWEAK TIMERA_1_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Ovf_Handler
                B       TIMERA_1_Ovf_Handler

                PUBWEAK TIMERA_1_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Udf_Handler
                B       TIMERA_1_Udf_Handler

                PUBWEAK TIMERA_1_Cmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Cmp_Handler
                B       TIMERA_1_Cmp_Handler

                PUBWEAK TIMERA_2_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Ovf_Handler
                B       TIMERA_2_Ovf_Handler

                PUBWEAK TIMERA_2_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Udf_Handler
                B       TIMERA_2_Udf_Handler

                PUBWEAK TIMERA_2_Cmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Cmp_Handler
                B       TIMERA_2_Cmp_Handler

                PUBWEAK TIMERA_3_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Ovf_Handler
                B       TIMERA_3_Ovf_Handler

                PUBWEAK TIMERA_3_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Udf_Handler
                B       TIMERA_3_Udf_Handler

                PUBWEAK TIMERA_3_Cmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Cmp_Handler
                B       TIMERA_3_Cmp_Handler

                PUBWEAK TIMERA_4_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Ovf_Handler
                B       TIMERA_4_Ovf_Handler

                PUBWEAK TIMERA_4_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Udf_Handler
                B       TIMERA_4_Udf_Handler

                PUBWEAK TIMERA_4_Cmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Cmp_Handler
                B       TIMERA_4_Cmp_Handler

                PUBWEAK TIMERB_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Ovf_Handler
                B       TIMERB_Ovf_Handler

                PUBWEAK TIMERB_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Udf_Handler
                B       TIMERB_Udf_Handler

                PUBWEAK TIMERB_Cmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Cmp_Handler
                B       TIMERB_Cmp_Handler

                PUBWEAK USART_1_RxErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_RxErr_Handler
                B       USART_1_RxErr_Handler

                PUBWEAK USART_1_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_RxEnd_Handler
                B       USART_1_RxEnd_Handler

                PUBWEAK USART_1_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_TxEmpty_Handler
                B       USART_1_TxEmpty_Handler

                PUBWEAK USART_1_TxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_TxEnd_Handler
                B       USART_1_TxEnd_Handler

                PUBWEAK USART_2_RxErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_RxErr_Handler
                B       USART_2_RxErr_Handler

                PUBWEAK USART_2_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_RxEnd_Handler
                B       USART_2_RxEnd_Handler

                PUBWEAK USART_2_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_TxEmpty_Handler
                B       USART_2_TxEmpty_Handler

                PUBWEAK USART_2_TxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_TxEnd_Handler
                B       USART_2_TxEnd_Handler

                PUBWEAK USART_3_RxErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_RxErr_Handler
                B       USART_3_RxErr_Handler

                PUBWEAK USART_3_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_RxEnd_Handler
                B       USART_3_RxEnd_Handler

                PUBWEAK USART_3_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_TxEmpty_Handler
                B       USART_3_TxEmpty_Handler

                PUBWEAK USART_3_TxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_TxEnd_Handler
                B       USART_3_TxEnd_Handler

                PUBWEAK USART_4_RxErr_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_RxErr_Handler
                B       USART_4_RxErr_Handler

                PUBWEAK USART_4_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_RxEnd_Handler
                B       USART_4_RxEnd_Handler

                PUBWEAK USART_4_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_TxEmpty_Handler
                B       USART_4_TxEmpty_Handler

                PUBWEAK USART_4_TxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_TxEnd_Handler
                B       USART_4_TxEnd_Handler

                PUBWEAK SPI_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_RxEnd_Handler
                B       SPI_RxEnd_Handler

                PUBWEAK SPI_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_TxEmpty_Handler
                B       SPI_TxEmpty_Handler

                PUBWEAK SPI_Idle_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_Idle_Handler
                B       SPI_Idle_Handler

                PUBWEAK SPI_Err_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_Err_Handler
                B       SPI_Err_Handler

                PUBWEAK TIMER4_GCmpUH_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpUH_Handler
                B       TIMER4_GCmpUH_Handler

                PUBWEAK TIMER4_GCmpUL_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpUL_Handler
                B       TIMER4_GCmpUL_Handler

                PUBWEAK TIMER4_GCmpVH_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpVH_Handler
                B       TIMER4_GCmpVH_Handler

                PUBWEAK TIMER4_GCmpVL_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpVL_Handler
                B       TIMER4_GCmpVL_Handler

                PUBWEAK TIMER4_GCmpWH_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpWH_Handler
                B       TIMER4_GCmpWH_Handler

                PUBWEAK TIMER4_GCmpWL_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpWL_Handler
                B       TIMER4_GCmpWL_Handler

                PUBWEAK TIMER4_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_Ovf_Handler
                B       TIMER4_Ovf_Handler

                PUBWEAK TIMER4_Udf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_Udf_Handler
                B       TIMER4_Udf_Handler

                PUBWEAK TIMER4_ReloadU_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadU_Handler
                B       TIMER4_ReloadU_Handler

                PUBWEAK TIMER4_ReloadV_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadV_Handler
                B       TIMER4_ReloadV_Handler

                PUBWEAK TIMER4_ReloadW_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadW_Handler
                B       TIMER4_ReloadW_Handler

                PUBWEAK EMB_GR0_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
EMB_GR0_Handler
                B       EMB_GR0_Handler

                PUBWEAK CMP_1_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_1_Handler
                B       CMP_1_Handler

                PUBWEAK CMP_2_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_2_Handler
                B       CMP_2_Handler

                PUBWEAK CMP_3_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_3_Handler
                B       CMP_3_Handler

                PUBWEAK I2C_RxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_RxEnd_Handler
                B       I2C_RxEnd_Handler

                PUBWEAK I2C_TxEnd_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_TxEnd_Handler
                B       I2C_TxEnd_Handler

                PUBWEAK I2C_TxEmpty_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_TxEmpty_Handler
                B       I2C_TxEmpty_Handler

                PUBWEAK I2C_Err_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_Err_Handler
                B       I2C_Err_Handler

                PUBWEAK USART_1_WKUP_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_WKUP_Handler
                B       USART_1_WKUP_Handler

                PUBWEAK PWR_Lvd1_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
PWR_Lvd1_Handler
                B       PWR_Lvd1_Handler

                PUBWEAK PWR_Lvd2_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
PWR_Lvd2_Handler
                B       PWR_Lvd2_Handler

                PUBWEAK FCM_Err_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_Err_Handler
                B       FCM_Err_Handler

                PUBWEAK FCM_End_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_End_Handler
                B       FCM_End_Handler

                PUBWEAK FCM_Ovf_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_Ovf_Handler
                B       FCM_Ovf_Handler

                PUBWEAK WDT_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
WDT_Handler
                B       WDT_Handler

                PUBWEAK CTC_Err_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
CTC_Err_Handler
                B       CTC_Err_Handler

                PUBWEAK ADC_SeqA_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqA_Handler
                B       ADC_SeqA_Handler

                PUBWEAK ADC_SeqB_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqB_Handler
                B       ADC_SeqB_Handler

                PUBWEAK ADC_ChCmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_ChCmp_Handler
                B       ADC_ChCmp_Handler

                PUBWEAK ADC_SeqCmp_Handler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqCmp_Handler
                B       ADC_SeqCmp_Handler

                END

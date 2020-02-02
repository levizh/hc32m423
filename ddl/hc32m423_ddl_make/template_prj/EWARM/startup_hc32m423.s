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
                DCD     Reset_IrqHandler          ; Reset
                DCD     NMI_IrqHandler            ; NMI
                DCD     HardFault_IrqHandler      ; Hard Fault
                DCD     MemManage_IrqHandler      ; MemManage Fault
                DCD     BusFault_IrqHandler       ; Bus Fault
                DCD     UsageFault_IrqHandler     ; Usage Fault
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_IrqHandler            ; SVCall
                DCD     DebugMon_IrqHandler       ; Debug Monitor
                DCD     0                         ; Reserved
                DCD     PendSV_IrqHandler         ; PendSV
                DCD     SysTick_IrqHandler        ; SysTick

; Numbered IRQ handler vectors

; Note: renaming to device dependent ISR function names are done in
;      (section "IRQ name definition for all type MCUs")
                DCD     IRQ000_IrqHandler
                DCD     IRQ001_IrqHandler
                DCD     IRQ002_IrqHandler
                DCD     IRQ003_IrqHandler
                DCD     IRQ004_IrqHandler
                DCD     IRQ005_IrqHandler
                DCD     IRQ006_IrqHandler
                DCD     IRQ007_IrqHandler
                DCD     EXINT00_IrqHandler
                DCD     EXINT01_IrqHandler
                DCD     EXINT02_IrqHandler
                DCD     EXINT03_IrqHandler
                DCD     EXINT04_IrqHandler
                DCD     EXINT05_IrqHandler
                DCD     EXINT06_IrqHandler
                DCD     EXINT07_IrqHandler
                DCD     DMA_Tc0_IrqHandler
                DCD     DMA_Tc1_IrqHandler
                DCD     DMA_Tc2_IrqHandler
                DCD     DMA_Tc3_IrqHandler
                DCD     DMA_Btc0_IrqHandler
                DCD     DMA_Btc1_IrqHandler
                DCD     DMA_Btc2_IrqHandler
                DCD     DMA_Btc3_IrqHandler
                DCD     DMA_Err_IrqHandler
                DCD     EFM_PgmEraseErr_IrqHandler
                DCD     EFM_ColErr_IrqHandler
                DCD     EFM_OpEnd_IrqHandler
                DCD     DCU_IrqHandler
                DCD     TIMER0_1_CmpA_IrqHandler
                DCD     TIMER0_1_CmpB_IrqHandler
                DCD     TIMER0_2_CmpA_IrqHandler
                DCD     TIMER0_2_CmpB_IrqHandler
                DCD     CLK_XtalStop_IrqHandler
                DCD     SWDT_IrqHandler
                DCD     TIMERA_1_Ovf_IrqHandler
                DCD     TIMERA_1_Udf_IrqHandler
                DCD     TIMERA_1_Cmp_IrqHandler
                DCD     TIMERA_2_Ovf_IrqHandler
                DCD     TIMERA_2_Udf_IrqHandler
                DCD     TIMERA_2_Cmp_IrqHandler
                DCD     TIMERA_3_Ovf_IrqHandler
                DCD     TIMERA_3_Udf_IrqHandler
                DCD     TIMERA_3_Cmp_IrqHandler
                DCD     TIMERA_4_Ovf_IrqHandler
                DCD     TIMERA_4_Udf_IrqHandler
                DCD     TIMERA_4_Cmp_IrqHandler
                DCD     TIMERB_Ovf_IrqHandler
                DCD     TIMERB_Udf_IrqHandler
                DCD     TIMERB_Cmp_IrqHandler
                DCD     USART_1_RxErr_IrqHandler
                DCD     USART_1_RxEnd_IrqHandler
                DCD     USART_1_TxEmpty_IrqHandler
                DCD     USART_1_TxEnd_IrqHandler
                DCD     USART_2_RxErr_IrqHandler
                DCD     USART_2_RxEnd_IrqHandler
                DCD     USART_2_TxEmpty_IrqHandler
                DCD     USART_2_TxEnd_IrqHandler
                DCD     USART_3_RxErr_IrqHandler
                DCD     USART_3_RxEnd_IrqHandler
                DCD     USART_3_TxEmpty_IrqHandler
                DCD     USART_3_TxEnd_IrqHandler
                DCD     USART_4_RxErr_IrqHandler
                DCD     USART_4_RxEnd_IrqHandler
                DCD     USART_4_TxEmpty_IrqHandler
                DCD     USART_4_TxEnd_IrqHandler
                DCD     SPI_RxEnd_IrqHandler
                DCD     SPI_TxEmpty_IrqHandler
                DCD     SPI_Idle_IrqHandler
                DCD     SPI_Err_IrqHandler
                DCD     TIMER4_GCmpUH_IrqHandler
                DCD     TIMER4_GCmpUL_IrqHandler
                DCD     TIMER4_GCmpVH_IrqHandler
                DCD     TIMER4_GCmpVL_IrqHandler
                DCD     TIMER4_GCmpWH_IrqHandler
                DCD     TIMER4_GCmpWL_IrqHandler
                DCD     TIMER4_Ovf_IrqHandler
                DCD     TIMER4_Udf_IrqHandler
                DCD     TIMER4_ReloadU_IrqHandler
                DCD     TIMER4_ReloadV_IrqHandler
                DCD     TIMER4_ReloadW_IrqHandler
                DCD     EMB_GR0_IrqHandler
                DCD     CMP_1_IrqHandler
                DCD     CMP_2_IrqHandler
                DCD     CMP_3_IrqHandler
                DCD     I2C_RxEnd_IrqHandler
                DCD     I2C_TxEnd_IrqHandler
                DCD     I2C_TxEmpty_IrqHandler
                DCD     I2C_Err_IrqHandler
                DCD     USART_1_WKUP_IrqHandler
                DCD     PWR_Lvd1_IrqHandler
                DCD     PWR_Lvd2_IrqHandler
                DCD     FCM_Err_IrqHandler
                DCD     FCM_End_IrqHandler
                DCD     FCM_Ovf_IrqHandler
                DCD     WDT_IrqHandler
                DCD     CTC_Err_IrqHandler
                DCD     ADC_SeqA_IrqHandler
                DCD     ADC_SeqB_IrqHandler
                DCD     ADC_ChCmp_IrqHandler
                DCD     ADC_SeqCmp_IrqHandler


                THUMB
; Dummy Exception Handlers (infinite loops which can be modified)

                PUBWEAK Reset_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(2)
Reset_IrqHandler
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

                PUBWEAK NMI_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
NMI_IrqHandler
                B       NMI_IrqHandler

                PUBWEAK HardFault_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_IrqHandler
                B       HardFault_IrqHandler

                PUBWEAK MemManage_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
MemManage_IrqHandler
                B       MemManage_IrqHandler

                PUBWEAK BusFault_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
BusFault_IrqHandler
                B       BusFault_IrqHandler

                PUBWEAK UsageFault_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
UsageFault_IrqHandler
                B       UsageFault_IrqHandler

                PUBWEAK SVC_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SVC_IrqHandler
                B       SVC_IrqHandler

                PUBWEAK DebugMon_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DebugMon_IrqHandler
                B       DebugMon_IrqHandler

                PUBWEAK PendSV_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_IrqHandler
                B       PendSV_IrqHandler

                PUBWEAK SysTick_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_IrqHandler
                B       SysTick_IrqHandler

                PUBWEAK IRQ000_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ000_IrqHandler
                B       IRQ000_IrqHandler

                PUBWEAK IRQ001_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ001_IrqHandler
                B       IRQ001_IrqHandler

                PUBWEAK IRQ002_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ002_IrqHandler
                B       IRQ002_IrqHandler

                PUBWEAK IRQ003_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ003_IrqHandler
                B       IRQ003_IrqHandler

                PUBWEAK IRQ004_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ004_IrqHandler
                B       IRQ004_IrqHandler

                PUBWEAK IRQ005_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ005_IrqHandler
                B       IRQ005_IrqHandler

                PUBWEAK IRQ006_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ006_IrqHandler
                B       IRQ006_IrqHandler

                PUBWEAK IRQ007_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
IRQ007_IrqHandler
                B       IRQ007_IrqHandler

                PUBWEAK EXINT00_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT00_IrqHandler
                B       EXINT00_IrqHandler

                PUBWEAK EXINT01_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT01_IrqHandler
                B       EXINT01_IrqHandler

                PUBWEAK EXINT02_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT02_IrqHandler
                B       EXINT02_IrqHandler

                PUBWEAK EXINT03_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT03_IrqHandler
                B       EXINT03_IrqHandler

                PUBWEAK EXINT04_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT04_IrqHandler
                B       EXINT04_IrqHandler

                PUBWEAK EXINT05_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT05_IrqHandler
                B       EXINT05_IrqHandler

                PUBWEAK EXINT06_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT06_IrqHandler
                B       EXINT06_IrqHandler

                PUBWEAK EXINT07_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EXINT07_IrqHandler
                B       EXINT07_IrqHandler

                PUBWEAK DMA_Tc0_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc0_IrqHandler
                B       DMA_Tc0_IrqHandler

                PUBWEAK DMA_Tc1_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc1_IrqHandler
                B       DMA_Tc1_IrqHandler

                PUBWEAK DMA_Tc2_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc2_IrqHandler
                B       DMA_Tc2_IrqHandler

                PUBWEAK DMA_Tc3IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Tc3IrqHandler
                B       DMA_Tc3IrqHandler

                PUBWEAK DMA_Btc0_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc0_IrqHandler
                B       DMA_Btc0_IrqHandler

                PUBWEAK DMA_Btc1_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc1_IrqHandler
                B       DMA_Btc1_IrqHandler

                PUBWEAK DMA_Btc2_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc2_IrqHandler
                B       DMA_Btc2_IrqHandler

                PUBWEAK DMA_Btc3_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Btc3_IrqHandler
                B       DMA_Btc3_IrqHandler

                PUBWEAK DMA_Err_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DMA_Err_IrqHandler
                B       DMA_Err_IrqHandler

                PUBWEAK EFM_PgmEraseErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_PgmEraseErr_IrqHandler
                B       EFM_PgmEraseErr_IrqHandler

                PUBWEAK EFM_ColErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_ColErr_IrqHandler
                B       EFM_ColErr_IrqHandler

                PUBWEAK EFM_OpEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EFM_OpEnd_IrqHandler
                B       EFM_OpEnd_IrqHandler

                PUBWEAK DCU_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
DCU_IrqHandler
                B       DCU_IrqHandler

                PUBWEAK TIMER0_1_CmpA_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_1_CmpA_IrqHandler
                B       TIMER0_1_CmpA_IrqHandler

                PUBWEAK TIMER0_1_CmpB_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_1_CmpB_IrqHandler
                B       TIMER0_1_CmpB_IrqHandler

                PUBWEAK TIMER0_2_CmpA_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_2_CmpA_IrqHandler
                B       TIMER0_2_CmpA_IrqHandler

                PUBWEAK TIMER0_2_CmpB_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER0_2_CmpB_IrqHandler
                B       TIMER0_2_CmpB_IrqHandler

                PUBWEAK CLK_XtalStop_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CLK_XtalStop_IrqHandler
                B       CLK_XtalStop_IrqHandler

                PUBWEAK SWDT_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SWDT_IrqHandler
                B       SWDT_IrqHandler

                PUBWEAK TIMERA_1_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Ovf_IrqHandler
                B       TIMERA_1_Ovf_IrqHandler

                PUBWEAK TIMERA_1_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Udf_IrqHandler
                B       TIMERA_1_Udf_IrqHandler

                PUBWEAK TIMERA_1_Cmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_1_Cmp_IrqHandler
                B       TIMERA_1_Cmp_IrqHandler

                PUBWEAK TIMERA_2_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Ovf_IrqHandler
                B       TIMERA_2_Ovf_IrqHandler

                PUBWEAK TIMERA_2_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Udf_IrqHandler
                B       TIMERA_2_Udf_IrqHandler

                PUBWEAK TIMERA_2_Cmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_2_Cmp_IrqHandler
                B       TIMERA_2_Cmp_IrqHandler

                PUBWEAK TIMERA_3_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Ovf_IrqHandler
                B       TIMERA_3_Ovf_IrqHandler

                PUBWEAK TIMERA_3_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Udf_IrqHandler
                B       TIMERA_3_Udf_IrqHandler

                PUBWEAK TIMERA_3_Cmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_3_Cmp_IrqHandler
                B       TIMERA_3_Cmp_IrqHandler

                PUBWEAK TIMERA_4_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Ovf_IrqHandler
                B       TIMERA_4_Ovf_IrqHandler

                PUBWEAK TIMERA_4_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Udf_IrqHandler
                B       TIMERA_4_Udf_IrqHandler

                PUBWEAK TIMERA_4_Cmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERA_4_Cmp_IrqHandler
                B       TIMERA_4_Cmp_IrqHandler

                PUBWEAK TIMERB_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Ovf_IrqHandler
                B       TIMERB_Ovf_IrqHandler

                PUBWEAK TIMERB_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Udf_IrqHandler
                B       TIMERB_Udf_IrqHandler

                PUBWEAK TIMERB_Cmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMERB_Cmp_IrqHandler
                B       TIMERB_Cmp_IrqHandler

                PUBWEAK USART_1_RxErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_RxErr_IrqHandler
                B       USART_1_RxErr_IrqHandler

                PUBWEAK USART_1_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_RxEnd_IrqHandler
                B       USART_1_RxEnd_IrqHandler

                PUBWEAK USART_1_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_TxEmpty_IrqHandler
                B       USART_1_TxEmpty_IrqHandler

                PUBWEAK USART_1_TxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_TxEnd_IrqHandler
                B       USART_1_TxEnd_IrqHandler

                PUBWEAK USART_2_RxErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_RxErr_IrqHandler
                B       USART_2_RxErr_IrqHandler

                PUBWEAK USART_2_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_RxEnd_IrqHandler
                B       USART_2_RxEnd_IrqHandler

                PUBWEAK USART_2_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_TxEmpty_IrqHandler
                B       USART_2_TxEmpty_IrqHandler

                PUBWEAK USART_2_TxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_2_TxEnd_IrqHandler
                B       USART_2_TxEnd_IrqHandler

                PUBWEAK USART_3_RxErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_RxErr_IrqHandler
                B       USART_3_RxErr_IrqHandler

                PUBWEAK USART_3_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_RxEnd_IrqHandler
                B       USART_3_RxEnd_IrqHandler

                PUBWEAK USART_3_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_TxEmpty_IrqHandler
                B       USART_3_TxEmpty_IrqHandler

                PUBWEAK USART_3_TxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_3_TxEnd_IrqHandler
                B       USART_3_TxEnd_IrqHandler

                PUBWEAK USART_4_RxErr_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_RxErr_IrqHandler
                B       USART_4_RxErr_IrqHandler

                PUBWEAK USART_4_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_RxEnd_IrqHandler
                B       USART_4_RxEnd_IrqHandler

                PUBWEAK USART_4_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_TxEmpty_IrqHandler
                B       USART_4_TxEmpty_IrqHandler

                PUBWEAK USART_4_TxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_4_TxEnd_IrqHandler
                B       USART_4_TxEnd_IrqHandler

                PUBWEAK SPI_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_RxEnd_IrqHandler
                B       SPI_RxEnd_IrqHandler

                PUBWEAK SPI_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_TxEmpty_IrqHandler
                B       SPI_TxEmpty_IrqHandler

                PUBWEAK SPI_Idle_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_Idle_IrqHandler
                B       SPI_Idle_IrqHandler

                PUBWEAK SPI_Err_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
SPI_Err_IrqHandler
                B       SPI_Err_IrqHandler

                PUBWEAK TIMER4_GCmpUH_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpUH_IrqHandler
                B       TIMER4_GCmpUH_IrqHandler

                PUBWEAK TIMER4_GCmpUL_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpUL_IrqHandler
                B       TIMER4_GCmpUL_IrqHandler

                PUBWEAK TIMER4_GCmpVH_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpVH_IrqHandler
                B       TIMER4_GCmpVH_IrqHandler

                PUBWEAK TIMER4_GCmpVL_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpVL_IrqHandler
                B       TIMER4_GCmpVL_IrqHandler

                PUBWEAK TIMER4_GCmpWH_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpWH_IrqHandler
                B       TIMER4_GCmpWH_IrqHandler

                PUBWEAK TIMER4_GCmpWL_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_GCmpWL_IrqHandler
                B       TIMER4_GCmpWL_IrqHandler

                PUBWEAK TIMER4_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_Ovf_IrqHandler
                B       TIMER4_Ovf_IrqHandler

                PUBWEAK TIMER4_Udf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_Udf_IrqHandler
                B       TIMER4_Udf_IrqHandler

                PUBWEAK TIMER4_ReloadU_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadU_IrqHandler
                B       TIMER4_ReloadU_IrqHandler

                PUBWEAK TIMER4_ReloadV_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadV_IrqHandler
                B       TIMER4_ReloadV_IrqHandler

                PUBWEAK TIMER4_ReloadW_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
TIMER4_ReloadW_IrqHandler
                B       TIMER4_ReloadW_IrqHandler

                PUBWEAK EMB_GR0_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
EMB_GR0_IrqHandler
                B       EMB_GR0_IrqHandler

                PUBWEAK CMP_1_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_1_IrqHandler
                B       CMP_1_IrqHandler

                PUBWEAK CMP_2_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_2_IrqHandler
                B       CMP_2_IrqHandler

                PUBWEAK CMP_3_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CMP_3_IrqHandler
                B       CMP_3_IrqHandler

                PUBWEAK I2C_RxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_RxEnd_IrqHandler
                B       I2C_RxEnd_IrqHandler

                PUBWEAK I2C_TxEnd_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_TxEnd_IrqHandler
                B       I2C_TxEnd_IrqHandler

                PUBWEAK I2C_TxEmpty_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_TxEmpty_IrqHandler
                B       I2C_TxEmpty_IrqHandler

                PUBWEAK I2C_Err_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
I2C_Err_IrqHandler
                B       I2C_Err_IrqHandler

                PUBWEAK USART_1_WKUP_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
USART_1_WKUP_IrqHandler
                B       USART_1_WKUP_IrqHandler

                PUBWEAK PWR_Lvd1_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PWR_Lvd1_IrqHandler
                B       PWR_Lvd1_IrqHandler

                PUBWEAK PWR_Lvd2_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
PWR_Lvd2_IrqHandler
                B       PWR_Lvd2_IrqHandler

                PUBWEAK FCM_Err_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_Err_IrqHandler
                B       FCM_Err_IrqHandler

                PUBWEAK FCM_End_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_End_IrqHandler
                B       FCM_End_IrqHandler

                PUBWEAK FCM_Ovf_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
FCM_Ovf_IrqHandler
                B       FCM_Ovf_IrqHandler

                PUBWEAK WDT_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
WDT_IrqHandler
                B       WDT_IrqHandler

                PUBWEAK CTC_Err_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
CTC_Err_IrqHandler
                B       CTC_Err_IrqHandler

                PUBWEAK ADC_SeqA_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqA_IrqHandler
                B       ADC_SeqA_IrqHandler

                PUBWEAK ADC_SeqB_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqB_IrqHandler
                B       ADC_SeqB_IrqHandler

                PUBWEAK ADC_ChCmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_ChCmp_IrqHandler
                B       ADC_ChCmp_IrqHandler

                PUBWEAK ADC_SeqCmp_IrqHandler
                SECTION .text:CODE:NOROOT:REORDER(1)
ADC_SeqCmp_IrqHandler
                B       ADC_SeqCmp_IrqHandler

                END

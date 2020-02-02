;/******************************************************************************
;* Copyright (C) 2016, Huada Semiconductor Co.,Ltd All rights reserved.
;*
;* This software is owned and published by:
;* Huada Semiconductor Co.,Ltd ("HDSC").
;*
;* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
;* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
;*
;* This software contains source code for use with HDSC
;* components. This software is licensed by HDSC to be adapted only
;* for use in systems utilizing HDSC components. HDSC shall not be
;* responsible for misuse or illegal use of this software for devices not
;* supported herein. HDSC is providing this software "AS IS" and will
;* not be responsible for issues arising from incorrect user implementation
;* of the software.
;*
;* Disclaimer:
;* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
;* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
;* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
;* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
;* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
;* WARRANTY OF NONINFRINGEMENT.
;* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
;* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
;* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
;* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
;* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
;* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
;* SAVINGS OR PROFITS,
;* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
;* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
;* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
;* FROM, THE SOFTWARE.
;*
;* This software may be replicated in part or whole for the licensed use,
;* with the restriction that this Disclaimer and Copyright notice must be
;* included with each copy of this software, whether used in part or whole,
;* at all times.
;*/
;/*****************************************************************************/

;/*****************************************************************************/
;/*  Startup for ARM                                                          */
;/*  Version     V1.0                                                         */
;/*  Date        2020-02-01                                                   */
;/*  Target-mcu  HC32M423                                                     */
;/*****************************************************************************/

; Stack Configuration
; Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>

Stack_Size      EQU     0x00000200

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; Heap Configuration
;  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>

Heap_Size       EQU     0x00000000

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

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



__Vectors_End

__Vectors_Size                     EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main

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
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler\
                PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler\
                PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC
                EXPORT  IRQ000_Handler            [WEAK]
                EXPORT  IRQ001_Handler            [WEAK]
                EXPORT  IRQ002_Handler            [WEAK]
                EXPORT  IRQ003_Handler            [WEAK]
                EXPORT  IRQ004_Handler            [WEAK]
                EXPORT  IRQ005_Handler            [WEAK]
                EXPORT  IRQ006_Handler            [WEAK]
                EXPORT  IRQ007_Handler            [WEAK]
                EXPORT  EXINT00_Handler           [WEAK]
                EXPORT  EXINT01_Handler           [WEAK]
                EXPORT  EXINT02_Handler           [WEAK]
                EXPORT  EXINT03_Handler           [WEAK]
                EXPORT  EXINT04_Handler           [WEAK]
                EXPORT  EXINT05_Handler           [WEAK]
                EXPORT  EXINT06_Handler           [WEAK]
                EXPORT  EXINT07_Handler           [WEAK]
                EXPORT  DMA_Tc0_Handler           [WEAK]
                EXPORT  DMA_Tc1_Handler           [WEAK]
                EXPORT  DMA_Tc2_Handler           [WEAK]
                EXPORT  DMA_Tc3_Handler           [WEAK]
                EXPORT  DMA_Btc0_Handler          [WEAK]
                EXPORT  DMA_Btc1_Handler          [WEAK]
                EXPORT  DMA_Btc2_Handler          [WEAK]
                EXPORT  DMA_Btc3_Handler          [WEAK]
                EXPORT  DMA_Err_Handler           [WEAK]
                EXPORT  EFM_PgmEraseErr_Handler   [WEAK]
                EXPORT  EFM_ColErr_Handler        [WEAK]
                EXPORT  EFM_OpEnd_Handler         [WEAK]
                EXPORT  DCU_Handler               [WEAK]
                EXPORT  TIMER0_1_CmpA_Handler     [WEAK]
                EXPORT  TIMER0_1_CmpB_Handler     [WEAK]
                EXPORT  TIMER0_2_CmpA_Handler     [WEAK]
                EXPORT  TIMER0_2_CmpB_Handler     [WEAK]
                EXPORT  CLK_XtalStop_Handler      [WEAK]
                EXPORT  SWDT_Handler              [WEAK]
                EXPORT  TIMERA_1_Ovf_Handler      [WEAK]
                EXPORT  TIMERA_1_Udf_Handler      [WEAK]
                EXPORT  TIMERA_1_Cmp_Handler      [WEAK]
                EXPORT  TIMERA_2_Ovf_Handler      [WEAK]
                EXPORT  TIMERA_2_Udf_Handler      [WEAK]
                EXPORT  TIMERA_2_Cmp_Handler      [WEAK]
                EXPORT  TIMERA_3_Ovf_Handler      [WEAK]
                EXPORT  TIMERA_3_Udf_Handler      [WEAK]
                EXPORT  TIMERA_3_Cmp_Handler      [WEAK]
                EXPORT  TIMERA_4_Ovf_Handler      [WEAK]
                EXPORT  TIMERA_4_Udf_Handler      [WEAK]
                EXPORT  TIMERA_4_Cmp_Handler      [WEAK]
                EXPORT  TIMERB_Ovf_Handler        [WEAK]
                EXPORT  TIMERB_Udf_Handler        [WEAK]
                EXPORT  TIMERB_Cmp_Handler        [WEAK]
                EXPORT  USART_1_RxErr_Handler     [WEAK]
                EXPORT  USART_1_RxEnd_Handler     [WEAK]
                EXPORT  USART_1_TxEmpty_Handler   [WEAK]
                EXPORT  USART_1_TxEnd_Handler     [WEAK]
                EXPORT  USART_2_RxErr_Handler     [WEAK]
                EXPORT  USART_2_RxEnd_Handler     [WEAK]
                EXPORT  USART_2_TxEmpty_Handler   [WEAK]
                EXPORT  USART_2_TxEnd_Handler     [WEAK]
                EXPORT  USART_3_RxErr_Handler     [WEAK]
                EXPORT  USART_3_RxEnd_Handler     [WEAK]
                EXPORT  USART_3_TxEmpty_Handler   [WEAK]
                EXPORT  USART_3_TxEnd_Handler     [WEAK]
                EXPORT  USART_4_RxErr_Handler     [WEAK]
                EXPORT  USART_4_RxEnd_Handler     [WEAK]
                EXPORT  USART_4_TxEmpty_Handler   [WEAK]
                EXPORT  USART_4_TxEnd_Handler     [WEAK]
                EXPORT  SPI_RxEnd_Handler         [WEAK]
                EXPORT  SPI_TxEmpty_Handler       [WEAK]
                EXPORT  SPI_Idle_Handler          [WEAK]
                EXPORT  SPI_Err_Handler           [WEAK]
                EXPORT  TIMER4_GCmpUH_Handler     [WEAK]
                EXPORT  TIMER4_GCmpUL_Handler     [WEAK]
                EXPORT  TIMER4_GCmpVH_Handler     [WEAK]
                EXPORT  TIMER4_GCmpVL_Handler     [WEAK]
                EXPORT  TIMER4_GCmpWH_Handler     [WEAK]
                EXPORT  TIMER4_GCmpWL_Handler     [WEAK]
                EXPORT  TIMER4_Ovf_Handler        [WEAK]
                EXPORT  TIMER4_Udf_Handler        [WEAK]
                EXPORT  TIMER4_ReloadU_Handler    [WEAK]
                EXPORT  TIMER4_ReloadV_Handler    [WEAK]
                EXPORT  TIMER4_ReloadW_Handler    [WEAK]
                EXPORT  EMB_GR0_Handler           [WEAK]
                EXPORT  CMP_1_Handler             [WEAK]
                EXPORT  CMP_2_Handler             [WEAK]
                EXPORT  CMP_3_Handler             [WEAK]
                EXPORT  I2C_RxEnd_Handler         [WEAK]
                EXPORT  I2C_TxEnd_Handler         [WEAK]
                EXPORT  I2C_TxEmpty_Handler       [WEAK]
                EXPORT  I2C_Err_Handler           [WEAK]
                EXPORT  USART_1_WKUP_Handler      [WEAK]
                EXPORT  PWR_Lvd1_Handler          [WEAK]
                EXPORT  PWR_Lvd2_Handler          [WEAK]
                EXPORT  FCM_Err_Handler           [WEAK]
                EXPORT  FCM_End_Handler           [WEAK]
                EXPORT  FCM_Ovf_Handler           [WEAK]
                EXPORT  WDT_Handler               [WEAK]
                EXPORT  CTC_Err_Handler           [WEAK]
                EXPORT  ADC_SeqA_Handler          [WEAK]
                EXPORT  ADC_SeqB_Handler          [WEAK]
                EXPORT  ADC_ChCmp_Handler         [WEAK]
                EXPORT  ADC_SeqCmp_Handler        [WEAK]

IRQ000_Handler
IRQ001_Handler
IRQ002_Handler
IRQ003_Handler
IRQ004_Handler
IRQ005_Handler
IRQ006_Handler
IRQ007_Handler
EXINT00_Handler
EXINT01_Handler
EXINT02_Handler
EXINT03_Handler
EXINT04_Handler
EXINT05_Handler
EXINT06_Handler
EXINT07_Handler
DMA_Tc0_Handler
DMA_Tc1_Handler
DMA_Tc2_Handler
DMA_Tc3_Handler
DMA_Btc0_Handler
DMA_Btc1_Handler
DMA_Btc2_Handler
DMA_Btc3_Handler
DMA_Err_Handler
EFM_PgmEraseErr_Handler
EFM_ColErr_Handler
EFM_OpEnd_Handler
DCU_Handler
TIMER0_1_CmpA_Handler
TIMER0_1_CmpB_Handler
TIMER0_2_CmpA_Handler
TIMER0_2_CmpB_Handler
CLK_XtalStop_Handler
SWDT_Handler
TIMERA_1_Ovf_Handler
TIMERA_1_Udf_Handler
TIMERA_1_Cmp_Handler
TIMERA_2_Ovf_Handler
TIMERA_2_Udf_Handler
TIMERA_2_Cmp_Handler
TIMERA_3_Ovf_Handler
TIMERA_3_Udf_Handler
TIMERA_3_Cmp_Handler
TIMERA_4_Ovf_Handler
TIMERA_4_Udf_Handler
TIMERA_4_Cmp_Handler
TIMERB_Ovf_Handler
TIMERB_Udf_Handler
TIMERB_Cmp_Handler
USART_1_RxErr_Handler
USART_1_RxEnd_Handler
USART_1_TxEmpty_Handler
USART_1_TxEnd_Handler
USART_2_RxErr_Handler
USART_2_RxEnd_Handler
USART_2_TxEmpty_Handler
USART_2_TxEnd_Handler
USART_3_RxErr_Handler
USART_3_RxEnd_Handler
USART_3_TxEmpty_Handler
USART_3_TxEnd_Handler
USART_4_RxErr_Handler
USART_4_RxEnd_Handler
USART_4_TxEmpty_Handler
USART_4_TxEnd_Handler
SPI_RxEnd_Handler
SPI_TxEmpty_Handler
SPI_Idle_Handler
SPI_Err_Handler
TIMER4_GCmpUH_Handler
TIMER4_GCmpUL_Handler
TIMER4_GCmpVH_Handler
TIMER4_GCmpVL_Handler
TIMER4_GCmpWH_Handler
TIMER4_GCmpWL_Handler
TIMER4_Ovf_Handler
TIMER4_Udf_Handler
TIMER4_ReloadU_Handler
TIMER4_ReloadV_Handler
TIMER4_ReloadW_Handler
EMB_GR0_Handler
CMP_1_Handler
CMP_2_Handler
CMP_3_Handler
I2C_RxEnd_Handler
I2C_TxEnd_Handler
I2C_TxEmpty_Handler
I2C_Err_Handler
USART_1_WKUP_Handler
PWR_Lvd1_Handler
PWR_Lvd2_Handler
FCM_Err_Handler
FCM_End_Handler
FCM_Ovf_Handler
WDT_Handler
CTC_Err_Handler
ADC_SeqA_Handler
ADC_SeqB_Handler
ADC_ChCmp_Handler
ADC_SeqCmp_Handler

                B .

                ENDP

                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END

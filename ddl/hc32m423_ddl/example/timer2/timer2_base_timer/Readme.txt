﻿================================================================================
                                样例使用说明
================================================================================
版本历史
日期        版本    负责人         IAR     MDK     GCC     描述
2019-06-20  1.0     Wuze           7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例主要展示TIMER2基本定时器功能，实现了用TIMER2定时1毫秒。

说明：例程中，TIMER2的时钟源为同步时钟源HCLK。

================================================================================
测试环境
================================================================================
测试用板:
---------------------
STK_HC32M423_LQFP48_050_V11

辅助工具:
---------------------
无

辅助软件:
---------------------
无

================================================================================
使用步骤
================================================================================
1）打开工程并重新编译，将程序下载至目标板；
2）将示波器探头连接至P30，会看到示波器显示500Hz的方波。

================================================================================
注意
================================================================================
无

================================================================================

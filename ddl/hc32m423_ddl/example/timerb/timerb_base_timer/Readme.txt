﻿================================================================================
                                样例使用说明
================================================================================
版本历史
日期        版本    负责人         IAR     MDK     GCC     描述
2020-02-07  1.0     Hongjh         7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例展示TimerB模块基本计数功能。

说明：
1、本样例设置TimerB为锯齿波、向上计数模式，使能计数上溢中断
2、中断处理程序翻转RGB绿色灯引脚，RGB绿色灯闪烁。

================================================================================
测试环境
================================================================================
测试用板:
---------------------
STK_HC32M423_LQFP64_050_V10

辅助工具:
---------------------
无

辅助软件:
---------------------
无

================================================================================
使用步骤
================================================================================
1）打开工程并重新编译；
2）启动IDE的下载程序功能，关闭IDE下载界面；
3）观察RGB绿色灯状态，不停闪烁，闪烁频率为1Hz。

================================================================================
注意
================================================================================
无

================================================================================

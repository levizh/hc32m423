================================================================================
                                样例使用说明
================================================================================
版本历史
日期        版本    负责人         IAR     MDK     GCC     描述
2019-06-28  1.0     Chengy         7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例主要是系统时钟切换，并输出系统时钟的8分频。
系统时钟由HRC（默认8MHz）切换到HRC(更新后的时钟32M)，再切换到XTAL(20MHz)


================================================================================
测试环境
================================================================================
测试用板:
---------------------
STK_HC32M423_LQFP48_050_V11

辅助工具:
---------------------
示波器

辅助软件:
---------------------
无

================================================================================
使用步骤
================================================================================
1）连接P31与示波器
2）打开工程并重新编译；
3）启动IDE的下载和调试功能，全速运行；
4) 通过按键SW1切换系统时钟频率；
5）查看示波器,可观察到波形及频率变化，由1MHz->4MHz->2.5MHz变化


================================================================================
注意
================================================================================


================================================================================

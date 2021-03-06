================================================================================
                                样例使用说明
================================================================================
版本历史
日期        版本    负责人         IAR     MDK     GCC     描述
2020-02-11  1.0     Yangjp         7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例展示TimerA模块捕获及外部中断事件触发捕获功能。

说明：
本样例设置TimerA为锯齿波、向上计数模式，TimerA单元3的通道1、2开启捕获上升沿输入
功能及外部中断事件(SW1按键触发)，通道1捕获到P71输入上升沿则切换LED_R的状态，通
道2捕获到P72输入上升沿则则切换LED_G的状态；SW1按下则同时切换LED_R和LED_G的状态。

================================================================================
测试环境
================================================================================
测试用板:
---------------------
STK_HC32M423_LQFP48_050_V11

辅助工具:
---------------------
跳线一根

辅助软件:
---------------------
无

================================================================================
使用步骤
================================================================================
1）打开工程并重新编译；
2）启动IDE的下载程序功能，关闭IDE下载界面；
3）通过跳线将P71和P72引脚交替拉高，观察LED_R和LED_G的状态；
4）P71的有效输入切换LED_R状态，P72的有效输入切换LED_G状态，则功能正常；
5）按下SW1按键则触发通道1、2捕获，同时改变LED_R、LED_G状态。

================================================================================
注意
================================================================================
无

================================================================================

﻿================================================================================
                                样例使用说明
================================================================================
版本历史 
日期        版本    负责人         IAR     MDK     GCC     描述
2019-07-08  1.0     Wangmin        7.70    5.16    8.3.1   first version
================================================================================
平台说明
================================================================================
GCC工程，由Eclipse IDE外挂GNU-ARM Toolchain，再结合pyOCD GDB Server实现工程的编译、
链接和调试。在用Eclipse导入工程后，请将xxxx_PyOCDDebug中pyocd-gdbserver和SVD文件
设置为正确的路径；请将xxxx_PyOCDDownload中pyocd设置为正确的路径。注意，这些路径不
能包含非英文字符。


功能描述
================================================================================
本样例为CMP外设配置为普通比较模式的timer windows功能时,选择芯片内部Vref（具体电
压请查看数据手册）为参考电压，IVCMP1_0为比较电压，选择TIMB_1_PWM信号,通过VCOUT引
脚输出比较结果的样例。


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
1）打开工程并重新编译。
2）芯片引脚P13连接输入比较电压(<VCC),P15接入示波器查看PWM输出波形。
3）全速运行样例代码。
4）调节输入比较电压值，查看LED灯变化。
5）PWM输出高时，CMP输出有效，如下：
   	当比较电压>Vref，绿色LED亮；
   	当比较电压<Vref，绿色LED灭。
   PWM输出低时，CMP输出无效，VCOUT默认为低电平，绿色LED灯亮。


================================================================================
注意
================================================================================
1）

================================================================================

//
// Created by KuroNeko359 on 2025/10/20.
//

#ifndef DATA_STRUCTURE_TIMER_H
#define DATA_STRUCTURE_TIMER_H

#include <time.h>

// 开始计时，返回起始时钟值
clock_t timer_start();

// 结束计时，计算从start到现在的耗时（单位：秒）
double timer_end(clock_t start);

// 辅助函数：将秒转换为毫秒
double seconds_to_ms(double seconds);

// 辅助函数：将秒转换为微秒
double seconds_to_us(double seconds);
#endif //DATA_STRUCTURE_TIMER_H
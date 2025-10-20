//
// Created by KuroNeko359 on 2025/10/20.
//
#include "tools/timer.h"

#include <stdio.h>
#include <time.h>  // 用于clock()和CLOCKS_PER_SEC

// 开始计时
clock_t timer_start() {
    printf("timer start");
    return clock();
}

// 结束计时（返回秒数）
double timer_end(clock_t start) {
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

// 秒转毫秒
double seconds_to_ms(double seconds) {
    return seconds * 1000.0;
}

// 秒转微秒
double seconds_to_us(double seconds) {
    return seconds * 1000000.0;
}
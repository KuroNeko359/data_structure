//
// Created by KuroNeko359 on 2025/9/25.
//
#ifndef CSAPP_DEBUG_H
#define CSAPP_DEBUG_H

#ifndef ENABLE_DEBUG
#define ENABLE_DEBUG 1
#endif

#define DEBUG_PRINT(fmt, ...) do { \
time_t now = time(NULL); \
struct tm *t = localtime(&now); \
char time_str[20]; \
strftime(time_str, sizeof(time_str), "%H:%M:%S", t); \
printf("[%s] %s:%d %s() " fmt "\n", \
time_str, __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
} while(0)

// void debug_printf(const char* fmt, ...);

void log_printf(const char *fmt, ...);

#endif //CSAPP_DEBUG_H

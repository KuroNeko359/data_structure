//
// Created by KuroNeko359 on 2025/9/25.
//
#ifndef DATA_STRUCTURE_DEBUG_H
#define DATA_STRUCTURE_DEBUG_H

#ifndef ENABLE_DEBUG
#define ENABLE_DEBUG 1
#endif

#include <time.h>
#include <stdio.h>

#define _LOG_BASE(level, stream, color_prefix, color_suffix, fmt, ...) do { \
time_t now = time(NULL); \
struct tm *t = localtime(&now); \
char time_str[20]; \
strftime(time_str, sizeof(time_str), "%H:%M:%S", t); \
fprintf(stream, color_prefix"[%s] ["level"] %s:%d %s() "fmt color_suffix"\n", \
time_str, __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
} while(0)

#define _NO_COLOR ""

#define DEBUG_PRINT(fmt, ...) _LOG_BASE("DEBUG", stdout, _NO_COLOR, _NO_COLOR, fmt, ##__VA_ARGS__)
#define ERROR_PRINT(fmt, ...) _LOG_BASE("ERROR", stderr, _NO_COLOR, _NO_COLOR, fmt, ##__VA_ARGS__)
#define WARN_PRINT(fmt, ...)  _LOG_BASE("WARN",  stderr, "\033[33m", "\033[0m", fmt, ##__VA_ARGS__)


#endif //DATA_STRUCTURE_DEBUG_H

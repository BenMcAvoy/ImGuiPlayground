#pragma once

#ifdef _WIN32
#include <windows.h>
#include <stdio.h>

#define SETCOLOR(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

#define INFO(...) { \
	SYSTEMTIME st; \
	GetLocalTime(&st); \
	SETCOLOR(10); printf("[%02d:%02d:%02d.%03d] ", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); SETCOLOR(7); \
	printf(__VA_ARGS__); \
}

#define WARN(...) { \
	SYSTEMTIME st; \
	GetLocalTime(&st); \
	SETCOLOR(14); printf("[%02d:%02d:%02d.%03d] ", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); SETCOLOR(7); \
	printf(__VA_ARGS__); \
}

#define ERROR(...) { \
	SYSTEMTIME st; \
	GetLocalTime(&st); \
	SETCOLOR(12); printf("[%02d:%02d:%02d.%03d] ", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds); SETCOLOR(7); \
	printf(__VA_ARGS__); \
}

#elif __linux__

#include <stdio.h>
#include <time.h>

#define SETCOLOR(color) printf("\033[%dm", color)

#define INFO(...) { \
    time_t rawtime; \
    struct tm *timeinfo; \
    time(&rawtime); \
    timeinfo = localtime(&rawtime); \
    SETCOLOR(32); printf("[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); SETCOLOR(0); \
    printf(__VA_ARGS__); \
}

#define WARN(...) { \
    time_t rawtime; \
    struct tm *timeinfo; \
    time(&rawtime); \
    timeinfo = localtime(&rawtime); \
    SETCOLOR(33); printf("[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); SETCOLOR(0); \
    printf(__VA_ARGS__); \
}

#define ERROR(...) { \
    time_t rawtime; \
    struct tm *timeinfo; \
    time(&rawtime); \
    timeinfo = localtime(&rawtime); \
    SETCOLOR(31); printf("[%02d:%02d:%02d] ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec); SETCOLOR(0); \
    printf(__VA_ARGS__); \
}
#endif


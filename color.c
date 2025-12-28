#include "color.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

/*
void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

    switch (color) {
        case COLOR_RED:
            attr = FOREGROUND_RED;
            break;
        case COLOR_GREEN:
            attr = FOREGROUND_GREEN;
            break;
        case COLOR_YELLOW:
            attr = FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case COLOR_BLUE:
            attr = FOREGROUND_BLUE;
            break;
        case COLOR_MAGENTA:
            attr = FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case COLOR_CYAN:
            attr = FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case COLOR_WHITE:
            attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    }

    SetConsoleTextAttribute(hConsole, attr);
}

void reset_color(void) {
    set_color(COLOR_WHITE);
}

*/
void set_color(int color) {
    switch (color) {
        case COLOR_RED:     printf("\033[31m"); break;
        case COLOR_GREEN:   printf("\033[32m"); break;
        case COLOR_YELLOW:  printf("\033[33m"); break;
        case COLOR_BLUE:    printf("\033[34m"); break;
        case COLOR_MAGENTA: printf("\033[35m"); break;
        case COLOR_CYAN:    printf("\033[36m"); break;
        case COLOR_WHITE:   printf("\033[37m"); break;
        default:            printf("\033[0m");
    }
}

void reset_color(void) {
    printf("\033[0m");
}

#endif

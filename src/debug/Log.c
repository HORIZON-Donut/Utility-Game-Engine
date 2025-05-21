#include "Log.h"

#include <stdio.h>
#include <string.h>

#define COLOR_RESET "\x1b[0m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_RED "\x1b[31m"
#define COLOR_YELLOW "\x1b[33m"

void ReportTest(char* message, int status)
{
    char result[5];
    char* color;

    switch(status)
    {
        case 0:
            strcpy(result, "PASS");
            color = COLOR_GREEN;
            break;
        
        case 1:
            strcpy(result, "FAIL");
            color = COLOR_RED;
            break;
        
        default:
            strcpy(result, "INVA");
            color = COLOR_YELLOW;
            break;
    }

    printf("[ %s%s%s ] %s\n", color, result, COLOR_RESET, message);
}
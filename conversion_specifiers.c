#include "main.h"

int conversion_specifiers(const char *format, va_list args, int *total_chars_printed)
{
    int num = va_arg(args, int);
    char num_str[12]; 
    int len = snprintf(num_str, sizeof(num_str), "%d", num);
    write(1, num_str, len);
    *total_chars_printed += len;
    return(len);
}



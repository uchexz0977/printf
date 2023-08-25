#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>  

int _printf(const char *format, ...);
int conversion_specifiers(const char *format, va_list args, int *total_chars_printed);

#endif /* MAIN_H */


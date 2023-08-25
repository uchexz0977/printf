#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	if (format == NULL)
	return (-1);

	va_list args;
	va_start(args, format);

	int total_chars_printed = 0;

	for (int i = 0; format[i] != '\0'; i++)
    {
		if (format[i] == '%')
        {
			i++; // Move past the %
			switch (format[i])
            {
				case 'c':
                    // Handle %c
                    {
						char c = va_arg(args, int);
						write(1, &c, 1);
						total_chars_printed++;
                    }
					break;
				case 's':
                    // Handle %s
                    {
						char *s = va_arg(args, char*);
						int len = 0;
						while (s[len] != '\0')
                        {
							len++;
                        }
						write(1, s, len);
						total_chars_printed += len;
                    }
					break;
				case 'd': case 'i':
                    // Handle %d and %i
                    {
						int num = va_arg(args, int);
						total_chars_printed += _printf("%d", num);
                    }
					break;
					case '%':
                    // Handle %%
					write(1, "%", 1);
					total_chars_printed++;
					break;
					default:
                    // Handle unknown specifier by printing % as is
					write(1, "%", 1);
					total_chars_printed++;
					i--; // Revert i as we didn't process this %
					break;
            }
        }
		else
        {
			write(1, &format[i], 1);
			total_chars_printed++;
        }
    }

	va_end(args);
	return total_chars_printed;
}


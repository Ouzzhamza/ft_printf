#include "ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("Testing ft_printf:\n");
    
    ft_printf("Printing a string: %s\n", "Hello, world!");

    ft_printf("Printing a character: %c\n", 'A');

    ft_printf("Printing an integer: %d\n", 42);

    ft_printf("Printing an unsigned integer: %u\n", 12345);

    ft_printf("Printing a hexadecimal number: %x\n", 255);

    ft_printf("Printing a pointer address: %p\n", (void *)0x12345678);

    return 0;
}
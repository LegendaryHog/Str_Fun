#include <stdio.h>

int my_puts (const char* s);

int main (void)
{
    char s[] = "Poltorashka";
    char a[] = "";
    printf ("%d\n", my_puts (s));
    printf ("%d\n", my_puts (a));
    return 0;
}

int my_puts (const char* s)
{
    int test = 0;

    while (*s != '\0')
    {
       putchar (*s);
       test++;
       s++;
    }

    putchar ('\n');

    if (test == 0)
    {
        return EOF;
    }

    return test;
}

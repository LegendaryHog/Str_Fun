#include <stdio.h>
#include <string.h>

char* my_strcpy (char* strcp, const char* str);

int main (void)
{
    char str[]= "Poltorashka";
    char strcp[13];

    my_strcpy (strcp, str);
    printf ("%s\n", strcp);
    printf ("%d\n", my_strcpy (strcp, str) - strcp);
    puts (my_strcpy (strcp, str));
    return 0;
}

char* my_strcpy (char* strcp, const char* str)
{
    char* ptr = strcp;

    while (*str != '\0')
    {
        *strcp++ = *str++;
    }
    *strcp = '\0';
    return ptr;
}

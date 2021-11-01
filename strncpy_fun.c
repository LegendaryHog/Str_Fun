#include <stdio.h>

char* my_strncpy (char* strcp, const char* str, size_t num);

int main (void)
{
    char str[] = "Poltorashka";
    char strcp[11] = "";

    puts (my_strncpy (strcp, str, 6));
    puts (my_strncpy (strcp, str, 11));


    return 0;
}

char* my_strncpy (char* strcp, const char* str, size_t num)
{
    char* ptr = strcp;

    while ((strcp - ptr < num) && (*str != '\0'))
    {
        *strcp++ = *str++;
    }

    *strcp = '\0';

    return ptr;
}

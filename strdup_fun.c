#include <stdio.h>
#include <stdlib.h>

char* My_strdup (const char* str);

int main (void)
{
    char* str = "Poltorashka";

    printf ("%s", My_strdup (str));

    return 0;
}

char* My_strdup (const char* str)
{
    size_t len = 0;
    size_t i = 0;

    while (str[i] != '\0')
    {
        i++;
        len++;
    }

    i = 0;

    char* ptrdup = (char*) calloc (len + 1, sizeof (char));

    if (ptrdup == NULL)
    {
        return NULL;
    }


    while (str[i] != '\0')
    {
        ptrdup[i] = str[i];
        i++;

    }

    ptrdup[i] = '\0';

    return ptrdup;
}

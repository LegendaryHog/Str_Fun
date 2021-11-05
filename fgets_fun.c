#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* My_fgets (char* string, int num, FILE* filestream);

int main (void)
{
    FILE* poltor = fopen ("poltor.txt", "r");
    assert (poltor != NULL);
    char* string = (char*) calloc (20, sizeof (char));
    printf ("%s\n", My_fgets (string, 6, poltor));
    //printf ("%s\n", My_fgets (string, 11, poltor));

    return 0;
}

char* My_fgets (char* string, int num, FILE* filestream)
{
    char* ptr = (char*)string;

    if (feof (filestream) == 0)
    {
        return NULL;
    }
    else
    {
        while (ptr - string < num && feof (filestream) == 0 && *(ptr - 1) != '\n')
        {
            *ptr = fgetc (filestream);
            ptr++;
        }
        *(ptr + 1) = '\0';
        return string;
    }
}

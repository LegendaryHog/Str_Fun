#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t my_getline (char** lineptr, size_t* ptr_alloc_mem, FILE* filestrem);

int main (void)
{
    FILE* poltor = fopen ("poltor.txt", "r");
    assert (poltor != NULL);
    size_t mem_alloc = 6;
    char* poltorashka = (char*) calloc (mem_alloc, sizeof (char));
    printf ("%zd\n", my_getline(&poltorashka, &mem_alloc, poltor));
    free (poltorashka);
    fclose (poltor); 

    return 0;
}

size_t my_getline (char** ptr_str, size_t* ptr_alloc_mem, FILE* filestream)
{
    size_t read_bytes  = 0;
    size_t new_bytes   = 0;
    char   now_reading = 0;
    size_t i           = 0;

    do
    {
        read_bytes++;
        now_reading = fgetc (filestream);
        if (read_bytes >= *ptr_alloc_mem - 1)
        {
            *ptr_alloc_mem += 1;
            new_bytes++;
            *ptr_str = (char*) realloc (*ptr_str, *ptr_alloc_mem);
        }
        *(*(ptr_str) + i) = now_reading;
        i++;
    }
    while (now_reading != '\n' && now_reading != '\r' && feof (filestream) == 0);

    return new_bytes;
}


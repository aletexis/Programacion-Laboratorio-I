#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;//reservo memoria estatica para un entero
    int* p = (int*) malloc(sizeof(int));//reservo memoria dinamica para un entero

    if(p == NULL)
    {
        printf("\n\n\t\t>>> No se pudo conseguir espacio en memoria <<<\n\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        x = 10;

        *p = 10;

        printf("X vale %d\n", x);
        printf("P vale %d\n", *p);

        free(p);
    }


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* vecDinamico = (int*) malloc(5 * sizeof(int));

    if(vecDinamico == NULL)
    {
        printf("\n\n\t>>> No se pudo conseguir espacio en memoria <<<\n\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<5; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", vecDinamico + i);
    }

    printf("\n-------------------\n");

    for(int i=0; i<5; i++)
    {
        printf("%d ", *(vecDinamico + i));
    }

    int* aux = (int*) realloc(vecDinamico, 10 * sizeof(int));

    if(aux != NULL)
    {
        vecDinamico = aux;
        printf("\n\n\t>>> Se puedo reasignar el array <<<\n\n");

        for(int i=5; i<10; i++)
        {
            printf("\nIngrese un numero: ");
            scanf("%d", vecDinamico + i);
        }

        printf("\n-------------------\n");

        for(int i=0; i<10; i++)
        {
            printf("%d ", *(vecDinamico + i));
        }
    }
    else
    {
        printf("\n\n\t>>> No se puedo reasignar el array <<<\n\n");
    }

    printf("\n\n");

    vecDinamico = (void*) realloc(vecDinamico, 6 * sizeof(int));

    for(int i=0; i<6; i++)
    {
        printf("%d ", *(vecDinamico + i));
    }

    free(vecDinamico);



    /////////////////

    /*
    int* vec = (int*) calloc(5, sizeof(int));

    for(int i=0; i<6; i++)
    {
        printf("%d ", *(vec + i));
    }
    */

    return 0;
}

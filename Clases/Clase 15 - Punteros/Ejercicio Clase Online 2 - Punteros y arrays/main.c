#include <stdio.h>
#include <stdlib.h>

void showVector(int vec[], int size);
void showVectorP(int* vec, int size);

int main()
{
    int vec[] = {4,3,7,6,8};

    /*printf("%d\n", *vec);
    printf("%d\n", *(vec + 1));//es un sizeof, va sumando 4 bytes
    printf("%d\n", *(vec + 2));
    printf("%d\n", *(vec + 3));
    printf("%d\n", *(vec + 4));*/

    showVector(vec, 5);
    printf("\n\n----------\n\n");
    showVectorP(vec, 5);
    printf("\n\n");


    return 0;
}

void showVector(int vec[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", vec[i]); //notacion vectorial
    }
}

void showVectorP(int* vec, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", *(vec + i)); //notacion de puntero
    }
}


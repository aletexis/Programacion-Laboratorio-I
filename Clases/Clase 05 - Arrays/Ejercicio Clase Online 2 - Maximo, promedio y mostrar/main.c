#include <stdio.h>
#include <stdlib.h>
#include "library.h"

#define SIZE 5

int main()
{
    int numbers[SIZE];
    int max;

    for(int i=0; i<SIZE; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numbers[i]);
    }

    showArrayUp(numbers, SIZE);
    showArrayDown(numbers, SIZE);
    max = getMax(numbers, SIZE);
    printf("\n\nEl mayor numero ingresado es %d y fue ingresado en la/s posicion/es",max);

    //busqueda de las posiciones que guardan un valor de un num max
    for(int i=0; i<SIZE; i++)
    {
        if(numbers[i] == max)
        {
             printf(" %d", i + 1);
        }
    }

    printf("\n\nEl promedio de los numeros ingresados es %.2f", getAverage(numbers, SIZE));
    searchNumber(numbers, SIZE);
    printf("\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "library.h"

#define SIZE 5

int main()
{
    //int numbers[] = {3, 2, 6, 5, 8};

    //printf("%d\n", searchNumber(6, numbers, 5));
    //printf("%d\n", searchNumber(9, numbers, 5));

    ///////////////////////////

    int numbers[SIZE];
    int numberToSearch;

    for(int i=0; i<SIZE; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numbers[i]);
    }

    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d", &numberToSearch);


    if((searchNumber(numberToSearch, numbers, SIZE)) == -1)
    {
       printf("\nEl numero %d no esta en el array", numberToSearch);
    }
    else
    {
        printf("\nEl numero %d esta en el array", numberToSearch);
    }

    printf("\nEl numero maximo es %d", getMax(numbers, SIZE));
    printf("\nEl numero minimo es %d", getMin(numbers, SIZE));
    printf("\nEl promedio es %.2f", getAverage(numbers, SIZE));
    printf("\n");

    return 0;
}

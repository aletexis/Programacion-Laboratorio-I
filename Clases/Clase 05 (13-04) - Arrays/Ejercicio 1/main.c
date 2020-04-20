/**
*Solicitar al usuario 5 números,
*almacenar estos en un array de enteros,
*listar el máximo, el mínimo y el promedio.
*Permitir Modificar el valor de cualquiera de
*los números cargados indicando el índice del
mismo y su nuevo valor.**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "utn.h"

#define SIZE 5

int main()
{
    int numbers[SIZE];
    int actualNumber;
    int i;
    int newNumber;
    int option = 0;

    for(i=0; i<SIZE; i++)
    {
        actualNumber = getInt("\nIngrese un numero: ");
        numbers[i] = actualNumber;
    }

    while(option != 3)
    {
         option = getInt("\n\n 1. Mostrar \n 2. Modificar \n 3. Salir\n\n Ingrese una opcion: ");
         switch(option)
         {
            case 1:
                printf("\n\n  INDICE - NUMERO\n");
                for(i=0; i<SIZE; i++)
                {
                    printf("    %d    -   %d \n", i, numbers[i]);
                }
                printf("\nEl numero maximo es %d", getMax(numbers, SIZE));
                printf("\nEl numero minimo es %d", getMin(numbers, SIZE));
                printf("\nEl promedio es %.2f", getAverage(numbers, SIZE));
                break;

            case 2:
                i = getInt("\nIngrese el indice a modificar: ");
                if(i>=0 && i<SIZE)
                {
                    newNumber = getInt("\nIngrese el valor: ");
                    numbers[i] = newNumber;
                }
                else
                {
                    printf("\nEl indice ingresado esta fuera de rango");
                }
                break;
         }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"

int main()
{
    //int bufferInt;
    float bufferFloat;

    /*
    if(getIntNumber(&bufferInt, "\nIngrese un numero entero: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", -2, 20, 2) == 0)
    {
        printf("\nEl numero es: %d", bufferInt);
    }
    else
    {
        printf("\nERROR\n");
    }
    */

    if(getFloatNumber(&bufferFloat, "\nIngrese un numero flotante: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", -2, 20.50, 5) == 0)
    {
        printf("\nEl numero es: %.2f", bufferFloat);
    }
    else
    {
        printf("\nERROR\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "validations.h"

int main()
{
    int bufferInt;

    if(getIntNumber(&bufferInt, "\nIngrese un numero entero: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", -2, 20, 2) == 0)
    {
        printf("\nEl numero es: %d", bufferInt);
    }
    else
    {
        printf("\nERROR\n");
    }


    return 0;
}

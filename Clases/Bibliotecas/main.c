#include <stdio.h>
#include <stdlib.h>
#include "validations.h"

int main()
{
    int bufferInt;
    float bufferFloat;
    char bufferChar;
    char bufferString[50];


    if(getIntNumber(&bufferInt, "\nIngrese un numero entero: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", -2, 20, 2) == 0)
    {
        printf("\nEl numero es: %d\n", bufferInt);
    }
    else
    {
        printf("\nERROR\n");
    }



    if(getFloatNumber(&bufferFloat, "\nIngrese un numero flotante: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", -2, 20.50, 5) == 0)
    {
        printf("\nEl numero es: %.2f\n", bufferFloat);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(getCharacter(&bufferChar, "\nIngrese un caracter: ", "\nError. Caracter invalido.\n", 3) == 0)
    {
        printf("\nEl caracter es: %c\n", bufferChar);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(getText(bufferString, "\nIngrese texto: ", "\nError. Texto invalido.\n", 3) == 0)
    {
        printf("\nEl texto es: %s\n", bufferString);
    }
    else
    {
        printf("\nERROR\n");
    }

    return 0;
}

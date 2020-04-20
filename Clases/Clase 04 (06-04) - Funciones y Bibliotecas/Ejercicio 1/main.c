#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
Desarrollar una biblioteca "utn.h" que posea funciones para pedirle al usuario el ingreso de datos

getInt()
getFloat()
getChar()
**/

int main()
{
    int intNumber;
    float floatNumber;
    char character;

    intNumber = getInt("Ingrese un numero entero: ");
    floatNumber = getFloat("Ingrese un numero flotante: ");
    character = getChar("Ingrese un caracter: ");

    printf("\nEl numero entero es: %d", intNumber);
    printf("\nEl numero flotante es: %.2f", floatNumber);
    printf("\nEl caracter es: %c\n", character);

    return 0;
}

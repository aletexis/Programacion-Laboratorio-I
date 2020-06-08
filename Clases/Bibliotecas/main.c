#include <stdio.h>
#include <stdlib.h>
#include "validations.h"

#define SIZE 10

int main()
{
    int bufferInt;
    float bufferFloat;
    char bufferChar;
    char bufferString[50];
    char bufferAlphanumeric[50];
    char bufferTelephone[11];
    char bufferDNI[11];
    char bufferEmail[50];
    char bufferGender;



    if(validations_getUnsignedInt(&bufferInt, "\nIngrese un numero entero: ", "\nError. Numero invalido. Rango: entre -2 y 20\n",1, SIZE, -2, 20, 9) == 0)
    {
        printf("\nEl numero es: %d\n", bufferInt);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(validations_getFloat(&bufferFloat, "\nIngrese un numero flotante: ", "\nError. Numero invalido. Rango: entre -2 y 20\n", 1, SIZE, -2, 20.50, 9) == 0)
    {
        printf("\nEl numero es: %.2f\n", bufferFloat);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(validations_getChar(&bufferChar,"\nIngrese un caracter: ", "\nError. Caracter invalido.\n",0, 3, 9) == 0)
    {
        printf("\nEl caracter es: %c\n", bufferChar);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(validations_getText(bufferString, "\nIngrese un texto: ", "\nError. Texto invalido.\n", 1, 50, 9) == 0)
    {
        printf("\nEl texto es: %s\n", bufferString);
    }
    else
    {
        printf("\nERROR\n");
    }

    if(validations_getAlfanumeric(bufferAlphanumeric, "\nIngrese un alfanumerico: ", "\nError. Alfanumerico invalido.\n", 1, 10, 9) == 0)
    {
        printf("\nEl alfanumerico es: %s\n", bufferAlphanumeric);
    }
    else
    {
        printf("\nERROR\n");
    }


    if(validations_getTelephone(bufferTelephone, "\nIngrese un telefono (Formato: 1112345678 o 1234-5678): ", "\nError. Telefono invalido. Formato: 1112345678 o 1234-5678\n", 9) == 0)
    {
        printf("\nEl telefono es: %s\n", bufferTelephone);
    }
    else
    {
        printf("\nERROR\n");
    }



    if(validations_getDNI(bufferDNI, "\nIngrese un DNI (Formato: 12.345.678 o 12345678): ", "\nError. DNI invalido. Formato: 12.345.678 o 12345678\n", 9) == 0)
    {
        printf("\nEl DNI es: %s\n", bufferDNI);
    }
    else
    {
        printf("\nERROR\n");
    }


    if(validations_getEmail(bufferEmail, "\nIngrese un e-mail: ", "\nError. e-mail invalido.\n", 5, 50, 9) == 0)
    {
        printf("\nEl e-mail es: %s\n", bufferEmail);
    }
    else
    {
        printf("\nERROR\n");
    }
*/
    if(validations_getGenre(&bufferGender, "\nIngrese un genero: ", "\nError. Genero invalido. Debe ser f o m\n", 9) == 0)
    {
        printf("\nEl genero es: %c\n", bufferGender);
    }
    else
    {
        printf("\nERROR\n");
    }

    return 0;
}

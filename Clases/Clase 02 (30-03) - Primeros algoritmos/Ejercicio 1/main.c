/**
*
* Objetivo:
*   -Realizar un programa que solicite cinco números e imprima por pantalla el
*    promedio, el máximo y el mínimo.
*
* Aspectos a destacar:
*   -El uso de bucles para pedir un número tras otro
*   -El uso de acumuladores, se tiene que guardar la suma para luego hacer
*    el promedio
*   -El uso del if para preguntar si el numero ingresado es mayor o menor
*    para guardar los máximos y mínimo
**/

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int maximo;
    int minimo;
    int acumulador;
    int numero;
    int i;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    maximo = numero;
    minimo = numero;
    acumulador = numero;

    for(i=0;i<4;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);
        acumulador = acumulador + numero;

        if(numero > maximo)
        {
            maximo = numero;
        }

        if(numero < minimo)
        {
            minimo = numero;
        }
    }

    printf("\nEl maximo es: %i\n",maximo);
    printf("El minimo es: %i\n",minimo);
    printf("El promedio es: %i\n",acumulador / 5);
    return 0;

}

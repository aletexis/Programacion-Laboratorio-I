#include <stdio.h>
#include <stdlib.h>
/**
Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
**/

int main()
{
    int numero;
    int contadorPositivos = 0;
    int contadorNegativos = 0;
    int positivos;
    int negativos;
    int i;

    for(i=0; i<10; i++)
    {
        printf("\nIngrese un numero: ");
        scanf("%d", &numero);

        if(numero > 0)
        {
            contadorPositivos ++;
        }
        else
        {
            contadorNegativos ++;
        }
    }

    printf("\nLa cantidad de numeros positivos es: %d\n", contadorPositivos);
    printf("\nLa cantidad de numeros negativos es: %d\n", contadorNegativos);

    return 0;
}

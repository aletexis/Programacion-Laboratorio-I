#include <stdio.h>
#include <stdlib.h>

/** ------------------ PASAJE POR VALOR ------------------ **/

void duplicarNumero(int);
int duplicarNumero2(int);

int main()
{
    int num = 5;
    int num2 = 5;

    printf("Antes de la funcion num vale %d\n", num);
    duplicarNumero(num);
    printf("Despues de la funcion num vale %d\n", num);

    printf("-----------------------");

    printf("\nAntes de la funcion num2 vale %d\n", num2);
    num2 = duplicarNumero2(num2);
    printf("Despues de la funcion num2 vale %d\n", num2);


    return 0;
}

void duplicarNumero(int num)
{
    num = num * 2;
    printf("Dentro de la funcion num vale %d\n", num);
}

int duplicarNumero2(int num)
{
    num = num * 2;
    printf("Dentro de la funcion num vale %d\n", num);

    return num;
}

//pasarle una referencia a una funcion es pasarle la direccion de memoria
//cualquier funcion a la que le paso una direccion de memoria puede escribir en ese espacio


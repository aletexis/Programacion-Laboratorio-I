#include <stdio.h>
#include <stdlib.h>


void swap();

int main()
{

    int a = 4;
    int b = 6;

    printf("\na = %d \nb = %d\n",a,b);
    swap(&a,&b);
    printf("despues del swap");
    printf("\na = %d \nb = %d\n",a,b);

    return 0;
}

void swap(int* x, int* y)
{
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}







/*
int main()
{
    int a = 20;
    int* p;

    //&a es la direccion de memoria de a
    // *direccionMemoria es el valor guardado en esa direccion

    p = &a;
    *p = 30; // ====> *&a = 30; ======> a = 30;

    printf("%d\n", a);

    return 0;
}
*/


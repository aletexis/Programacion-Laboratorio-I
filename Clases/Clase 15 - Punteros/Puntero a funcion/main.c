#include <stdio.h>
#include <stdlib.h>

void saludar(void);
void despedir(void);
void brindar(void);


void queHago(void(*callback)(void));

int main()
{
    /*
    void (*pFunc) (void);//declaracion de un puntero a funcion

    pFunc = saludar;
    pFunc();//en vez de llamarla asi: saludar(); la llamo con un nombre que le puse yo, en este caso pFunc

    pFunc = despedir;
    pFunc();
    */

    queHago(saludar);//le paso de dir mem de saludar
    queHago(despedir);//le paso de dir mem de despedir
    queHago(brindar);//le paso de dir mem de brindar

    return 0;
}

void saludar(void)
{
    printf("\nHola\n");
}

void despedir(void)
{
    printf("\nChau\n");
}

void brindar(void)
{
    printf("\nChin Chin\n");
}

void queHago(void(*callback)(void))
{
    callback();
}

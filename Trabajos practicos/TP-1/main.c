#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int option;
    char cont = 'y';
    float a;
    float b;
    float su;
    float sub;
    float mult;
    float div;
    float factorialA;
    float factorialB;
    int flagA = 0;
    int flagB = 0;
    int calculated = 0;


    do{
        option = getMenuOption(flagA, flagB, a, b);

        switch(option)
        {
            case 1:
                a = getFloat("\nIngrese un operando: ", a);
                flagA = 1;
                break;
            case 2:
                b = getFloat("\nIngrese un operando: ", b);
                flagB = 1;
                break;
            case 3:
                if(flagA == 0 || flagB == 0)
                {
                    system("cls");
                    printf("\nEs necesario ingresar dos operandos para realizar los calculos");
                }
                else
                {
                    system("cls");
                    su = sum(a, b);
                    sub = subtraction(a, b);
                    mult = multiplication(a, b);
                    div = division(a, b);
                    factorialA = factorial(a);
                    factorialB = factorial(b);
                    calculated = 1;
                    printf("\nSe realizaron todas las operaciones");
                }
                break;
            case 4:
                if(flagA == 0 || flagB == 0)
                {
                    system("cls");
                    printf("\nEs necesario ingresar dos operandos para mostrar los resultados");
                }
                else if(calculated == 0)
                {
                    system("cls");
                    printf("\nEs necesario calcular para mostrar los resultados");
                }
                else
                {
                    showResults(su, sub, mult, div, factorialA, factorialB);
                }
                break;
            case 5:
                printf("\nSaliendo...\n");
                cont = 'n';
                break;
            default:
                system("cls");
                printf("\nEl numero de opcion no es valido. Ingrese nuevamente\n\n");
                break;
        }

    }while(cont == 'y');

    return 0;
}

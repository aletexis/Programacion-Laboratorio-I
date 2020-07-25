#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

/** \brief Muestra las opciones del menu dando la posibilidad de modificarlas y le permite al usuario ingresar una opcion
 *
 * \param flagA int Bandera que nos indica si se ingreso un numero
 * \param flagB int Bandera que nos indica si se ingreso un numero
 * \param a float El numero agregado
 * \param b float El numero agregado
 * \return int La opcion seleccionada
 *
 */
int getMenuOption(int flagA, int flagB, float a, float b)
{
    int option;

    printf("\n\n\t\t************** CALCULADORA **************\n\t\t\n");
    if(flagA == 1)
    {
        printf("\t\t    1. Ingresar 1er operando (A=%.2f)\n", a);
    }
    else
    {
        printf("\t\t    1. Ingresar 1er operando (A=x)\n");
    }

    if(flagB == 1)
    {
      printf("\t\t    2. Ingresar 2do operando (B=%.2f)\n", b);
    }
    else
    {
        printf("\t\t    2. Ingresar 2do operando (B=y)\n");
    }

    printf("\t\t    3. Calcular todas las operaciones\n");
    printf("\t\t    4. Informar resultados\n");
    printf("\t\t    5. Salir\n\t\t\n");
    printf("\t\t*****************************************\n");

    printf("\n\nIngrese una opcion: ");
    scanf("%d", &option);

    return option;
}

/** \brief Solicita un numero flotante al usuario
 *
 * \param message[] char El mensaje a mostrar
 * \param number float El numero ingresado
 * \return float El numero ingresado por el usuario.
 *
 */
float getFloat(char message[], float number)
{
    printf("%s", message);
    scanf("%f", &number);
    system("cls");
    printf("\nEl operando registrado es: %.2f", number);

    return number;
}

/** \brief Calcula la suma de dos numeros
 *
 * \param a float el primer numero a sumar
 * \param b float el segundo numero a sumar
 * \return float el resultado de la suma
 *
 */
float sum(float a, float b)
{
    float sum;

    sum = a + b;

    return sum;
}

/** \brief Calcula la resta de dos numeros
 *
 * \param a float el primer numero a restar
 * \param b float el segundo numero a restar
 * \return float el resultado de la resta
 *
 */
float subtraction (float a, float b)
{
    float subtraction;

    subtraction = a - b;

    return subtraction;
}

/** \brief Calcula la multiplicacion de dos numeros
 *
 * \param a float el primer numero a multiplicar
 * \param b float el segundo numero a multiplicar
 * \return float el resultado de la multiplicacion
 *
 */
float multiplication (float a, float b)
{
    float multiplication;

    multiplication = a * b;

    return multiplication;
}

/** \brief Calcula la division de dos numeros
 *
 * \param a float el primer numero que representa el dividendo
 * \param b float el segundo numero que representa el divisor
 * \return float el resultado de la division
 *
 */
float division (float a, float b)
{
    float division;

    if(b == 0)
    {
        division = 0;
    }
    else
    {
        division = a / b;
    }

    return division;
}

/** \brief Calcula el factorial de un numero
 *
 * \param number float el numero a calcular
 * \return float El resultado del factorial
 * No fue posible realizar el factorial de numeros flotantes
 */
float factorial(float number)
{
    float result;

    if(number < 0)
    {
        result = 0;
    }
    else if(number == 0)
    {
        result = 1;
    }
    else
    {
        result = number * factorial(number - 1);
    }

    return result;
}

/** \brief Muestra los resultados de todas las operaciones
 *
 * \param sum float el resultado de la suma
 * \param subtraction float el resultado de la resta
 * \param multiplication float el resultado de la multiplicacion
 * \param division float el resultado de la division
 * \param factorialA float el resulado del factorial de un numero
 * \param factorialB float el resulado del factorial de otro numero
 * \return void
 *
 */
void showResults(float sum, float subtraction, float multiplication, float division, float factorialA, float factorialB)
{
    system("cls");
    printf("\nEl resultado de A+B es:  %.2f", sum);
    printf("\nEl resultado de A-B es:  %.2f", subtraction);
    printf("\nEl resultado de A*B es:  %.2f", multiplication);

    if(division == 0)
    {
        printf("\nNo es posible dividir por cero");
    }
    else
    {
        printf("\nEl resultado de A/B es:  %.2f", division);
    }

    if(factorialA < 0 || factorialB < 0)
    {
        printf("\nNo es posible obtener el factorial de numeros negativos\n");
    }
    else
    {
        printf("\nEl factorial de A es: %.2f", factorialA);
        printf("\nEl factorial de B es: %.2f", factorialB);
    }
}

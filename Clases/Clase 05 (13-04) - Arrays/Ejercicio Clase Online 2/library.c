#include <stdio.h>
#include <stdlib.h>
#include "library.h"

/** \brief Muestra en pantalla el vector en forma ascendente
 *
 * \param array[] int El vector a mostrar
 * \param size int El tamaño del vector
 * \return void
 *
 */
void showArrayUp(int array[], int size)
{
    printf("\n");

    for(int i=0; i<size; i++)
    {
        printf(" %d", array[i]);
    }
}

/** \brief Muestra en pantalla el vector en forma descendente
 *
 * \param array[] int El vector a mostrar
 * \param size int El tamaño del vector
 * \return void
 *
 */
void showArrayDown(int array[], int size)
{
    printf("\n");

    for(int i=size-1; i>=0; i--)
    {
        printf(" %d", array[i]);
    }
}

/** \brief Busca el numero maximo en un vector
 *
 * \param numbers[] int El vector donde se realiza la busqueda
 * \param size int El tamaño del vector
 * \return int El maximo encontrado
 *
 */
int getMax(int numbers[], int size)
{
    int max = numbers[0];

    for(int i=1; i<size; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    return max;
}

/** \brief Calcula el promedio de los valores de un vector
 *
 * \param numbers[] int El vector donde estan guardados los valores
 * \param size int El tamaño del vector
 * \return float El promedio calculado
 *
 */
float getAverage(int numbers[], int size)
{
    int accumulator = 0;
    float average;

    for(int i=0; i<size; i++)
    {
        accumulator = accumulator + numbers[i];
    }

    average = (float) accumulator / size;

    return average;
}

/** \brief Busca un numero en el vector e informa cuantas veces esta
 *
 * \param array[] int El vector en el que se realiza la busqueda
 * \param size int El tamaño del vector
 * \return void
 *
 */
void searchNumber(int array[], int size)
{
    int number;
    int timesCounter = 0;

    printf("\n\nIngrese un numero a buscar: ");
    scanf("%d", &number);

    for(int i=0; i<size; i++)
    {
        if(array[i] == number)
        {
            timesCounter ++;
        }
    }

    if(timesCounter == 0)
    {
        printf("\nEl numero %d no esta en el array", number);
    }
    else if (timesCounter == 1)
    {
        printf("\nEl numero %d esta %d vez en el array", number, timesCounter);
    }
    else
    {
        printf("\nEl numero %d esta %d veces en el array", number, timesCounter);
    }
}

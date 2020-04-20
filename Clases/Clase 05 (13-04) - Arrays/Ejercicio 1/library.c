#include <stdio.h>
#include <stdlib.h>
#include "library.h"

/** \brief Busca el numero maximo en un vector
 *
 * \param numbers[] int El vector donde se realiza la busqueda
 * \param size int El tamaño del vector
 * \return int El maximo encontrado
 *
 */
int getMax(int numbers[], int size)
{
    int max;
    int flag = 0;

    for(int i=0; i<size; i++)
    {
        if(numbers[i] > max || flag == 0)
        {
            max = numbers[i];
            flag = 1;
        }
    }

    return max;
}

/** \brief Busca el numero minimo en un vector
 *
 * \param numbers[] int El vector donde se realiza la busqueda
 * \param size int El tamaño del vector
 * \return int El minimo encontrado
 *
 */
int getMin(int numbers[], int size)
{
    int min;
    int flag = 0;

    for(int i=0; i<size; i++)
    {
        if(numbers[i] < min || flag == 0)
        {
            min = numbers[i];
            flag = 1;
        }
    }

    return min;
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

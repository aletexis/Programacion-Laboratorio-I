#include <stdio.h>
#include <stdlib.h>
#include "library.h"


/** \brief Busca un entero dentro de un array de enteros
 *
 * \param int number El valor a buscar
 * \param [] int array El vector donde se realiza la busqueda
 * \param int size EL tamaño del vector
 * \return int El indice del elemento donde se encuentra el numero o -1 si no esta
 *
 */
int searchNumber(int number, int array[], int size)
{
    int ret = -1;

    for(int i=0; i<size; i++)
    {
        if(array[i] == number)
        {
            ret = i;
            break;
        }
    }

    return ret;
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

/** \brief Busca el numero minimo en un vector
 *
 * \param numbers[] int El vector donde se realiza la busqueda
 * \param size int El tamaño del vector
 * \return int El minimo encontrado
 *
 */
int getMin(int numbers[], int size)
{
    int min = numbers[0];

    for(int i=1; i<size; i++)
    {
        if(numbers[i] < min)
        {
            min = numbers[i];
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

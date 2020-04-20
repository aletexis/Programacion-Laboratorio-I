#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void showIntArray(int[], int);
void sortInt(int[], int, int);

int main()
{
    int vec[] = {8,5,9,2,4};

    showIntArray(vec, SIZE);
    sortInt(vec, SIZE, 0);
    showIntArray(vec, SIZE);

    return 0;
}

/** \brief Muestra un vector de enteros
 *
 * \param array[] int El array a mostrar
 * \param size int El tamaño del array
 * \return void
 *
 */
void showIntArray(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}

/** \brief Ordena los elementos de un vector con numeros enteros
 *
 * \param array[] int El array a ordenar
 * \param size int El tamaño del vector
 * \param mode int El criterio de ordenamiento, 0 es ascendente y 1 descendente
 * \return void
 *
 */
void sortInt(int array[], int size, int mode)
{
    int aux;

    if(mode == 0)
    {
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if(array[i] > array[j]) //criterio de ordenamiento
                {
                    aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
                }
            }
        }
    }
    else if(mode == 1)
    {
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if(array[i] < array[j]) //criterio de ordenamiento
                {
                    aux = array[j];
                    array[j] = array[i];
                    array[i] = aux;
                }
            }
        }
    }
}

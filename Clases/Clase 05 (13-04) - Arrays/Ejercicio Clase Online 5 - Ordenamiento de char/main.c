#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void showCharArray(char[], int);
void sortChar(char[], int, int);

int main()
{
    char vec[] = {'z', 'a', 'c', 't', 'r', 'a', 'f'};

    showCharArray(vec, SIZE);
    sortChar(vec, SIZE, 0);
    showCharArray(vec, SIZE);

    return 0;
}

/** \brief Muestra un vector de caracteres
 *
 * \param array[] int El array a mostrar
 * \param size int El tamaño del array
 * \return void
 *
 */
void showCharArray(char array[], int size)
{
    for(int i=0; i<size; i++)
    {
        printf(" %c", array[i]);
    }
    printf("\n");
}

/** \brief Ordena los elementos de un vector con caracteres
 *
 * \param array[] int El array a ordenar
 * \param size int El tamaño del vector
 * \param mode int El criterio de ordenamiento, 0 es ascendente y 1 descendente
 * \return void
 *
 */
void sortChar(char array[], int size, int mode)
{
    char aux;

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

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Bicicleta.h"

/** \brief Parsea los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param list LinkedList* La lista de paises
 * \return int (1) si pudo parsear los datos (-1) si no pudo
 *
 */
int parser_Bicicleta_FromText(FILE* pFile, LinkedList* list)
{
    int ok = -1;
    int r;

    /****/
    char idStr[50];
    char nombreStr[128];
    char tipoStr[128];
    char tiempoStr[50];
    /****/

    eBicicleta* newBicicleta = NULL;

    if(pFile != NULL && list != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, tipoStr, tiempoStr);

        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, tipoStr, tiempoStr);
            if(r == 4)
            {
                newBicicleta = bicicleta_newParametersStr(idStr, nombreStr, tipoStr, tiempoStr);
                if(newBicicleta != NULL)
                {
                    ll_add(list, newBicicleta);
                    ok = 1;
                }
            }
            else
            {
                break;
            }
        }
    }
    return ok;
}

/** \brief Parsea los datos los datos de los paises desde el archivo data.csv (modo binario).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param list LinkedList* La lista de paises
 * \return int (1) si pudo parsear los datos (-1) si no pudo
 *
 */
int parser_Bicicleta_FromBinary(FILE* pFile, LinkedList* list)
{
    int ok = -1;
    int r;
    eBicicleta* newBicicleta = NULL;

    if(pFile != NULL && list != NULL)
    {
        while(!feof(pFile))
        {
            newBicicleta = bicicleta_new();

            if(newBicicleta != NULL)
            {
                r = fread(newBicicleta, sizeof(newBicicleta), 1, pFile);
            }
            if(r < 1)
            {
                break;
            }
            ll_add(list, newBicicleta);
            ok = 1;
        }
    }

    return ok;
}

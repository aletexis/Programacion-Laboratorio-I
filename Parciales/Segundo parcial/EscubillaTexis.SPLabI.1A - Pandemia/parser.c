#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Country.h"

/** \brief Parsea los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param list LinkedList* La lista de paises
 * \return int (1) si pudo parsear los datos (-1) si no pudo
 *
 */
int parser_Country_FromText(FILE* pFile, LinkedList* list)
{
    int ok = -1;
    int r;

    /****/
    char idStr[50];
    char nombreStr[128];
    char recuperadosStr[50];
    char infectadosStr[50];
    char muertosStr[50];
    /****/

    Country* newCountry = NULL;

    if(pFile != NULL && list != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, recuperadosStr, infectadosStr, muertosStr);

        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr, nombreStr, recuperadosStr, infectadosStr, muertosStr);
            if(r == 5)
            {
                newCountry = country_newParametersStr(idStr, nombreStr, recuperadosStr, infectadosStr, muertosStr);
                if(newCountry != NULL)
                {
                    ll_add(list, newCountry);
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
int parser_Country_FromBinary(FILE* pFile, LinkedList* list)
{
    int ok = -1;
    int r;
    Country* newCountry = NULL;

    if(pFile != NULL && list != NULL)
    {
        while(!feof(pFile))
        {
            newCountry = country_new();

            if(newCountry != NULL)
            {
                r = fread(newCountry, sizeof(newCountry), 1, pFile);
            }
            if(r < 1)
            {
                break;
            }
            ll_add(list, newCountry);
            ok = 1;
        }
    }

    return ok;
}

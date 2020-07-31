#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Bicicleta.h"
#include "Controller.h"
#include "parser.h"
#include "validations.h"
#include "menu.h"
#include "extras.h"


/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param list LinkedList* La lista de bicicletas
 * \return int (1) si se cargo el archivo (-1) si no se cargo
 *
 */
int controller_loadFromText(char* path, LinkedList* list)
{
    int ret = -1;
    FILE* pFile;

    if(path != NULL && list != NULL)
    {
        if((pFile = fopen(path, "r")) != NULL)
        {
            if(parser_Bicicleta_FromText(pFile, list) == 1)
            {
                printf("\n\n\t>>> Archivo cargado exitosamente <<<\n\n");
                ret = 1;
            }
        }
        else
        {
            printf("\n\n\t>>> Error al cargar el archivo <<<\n\n");
        }
        fclose(pFile);
    }

    return ret;
}
/** \brief Carga los datos desde el archivo data.csv (modo binario).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param list LinkedList* La lista de bicicletas
 * \return int (1) si se cargo el archivo (-1) si no se cargo
 *
 */
int controller_loadFromBinary(char* path, LinkedList* list)
{
    int ret = -1;
    FILE* pFile;

    if(path != NULL && list != NULL)
    {
        if((pFile = fopen(path, "rb")) != NULL)
        {
            if(parser_Bicicleta_FromBinary(pFile, list) == 1)
            {
                printf("\n\n\t>>> Archivo cargado exitosamente <<<\n\n");
                ret = 1;
            }
        }
        else
        {
            printf("\n\n\t>>> Error al cargar el archivo <<<\n\n");
        }
        fclose(pFile);
    }

    return ret;
}


/** \brief Lista bicicletas
 *
 * \param list LinkedList* La lista de bicicletas
 * \return int (1) si se listaron los bicicletas (-1) si no se listaron
 *
 */
int controller_list(LinkedList* list)
{
    int ret = -1;
    int flag = 0;
    eBicicleta* auxeBicicleta;

    if(list != NULL)
    {
        ret = 1;
        printf("\n");
        printf("\n\t\t _______________________________________________________________________\n");
        printf("\n\t\t     ID                  NOMBRE                TIPO         TIEMPO         ");
        printf("\n\t\t _______________________________________________________________________\n\n");

        for(int i=0; i<ll_len(list); i++)
        {
            auxeBicicleta = (eBicicleta*)ll_get(list, i);
            if(auxeBicicleta != NULL)
            {
                bicicleta_printOne(auxeBicicleta);
                flag = 1;
            }
        }

        printf("\n\t\t _______________________________________________________________________\n\n");
        if(flag == 0)
        {
            printf("\n\n\t>>> No hay bicicletas para mostrar <<<\n\n");
        }
        printf("\n\n");
    }

    return ret;
}
/** \brief Ordena los bicicletas
 *
 * \param list LinkedList* La lista a ordenar
 * \param sortBy int El numero del campo a ordenar. Sigue el orden de como aparecen en la estructura
 * \param order int El orden (1) ascendente (0) descendente
 * \return int (1) si ordeno exitosamente (-1) si no pudo
 *
 */
int controller_sortParam(LinkedList* list, int sortBy, int order)
{
    int ret = -1;

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            switch(sortBy)
            {
                case 5:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, bicicleta_sortByTipoYTiempo, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
            }
            ret = 1;
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    return ret;
}


/** \brief Guarda los datos de los bicicletas en el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param list LinkedList* La lista de bicicletas a guardar
 * \return int (1) si se guardaron bicicletas (-1) si no se guardaron
 *
 */
int controller_saveAsText(char* path, LinkedList* list)
{
    eBicicleta* auxeBicicleta;
    FILE* pFile = fopen(path, "w");
    int size = ll_len(list);
    int ret = -1;

    /*********/
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;
    /*********/


    if(pFile == NULL)
    {
        printf("\n\n\t>>> Error al guardar el archivo <<<\n\n");
    }

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            fprintf(pFile, "id,nombre,tipo,tiempo\n");

            for(int i=0; i<size; i++)
            {
                auxeBicicleta = (eBicicleta*)ll_get(list, i);

                bicicleta_getId(auxeBicicleta,&id);
                bicicleta_getNombre(auxeBicicleta,nombre);
                bicicleta_getTipo(auxeBicicleta,tipo);
                bicicleta_getTiempo(auxeBicicleta,&tiempo);

                fprintf(pFile, "%d,%s,%s,%d\n",id,nombre,tipo,tiempo);
            }
            printf("\n\n\t>>> Archivo guardado exitosamente <<<\n\n");
            ret = 1;
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    fclose(pFile);

    return ret;
}
/** \brief Guarda los datos de bicicletas en el archivo data.csv (modo binario).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param list LinkedList* La lista de bicicletas a guardar
 * \return int (1) si se guardaron los bicicletas (-1) si no se guardaron
 *
 */
int controller_saveAsBinary(char* path, LinkedList* list)
{
    eBicicleta* auxeBicicleta;
    FILE* pFile = fopen(path, "wb");
    int size = ll_len(list);
    int ret = -1;


    if(pFile == NULL)
    {
        printf("\n\n\t>>> Error al guardar el archivo <<<\n\n");
    }

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            for(int i=0; i<size; i++)
            {
                auxeBicicleta = (eBicicleta*)ll_get(list, i);
                fwrite(auxeBicicleta, sizeof(eBicicleta), 1, pFile);

            }
            printf("\n\n\t>>> Archivo guardado exitosamente <<<\n\n");
            ret = 1;
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    fclose(pFile);

    return ret;
}




/** \brief Filtra las bicicletas por BMX
 *
 * \param element void* La bicicleta a filtrar en el caso de que cumpla el criterio
 * \return int (1) si se filtro la bicicleta (-1) si no se filtro
 *
 */
int controller_filterBMX(void* element)
{
    int ret = -1;
    eBicicleta* bicicleta = NULL;
    char tipo[128];

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("BMX", tipo) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}

/** \brief Filtra las bicicletas por Playera
 *
 * \param element void* La bicicleta a filtrar en el caso de que cumpla el criterio
 * \return int (1) si se filtro la bicicleta (-1) si no se filtro
 *
 */
int controller_filterPlayera(void* element)
{
    int ret = -1;
    eBicicleta* bicicleta = NULL;
    char tipo[128];

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("PLAYERA", tipo) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}

/** \brief Filtra las bicicletas por MTB
 *
 * \param element void* La bicicleta a filtrar en el caso de que cumpla el criterio
 * \return int (1) si se filtro la bicicleta (-1) si no se filtro
 *
 */
int controller_filterMTB(void* element)
{
    int ret = -1;
    eBicicleta* bicicleta = NULL;
    char tipo[128];

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("MTB", tipo) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}

/** \brief Filtra las bicicletas por Paseo
 *
 * \param element void* La bicicleta a filtrar en el caso de que cumpla el criterio
 * \return int (1) si se filtro la bicicleta (-1) si no se filtro
 *
 */
int controller_filterPaseo(void* element)
{
    int ret = -1;
    eBicicleta* bicicleta = NULL;
    char tipo[128];

    if(element != NULL)
    {
        bicicleta = (eBicicleta*) element;
        bicicleta_getTipo(bicicleta, tipo);
        if(strcmp("PASEO", tipo) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}

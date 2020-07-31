#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Country.h"
#include "Controller.h"
#include "parser.h"
#include "validations.h"
#include "menu.h"
#include "extras.h"


/** \brief Obtiene un id guardado en un archivo
 *
 * \param id int* Donde se guardara el id obtenido
 * \return int (0) si lo obtuvo (1) en caso de error
 *
 */
int getID(int* id)
{
    int error = 1;
    *id = 1001;
    FILE* f = fopen("proximoId.bin", "rb");//si es la primera vez que ejecuto el programa no existe el archivo
                                           //fopen va a devolver NULL, no entra al if y el id va a ser 1000
    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);//si existe piso el 1000 con el id disponible en el archivo
        fclose(f);
        error = 0;
    }
    return error;
}

/** \brief Actualiza y guarda el ultimo id utilizado
 *
 * \param id int El ultimo id que se utilizo
 * \return int (0) si lo actualizo (1) en caso de error
 *
 */
int updateID(int id)
{
    int error = 1;
    id++;//incrementa el ultimo id que se uso ya que sera el proximo disponible para usar
    FILE* f = fopen("proximoId.bin", "wb");

    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);
        fclose(f);
        error = 0;
    }
    return error;
}


/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param list LinkedList* La lista de paises
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
            if(parser_Country_FromText(pFile, list) == 1)
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
 * \param list LinkedList* La lista de paises
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
            if(parser_Country_FromBinary(pFile, list) == 1)
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

/** \brief Agrega un **********
 *
 * \param list LinkedList* La lista de paises
 * \return int (1) si se agrego un pais (-1) si no se agrego
 *
 */
int controller_add(LinkedList* list)
{
    Country* newCountry = country_new();
    int ret = -1;

    /********/
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
    /********/


    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            system("clear");
            printf("\n\t*** ALTA ******************************************************\n\n");

            getID(&id);

            if(! (validations_getText(nombre,"\n\tIngrese nombre del pais: ", "\n\t(!) Error. Caracteres invalidos.\n", 3, 128, 4)) &&
               ! (validations_getUnsignedInt(&recuperados,"\n\tIngrese cantidad de recuperados: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,999999999,1,999999999,4)) &&
               ! (validations_getUnsignedInt(&infectados,"\n\tIngrese cantidad de infectados: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,999999999,1,999999999,4)) &&
               ! (validations_getUnsignedInt(&muertos,"\n\tIngrese cantidad de muertos: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,999999999,1,999999999,4)))

            {
                newCountry = country_newParameters(id, nombre, recuperados, infectados, muertos);
                ll_add(list,newCountry);
                printf("\n\n\t>>> Pais dado de alta exitosamente <<<\n\n");
                ret = 1;
            }

            updateID(id);
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Modifica un **********
 *
 * \param list LinkedList* La lista de **********
 * \return int (1) si se modifico el ********** (-1) si no se modifico
 *
 */
int controller_edit(LinkedList* list)
{
    Country* auxCountry;
    int index = -1;
    int ret = -1;

    /********/
    int id;
    char newNombre[128];
    int newRecuperados;
    int newInfectados;
    int newMuertos;
    /********/

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            system_clear("linux");
            printf("\n\t*** MODIFICACION *******************************************************\n\n");

            controller_list(list);

            validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,999999,1,999999,4);

            controller_country_findOne(list, id, &index);

            if(index == -1)
            {
                printf("\n\n\t\t>>> No hay registro de un pais con el ID %d <<<\n\n\n", id);
            }
            else
            {
                auxCountry = (Country*)ll_get(list, index);
                system_clear("linux");
                printf("\n\t\tEl pais que se modificara es:");
                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID           NOMBRE         RECUPERADOS       INFECTADOS      MUERTOS     ");
                printf("\n\t\t ___________________________________________________________\n");
                country_printOne(auxCountry);
                printf("\n\t\t ___________________________________________________________\n\n");


                switch(menu_modify())
                {
                    case 1:
                        validations_getText(newNombre,"\n\tIngrese nuevo nombre del pais: ", "\n\t(!) Error. Caracteres invalidos.\n", 3, 128, 4);
                        if(confirm(5,0))
                        {
                            country_setNombre(auxCountry, newNombre);
                        }
                        break;
                    case 2:
                        validations_getUnsignedInt(&newRecuperados,"\n\tIngrese nueva cantidad de recuperados: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,999999999,1,999999999,4);
                        if(confirm(5,0))
                        {
                            country_setRecuperados(auxCountry, newRecuperados);
                        }
                        break;
                    case 3:
                        validations_getUnsignedInt(&newInfectados,"\n\tIngrese nueva cantidad de infectados: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,999999999,1,999999999,4);
                        if(confirm(5,0))
                        {
                            country_setRecuperados(auxCountry, newInfectados);
                        }
                        break;
                    case 4:
                       validations_getUnsignedInt(&newMuertos,"\n\tIngrese nueva cantidad de muertos: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,999999999,1,999999999,4);
                        if(confirm(5,0))
                        {
                            country_setRecuperados(auxCountry, newMuertos);
                        }
                        break;
                }

                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID           NOMBRE         RECUPERADOS       INFECTADOS      MUERTOS     ");
                printf("\n\t\t ___________________________________________________________\n");
                country_printOne(auxCountry);
                printf("\n\t\t ___________________________________________________________\n\n");

                system_pause("linux");
                ret = 1;
            }
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Elimina un pais
 *
 * \param list LinkedList* La lista de paises
 * \return int (1) si se elimino el pais (-1) si no se elimino
 *
 */
int controller_remove(LinkedList* list)
{
    Country* auxCountry;
    int index = -1;
    int id;
    int ret = -1;


    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            system_clear("linux");
            printf("\n\t*** BAJA *******************************************************\n\n");

            controller_list(list);

            validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,999999,1,999999,4);

            controller_country_findOne(list, id, &index);

            if(index == -1)
            {
                printf("\n\n\t\t>>> No hay registro de ******************** con el ID: %d <<<\n\n\n", id);
            }
            else
            {
                auxCountry = (Country*)ll_get(list, index);
                system_clear("linux");
                printf("\n\t\t******************** que se dara de baja es:");
                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID           NOMBRE         RECUPERADOS       INFECTADOS      MUERTOS     ");
                printf("\n\t\t ___________________________________________________________\n");
                country_printOne(auxCountry);
                printf("\n\t\t ___________________________________________________________\n\n");

                if(confirm(4,0))
                {
                    ll_remove(list, index);
                    country_delete(auxCountry);
                }
                ret = 1;
            }
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Lista paises
 *
 * \param list LinkedList* La lista de paises
 * \return int (1) si se listaron los paises (-1) si no se listaron
 *
 */
int controller_list(LinkedList* list)
{
    int ret = -1;
    int flag = 0;
    Country* auxCountry;

    if(list != NULL)
    {
        ret = 1;
        printf("\n");
        printf("\n\t\t ___________________________________________________________________________________\n");
        printf("\n\t\t     ID               NOMBRE         RECUPERADOS       INFECTADOS        MUERTOS     ");
        printf("\n\t\t ___________________________________________________________________________________\n\n");

        for(int i=0; i<ll_len(list); i++)
        {
            auxCountry = (Country*)ll_get(list, i);
            if(auxCountry != NULL)
            {
                country_printOne(auxCountry);
                flag = 1;
            }
        }

        printf("\n\t\t ___________________________________________________________________________________\n\n");
        if(flag == 0)
        {
            printf("\n\n\t>>> No hay paises para mostrar <<<\n\n");
        }
        printf("\n\n");
    }

    return ret;
}


/** \brief Ordena los paises
 *
 * \param list LinkedList* La lista de paises
 * \return int (1) si se ordenaron los paises (-1) si no se ordenaron
 *
 */
int controller_sortMenu(LinkedList* list)
{
    int ret = -1;
    int order;

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            switch(menu_sort())
            {
                case 1:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortById, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 2:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByNombre, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 3:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByRecuperados, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 4:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByInfectados, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 5:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByMuertos, order);
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

/** \brief Ordena los paises
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
                case 1:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortById, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 2:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByNombre, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 3:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByRecuperados, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 4:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByInfectados, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 5:
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(list, country_sortByMuertos, order);
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

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param list LinkedList* La lista de paises a guardar
 * \return int (1) si se guardaron paises (-1) si no se guardaron
 *
 */
int controller_saveAsText(char* path, LinkedList* list)
{
    Country* auxCountry;
    FILE* pFile = fopen(path, "w");
    int size = ll_len(list);
    int ret = -1;

    /*********/
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
    /*********/


    if(pFile == NULL)
    {
        printf("\n\n\t>>> Error al guardar el archivo <<<\n\n");
    }

    if(ll_isEmpty(list) == 0)
    {
        if(list != NULL)
        {
            fprintf(pFile, "id,nombre,recuperados,infectados,muertos\n");

            for(int i=0; i<size; i++)
            {
                auxCountry = (Country*)ll_get(list, i);

                country_getId(auxCountry,&id);
                country_getNombre(auxCountry,nombre);
                country_getRecuperados(auxCountry,&recuperados);
                country_getInfectados(auxCountry,&infectados);
                country_getMuertos(auxCountry,&muertos);

                fprintf(pFile, "%d,%s,%d,%d,%d\n",id,nombre,recuperados,infectados,muertos);
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

/** \brief Guarda los datos de paises en el archivo data.csv (modo binario).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param list LinkedList* La lista de paises a guardar
 * \return int (1) si se guardaron los paises (-1) si no se guardaron
 *
 */
int controller_saveAsBinary(char* path, LinkedList* list)
{
    Country* auxCountry;
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
                auxCountry = (Country*)ll_get(list, i);
                fwrite(auxCountry, sizeof(Country), 1, pFile);

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


/** \brief Busca un pais
 *
 * \param list LinkedList* La lista de paises
 * \param id int El ID del pais a buscar
 * \param index int* El indice que indica la posicion del pais en la lista
 * \return int (1) si se encontro el pais (-1) si no se encontro
 *
 */
int controller_country_findOne(LinkedList* list, int id, int* index)
{
    int ret = -1;
    int size;
    int auxId;
    Country* auxCountry;

    if(list != NULL)
    {
        size = ll_len(list);

        for(int i=0; i<size; i++)
        {
            auxCountry = (Country*)ll_get(list, i);
            country_getId(auxCountry, &auxId);

            if(auxCountry != NULL && id == auxId)
            {
                *index = i;
                ret = 1;
                break;
            }
        }
    }

    return ret;
}


/** \brief Funcion que se le llama en ll_filter para crear una nueva lista con los paises exitosos
 *
 * \param Recibe el puntero al elemento para determinar el filtro
 * \return Retorna 1 en caso de que deba ser agregado a la nueva LL
 *
 */
int controller_filterBySuccess(void* element)
{
    int ret = -1;
    Country* country = NULL;
    int muertos;

    if(element != NULL)
    {
        country = (Country*) element;
        country_getMuertos(country, &muertos);
        if(muertos > 5000 && muertos < 8000)
        {
            ret = 1;
        }
    }

    return ret;
}

/** \brief Funcion que se le llama en ll_filter para crear una nueva lista con los paises complicados
 *
 * \param Recibe el puntero al elemento para determinar el filtro
 * \return Retorna 1 en caso de que deba ser agregado a la nueva LL
 *
 */
int controller_filterByFailure(void* element)
{
    int ret = -1;
    Country* country = NULL;
    int infectados;
    int recuperados;

    if(element != NULL)
    {
        country = (Country*) element;
        country_getInfectados(country, &infectados);
        country_getRecuperados(country, &recuperados);
        if(recuperados*3 <= infectados)
        {
            ret = 1;
        }
    }

    return ret;
}

int controller_paisConMasMuertos(LinkedList* list)
{
    int retorno = -1;
    Country* country = NULL;
    int cantidadMayor;
    int cantidadMuertos;
    int flag = 0;
    LinkedList* newList = NULL;
    newList = ll_newLinkedList();

    if(list != NULL && newList != NULL)
    {
        for(int i=0; i<ll_len(list); i++)
        {
        	country = (Country*) ll_get(list, i);
            country_getMuertos(country, &cantidadMuertos);
            if(flag == 0 || cantidadMuertos > cantidadMayor)
            {
            	cantidadMayor = cantidadMuertos;
				flag = 1;
            }
        }
        for(int i=0; i<ll_len(list); i++)
        {
        	country = (Country*) ll_get(list, i);
        	country_getMuertos(country, &cantidadMuertos);
        	if(cantidadMuertos == cantidadMayor)
        	{
        		ll_add(newList, country);
        		retorno = 0;
        	}
        }

        printf("\n\nPais/es con mas muertos: ");
        controller_list(newList);
    }

    return retorno;
}

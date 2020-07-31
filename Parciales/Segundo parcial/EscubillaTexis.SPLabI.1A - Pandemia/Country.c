#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "Country.h" /****************************/

/** \brief Genera espacio en memoria para guardar un **********
 *
 * \param void
 * \return Country* pCountry El puntero al **********
 *
 */
Country* country_new()
{
    Country* pCountry = (Country*)calloc(sizeof(Country), 1);
    return pCountry;
}

/** \brief Le asigna unos nuevos parametros al nuevo **********
 *
 * \param id int La variable a la que se le asigna el nuevo id
 * \param nombre char* La variable a la que se le asigna el nuevo **********
 * \param recuperados int La variable a la que se le asigna los nuevos **********
 * \param infectados int La variable a la que se le asigna los nuevos **********
 * \param muertos int La variable a la que se le asigna los nuevos **********
 * \return Country* El ********** con los datos cargados
 *
 */
Country* country_newParameters(int id, char* nombre, int recuperados, int infectados, int muertos)
{
    Country* newCountry = country_new();

    if(newCountry != NULL)
    {
        if(! (country_setId(newCountry, id) && country_setNombre(newCountry, nombre) && country_setRecuperados(newCountry, recuperados) && country_setInfectados(newCountry, infectados) && country_setMuertos(newCountry, muertos)))
        {
            free(newCountry);
            newCountry = NULL;
        }
    }

    return newCountry;
}

/** \brief Le asigna unos nuevos parametros al nuevo **********
 *
 * \param char* idStr La variable a la que se le asigna el nuevo id
 * \param char* nombreStr La variable a la que se le asigna el nuevo **********
 * \param char* recuperadosStr La variable a la que se le asigna los nuevos **********
 * \param char* infectadosStr La variable a la que se le asigna los nuevos **********
 * \param char* muertosStr La variable a la que se le asigna los nuevos **********
 * \return Country* El ********** con los datos cargados
 *
 */
Country* country_newParametersStr(char* idStr,char* nombreStr,char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    return country_newParameters(atoi(idStr), nombreStr, atoi(recuperadosStr), atoi(infectadosStr), atoi(muertosStr));
}

/** \brief Libera el espacio en memoria
 *
 * \param Country* El campo de la estructura que se desea liberar
 * \return void
 *
 */
void country_delete(Country* this)
{
    free(this);
}

/** \brief Establece un valor al campo id
 *
 * \param Country* El campo de la estructura donde se establecera el valor
 * \param int El id que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int country_setId(Country* this, int id)
{
    int ok = 0;

    if(this != NULL && id >=0) //valido que id sea positivo
    {
        this->id = id;
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo id
 *
 * \param Country* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int country_getId(Country* this, int* id)
{
    int ok = 0;

    if(this != NULL && id != NULL)
    {
       *id = this->id;
       ok = 1;

    }
    return ok;
}

/** \brief Establece un valor al campo nombre
 *
 * \param Country* El campo de la estructura donde se establecera el valor
 * \param char* El nombre que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int country_setNombre(Country* this, char* nombre)
{
    int ok = 0;

    if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) < 128)//valido que sea de un largo determinado
    {
        strcpy(this->nombre,nombre);
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo nombre
 *
 * \param Country* El campo de la estructura del que se desea obtener el valor
 * \param char* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int country_getNombre(Country* this,char* nombre)
{
    int ok = 0;

    if(this != NULL && nombre != NULL)
    {
       strcpy(nombre,this->nombre);
       ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo recuperados
 *
 * \param Country* El campo de la estructura donde se establecera el valor
 * \param int Los recuperados que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int country_setRecuperados(Country* this, int recuperados)
{
    int ok = 0;

    if(this != NULL && recuperados >=0)// valido que sea positivo
    {
      this->recuperados = recuperados;
      ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo recuperados
 *
 * \param Country* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int country_getRecuperados(Country* this, int* recuperados)
{
    int ok = 0;

    if(this != NULL && recuperados != NULL)
    {
      *recuperados = this->recuperados;
      ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo infectados
 *
 * \param Country* El campo de la estructura donde se establecera el valor
 * \param int Los infectados que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int country_setInfectados(Country* this, int infectados)
{
    int ok = 0;

    if(this != NULL && infectados >=0) //valido que sea positivo
    {
        this->infectados = infectados;
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo infectados
 *
 * \param Country* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int country_getInfectados(Country* this, int* infectados)
{
    int ok = 0;

    if(this != NULL && infectados != NULL)
    {
       *infectados = this->infectados;
       ok = 1;

    }
    return ok;
}

/** \brief Establece un valor al campo muertos
 *
 * \param Country* El campo de la estructura donde se establecera el valor
 * \param int Los muertos que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int country_setMuertos(Country* this, int muertos)
{
    int ok = 0;

    if(this != NULL && muertos >=0) //valido que sea positivo
    {
        this->muertos = muertos;
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo muertos
 *
 * \param Country* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int country_getMuertos(Country* this, int* muertos)
{
    int ok = 0;

    if(this != NULL && muertos != NULL)
    {
       *muertos = this->muertos;
       ok = 1;

    }
    return ok;
}



/** \brief Ordena los elementos por id
 *
 * \param void* element1 El primer elemento a comparar
 * \param void* element2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int country_sortById(void* country1, void* country2)
{
    int element1;
    int element2;
    int ret = 0;

    if ((country1 != NULL) && (country2 != NULL))
    {
        country_getId(country1, &element1);
        country_getId(country2, &element2);

        if(element1 > element2)
        {
            ret = 1;
        }
        else if(element1 < element2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por nombre
 *
 * \param void* country1 El primer elemento a comparar
 * \param void* country2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int country_sortByNombre(void* country1, void* country2)
{
    char element1[128];
    char element2[128];
    int ret = 0;
    int comparison;

    if(country1 != NULL && country2 != NULL)
    {
        country_getNombre(country1, element1);
        country_getNombre(country2, element2);
        comparison = strcmp(element1, element2);

        if(comparison > 0)
        {
            ret = 1;
        }
        else if(comparison < 0)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por recuperados
 *
 * \param void* country1 El primer elemento a comparar
 * \param void* country2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int country_sortByRecuperados(void* country1, void* country2)
{
    int element1;
    int element2;
    int ret = 0;

    if ((country1 != NULL) && (country2 != NULL))
    {
        country_getRecuperados(country1, &element1);
        country_getRecuperados(country2, &element2);

        if(element1 > element2)
        {
            ret = 1;
        }
        else if(element1 < element2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por infectados
 *
 * \param void* country1 El primer elemento a comparar
 * \param void* country2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int country_sortByInfectados(void* country1, void* country2)
{
    int element1;
    int element2;
    int ret = 0;

    if ((country1 != NULL) && (country2 != NULL))
    {
        country_getInfectados(country1, &element1);
        country_getInfectados(country2, &element2);

        if(element1 > element2)
        {
            ret = 1;
        }
        else if(element1 < element2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por muertos
 *
 * \param void* country1 El primer elemento a comparar
 * \param void* country2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int country_sortByMuertos(void* country1, void* country2)
{
    int element1;
    int element2;
    int ret = 0;

    if ((country1 != NULL) && (country2 != NULL))
    {
        country_getMuertos(country1, &element1);
        country_getMuertos(country2, &element2);

        if(element1 > element2)
        {
            ret = 1;
        }
        else if(element1 < element2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Muestra un solo pais y sus atributos
 *
 * \param Country* country El pais a mostrar
 * \return int (1) si pudo mostrarlos (0) si no pudo
 *
 */
int country_printOne(Country* country)
{
    int ok = 0;

    /********/
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
    /********/

    if(country != NULL)
    {
        country_getId(country,&id);
        country_getNombre(country,nombre);
        country_getRecuperados(country,&recuperados);
        country_getInfectados(country,&infectados);
        country_getMuertos(country,&muertos);

        printf("\t       %5d       %18s           %8d        %8d      %8d\n",id,nombre,recuperados,infectados,muertos);
        ok = 1;
    }

    return ok;
}



/** \brief Mapea los paises recuperados
 *
 * \param this void* El pais a mapear
 * \return int (1) si mapeo correctamente (0) si no pudo
 *
 */
void* country_map(void* this)
{
    this = (Country*)this;
    int aleatorio1;
    int aleatorio2;
    int aleatorio3;

    aleatorio1 = rand()%(100)+10;
    country_setRecuperados(this, aleatorio1);

    aleatorio2 = rand()%(1000)+101;
    country_setInfectados(this, aleatorio2);

    aleatorio3 = rand()%(10000)+1001;
    country_setMuertos(this, aleatorio3);

    return this;
}

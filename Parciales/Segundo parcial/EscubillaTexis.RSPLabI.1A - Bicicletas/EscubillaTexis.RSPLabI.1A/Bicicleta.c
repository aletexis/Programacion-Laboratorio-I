#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "Bicicleta.h"

/** \brief Genera espacio en memoria para guardar una bicicleta
 *
 * \param void
 * \return eBicicleta* peBicicleta El puntero a la bicicleta
 *
 */
eBicicleta* bicicleta_new()
{
    eBicicleta* peBicicleta = (eBicicleta*)calloc(sizeof(eBicicleta), 1);
    return peBicicleta;
}

/** \brief Le asigna unos nuevos parametros a la nueva bicicleta
 *
 * \param id int La variable a la que se le asigna el nuevo id
 * \param nombre char* La variable a la que se le asigna el nuevo nombre
 * \param tipo int La variable a la que se le asigna los nuevos tipo
 * \param tiempo int La variable a la que se le asigna los nuevos tiempo
 * \return eBicicleta* La bicicleta con los datos cargados
 *
 */
eBicicleta* bicicleta_newParameters(int id, char* nombre, char* tipo, int tiempo)
{
    eBicicleta* neweBicicleta = bicicleta_new();

    if(neweBicicleta != NULL)
    {
        if(! (bicicleta_setId(neweBicicleta, id) && bicicleta_setNombre(neweBicicleta, nombre) && bicicleta_setTipo(neweBicicleta, tipo) && bicicleta_setTiempo(neweBicicleta, tiempo)))
        {
            free(neweBicicleta);
            neweBicicleta = NULL;
        }
    }

    return neweBicicleta;
}

/** \brief Le asigna unos nuevos parametros a la nueva bicicleta
 *
 * \param char* idStr La variable a la que se le asigna el nuevo id
 * \param char* nombreStr La variable a la que se le asigna el nuevo nombre
 * \param char* tipoStr La variable a la que se le asigna el nuevo tipo
 * \param char* tiempoStr La variable a la que se le asigna el nuevo tiempo
 * \return eBicicleta* La bicicleta con los datos cargados
 *
 */
eBicicleta* bicicleta_newParametersStr(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr)
{
    return bicicleta_newParameters(atoi(idStr), nombreStr, tipoStr, atoi(tiempoStr));
}

/** \brief Libera el espacio en memoria
 *
 * \param eBicicleta* El campo de la estructura que se desea liberar
 * \return void
 *
 */
void bicicleta_delete(eBicicleta* this)
{
    free(this);
}

/** \brief Establece un valor al campo id
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param int El id que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int bicicleta_setId(eBicicleta* this, int id)
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
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int bicicleta_getId(eBicicleta* this, int* id)
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
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param char* El nombre que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int bicicleta_setNombre(eBicicleta* this, char* nombre)
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
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param char* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int bicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int ok = 0;

    if(this != NULL && nombre != NULL)
    {
       strcpy(nombre,this->nombre);
       ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo tipo
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param int El tipo que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int bicicleta_setTipo(eBicicleta* this, char* tipo)
{
    int ok = 0;

    if(this != NULL && tipo != NULL && strlen(tipo) >= 3 && strlen(tipo) < 128)//valido que sea de un largo determinado
    {
        strcpy(this->tipo,tipo);
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo tipo
 *
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int ok = 0;

    if(this != NULL && tipo != NULL)
    {
       strcpy(tipo,this->tipo);
       ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo tiempo
 *
 * \param eBicicleta* El campo de la estructura donde se establecera el valor
 * \param int Los tiempo que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int bicicleta_setTiempo(eBicicleta* this, int tiempo)
{
    int ok = 0;

    if(this != NULL && tiempo >=0) //valido que sea positivo
    {
        this->tiempo = tiempo;
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo tiempo
 *
 * \param eBicicleta* El campo de la estructura del que se desea obtener el valor
 * \param int* Donde se guardara el valor
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int bicicleta_getTiempo(eBicicleta* this, int* tiempo)
{
    int ok = 0;

    if(this != NULL && tiempo != NULL)
    {
       *tiempo = this->tiempo;
       ok = 1;

    }
    return ok;
}



/** \brief Ordena los elementos por tipo y tiempo
 *
 * \param void* bicicleta1 El primer elemento a comparar
 * \param void* bicicleta2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int bicicleta_sortByTipoYTiempo(void* bicicleta1, void* bicicleta2)
{
    char elementChar1[128];
    char elementChar2[128];
    int elementInt1;
    int elementInt2;
    int ret = 0;
    int comparison;

    if(bicicleta1 != NULL && bicicleta2 != NULL)
    {
        bicicleta_getTipo(bicicleta1, elementChar1);
        bicicleta_getTipo(bicicleta2, elementChar2);

        comparison = strcmp(elementChar1, elementChar2);

        if(comparison > 0)
        {
            ret = 1;
        }
        else if(comparison < 0)
        {
            ret = -1;
        }
        else if(comparison == 0)
        {
            if ((bicicleta1 != NULL) && (bicicleta2 != NULL))
            {
                bicicleta_getTiempo(bicicleta1, &elementInt1);
                bicicleta_getTiempo(bicicleta2, &elementInt2);

                if(elementInt1 > elementInt2)
                {
                    ret = 1;
                }
                else if(elementInt1 < elementInt2)
                {
                    ret = -1;
                }
            }
        }
    }
    return ret;
}


/** \brief Muestra una sola bicicleta y sus atributos
 *
 * \param eBicicleta* bicicleta El pais a mostrar
 * \return int (1) si pudo mostrarlos (0) si no pudo
 *
 */
int bicicleta_printOne(eBicicleta* bicicleta)
{
    int ok = 0;

    /********/
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;
    /********/

    if(bicicleta != NULL)
    {
        bicicleta_getId(bicicleta,&id);
        bicicleta_getNombre(bicicleta,nombre);
        bicicleta_getTipo(bicicleta,tipo);
        bicicleta_getTiempo(bicicleta,&tiempo);

        printf("\t         %5d       %18s            %8s       %8d\n",id,nombre,tipo,tiempo);
        ok = 1;
    }

    return ok;
}



/** \brief Mapea las bicicletas por un tiempo aleatorio
 *
 * \param this void* La bicicleta a mapear
 * \return int (1) si mapeo correctamente (0) si no pudo
 *
 */
void* bicicleta_map(void* this)
{
    this = (eBicicleta*)this;
    int aleatorio;

    aleatorio = 50+rand()%(121-50);

    bicicleta_setTiempo(this, aleatorio);

    return this;
}

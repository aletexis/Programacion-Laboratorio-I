#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "extras.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* newList;

    newList = (LinkedList*) malloc(sizeof(LinkedList));

    if(newList != NULL)
    {
        newList->size = 0;
        newList->pFirstNode = NULL;
    }

    return newList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int quantity = -1;

    if(this != NULL)
    {
        quantity = this->size;
    }
    return quantity;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* node = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        node = this->pFirstNode;

        for(int i=0; i<nodeIndex; i++)
        {
            node = node->pNextNode;//apunto al nodo siguiente
        }
    }

    return node;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode;
    Node* previousNode;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode = (Node*) malloc(sizeof(Node));
        if(newNode != NULL)
        {
            newNode->pElement = pElement;
            newNode->pNextNode = NULL;

            if(nodeIndex == 0)
            {
                newNode->pNextNode = this->pFirstNode;//el nuevo nodo apunta al viejo 0
                this->pFirstNode = newNode; //engancho la lista al nuevo nodo ya que es el nuevo 0
            }
            else
            {
                previousNode = getNode(this, nodeIndex - 1);//consigo el nodo anterior
                newNode->pNextNode = previousNode->pNextNode;//el nuevo nodo apunta a lo que apuntaba el nodo que tengo atras
                previousNode->pNextNode = newNode;//el nodo que tengo atras apunta al nodo nuevo
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);//addNode valida el indice y que la lista != NULL
}

/** \brief Obtiene un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node = getNode(this, index);//getNode valida el indice y que la lista != NULL

    if(node != NULL)
    {
        returnAux = node->pElement;
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* node = getNode(this, index);//getNode valida el indice y que la lista != NULL

    if(node != NULL)
    {
        node->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodeToRemove = getNode(this,index);//getNode valida el indice y que la lista != NULL

    if(nodeToRemove != NULL)
    {
        if(index==0)
        {
            this->pFirstNode = nodeToRemove->pNextNode;
            free(nodeToRemove);
            this->size--;
            returnAux = 0;
        }

        Node* previousNode = getNode(this, index-1);

        if(previousNode != NULL)
        {
            previousNode->pNextNode = nodeToRemove->pNextNode;
            free(nodeToRemove);
            this->size--;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        for(int i=0; i<ll_len(this); i++)
        {
            Node* node = getNode(this, i);
            if(node != NULL && pElement == node->pElement)
            {
                returnAux = i;
                break;//para que me devuelva la primer ocurrencia
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;
        if(!ll_len(this))
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);//addNode valida el indice y que la lista != NULL
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);//no lo valido porque el elemento puede ser NULL

        if(ll_remove(this, index)== -1)
        {
            returnAux = NULL;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 0;

        int index = ll_indexOf(this, pElement);//busco en que index esta el pElement
        void* element = ll_get(this, index);//obtengo el pElement

        if(index != -1 && pElement == element)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;

        for(int i=0; i<ll_len(this2); i++)
        {
            if(!ll_contains(this, ll_get(this2, i)/*obtengo los pElement*/))
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* sublist = NULL;

    if(this != NULL && from >= 0 && from <= ll_len(this) && to > from && to <= ll_len(this))
    {
        sublist = ll_newLinkedList();

        if(sublist != NULL)
        {
            for(int i=from; i<to; i++)
            {
                void* element = ll_get(this, i);
                if(ll_add(sublist, element) == -1)
                {
                    sublist = NULL;
                }
            }
        }
    }

    return sublist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a las listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clonedList = NULL;

    if(this != NULL)
    {
        clonedList = ll_subList(this,0,ll_len(this));
    }

    return clonedList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int size = ll_len(this);
    void* auxElement;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if((order == 1 && pFunc(ll_get(this, i), ll_get(this, j))>0) ||
                   (order == 0 && pFunc(ll_get(this, i), ll_get(this, j))<0))
                {
                    auxElement = ll_get(this, i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, auxElement);
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;

}

/** \brief Filtra elementos de una lista
 *
 * \param LinkedList* La lista a filtrar
 * \param int (*pFunc)(void*) La funcion que establece el criterio de filtrado
 * \return LinkedList* newList La nueva lista filtrada
 *
 */
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;
    void* element = NULL;

    if(this != NULL && pFunc != NULL)
    {
        newList = ll_newLinkedList();

        if(newList != NULL)
        {
            for(int i=0; i<ll_len(this); i++)//recorre la lista que le llega
            {
                element = ll_get(this,i);

                if(pFunc(element) == 1)//le pasa los elementos a la funcion que valida
                {
                    ll_add(newList,element);//si cumple los requisitos agrega el elemento a la nueva lista
                }
            }
        }
    }
    return newList;
}

/** \brief Mapea elementos de una lista
 *
 * \param LinkedList* La lista a mapear
 * \param void* (*pFunc)(void*) La funcion que establece el criterio de mapeo
 * \return LinkedList* newList La nueva lista mapeada
 *
 */
LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void*))
{
    LinkedList* newList = NULL;
    void* element = NULL;

    if(this != NULL && pFunc != NULL)
    {
        newList = ll_newLinkedList();

        if(newList != NULL)
        {
            for(int i=0; i<ll_len(this); i++)
            {
                element = ll_get(this,i);

                if(pFunc(element))
                {
                    ll_add(newList,element);
                }
            }
        }
    }
    return newList;
}

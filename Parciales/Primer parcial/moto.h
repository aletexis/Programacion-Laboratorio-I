#include "type.h"
#include "color.h"
#include "client.h"
#include "patent.h"

#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char brand[20];
    int idType;
    int idColor;
    int cilindrada;
    int idClient;
    int idPatent;
    int state;

}eMoto;


/** \brief Hardcodea las motos
 *
 * \param motorcycles[] eMoto El array de motos
 * \param motorcyclesToHardcode int La cantidad de motos a harcodear
 * \return void
 *
 */
void moto_hardcode(eMoto motorcycles[], int motorcyclesToHardcode);
/** \brief Inicializa el array de motos en 0 o vacio
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array
 * \return void
 *
 */
void moto_initializate(eMoto motorcycles[], int sizeMotorcycles);
/** \brief Busca lugar libre en el array de motos para guardar nuevos datos
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int moto_findFreeSpace(eMoto motorcycles[], int sizeMotorcycles);
/** \brief Verifica la existencia de otra moto con el mismo ID
 *
 * \param id int El ID a buscar
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int moto_findOne(int id, eMoto motorcycles[], int sizeMotorcycles);


/** \brief Da de alta una moto
 *
 * \param int id El id que se le asignara a la moto
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de moto
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de moto
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
int moto_load(int id, eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Da de baja una moto
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_delate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Modifica una moto
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_modify(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra las motos cargadas en una lista
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_show(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra solo una moto
 *
 * \param eMoto La moto a mostrar
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_showOne(eMoto, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Ordena las motos
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_sort(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);

/** \brief Ordena las motos por patente
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void moto_sortPatent(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);

/** \brief Carga la descripcion de los tipos de motos
 *
 * \param description[] char Donde se cargara la informacion
 * \param id int El id de la estructura Type
 * \param types[] eType El array de tipos de motos
 * \param sizeTypes int El tamaño del array de tipos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int moto_loadTypeDescription(char description[], int id, eType types[], int sizeTypes);
/** \brief Carga el nombre de los colores de motos
 *
 * \param colorName[] char Donde se cargara la informacion
 * \param id int El id de la estructura Color
 * \param colors[] eColor El array de colores de motos
 * \param sizeColors int El tamaño del array de colores
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int moto_loadColorName(char colorName[], int id, eColor colors[], int sizeColors);
/** \brief Carga el nombre de los clientes
 *
 * \param clientName[] char Donde se cargara la informacion
 * \param id int El id de la estructura cliente
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int moto_loadClientName(char clientName[], int id, eClient clients[], int sizeClients);
/** \brief Carga la descripcion de la patente
 *
 * \param patentDescription[] char Donde se cargara la informacion
 * \param id int El id de la estructura patente
 * \param patentes ePatente El array de  patentes
 * \param sizePatentes int El tamaño del array de patentes
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int moto_loadPatentDescription(char patentDescription[], int id, ePatent patents[], int sizePatents);

#endif // MOTO_H_INCLUDED



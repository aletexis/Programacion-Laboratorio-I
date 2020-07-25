#include "moto.h"
#include "service.h"

#ifndef WORK_H_INCLUDED
#define WORK_H_INCLUDED

typedef struct
{
    int day;
    int month;
    int year;

}eDate;

typedef struct
{
    int id;
    int idMoto;
    int idService;
    eDate date;
    int state;
}eWork;


void work_hardcode(eWork works[], int worksToHardcode);

/** \brief Inicializa el array de trabajos en 0 o vacio
 *
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array
 * \return void
 *
 */
void work_initializate(eWork works[], int sizeWorks);
/** \brief Busca lugar libre en el array de trabajos para guardar nueva informacion
 *
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int work_findFreeSpace(eWork works[], int sizeWorks);
/** \brief Verifica la existencia de otro trabajo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int work_findOne(int id, eWork works[], int sizeWorks);

/** \brief Da de alta un trabajo
 *
 * \param id int ID incremental
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return int (1) si pudo dar de alta, (0) si no pudo
 *
 */
int work_load(int id, eWork works[], int sizeWorks, eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra un listado de trabajos
 *
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void work_show(eWork works[], int sizeWorks, eMoto motorcycles[], int sizeMotorcycles, eService services[], int sizeServices);
/** \brief Muestra solo un trabajo
 *
 * \param x eWork El trabajo a mostrar
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void work_showOne(eWork x, eMoto motorcycles[], int sizeMotorcycles, eService services[], int sizeServices);


/** \brief Carga el nombre/marca de la moto
 *
 * \param motoName[] char Donde se cargara la informacion
 * \param id int El id de la estructura Moto
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int work_loadMotoName(char motoName[], int id, eMoto motorcycles[], int sizeMotorcycles);
/** \brief Carga la descripcion del servicio
 *
 * \param serviceDescription[] char Donde se cargara la informacion
 * \param id int El id de la estructura Service
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int work_loadServiceDescription(char serviceDescription[], int id, eService services[], int sizeServices);

#endif // WORK_H_INCLUDED

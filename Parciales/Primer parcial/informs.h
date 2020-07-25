//cualquier cosa probar con descomentar estos includes para que reconozca las estructuras
//#include "moto.h"
//#include "type.h"
//#include "color.h"

#ifndef INFORMS_H_INCLUDED
#define INFORMS_H_INCLUDED

typedef struct{

	int idColor;
	int quantity;
	int state;

}eColor_MostChosen;

typedef struct{

	int idClient;
	int quantity;
	int state;

}eClient_MasMotos;

#endif // INFORMS_H_INCLUDED

/** \brief Muestra el menu de informes y hace lo indicado en la opcion
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param colors_mostChosen[] eColor_MostChosen
 * \return void
 *
 */
void inform(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eWork works[], int sizeWorks, eClient clients[], int sizeClients, eColor_MostChosen colors_mostChosen[], ePatent patents[], int sizePatents, eClient_MasMotos CCMMlist[]);


/** \brief Muestra las motos del color seleccionado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \return void
 *
 */
void inform_motoXcolor(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra las motos del tipo seleccionado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \return void
 *
 */
void inform_motoXtype(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Informa la o las motos de mayor cilindrada
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \return void
 *
 */
void inform_motoWithHigherCilindrada(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra un listado de las motos separadas por tipo
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \return void
 *
 */
void inform_motoXAllTypes(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Informa la cantidad de motos que hay de un tipo y color ingresado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void inform_motoCountByColorAndType(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra el o los colores mas elegidos por los clientes
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param colors_MostChosen[] eColor_MostChosen El array de colores mas elegidos
 * \return void
 *
 */
void inform_colorMostChosenByClients(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eColor_MostChosen colors_MostChosen[], ePatent patents[], int sizePatents);
/** \brief Muestra todos los trabajos realizados en una moto ingresada por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_motoAndWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);
/** \brief Informa la suma de los importes de los servicios que se le hicieron a una moto y la fecha
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_sumOfAmountsOfWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);
/** \brief Muestra las motos a las que se le realizo un servicio ingresado por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceAndMotos(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);
/** \brief Muestra todos los servicios realizados en una fecha ingresada por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param works[] eWork El array de trabajos
 * \param sizeWorks int El tamaño del array de trabajos
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array de servicios
 * \return void
 *
 */
void inform_serviceXdate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);




/** \brief Muestra las motos enduro con cilindrada mayor a 300
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_EnduroConCilindradaMayorA300(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra motos con sus patentes ordenadas ascendentemente por el id de las mismas
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_motosConPatentes(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra las motos de color negro
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_motosNegras(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra las motos de una patente seleccionada por el usuario
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_motoXPatente(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra el cliente que tiene mas motos
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_ClienteConMasMotos(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eClient_MasMotos CCMMlist[], ePatent patents[], int sizePatents);
/** \brief Muestra las motos de las clientes mujeres
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_motosDeClientesMujeres(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents);
/** \brief Muestra el promedio de los servicios realizados
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_promedioServicios(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);
/** \brief Muestra todas las limpiezas realizadas
 *
 * \param motorcycles[] eMoto El array de motos
 * \param sizeMotorcycles int El tamaño del array de motos
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array de colores
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array de clientes
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array de patentes
 * \return void
 *
 */
void inform_limpiezas(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents);

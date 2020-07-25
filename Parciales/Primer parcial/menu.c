#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"
#include "validations.h"


int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *                MENU                *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *    1.  ALTA DE MOTO                *");
    printf("\n\t\t\t\t *    2.  BAJA DE MOTO                *");
    printf("\n\t\t\t\t *    3.  MODIFICACION DE MOTO        *");
    printf("\n\t\t\t\t *    4.  LISTAR MOTOS                *");
    printf("\n\t\t\t\t *    5.  LISTAR TIPOS                *");
    printf("\n\t\t\t\t *    6.  LISTAR COLORES              *");
    printf("\n\t\t\t\t *    7.  LISTAR SERVICIOS            *");
    printf("\n\t\t\t\t *    8.  LISTAR PATENTES             *");
    printf("\n\t\t\t\t *    9.  ALTA TRABAJO                *");
    printf("\n\t\t\t\t *    10. MOSTRAR TRABAJOS            *");
    printf("\n\t\t\t\t *    11. INFORMES                    *");
    printf("\n\t\t\t\t *    12. SALIR                       *");
    printf("\n\t\t\t\t *                                    *");
    printf("\n\t\t\t\t *____________________________________*\n\n");
    option = getOption(12);

	return option;
}

int menu_motoModify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. COLOR                           |");
    printf("\n\t\t\t\t |    2. CILINDRADA                      |");
    printf("\n\t\t\t\t |    3. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(3);

    return option;
}

int menu_motoSort()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |             ORDENAR POR               |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1.                                 |");
    printf("\n\t\t\t\t |    2.                                 |");
    printf("\n\t\t\t\t |    3.                                 |");
    printf("\n\t\t\t\t |    4.                                 |");
    printf("\n\t\t\t\t |    5.                                 |");
    printf("\n\t\t\t\t |    6.                                 |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(6);

    return option;
}

int menu_order()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |                ORDEN                  |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |           1. ASCENDENTE               |");
    printf("\n\t\t\t\t |          -1. DESCENDENTE              |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");
    validations_getSignedInt(&option, "\n\tIntroduzca una opcion: ", "\n\t(!) Error. Opcion inexistente\n", 1, sizeof(int),-1, 1,4);

    return option;
}

int menu_inform()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  ____________________________________________________");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |                       INFORMES                     |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |   1.   INFORME MOTOS POR COLOR                     |");
    printf("\n\t\t\t\t |   2.   INFORME MOTOS POR TIPO                      |");
    printf("\n\t\t\t\t |   3.   INFORME MOTO CON MAYOR CILINDRADA           |");
    printf("\n\t\t\t\t |   4.   INFORME MOTOS SEPARADAS POR TIPOS           |");
    printf("\n\t\t\t\t |   5.   INFORME MOTOS CONTADAS POR COLOR Y TIPO     |");
    printf("\n\t\t\t\t |   6.   INFORME COLORES MAS ELEGIDOS                |");
    printf("\n\t\t\t\t |   7.   INFORME TODOS LOS TRABAJOS DE UNA MOTO      |");
    printf("\n\t\t\t\t |   8.   INFORME SUMA DE IMPORTES DE LOS SERVICIOS   |");
    printf("\n\t\t\t\t |   9.   INFORME MOTOS CON SERVICIOS REALIZADOS      |");
    printf("\n\t\t\t\t |   10.  INFORME SERVICIOS DE UNA FECHA              |");
    printf("\n\t\t\t\t |   11.  INFORME MOTOS ENDURO CON CILINDRADA >300    |");
    printf("\n\t\t\t\t |   12.  INFORME MOTOS CON SUS PATENTES ORDENADAS    |");
    printf("\n\t\t\t\t |   13.  INFORME MOTOS DE COLOR NEGRO                |");
    printf("\n\t\t\t\t |   14.  INFORME MOTOS POR PATENTE                   |");
    printf("\n\t\t\t\t |   15.  INFORME CLIENTE CON MAS MOTOS               |");
    printf("\n\t\t\t\t |   16.  INFORME MOTOS DE CLIENTES MUJERES           |");
    printf("\n\t\t\t\t |   17.  INFORME PROMEDIO SERVICIOS                  |");
    printf("\n\t\t\t\t |   18.  INFORME LIMPIEZAS REALIZADAS                |");
    printf("\n\t\t\t\t |   19.  VOLVER                                      |");
    printf("\n\t\t\t\t |                                                    |");
    printf("\n\t\t\t\t |____________________________________________________|\n\n");
    option = getOption(19);

    return option;
}

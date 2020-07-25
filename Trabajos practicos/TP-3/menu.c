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
    printf("\n\t\t\t  ________________________________________________");
    printf("\n\t\t\t *                                                *");
    printf("\n\t\t\t *                      MENU                      *");
    printf("\n\t\t\t *                                                *");
    printf("\n\t\t\t *    1.  CARGAR DESDE data.csv (modo texto)      *");
    printf("\n\t\t\t *    2.  CARGAR DESDE data.bin (modo binario)    *");
    printf("\n\t\t\t *    3.  ALTA DE EMPLEADO                        *");
    printf("\n\t\t\t *    4.  BAJA DE EMPLEADO                        *");
    printf("\n\t\t\t *    5.  MODIFICACION DE EMPLEADO                *");
    printf("\n\t\t\t *    6.  LISTAR EMPLEADOS                        *");
    printf("\n\t\t\t *    7.  ORDENAR EMPLEADOS                       *");
    printf("\n\t\t\t *    8.  GUARDAR EN data.csv (modo texto)        *");
    printf("\n\t\t\t *    9.  GUARDAR EN data.bin (modo binario)      *");
    printf("\n\t\t\t *    10. SALIR                                   *");
    printf("\n\t\t\t *________________________________________________*\n\n");
    option = getOption(10);

	return option;
}

int menu_modify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. NOMBRE                          |");
    printf("\n\t\t\t\t |    2. HORAS TRABAJADAS                |");
    printf("\n\t\t\t\t |    3. SUELDO                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(3);

    return option;
}

int menu_sort()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |             ORDENAR POR               |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. ID                              |");
    printf("\n\t\t\t\t |    2. NOMBRE                          |");
    printf("\n\t\t\t\t |    3. HORAS TRABAJADAS                |");
    printf("\n\t\t\t\t |    4. SUELDO                          |");
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


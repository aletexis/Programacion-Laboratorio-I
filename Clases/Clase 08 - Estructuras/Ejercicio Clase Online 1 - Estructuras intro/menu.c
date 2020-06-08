#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "extras.h"

int menu_preMain()
{
    int option;

    printf("\n");
    printf("\n\t\t _______________________________________\n\t\t*                                       *\n\t\t*                 MENU                  *\n\t\t*                                       *");
    printf("\n\t\t*    1. EMPLEADOS                       *");
    printf("\n\t\t*    9. SECTORES                        *");
    printf("\n\t\t*    3. SALIR                           *");
    printf("\n\t\t*                                       *\n\t\t*_______________________________________*\n\n");
    option = getOption(3);

	return option;
}

int menu_main()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *                 MENU                  *");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *    1. ALTA DE EMPLEADO                *");
    printf("\n\t\t\t\t *    2. BAJA DE EMPLEADO                *");
    printf("\n\t\t\t\t *    3. MODIFICACION DE EMPLEADO        *");
    printf("\n\t\t\t\t *    4. MOSTRAR EMPLEADOS               *");
    printf("\n\t\t\t\t *    5. ORDENAR                         *");
    printf("\n\t\t\t\t *    6. INFORMES                        *");
    printf("\n\t\t\t\t *    7. SALIR                           *");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *_______________________________________*\n\n");
    option = getOption(10);

	return option;
}

int menu_employeeModify()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA MODIFICAR?         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. NOMBRE                          |");
    printf("\n\t\t\t\t |    2. SEXO                            |");
    printf("\n\t\t\t\t |    3. EDAD                            |");
    printf("\n\t\t\t\t |    4. SUELDO                          |");
    printf("\n\t\t\t\t |    5. FECHA DE INGRESO                |");
    printf("\n\t\t\t\t |    6. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(6);

    return option;
}

int menu_employeeSort()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |             ORDENAR POR               |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. NOMBRE                          |");
    printf("\n\t\t\t\t |    2. SEXO                            |");
    printf("\n\t\t\t\t |    3. EDAD                            |");
    printf("\n\t\t\t\t |    4. SUELDO                          |");
    printf("\n\t\t\t\t |    5. FECHA DE INGRESO                |");
    printf("\n\t\t\t\t |    6. VOLVER                          |");
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
    printf("\n\t\t\t\t |           2. DESCENDENTE              |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");
    option = getOption(2);

    return option;
}

int menu_employeeInform()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |               INFORMES                |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. NOMBRE                          |");
    printf("\n\t\t\t\t |    2. SEXO                            |");
    printf("\n\t\t\t\t |    3. EDAD                            |");
    printf("\n\t\t\t\t |    4. SUELDO                          |");
    printf("\n\t\t\t\t |    5. FECHA DE INGRESO                |");
    printf("\n\t\t\t\t |    6. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");
    option = getOption(6);

    return option;
}

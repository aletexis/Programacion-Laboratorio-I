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
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *                 MENU                  *");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *    1. ALTA                            *");
    printf("\n\t\t\t\t *    2. BAJA                            *");
    printf("\n\t\t\t\t *    3. MODIFICACION                    *");
    printf("\n\t\t\t\t *    4. MOSTRAR                         *");
    printf("\n\t\t\t\t *    5. SALIR                           *");
    printf("\n\t\t\t\t *                                       *");
    printf("\n\t\t\t\t *_______________________________________*\n\n");
    option = getOption(5);

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
    printf("\n\t\t\t\t |    2. APELLIDO                        |");
    printf("\n\t\t\t\t |    3. SALARIO                         |");
    printf("\n\t\t\t\t |    4. SECTOR                          |");
    printf("\n\t\t\t\t |    5. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(5);

    return option;
}

int menu_inform()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |               INFORMES                |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. MOSTRAR EMPLEADOS               |");
    printf("\n\t\t\t\t |    2. MOSTRAR EMPLEADOS ORDENADOS     |");
    printf("\n\t\t\t\t |    3. SALARIOS                        |");
    printf("\n\t\t\t\t |    4. VOLVER                          |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");
    option = getOption(4);

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

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
    printf("\n\t\t\t *    2.  LISTAR                                  *");
    printf("\n\t\t\t *    3.  ASIGNAR ESTADISTICAS                    *");
    printf("\n\t\t\t *    4.  FILTRAR PAISES EXITOSOS                 *");
    printf("\n\t\t\t *    5.  FILTRAR PAISES EN EL HORNO              *");
    printf("\n\t\t\t *    6.  ORDENAR POR NIVEL DE INFECCION          *");
    printf("\n\t\t\t *    7.  LISTAR EL MAS CASTIGADO                 *");
    printf("\n\t\t\t *                                                *");
    printf("\n\t\t\t *    8. SALIR                                    *");
    printf("\n\t\t\t *________________________________________________*\n\n");
    option = getOption(8);

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
    printf("\n\t\t\t\t |    2. RECUPERADOS                     |");
    printf("\n\t\t\t\t |    3. INFECTADOS                      |");
    printf("\n\t\t\t\t |    4. MUERTOS                         |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(4);

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
    printf("\n\t\t\t\t |    3. RECUPERADOS                     |");
    printf("\n\t\t\t\t |    4. INFECTADOS                      |");
    printf("\n\t\t\t\t |    5. MUERTOS                         |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(5);

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

int menu_filter()
{
    int option;

    printf("\n");
    printf("\n\t\t\t\t  _______________________________________");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |          QUE DESEA FILTRAR?           |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |    1. PAISES EXITOSOS                 |");
    printf("\n\t\t\t\t |    2. PAISES EN EL HORNO              |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(2);

    return option;
}

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
    printf("\n\t\t\t *    1.  CARGAR ARCHIVO                          *");
    printf("\n\t\t\t *    2.  IMPRIMIR LISTA                          *");
    printf("\n\t\t\t *    3.  ASIGNAR TIEMPOS                         *");
    printf("\n\t\t\t *    4.  FILTRAR POR TIPO                        *");
    printf("\n\t\t\t *    5.  MOSTRAR POSICIONES                      *");
    printf("\n\t\t\t *    6.  GUARDAR POSICIONES                      *");
    printf("\n\t\t\t *                                                *");
    printf("\n\t\t\t *    7. SALIR                                    *");
    printf("\n\t\t\t *________________________________________________*\n\n");
    option = getOption(7);

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
    printf("\n\t\t\t\t |    1. BMX                             |");
    printf("\n\t\t\t\t |    2. PLAYERA                         |");
    printf("\n\t\t\t\t |    3. MTB                             |");
    printf("\n\t\t\t\t |    4. PASEO                           |");
    printf("\n\t\t\t\t |                                       |");
    printf("\n\t\t\t\t |_______________________________________|\n\n");

    option = getOption(4);

    return option;
}

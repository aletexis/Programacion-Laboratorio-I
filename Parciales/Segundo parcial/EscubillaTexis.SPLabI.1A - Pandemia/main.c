#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Country.h"
#include "extras.h"
#include "menu.h"
#include "validations.h"


int main()
{
    srand (time(NULL));

    char exit = 'n';
    LinkedList* list = ll_newLinkedList();
    LinkedList* listMap = NULL;
    LinkedList* listFilterExitosos = NULL;
    LinkedList* listFilterHorno = NULL;
    int flag = 0;
    //char path[128];

    do
    {
        switch(menu_main())
        {
            case 1:///cargar el archivo
                //validations_getPath(path,"\n\tIngrese el nombre del archivo incluyendo su extension: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 128, 4);
                //controller_loadFromText(path, list);
                controller_loadFromText("pandemia.csv", list);
                break;

            case 2:///imprimir lista
                controller_list(list);
                break;

            case 3:///asignar estadisticas
                listMap = ll_map(list, country_map);
                if(listMap != NULL)
                {
                    controller_list(listMap);
                }
                break;

            case 4:///filtrar por paises exitosos
                listFilterExitosos = ll_filter(listMap, controller_filterBySuccess);
                if(listFilterExitosos != NULL)
                {
                    controller_list(listFilterExitosos);
                    printf("\n\n\t>>> Paises filtrados exitosamente <<<\n\n\n\tGuardando en el archivo .csv ...\n");
                    controller_saveAsText("exitosos.csv", listFilterExitosos);
                }
                break;

            case 5:///filtrar por paises en el horno
                listFilterHorno = ll_filter(listMap, controller_filterByFailure);
                if(listFilterHorno != NULL)
                {
                    controller_list(listFilterHorno);
                    printf("\n\n\t>>> Paises filtrados exitosamente <<<\n\n\n\tGuardando en el archivo .csv ...\n");
                    controller_saveAsText("enelhorno.csv", listFilterHorno);
                }
                break;

            case 6:///ordenar por nivel de infeccion
                controller_sortParam(listMap, 4, 0);
                controller_list(listMap);
                break;

            case 7:///mostrar mas castigado (nombre pais mas muertos)
                controller_paisConMasMuertos(listMap);
                break;

            case 8:///salir
                if(confirm(12,flag) == 1)
                {
                    exit = 's';
                    ll_deleteLinkedList(listMap);
                }
                break;
        }
    }
    while(exit == 'n');

    return 0;
}

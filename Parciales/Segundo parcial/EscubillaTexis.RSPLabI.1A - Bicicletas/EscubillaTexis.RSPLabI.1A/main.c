#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Bicicleta.h"
#include "extras.h"
#include "menu.h"
#include "validations.h"

/**
1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
   del mismo.

2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de las bicicletas.

3) Asignar tiempos: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y una
función que asignará a la bicicleta un valor de tiempo entre 50 y 120 minutos calculado de
manera aleatoria se mostrará por pantalla el mismo.

4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan
bicicletas del tipo seleccionado.

5) Mostrar posiciones: Se deberá mostrar por pantalla un listado de las bicicletas ordenadas
por tipo y dentro de las del mismo tipo que aparezcan ordenadas por tiempo ascendente.

6) Guardar posiciones: Se deberá guardar el listado del punto anterior en un archivo de texto.

**/

int main()
{
    srand (time(NULL));

    char exit = 'n';
    LinkedList* list = ll_newLinkedList();
    LinkedList* listMap = NULL;
    LinkedList* listFiltered = NULL;
    LinkedList* listSorted = NULL;
    int flag = 0;
    char path[128];

    do
    {
        switch(menu_main())
        {
            case 1:///cargar el archivo
                validations_getPath(path,"\n\tIngrese el nombre del archivo incluyendo su extension: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 128, 4);
                controller_loadFromText(path, list);
                //controller_loadFromText("bicicletas.csv", list);
                break;

            case 2:///imprimir lista
                controller_list(list);
                break;

            case 3:///asignar tiempos
                listMap = ll_map(list, bicicleta_map);
                if(listMap != NULL)
                {
                    controller_list(listMap);
                }
                break;

            case 4:///filtrar por tipo
                switch(menu_filter())
                {
                        case 1:
                            listFiltered = ll_filter(list,controller_filterBMX);
                            controller_list(listFiltered);
                            controller_saveAsText("bmx.csv", listFiltered);
                            flag = 1;
                            break;
                        case 2:
                           listFiltered = ll_filter(list,controller_filterPlayera);
                           controller_list(listFiltered);
                           controller_saveAsText("playera.csv", listFiltered);
                           flag = 1;
                            break;
                        case 3:
                            listFiltered = ll_filter(list,controller_filterMTB);
                            controller_list(listFiltered);
                            controller_saveAsText("mtb.csv", listFiltered);
                            flag = 1;
                            break;
                        case 4:
                            listFiltered = ll_filter(list,controller_filterPaseo);
                            controller_list(listFiltered);
                            controller_saveAsText("paseo.csv", listFiltered);
                            flag = 1;
                            break;
                }
                break;

            case 5:///mostrar posiciones ordenadas
                listSorted = ll_clone(listMap);
                controller_sortParam(listSorted, 5, 1);
                controller_list(listSorted);
                break;

            case 6:///guardar
                controller_saveAsText("listaordenada.csv", listSorted);
                flag = 1;
                break;

            case 7:///salir
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define SIZE 5

int main()
{
    /**
    tener un vector de punteros a ePerson donde en cada
    uno de esos elementos del vector de punteros van a tener
    la dir mem de las stucts ePerson

    en vez de tener las 5 structs en un vector las voy a tener
    desparramadas en la memoria pero con todas las llamadas
    en un mismo vector

    en vez de tener en la dinamica

    struct/struct/struct/struct/struct

    voy a tener

    punteroAStruct/punteroAStruct/punteroAStruct/punteroAStruct/punteroAStruct

    (puntero a puntero)

     **/

    ePerson** list = (ePerson**) malloc(5*sizeof(ePerson*));
    ePerson* auxPerson;
    int index;

    if(list == NULL)
    {
        printf("\n\n\t\t >>> No se pudo conseguir espacio en memoria <<<\n\n");
        exit(EXIT_FAILURE);
    }

    if(initializatePeople(list, SIZE))
    {
         printf("\n\n\t\t >>> Se inicializaron las personas <<<\n\n");
    }
    else
    {
         printf("\n\n\t\t >>> Problema al inicializar las personas <<<\n\n");
    }

    findFreeSpace(&index, list, SIZE);

    if(index != -1)
    {
        auxPerson = person_newParam(1234, "Jose", 'm', 82.5);

        if(auxPerson != NULL)
        {
            *(list + index) = auxPerson;
        }

        findFreeSpace(&index, list, SIZE);

        auxPerson = person_newParam(3333, "Ana", 'f', 59.5);

        if(auxPerson != NULL)
        {
            *(list + index) = auxPerson;
        }

        findFreeSpace(&index, list, SIZE);

        auxPerson = person_newParam(2222, "Luis", 'm', 69.5);

        if(auxPerson != NULL)
        {
            *(list + index) = auxPerson;
        }

        person_show(list, SIZE);

        printf("\n");

        free(*(list + 1));
        *(list +1) = NULL;

        person_show(list, SIZE);

         printf("\n");

        findFreeSpace(&index, list, SIZE);

        auxPerson = person_newParam(8888, "Julia", 'f', 62.7);

        if(auxPerson != NULL)
        {
            *(list + index) = auxPerson;
        }

        person_show(list, SIZE);


    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "service.h"

#define EMPTY 0
#define TAKEN 1

void service_show(eService services[], int sizeServices)
{
    printf("\n\t\t ****************** SERVICIOS ******************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t      ID         DESCRIPCION          PRECIO    \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<sizeServices; i++)
    {
        service_showOne(services[i]);
    }
}

void service_showOne(eService service)
{
    printf("\n\t\t     %d       %10s           %.2f\n", service.id, service.description, service.price);
}

int service_findOne(int id, eService services[], int sizeServices)
{
    int ret = -1;

    for(int i=0; i<sizeServices; i++)
    {
        if(services[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

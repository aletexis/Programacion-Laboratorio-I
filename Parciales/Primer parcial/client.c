#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client.h"

void client_show(eClient clients[], int sizeClients)
{
    printf("\n\t\t ******************** CLIENTES ********************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    NOMBRES       \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<sizeClients; i++)
    {
        client_showOne(clients[i]);
    }
}

void client_showOne(eClient client)
{
    printf("\n\t\t       %d                  %10s\n", client.id, client.name);
}

int client_findOne(int id, eClient clients[], int sizeClients)
{
    int ret = -1;

    for(int i=0; i<sizeClients; i++)
    {
        if(clients[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

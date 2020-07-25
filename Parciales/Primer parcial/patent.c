#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "patent.h"

void patent_show(ePatent patents[], int sizePatents)
{
    printf("\n\t\t ********************  PATENTE  ********************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    DESCRIPCION            \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<sizePatents; i++)
    {
        patent_showOne(patents[i]);
    }
}

void patent_showOne(ePatent patent)
{
    printf("\n\t\t       %d                   %10s\n", patent.id, patent.description);
}

int patent_findOne(int id, ePatent patents[], int sizePatents)
{
    int ret = -1;

    for(int i=0; i<sizePatents; i++)
    {
        if(patents[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

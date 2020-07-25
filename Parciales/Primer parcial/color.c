#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

void color_show(eColor colors[], int sizeColors)
{
    printf("\n\t\t ******************** COLORES ********************\n\n");
    printf("\t\t _______________________________________________\n\n");
    printf("\t\t        ID                    NOMBRE            \n");
    printf("\t\t _______________________________________________\n");

    for(int i=0; i<sizeColors; i++)
    {
        color_showOne(colors[i]);
    }
}

void color_showOne(eColor color)
{
    printf("\n\t\t       %d              %10s\n", color.id, color.colorName);
}

int color_findOne(int id, eColor colors[], int sizeColors)
{
    int ret = -1;

    for(int i=0; i<sizeColors; i++)
    {
        if(colors[i].id == id)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

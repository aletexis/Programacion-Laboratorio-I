#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "food.h"

void food_show(eFood foods[], int sizeFood)
{
    //printf("\n******* listado comidas *********\n");
    printf("   ID      DESCRIPION    PRECIO\n");

    for(int i=0; i<sizeFood; i++)
    {
        printf("    %d    %10s   %5.2\n", foods[i].id, foods[i].description, foods[i].price);
    }
    printf("\n");
}

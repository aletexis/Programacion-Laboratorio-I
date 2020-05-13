#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sector.h"

void sector_show(eSector sectors[], int sizeSec)
{
    printf("\n******************** SECTORES ********************\n\n");
    printf("    ID           DESCRIPCION\n");

    for(int i=0; i<sizeSec; i++)
    {
        printf("\n    %d %10s\n", sectors[i].id, sectors[i].description);
    }
}

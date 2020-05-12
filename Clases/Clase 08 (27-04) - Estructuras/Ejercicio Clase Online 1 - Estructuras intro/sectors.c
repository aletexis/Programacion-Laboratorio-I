/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sectors.h"
//#include "dataWarehouse.h"
#include "validations.h"


int sector_loadDescription(char description[], int id, eSector sectors[], int size)
{
    int ok = 0;

    for(int i=0; i<size; i++)
    {
        if(sectors[i].id == id)
        {
            strcpy(description, sectors[i].description);
            ok = 1;
        }
    }

    return ok;
}
*/


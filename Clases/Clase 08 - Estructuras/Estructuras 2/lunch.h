#include "employee.h"
#include "sector.h"
#include "food.h"

#ifndef LUNCH_H_INCLUDED
#define LUNCH_H_INCLUDED

typedef struct
{
    int id;
    int idEmployee;
    int idFood;
    eDate date;
    int state;
}eLunch;

#endif // LUNCH_H_INCLUDED


void lunch_initializate(eLunch lunches[], int sizeLunch);
int lunch_findFreeSpace(eLunch lunches[], int sizeLunch);
int lunch_load(int nextLunchId, eLunch lunches[], int sizeLunch, eEmployee list[], int size, eSector sectors[], int sizeSec, eFood foods[], int sizeFood);
void lunch_show(eLunch lunches[], int sizeLunch, eEmployee list[], int sizeEmp, eFood foods[], int sizeFood);
void lunch_showOne(eLunch lunch, eEmployee list[], int sizeEmp, eFood foods[], int sizeFood);
int lunch_loadDescriptionFood(char description[], int id, eFood foods[], int sizeFood);
int lunch_loadNameEmployee(char name[], int id, eEmployee list[], int sizeEmp);

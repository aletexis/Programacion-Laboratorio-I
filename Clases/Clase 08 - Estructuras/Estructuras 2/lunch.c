#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lunch.h"

void lunch_initializate(eLunch lunches[], int sizeLunch)
{
     for(int i=0; i<sizeLunch; i++)
     {
         lunches[i].state = 0;
     }
}

int lunch_findFreeSpace(eLunch lunches[], int sizeLunch)
{
    int ret = -1;

    for(int i=0; i<sizeLunch; i++)
    {
        if(lunches[i].state == 0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
int lunch_load(int idLunch, eLunch lunches[], int sizeLunch, eEmployee list[], int size, eSector sectors[], int sizeSec, eFood foods[], int sizeFood)
{
    int ok = 0;
    eLunch newLunch;
    int index;

    system("cls");
    printf("\n*** ALTA ALMUERZO **********************************************");

    index = lunch_findFreeSpace(lunches, sizeLunch);

    if(index == -1)
    {
        printf("\nSistema completo");
    }
    else
    {
        showEmployees(list, size, sectors, sizeSec);
        printf("Ingrese ID employee: ");
        scanf("%d", &newLunch.idEmployee);

        food_show(foods, sizeFood);
        printf("Ingrese ID comida: ");
        scanf("%d", &newLunch.idFood);

        printf("\nIngrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &newLunch.date.day, &newLunch.date.month, &newLunch.date.year);

        newLunch.id = idLunch;
        newLunch.state = 0;

        lunches[index] = newLunch;

        ok = 1;

        printf("\nSe dio de alta almuerzo exitosamente");
    }

    return ok;
}

void lunch_show(eLunch lunches[], int sizeLunch, eEmployee list[], int sizeEmp, eFood foods[], int sizeFood)
{
    int flag = 0;

    printf("\n******* listado almuerzos *********\n");
    printf("   ID     ID EMPLEADO       NOMBRE EMPLEADO       ID COMIDA    FECHA\n");

    for(int i=0; i<sizeLunch; i++)
    {
        if(lunches[i].state == 1)
        {
            lunch_showOne(lunches[i], list, sizeEmp, foods, sizeFood);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay almuerzos que mostrar");
    }
    printf("\n");
}

void lunch_showOne(eLunch lunch, eEmployee list[], int sizeEmp, eFood foods[], int sizeFood)
{
    char foodDescription[20];
    char nameEmployee[20];

    lunch_loadNameEmployee(nameEmployee, lunch.idEmployee, list, sizeEmp);
    lunch_loadDescriptionFood(foodDescription, lunch.idFood, foods, sizeFood);

    printf("    %d    %d    %s     %s      %d/%d/%d\n", lunch.id, lunch.idEmployee, nameEmployee, foodDescription, lunch.date.day, lunch.date.month, lunch.date.year);
}

int lunch_loadDescriptionFood(char description[], int id, eFood foods[], int sizeFood)
{
    int ok = 0;

    for(int i=0; i<sizeFood; i++)
    {
        if(foods[i].id == id)
        {
            strcpy(description, foods[i].description);
            ok = 1;
        }
    }

    return ok;
}

int lunch_loadNameEmployee(char name[], int id, eEmployee list[], int sizeEmp)
{
    int ok = 0;

    for(int i=0; i<sizeEmp; i++)
    {
        if(list[i].id == id && list[i].state == 1)
        {
            strcpy(name, list[i].name);
            ok = 1;
        }
    }

    return ok;
}

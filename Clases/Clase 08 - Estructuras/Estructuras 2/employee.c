#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "dataWarehouse.h"


void showEmployees(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag = 0;

    printf("\n******************** LISTADO DE EMPLEADOS ********************\n\n");
    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO       SECTOR\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1)
        {
            showEmployee(list[i], sectors, sizeSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados para mostrar\n");
    }
}

void showEmployee(eEmployee x, eSector sectors[], int sizeSec)
{
    char nameSector[20];

    sector_loadDescription(nameSector, x.idSector, sectors, sizeSec);

    printf("\n%d %8s     %c      %d    %.2f    %02d/%02d/%4d    %10s\n", x.id, x.name, x.gender,x.age, x.salary, x.dateOfAdmission.day, x.dateOfAdmission.month, x.dateOfAdmission.year, nameSector);
}

void sortEmployees(eEmployee list[], int size, int mode, eSector sectors[], int sizeSec)
{
    eEmployee auxEmployee;

    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            /*if(list[i].id > list[j].id && mode == 0)//asc  //(strcmp(list[i].name, list[j].name) > 0) //asc
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            else if (list[i].id < list[j].id && mode == 1)//desc (strcmp(list[i].name, list[j].name) < 0) //desc
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }*/
            /////////////////////////////////////
            if(list[i].gender > list[j].gender)
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
            else if(list[i].gender == list[j].gender && strcmp(list[i].name, list[j].name) > 0) //doble criterio, cuando dos personas son del mismo sexo las ordena alfabeticamente por nombre
            {
                auxEmployee = list[i];
                list[i] = list[j];
                list[j] = auxEmployee;
            }
        }
    }
}

void initializateEmployee(eEmployee list[], int size)
{

     for(int i=0; i<size; i++)
     {
         list[i].state = 0;
     }
}

int findFreeSpace(eEmployee list[], int size) //si no hay lugar retorna -1
{
    int ret = -1;

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int findEmployee(int id, eEmployee list[], int size)
{
    int ret = -1;

    for(int i=0; i<size; i++)
    {
        if(list[i].id == id && list[i].state == 1)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int altaEmployee(int nextID, eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int index;
    eEmployee auxEmployee;
    int ok = 0;

    index = findFreeSpace(list, size);

    if(index != -1)
    {
          auxEmployee.id = nextID;

          printf("\nIngrese nombre: ");
          setbuf(stdin, NULL);
          gets(auxEmployee.name);

          printf("\nIngrese sexo: ");
          setbuf(stdin, NULL);
          scanf("%c", &auxEmployee.gender);

          printf("\nIngrese edad: ");
          scanf("%d", &auxEmployee.age);

          printf("\nIngrese sueldo: ");
          scanf("%f", &auxEmployee.salary);

          printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
          scanf("%d/%d/%d", &auxEmployee.dateOfAdmission.day, &auxEmployee.dateOfAdmission.month, &auxEmployee.dateOfAdmission.year);

          sector_show(sectors, sizeSec);
          printf("\nIngrese id del sector: ");
          scanf("%d", &auxEmployee.idSector);

          auxEmployee.state = 1;

          list[index] = auxEmployee;
          ok = 1;
        }

    else
    {
        printf("\nNo hay lugar para agregar un empleado");
    }
    return ok;
}

void bajaEmployee(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int id;
    int index;
    char confirm;

    printf("\nIngrese id: ");
    scanf("%d", &id);

    index = findEmployee(id, list, size);

    if(index == -1)
    {
        printf("\nNo hay registro de un empleado con el ID: %d", id);
    }
    else
    {
        showEmployee(list[index], sectors, sizeSec);

        printf("\nConfirma la baja? (s/n) ");
        setbuf(stdin, NULL);
        scanf("%c", &confirm);

        if(confirm == 's')
        {
            list[index].state = 0;
            printf("\nSe ha realizado la baja con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}

void hardcodearEmployees(eEmployee list[], int employeesToHardcode)
{
    for(int i=0; i<employeesToHardcode; i++)
    {
        list[i].id = ids[i];
        strcpy(list[i].name, names[i]);
        //strcpy(list[i].surname, surnames[i]);
        list[i].age = ages[i];
        list[i].gender = genders[i];
        list[i].salary = salaries[i];
        list[i].dateOfAdmission.day = days[i];
        list[i].dateOfAdmission.month = months[i];
        list[i].dateOfAdmission.year = years[i];
        list[i].idSector = idsSector[i];
        list[i].state = 1;

    }
}

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

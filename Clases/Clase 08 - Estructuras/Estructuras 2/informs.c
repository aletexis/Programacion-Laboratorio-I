#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "sector.h"
#include "informs.h"

int informMenu()
{
    int option;

    printf("\n\n\t\t************** INFORMES **************\n\t\t\n");
    printf("\t\t    1.  Informe empleados de un anio\n");
    printf("\t\t    2.  Informe empleados varones\n");
    printf("\t\t    3.  Informe total de sueldos\n");
    printf("\t\t    4.  Informe empleados sector\n");
    printf("\t\t    5.  Informe empleados por sectores\n");
    printf("\t\t    6.  Informe total de sueldos sector\n");
    printf("\t\t    7.  Informe mayor sueldo sector\n");
    printf("\t\t    8.  Informe mayor sueldo por sectores\n");
    printf("\t\t    9.  Informe aumentar sueldos sector\n");
    printf("\t\t    10. Informe sector que mas cobra\n");
    printf("\t\t    11. Informe 11\n");
    printf("\t\t    12. Informe 12\n");
    printf("\t\t    13. Informe 13\n");
    printf("\t\t    14. Informe 14\n");
    printf("\t\t    15. Salir\n\t\t\n");
    printf("\t\t*****************************************\n");

    printf("\n\nIngrese una opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &option);

    return option;
}

void inform(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    char cont = 's';

    system("cls");
    printf("\n*** Informes *******************");

     do{

        switch(informMenu())
        {
            case 1:
                inform_employeesXyear(list, size, sectors, sizeSec);
                break;
            case 2:
                inform_employeesXmen(list, size, sectors, sizeSec);
                break;
            case 3:
                inform_totalsalaries(list, size);
                break;
            case 4:
                inform_employeesXsector(list, size, sectors, sizeSec);
                break;
            case 5:
                inform_employeeXallsectors(list, size, sectors, sizeSec);
                break;
            case 6:
                inform_totalSalariesXsector(list, size, sectors, sizeSec);
                break;
            case 7:
                inform_higherSalarySector(list, size, sectors, sizeSec);
                break;
            case 8:
                inform_higherSalaryEmployeeSector(list, size, sectors, sizeSec);
                break;
            case 9:
                inform_aumentarSueldoSectorPorcentaje(list, size, sectors, sizeSec);
                break;
            case 10:
                inform_sectorThatCollectMore(list, size, sectors, sizeSec);
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                printf("\n¿Esta seguro que desea salir? (y/n) \n");
                /*setbuf(stdin,NULL);
                scanf("%c", &confirm);
                if(confirm == 'y')
                {
                    cont = 'n';
                }*/
                cont = 'n';
                break;
        }

    }while(cont == 'y');
}

void inform_employeesXyear(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int year;
    int flag = 0;

    system("cls");
    printf("\n******************** EMPLEADOS POR ANIO DE INGRESO ********************\n\n");

    printf("\nIngrese año: ");
    scanf("%d", &year);

    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].dateOfAdmission.year == year)
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

void inform_employeesXmen(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag = 0;

    system("cls");
    printf("\n******************** EMPLEADOS VARONES ********************\n\n");

    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].gender == 'm')
        {
            showEmployee(list[i], sectors, sizeSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados varones para mostrar\n");
    }
}

void inform_totalsalaries(eEmployee list[], int size)
{
    float total = 0;

    system("cls");
    printf("\n******************** TOTAL SUELDOS ********************\n\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1)
        {
            total = total + list[i].salary;
        }
    }
    printf("\nTotal de sueldos $ %.2f\n", total);
}

void inform_employeesXsector(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag = 0;
    int idSector;

    system("cls");
    printf("\n******************** EMPLEADOS SECTOR ********************\n\n");

    sector_show(sectors, sizeSec);
    printf("\nIngrese ID del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].idSector == idSector)
        {
            printf("\n******************** LISTADO DE EMPLEADOS ********************\n\n");
            printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO       SECTOR\n");

            showEmployee(list[i], sectors, sizeSec);
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\nNo hay empleados en este sector\n");
    }
}

void inform_employeeXallsectors(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag;

    system("cls");
    printf("\n******************** EMPLEADOS POR SECTOR ********************\n\n");

    for(int i=0; i<sizeSec; i++)
    {
        flag = 0;
        printf("\nSector: %s", sectors[i].description);

        for(int j=0; j<size; j++)
        {
            if(list[j].state == 1 && list[j].idSector == sectors[i].id)
            {
                showEmployee(list[i], sectors, sizeSec);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay empleados en este sector\n");
        }
    }
}

void inform_totalSalariesXsector(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int idSector;
    float totalSalaries = 0;
    char sectorDescripion[20];

    system("cls");
    printf("\n******************** INFORME TOTAL SUELDOS SECTOR ********************\n\n");

    sector_show(sectors, sizeSec);
    printf("\nIngrese ID del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].idSector == idSector)
        {
            totalSalaries = totalSalaries + list[i].salary;
        }
    }

    sector_loadDescription(sectorDescripion, idSector, sectors, sizeSec);
    printf("\nTotal de sueldos del sector %s: $ %.2f\n", sectorDescripion, totalSalaries);
}

void inform_higherSalarySector(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int idSector;
    int flag = 0;
    float higherSalary = 0;
    char description[20];

    system("cls");
    printf("\n******************** MAYOR SUELDO SECTOR ********************\n\n");

    sector_show(sectors, sizeSec);
    printf("\nIngrese ID del sector: ");
    scanf("%d", &idSector);

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].idSector == idSector)
        {
            if(list[i].salary > higherSalary || flag == 0)
            {
                higherSalary = list[i].salary;
                flag = 1;
            }
        }
    }

    sector_loadDescription(description, idSector, sectors, sizeSec);
    printf("\nEl mayor sueldo del sector %s es $%.2f", description, higherSalary);
}

void inform_higherSalaryEmployeeSector(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag;
    float higherSalary;

    system("cls");
    printf("\n******************** EMPLEADOS POR SECTOR ********************\n\n");

    for(int i=0; i<sizeSec; i++)
    {
        flag = 0;
        higherSalary = 0;
        printf("\nSector: %s", sectors[i].description);
        printf("\n----------------");

        for(int j=0; j<size; j++)
        {
            if(list[j].state == 1 && list[j].idSector == sectors[i].id)
            {
                if(list[j].salary > higherSalary || flag == 0)
                {
                    higherSalary = list[j].salary;
                    flag = 1;
                }
            }
        }
        printf("\nEl mayor sueldo es $%.2f", higherSalary);
        printf("\n----------------------------------------------------");
    }
}

void inform_aumentarSueldoSectorPorcentaje(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int idSector;
    int flag = 0;
    int percentage;
    float increase;

    system("cls");
    printf("\n******************** MODIFICAR SULEDOS SECTOR PORCENTAJE ********************\n\n");

    sector_show(sectors, sizeSec);
    printf("\nIngrese ID del sector: ");
    scanf("%d", &idSector);

    printf("\nIngrese porcentaje de aumento: ");
    scanf("%d", &percentage);

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].idSector == idSector)
        {
            increase = list[i].salary * percentage / 100;
            list[i].salary += increase;
            flag = 1;
        }
    }
    if(flag == 1)
    {
        printf("\nSe han modificado los sueldos exitosamente\n");
    }
    else
    {
        printf("\nNo hay empleados a quienes aumentar\n");
    }
}

void inform_sectorThatCollectMore(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
   float totalSalaries[sizeSec];
   float highestTotal;
   int flag = 0;

   for(int i=0; i<sizeSec; i++)
   {
       totalSalaries[i] = getTotalSalariesSector(sectors[i].id, list, size);
   }

   for(int i=0; i<sizeSec; i++)
   {
       if(totalSalaries[i]>highestTotal || flag == 0)
       {
           highestTotal = totalSalaries[i];
           flag = 1;
       }
   }

   printf("\nEl total de sueldos mayor es $ %.2f y pertenece al sector ", highestTotal);

   for(int i=0; i<sizeSec; i++)
   {
       if(totalSalaries[i] == highestTotal)
       {
           printf("%s", sectors[i].description);
       }
   }

}

float getTotalSalariesSector(int idSector, eEmployee list[], int size)
{
    float totalSalaries = 0;

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].idSector == idSector)
        {
            totalSalaries += list[i].salary;
        }
    }

    return totalSalaries;
}

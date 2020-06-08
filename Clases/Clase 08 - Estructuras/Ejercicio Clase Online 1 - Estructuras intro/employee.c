#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "validations.h"
#include "menu.h"
#include "extras.h"
#include "dataWarehouse.h"
#include "sectors.h"

#define EMPTY 0
#define TAKEN 1

void employee_hardcode(eEmployee list[], int employeesToHardcode)
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
void employee_initializate(eEmployee list[], int size)
{
     for(int i=0; i<size; i++)
     {
         list[i].state = EMPTY;
     }
}

int findFreeSpace(eEmployee list[], int size) //si no hay lugar retorna -1, si hay retorna la posicion libre
{
    int ret = -1;

    for(int i=0; i<size; i++)
    {
        if(list[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

int employee_find(int id, eEmployee list[], int size)
{
    int ret = -1;

    for(int i=0; i<size; i++)
    {
        if(list[i].id == id && list[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}

void employee_load(eEmployee list[], int size)
{
    int index = findFreeSpace(list, size);
    int id;
    int exists;
    eEmployee auxEmployee;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {
        validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,sizeof(int),0,size,4);

        exists = employee_find(id, list, size);

        if(exists != -1)
        {
            printf("\n\n\t\t>>> El ID ya existe <<<\n\n\n");
            system("pause");
        }
        else
        {
            auxEmployee.id = id;

            validations_getText(auxEmployee.name,"\n\tIngrese nombre: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 20, 4);
            validations_getGender(&auxEmployee.gender,"\n\tIngrese sexo: ", "\n\t(!) Error. Caracter invalido. Debe ser f o m\n",4);
            validations_getUnsignedInt(&auxEmployee.age,"\n\tIngrese edad: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango de edad: 18-100\n",1, sizeof(int),18,100,4);
            validations_getFloat(&auxEmployee.salary,"\n\tIngrese salario: ", "\n\t(!) Error. Ingrese un valor numerico flotante.\n",1,15,0,9999999,4);
            //printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
            //scanf("%d/%d/%d", &auxEmployee.dateOfAdmission.day, &auxEmployee.dateOfAdmission.month, &auxEmployee.dateOfAdmission.year);


            auxEmployee.state = TAKEN;

            list[index] = auxEmployee;//copio al vec el empleado nuevo en el indice disponible

            printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
            system("pause");
        }
    }
}

void employee_delate(eEmployee list[], int size)
{
    int id;
    int index;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1, sizeof(int),0,size,4);

    index = employee_find(id, list, size);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de un empleado con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        printf("\n");
        printf("\n\t\t __________________________________________________________________________");
        printf("\n\t\t*        ID     NOMBRE    SEXO    EDAD    SUELDO    F. DE INGRESO          *");
        printf("\n\t\t*                                                                          *");
        employee_showOne(list[index]);
        printf("\n\t\t*                                                                          *\n\t\t*__________________________________________________________________________*\n\n");

        if(confirm(2))
        {
            list[index].state = EMPTY;
        }
    }
}

void employee_modify(eEmployee list[], int size)
{
    int id;
    int index;
    char newName[20];
    char newGender;
    int newAge;
    float newSalary;
    //int newDateOfAdmition;

    system("cls");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,sizeof(int),0,size,9);

    index = employee_find(id, list, size);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de un empleado con el ID: %d <<<\n\n\n", id);
        system("pause");
    }
    else
    {
        printf("\n");
        printf("\n\t\t __________________________________________________________________________");
        printf("\n\t\t*        ID     NOMBRE    SEXO    EDAD    SUELDO    F. DE INGRESO          *");
        printf("\n\t\t*                                                                          *");
        employee_showOne(list[index]);
        printf("\n\t\t*                                                                          *\n\t\t*__________________________________________________________________________*\n\n");

        switch(menu_employeeModify())
        {
            case 1:
                validations_getText(newName,"\n\tIngrese nuevo nombre: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 20, 4);
                if(confirm(3))
                {
                    strcpy(list[index].name, newName);
                }
                break;
            case 2:
                validations_getGender(&newGender,"\n\tIngrese nuevo sexo: ", "\n\t(!) Error. Caracter invalido.\n", 4);
                if(confirm(3))
                {
                    list[index].gender = newGender;
                }
                break;
            case 3:
                validations_getUnsignedInt(&newAge,"\n\tIngrese nueva edad: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango de edad: 18-100\n",1,sizeof(int),18,100,4);
                if(confirm(3))
                {
                    list[index].age = newAge;
                }
                break;
            case 4:
                validations_getFloat(&newSalary,"\n\tIngrese nuevo salario: ", "\n\t(!) Error. Ingrese un valor numerico flotante.\n",1,sizeof(float),0,9999999,4);
                if(confirm(3))
                {
                    list[index].salary = newSalary;
                }
                break;
            case 5:
                printf("\nAca va la fecha de ingreso");
                break;
        }

        printf("\n");
        printf("\n\t\t __________________________________________________________________________");
        printf("\n\t\t*        ID     NOMBRE    SEXO    EDAD    SUELDO    F. DE INGRESO          *");
        printf("\n\t\t*                                                                          *");
        employee_showOne(list[index]);
        printf("\n\t\t*                                                                          *\n\t\t*__________________________________________________________________________*\n\n");

        system("pause");
    }
}

void employee_show(eEmployee list[], int size)
{
    int flag = 0;

    system("cls");
    printf("\n\t*** LISTAR *********************************************************************************\n\n");
    printf("\t\tID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRESO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == TAKEN)
        {
            employee_showOne(list[i]);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void employee_showOne(eEmployee x)
{
    printf("\n\t\t%d %8s     %c      %d    %.2f    %02d/%02d/%4d\n", x.id, x.name, x.gender,x.age, x.salary, x.dateOfAdmission.day, x.dateOfAdmission.month, x.dateOfAdmission.year);
}

void employee_sort(eEmployee list[], int size, int mode)
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

void employee_inform(eEmployee list[], int size)
{
    char cont = 's';

    system("cls");
    printf("\n\t*** INFORMES *********************************************************************************\n\n");

    do{
        switch(menu_employeeInform())
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:

                break;
            case 7:
                if(confirm(7) == 1)
                {
                    cont = 'n';
                }
                break;
        }
    }while(cont == 's');
}

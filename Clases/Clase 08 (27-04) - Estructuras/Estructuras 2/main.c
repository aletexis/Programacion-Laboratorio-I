#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"

#define SIZE 10
#define SIZESEC 5
#define CANTHARDCODE 9
#define EMPTY 0
#define TAKEN 1

typedef struct
{
    int day;
    int month;
    int year;

}eDate;

typedef struct
{
    int id;
    char name[20];
    char gender;
    int age;
    float salary;
    eDate dateOfAdmission;
    eDate dateOfBirth;
    int idSector;  //fk
    int state;

}eEmployee;

typedef struct
{
    int id;  //pk
    char description[20];
}eSector;

void showEmployees(eEmployee[], int, eSector[], int);
void showEmployee(eEmployee x, eSector[], int);
void sortEmployees(eEmployee[], int, int, eSector[], int);
void initializateEmployee(eEmployee[], int);
int findFreeSpace(eEmployee[], int);
int findEmployee(int, eEmployee[], int);
int altaEmployee(int, eEmployee[], int, eSector[], int);
void bajaEmployee(eEmployee list[], int size, eSector[], int);
//modificar falta
int getMenuOption();
void hardcodearEmployees(eEmployee list[], int employeesToHardcode);

void inform(eEmployee[], int, eSector[], int);
void informMenu();
void inform_employeesXyear(eEmployee list[], int size);
void inform_employeesXmen(eEmployee list[], int size);
void inform_totalsalaries(eEmployee list[], int size);


/**
* description: es la cadena a la que quiero que se le copie el nombre del sector.
* Id: es el id del sector del cual yo quiero copiar la cadena
* Sectors: donde quiero hacer la busqueda
* Size: el tamaño de ese vector
**/
int sector_loadDescription(char description[], int id, eSector sectors[], int size);




int main()
{
    eEmployee list[SIZE];
    char cont = 's';
    //char confirm;
    int option;
    int nextID = 1000;
    eEmployee list[SIZE];
    eSector sectors[] = {{1, "Sistemas"}, {2, "RRHH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"}};

    initializateEmployee(list, SIZE);

    hardcodearEmployees(list, CANTHARDCODE);//hardcodeamos
    nextID += CANTHARDCODE;//acualizamos la variable para que siga desde 1005

    do{
        option = getMenuOption();

        switch(option)
        {
            case 1:
                if(altaEmployee(nextID, list, SIZE, sectors, SIZESEC) == 1)
                {
                    nextID++;
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                showEmployees(list, SIZE, sectors, SIZESEC);
                sortEmployees(list, SIZE, 0, sectors, SIZESEC);
                showEmployees(list, SIZE, sectors, SIZESEC);
                sortEmployees(list, SIZE, 1, sectors, SIZESEC);
                break;
            case 5:
                showEmployees(list, SIZE, sectors, SIZESEC);
                break;
            case 6:

                break;
            case 7:
                printf("\n¿Esta seguro que desea salir? (y/n) \n");
                /*setbuf(stdin,NULL);
                scanf("%c", &confirm);
                if(confirm == 'y')
                {
                    cont = 'n';
                }*/
                cont = 'n';
                break;
            default:
                system("cls");
                printf("\nEl numero de opcion no es valido. Ingrese nuevamente\n\n");
                break;
        }

    }while(cont == 'y');

    return 0;
}
void showEmployees(eEmployee list[], int size, eSector sectors[], int sizeSec)
{
    int flag = 0;

    printf("\n******************** LISTADO DE EMPLEADOS ********************\n\n");
    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO  SECTOR\n");

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

void sortEmployees(eEmployee list[], int size, int mode)
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

int getMenuOption()
{
    int option;

    printf("\n\n\t\t************** ABM **************\n\t\t\n");
    printf("\t\t    1. Alta\n");
    printf("\t\t    2. Baja\n");
    printf("\t\t    3. Modificacion\n");
    printf("\t\t    4. Ordenar\n");
    printf("\t\t    5. Listar\n");
    printf("\t\t    6. Informes\n");
    printf("\t\t    7. Salir\n\t\t\n");
    printf("\t\t*****************************************\n");

    printf("\n\nIngrese una opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &option);

    return option;
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

int altaEmployee(int nextID, eEmployee list[], int size)
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

void bajaEMployee(eEmployee list[], int size)
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
        showEmployee(list[index]);

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

void inform(eEmployee list[], int size)
{
    char seguir = 's';

    system("cls");
    printf("\n*** Informes *******************");

     do{

        switch(informMenu())
        {
            case 1:
                inform_employeesXyear(list, size);
                break;
            case 2:
                inform_employeesXmen(list, size);
                break;
            case 3:
                inform_totalsalaries(list, size);
                break;
            case 4:
                printf("\nInforme D");
                break;
            case 5:
                printf("\nInforme E");
                break;
            case 6:
                printf("\nInforme F");
                break;
            case 7:
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

void informMenu()
{
    int option;

    printf("\n\n\t\t************** INFORMES **************\n\t\t\n");
    printf("\t\t    1. Informe empleados de un anio\n");
    printf("\t\t    2. Informe empleados varones\n");
    printf("\t\t    3. informe total de sueldos\n");
    printf("\t\t    4. Informe D\n");
    printf("\t\t    5. Informe E\n");
    printf("\t\t    6. Informe F\n");
    printf("\t\t    7. Salir\n\t\t\n");
    printf("\t\t*****************************************\n");

    printf("\n\nIngrese una opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &option);

    return option;
}

void inform_employeesXyear(eEmployee list[], int size)
{
    int year;
    int flag = 0;

    system("cls");
    printf("\n******************** EMPLEADOS POR ANIO DE INGRESO ********************\n\n");

    printf("\ingrese año: ");
    scanf("%d", &year);

    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].dateOfAdmission.year == year)
        {
            showEmployee(list[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay empleados para mostrar\n");
    }
}

void inform_employeesXmen(eEmployee list[], int size)
{
    int flag = 0;

    system("cls");
    printf("\n******************** EMPLEADOS VARONES ********************\n\n");

    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1 && list[i].gender == 'm')
        {
            showEmployee(list[i]);
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


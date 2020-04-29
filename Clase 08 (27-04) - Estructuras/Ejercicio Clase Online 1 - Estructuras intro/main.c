#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
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
    int state;

}eEmployee;

void showEmployees(eEmployee[], int);
void showEmployee(eEmployee x);
void sortEmployees(eEmployee[], int, int);
void initializateEmployee(eEmployee[], int);

int main()
{
    /*
    eEmployee list[SIZE] = {
        {1234, "Jose", 'm', 23, 12300,{12,3,2018}},
        {3291, "Juana", 'f', 31, 23400,{10,11,2015}},
        {4455, "Daniela", 'f', 34, 21800, {16,3,2017}},
        {1189, "Lucia", 'f', 20, 20500, {11,2,2014}},
        {1020, "Andres", 'm', 23, 19700, {7,4,2012}}
    };*/

    eEmployee list[SIZE];
    char cont = 'y';

    do
    {
        switch(showMenu);

    }while(cont == 'y');

    //eEmployee oneEmployee = {1234, "Juan", 'm', 30, 20000.50, {27,4,2020}};
    //eEmployee anotherEmployee;
    //eDate auxDate;

    //anotherEmployee = oneEmployee;

    //printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
    //scanf("%d/%d/%d", &anotherEmployee.dateOfAdmission.day, &anotherEmployee.dateOfAdmission.month, &anotherEmployee.dateOfAdmission.year);

    /////////////////

   //printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
    //scanf("%2d/%2d/%4d", &auxDate.day, &auxDate.month, &auxDate.year);
    //anotherEmployee.dateOfAdmission = auxDate;
    /////////////////

    initializateEmployee(list, SIZE);

/*
    for(int i=0; i<SIZE; i++)
    {
        printf("\nIngrese id: ");
        scanf("%d", &list[i].id);

        printf("\nIngrese nombre: ");
        setbuf(stdin, NULL);
        gets(list[i].name);

        printf("\nIngrese sexo: ");
        setbuf(stdin, NULL);
        scanf("%c", &list[i].gender);

        printf("\nIngrese edad: ");
        scanf("%d", &list[i].age);

        printf("\nIngrese sueldo: ");
        scanf("%f", &list[i].salary);

        printf("\nIngrese fecha de ingreso dd/mm/aaaa: ");
        scanf("%d/%d/%d", &list[i].dateOfAdmission.day, &list[i].dateOfAdmission.month, &list[i].dateOfAdmission.year);
    }
*/
    showEmployees(list,SIZE);
    sortEmployees(list, SIZE, 0);
    showEmployees(list,SIZE);
    sortEmployees(list, SIZE, 1);
    showEmployees(list,SIZE);

    return 0;
}
void showEmployees(eEmployee list[], int size)
{
    int flag = 0;

    printf("\n******************** LISTADO DE EMPLEADOS ********************\n\n");
    printf("ID     NOMBRE    SEXO   EDAD    SUELDO    F. DE INGRSO\n");

    for(int i=0; i<size; i++)
    {
        if(list[i].state == 1)
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

void showEmployee(eEmployee x)
{
    printf("\n%d %8s     %c      %d    %.2f    %02d/%02d/%4d\n", x.id, x.name, x.gender,x.age, x.salary, x.dateOfAdmission.day, x.dateOfAdmission.month, x.dateOfAdmission.year);
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

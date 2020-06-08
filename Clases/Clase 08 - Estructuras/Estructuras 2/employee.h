#include "sector.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

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

#endif // EMPLOYEE_H_INCLUDED

void showEmployees(eEmployee[], int, eSector[], int);
void showEmployee(eEmployee x, eSector[], int);
void sortEmployees(eEmployee[], int, int, eSector[], int);
void initializateEmployee(eEmployee[], int);
int findFreeSpace(eEmployee[], int);
int findEmployee(int, eEmployee[], int);
int altaEmployee(int, eEmployee[], int, eSector[], int);
void bajaEmployee(eEmployee list[], int size, eSector[], int);
//modificar falta
void hardcodearEmployees(eEmployee list[], int employeesToHardcode);
/**
* description: es la cadena a la que quiero que se le copie el nombre del sector.
* Id: es el id del sector del cual yo quiero copiar la cadena
* Sectors: donde quiero hacer la busqueda
* Size: el tamaño de ese vector
**/
int sector_loadDescription(char description[], int id, eSector sectors[], int size);

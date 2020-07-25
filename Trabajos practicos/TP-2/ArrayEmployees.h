#include "validations.h"

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
     int id;
     char name[51];
     char lastName[51];
     float salary;
     int sector;
     int isEmpty;
}Employee;

#endif //ARRAYEMPLOYEES_H_INCLUDED

//Alta
int initEmployee(Employee[], int);
int findFreeSpace(Employee[], int);
int findEmployeeById(Employee[], int, int);

int addEmployee(Employee[], int, int);
void removeEmployee(Employee[], int);
void modifyEmployee(Employee[], int);

void printEmployees(Employee[], int);
void printOneEmployee(Employee oneEmployee);
void informEmployee(Employee[], int);
void sortEmployees(Employee[], int, int);
void printSalaries(Employee[], int);

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

void employee_hardcode(eEmployee[], int);
void employee_initializate(eEmployee[], int);
int findFreeSpace(eEmployee[], int);
int employee_find(int, eEmployee[], int);

void employee_load(eEmployee[], int);
void employee_delate(eEmployee[], int);
void employee_modify(eEmployee[], int);
void employee_show(eEmployee[], int);
void employee_showOne(eEmployee);
void employee_sort(eEmployee[], int, int);

#endif // EMPLOYEE_H_INCLUDED



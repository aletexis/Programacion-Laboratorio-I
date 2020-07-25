#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParameters(int id,char* name,int hoursWorked,int salary);
Employee* employee_newParametersStr(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setName(Employee* this,char* name);
int employee_getName(Employee* this,char* name);

int employee_setHoursWorked(Employee* this,int hoursWorked);
int employee_getHoursWorked(Employee* this,int* hoursWorked);

int employee_setSalary(Employee* this,int salary);
int employee_getSalary(Employee* this,int* salary);

int employee_printOne(Employee*);

int employee_sortById(void*, void*);
int employee_sortByName(void*, void*);
int employee_sortByHoursWorked(void*, void*);
int employee_sortBySalary(void*, void*);

#endif // employee_H_INCLUDED

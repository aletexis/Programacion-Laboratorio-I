#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "Employee.h"

/** \brief Genera espacio en memoria para guardar un empleado
 *
 * \param void
 * \return Employee* pEmployee El puntero al empleado
 *
 */
Employee* employee_new()
{
    Employee* pEmployee = (Employee*)calloc(sizeof(Employee), 1);
    return pEmployee;
}

/** \brief Le asigna unos nuevos parametros al nuevo empleado
 *
 * \param id int La variable a la que se le asigna el nuevo id
 * \param name char* La variable a la que se le asigna el nuevo nombre
 * \param hoursWorked int La variable a la que se le asigna las nuevas horas trabajadas
 * \param salary int La variable a la que se le asigna el nuevo salario
 * \return Employee* El empleado con los datos cargados
 *
 */
Employee* employee_newParameters(int id, char* name, int hoursWorked, int salary)
{
    Employee* newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if(! (employee_setId(newEmployee, id) && employee_setName(newEmployee, name) && employee_setHoursWorked(newEmployee, hoursWorked) && employee_setSalary(newEmployee, salary)))
        {
            free(newEmployee);
            newEmployee = NULL;
        }
    }

    return newEmployee;
}

/** \brief Le asigna unos nuevos parametros al nuevo empleado
 *
 * \param char* idStr La variable a la que se le asigna el nuevo id
 * \param char* nameStr La variable a la que se le asigna el nuevo nombre
 * \param char* hoursWorkedStr La variable a la que se le asigna las nuevas horas trabajadas
 * \param char* salaryStr La variable a la que se le asigna el nuevo salario
 * \return Employee* El empleado con los datos cargados
 *
 */
Employee* employee_newParametersStr(char* idStr,char* nameStr,char* hoursWorkedStr, char* salaryStr)
{
    return employee_newParameters(atoi(idStr), nameStr, atoi(hoursWorkedStr), atoi(salaryStr));
}

/** \brief Libera el espacio en memoria
 *
 * \param Employee* El campo de la estructura que se desea liberar
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);

}

/** \brief Establece un valor al campo id
 *
 * \param Employee* El campo de la estructura
 * \param int El id que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int employee_setId(Employee* this, int id)
{
    int ok = 0;

    if(this != NULL && id >=0) //valido que id sea positivo
    {
        this->id = id;
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo id
 *
 * \param Employee* El campo de la estructura que se desea obtener el dato
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int employee_getId(Employee* this, int* id)
{
    int ok = 0;

    if(this != NULL && id != NULL)
    {
       *id = this->id;
       ok = 1;

    }
    return ok;
}

/** \brief Establece un valor al campo nombre
 *
 * \param Employee* El campo de la estructura
 * \param int El nombre que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int employee_setName(Employee* this, char* name)
{
    int ok = 0;

    if(this != NULL && name != NULL && strlen(name) >= 3 && strlen(name) < 128)//valido que sea de un largo determinado
    {
        strcpy(this->name,name);
        ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo nombre
 *
 * \param Employee* El campo de la estructura que se desea obtener el dato
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int employee_getName(Employee* this,char* name)
{
    int ok = 0;

    if(this != NULL && name != NULL)
    {
       strcpy(name,this->name);
       ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo horas trabajadas
 *
 * \param Employee* El campo de la estructura
 * \param int Las horas trabajadas que se van a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int employee_setHoursWorked(Employee* this, int hoursWorked)
{
    int ok = 0;

    if(this != NULL && hoursWorked >=0)// valido que las horas sean positivas
    {
      this->hoursWorked = hoursWorked;
      ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo horas trabajadas
 *
 * \param Employee* El campo de la estructura que se desea obtener el dato
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int employee_getHoursWorked(Employee* this, int* hoursWorked)
{
    int ok = 0;

    if(this != NULL && hoursWorked != NULL)
    {
      *hoursWorked = this->hoursWorked;
      ok = 1;
    }
    return ok;
}

/** \brief Establece un valor al campo salario
 *
 * \param Employee* El campo de la estructura
 * \param int El salario que se va a establecer
 * \return int (1) si pudo establecer el valor (0) si no pudo
 *
 */
int employee_setSalary(Employee* this, int salary)
{
    int ok = 0;

    if(this != NULL && salary >=0)// valido que el salario sea positivo
    {
      this->salary = salary;
      ok = 1;
    }
    return ok;
}

/** \brief Obtiene un valor del campo salario
 *
 * \param Employee* El campo de la estructura que se desea obtener el dato
 * \return int (1) si pudo obtener el valor (0) si no pudo
 *
 */
int employee_getSalary(Employee* this, int* salary)
{
    int ok = 0;

    if(this != NULL && salary != NULL)
    {
      *salary = this->salary;
      ok = 1;
    }
    return ok;
}

/** \brief Ordena los elementos por id
 *
 * \param void* element1 El primer elemento a comparar
 * \param void* element2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int employee_sortById(void* element1, void* element2)
{
    int employee1;
    int employee2;
    int ret = 0;

    if ((element1 != NULL) && (element2 != NULL))
    {
        employee_getId(element1, &employee1);
        employee_getId(element2, &employee2);

        if(employee1 > employee2)
        {
            ret = 1;
        }
        else if(employee1 < employee2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por nombre
 *
 * \param void* element1 El primer elemento a comparar
 * \param void* element2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int employee_sortByName(void* element1, void* element2)
{
    char employee1[128];
    char employee2[128];
    int ret = 0;
    int comparison;

    if(element1 != NULL && element2 != NULL)
    {
        employee_getName(element1, employee1);
        employee_getName(element2, employee2);
        comparison = strcmp(employee1, employee2);

        if(comparison > 0)
        {
            ret = 1;
        }
        else if(comparison < 0)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por horas trabajadas
 *
 * \param void* element1 El primer elemento a comparar
 * \param void* element2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int employee_sortByHoursWorked(void* element1, void* element2)
{
    int employee1;
    int employee2;
    int ret = 0;

    if((element1 != NULL) && (element2 != NULL))
    {
        employee_getHoursWorked(element1, &employee1);
        employee_getHoursWorked(element2, &employee2);

        if(employee1 > employee2)
        {
            ret = 1;
        }
        else if(employee1 < employee2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Ordena los elementos por salario
 *
 * \param void* element1 El primer elemento a comparar
 * \param void* element2 El segundo elemento a comparar
 * \return (0) si son iguales, (1) si el primero es mayor, (-1) si el primero es menor
 *
 */
int employee_sortBySalary(void* element1, void* element2)
{
    int employee1;
    int employee2;
    int ret = 0;

    if((element1 != NULL) && (element2 != NULL))
    {
        employee_getSalary(element1, &employee1);
        employee_getSalary(element2, &employee2);

        if(employee1 > employee2)
        {
            ret = 1;
        }
        else if(employee1 < employee2)
        {
            ret = -1;
        }
    }
    return ret;
}

/** \brief Muestra un solo empleado y sus atributos
 *
 * \param Employee* oneEmployee El empleado a mostrar
 * \return int (1) si pudo mostrarlos (0) si no pudo
 *
 */
int employee_printOne(Employee* employee)
{
    int ok = 0;
    int id;
    char name[128];
    int hoursWorked;
    int salary;

    if(employee != NULL)
    {
        employee_getId(employee,&id);
        employee_getName(employee,name);
        employee_getHoursWorked(employee,&hoursWorked);
        employee_getSalary(employee,&salary);

        printf("\t     %10d          %10s    %10d    %10d\n",id,name,hoursWorked,salary);
        ok = 1;
    }

    return ok;
}


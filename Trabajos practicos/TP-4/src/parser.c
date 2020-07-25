#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si pudo parsear los datos (-1) si no pudo
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok = -1;
    int r;
    char idStr[50];
    char nameStr[128];
    char hoursWorkedStr[50];
    char salaryStr[50];
    Employee* newEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nameStr, hoursWorkedStr, salaryStr);

        while(!feof(pFile))
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nameStr, hoursWorkedStr, salaryStr);
            if(r == 4)
            {
                newEmployee = employee_newParametersStr(idStr, nameStr, hoursWorkedStr, salaryStr);
                if(newEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, newEmployee);
                    ok = 1;
                }
            }
            else
            {
                break;
            }
        }
    }
    return ok;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* La ruta del archivo que se cargara
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si pudo parsear los datos (-1) si no pudo
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = -1;
    int r;
    Employee* newEmployee = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            newEmployee = employee_new();

            if(newEmployee != NULL)
            {
                r = fread(newEmployee, sizeof(Employee), 1, pFile);
            }
            if(r < 1)
            {
                break;
            }
            ll_add(pArrayListEmployee, newEmployee);
            ok = 1;
        }
    }

    return ok;
}

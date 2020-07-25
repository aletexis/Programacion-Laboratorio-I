#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "validations.h"
#include "menu.h"
#include "extras.h"

int getID(int* id)
{
    int error = 1;

    *id = 1000;
    FILE* f = fopen("proximoId.bin", "rb");

    if(f != NULL)
    {
        fread(id, sizeof(int), 1, f);
        fclose(f);
        error = 0;
    }
    return error;
}

/** \brief Una vez que use el id y quiero guardar el id entregado
 *
 * \param id int
 * \return int
 *
 */
int updateID(int id)
{
    int error = 1;

    id++;
    FILE* f = fopen("proximoId.bin", "wb");

    if(f != NULL)
    {
        fwrite(&id, sizeof(int), 1, f);
        fclose(f);
        error = 0;
    }
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se cargo el archivo (-1) si no se cargo
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        if((pFile = fopen(path, "r")) != NULL)
        {
            if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 1)
            {
                printf("\n\n\t>>> Archivo cargado exitosamente <<<\n\n");
                ret = 1;
            }
        }
        else
        {
            printf("\n\n\t>>> Error al cargar el archivo <<<\n\n");
        }
        fclose(pFile);
    }

    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* La ruta donde se encuentra el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se cargo el archivo (-1) si no se cargo
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        if((pFile = fopen(path, "rb")) != NULL)
        {
            if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 1)
            {
                printf("\n\n\t>>> Archivo cargado exitosamente <<<\n\n");
                ret = 1;
            }
        }
        else
        {
            printf("\n\n\t>>> Error al cargar el archivo <<<\n\n");
        }
        fclose(pFile);
    }

    return ret;
}

/** \brief Agrega un empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se agrego el empleado (-1) si no se agrego
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee = employee_new();
    int ret = -1;
    int exists;
    int id;
    char name[128];
    int hoursWorked;
    int salary;


    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            system("clear");
            printf("\n\t*** ALTA ******************************************************\n\n");

            validations_getUnsignedInt(&id,"\n\tIngrese el ID: ", "\n\t(!) Error. Ingrese un valor numerico entero. \n",1,999999,1,999999,4);

            exists = controller_employee_findOne(pArrayListEmployee, id, &exists);

            if(exists != -1)
            {
                printf("\n\n\t\t>>> Ya hay registro de un empleado con el ID %d <<<\n\n\n", id);
                system_pause("linux");
            }
            else
            {
                if(! (validations_getText(name,"\n\tIngrese el nombre del empleado: ", "\n\t(!) Error. Caracteres invalidos.\n", 3, 128, 4)) &&
                   ! (validations_getUnsignedInt(&hoursWorked,"\n\tIngrese las horas trabajadas: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1-730\n",1,730,1,730,4)) &&
                   ! (validations_getUnsignedInt(&salary,"\n\tIngrese el salario: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,1000000,1,1000000,4)))
                {
                    newEmployee = employee_newParameters(id, name, hoursWorked, salary);
                    ll_add(pArrayListEmployee,newEmployee);
                    printf("\n\n\t>>> Empleado dado de alta exitosamente <<<\n\n");
                    ret = 1;
                }
            }
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Modifica un empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se modifico el empleado (-1) si no se modifico
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    int index;
    int id;
    char newName[128];
    int newHoursWorked;
    int newSalary;
    int ret = -1;


    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            system_clear("linux");
            printf("\n\t*** MODIFICACION *******************************************************\n\n");

            controller_listEmployee(pArrayListEmployee);

            validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,999999,1,999999,4);

            controller_employee_findOne(pArrayListEmployee, id, &index);

            if(index == -1)
            {
                printf("\n\n\t\t>>> No hay registro de un empleado con el ID %d <<<\n\n\n", id);
            }
            else
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
                system_clear("linux");
                printf("\n\t\tEl empleado que se modificara es:");
                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID              NOMBRE         HORAS       SALARIO     ");
                printf("\n\t\t ___________________________________________________________\n");
                employee_printOne(pAuxEmployee);
                printf("\n\t\t ___________________________________________________________\n\n");


                switch(menu_modify())
                {
                    case 1:
                        validations_getText(newName,"\n\tIngrese nuevo nombre: ", "\n\t(!) Error. Caracteres invalidos.\n", 3, 128, 4);
                        if(confirm(5))
                        {
                            employee_setName(pAuxEmployee, newName);
                        }
                        break;
                    case 2:
                        validations_getUnsignedInt(&newHoursWorked,"\n\tIngrese nuevas horas trabajadas: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);
                        if(confirm(5))
                        {
                            employee_setHoursWorked(pAuxEmployee, newHoursWorked);
                        }
                        break;
                    case 3:
                        validations_getUnsignedInt(&newSalary,"\n\tIngrese nuevo salario: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);
                        if(confirm(5))
                        {
                            employee_setSalary(pAuxEmployee, newSalary);
                        }
                        break;
                }

                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID              NOMBRE         HORAS       SALARIO     ");
                printf("\n\t\t ___________________________________________________________\n");
                employee_printOne(pAuxEmployee);
                printf("\n\t\t ___________________________________________________________\n\n");

                system_pause("linux");
                ret = 1;
            }
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Elimina un empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se elimino el empleado (-1) si no se elimino
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    int index;
    int id;
    int ret = -1;


    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            system_clear("linux");
            printf("\n\t*** BAJA *******************************************************\n\n");

            controller_listEmployee(pArrayListEmployee);

            validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,999999,1,999999,4);

            controller_employee_findOne(pArrayListEmployee, id, &index);

            if(index == -1)
            {
                printf("\n\n\t\t>>> No hay registro de un empleado con el ID: %d <<<\n\n\n", id);
            }
            else
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, index);
                system_clear("linux");
                printf("\n\t\tEl empleado que se dara de baja es:");
                printf("\n");
                printf("\n\t\t ___________________________________________________________\n");
                printf("\n\t\t     ID              NOMBRE         HORAS       SALARIO     ");
                printf("\n\t\t ___________________________________________________________\n");
                employee_printOne(pAuxEmployee);
                printf("\n\t\t ___________________________________________________________\n\n");

                if(confirm(4))
                {
                    ll_remove(pArrayListEmployee, index);
                    employee_delete(pAuxEmployee);
                }
                ret = 1;
            }
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }

    return ret;
}

/** \brief Lista empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se listaron los empleados (-1) si no se listaron
 *
 */
int controller_listEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int flag = 0;
    int size;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        ret = 1;
        size = ll_len(pArrayListEmployee);
        printf("\n");
        printf("\n\t\t ___________________________________________________________\n");
        printf("\n\t\t     ID              NOMBRE         HORAS       SALARIO     ");
        printf("\n\t\t ___________________________________________________________\n");

        for(int i=0; i<size; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if(auxEmployee != NULL)
            {
                employee_printOne(auxEmployee);
                flag = 1;
            }
        }
        printf("\n\t\t ___________________________________________________________\n\n");
        if(flag == 0)
        {
            printf("\n\n\t>>> No hay personas para mostrar <<<\n\n");
        }
        printf("\n\n");
    }

    return ret;
}

/** \brief Ordena los empleados
 *
 * \param pArrayListEmployee LinkedList* La lista de empleados
 * \return int (1) si se ordenaron los empleados (-1) si no se ordenaron
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int order;

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            switch(menu_sort())
            {
                case 1:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(pArrayListEmployee, employee_sortById, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 2:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(pArrayListEmployee, employee_sortByName, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 3:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(pArrayListEmployee, employee_sortByHoursWorked, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
                case 4:
                    order = menu_order();
                    if(order == -1)
                    {
                        order = 0;
                    }
                    printf("\n\n\tEsto tomara unos segundos...\n\n");
                    ll_sort(pArrayListEmployee, employee_sortBySalary, order);
                    printf("\n\n\t>>> El archivo se ordeno exitosamente <<<\n\n");
                    system_pause("linux");
                    break;
            }
            ret = 1;
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados a guardar
 * \return int (1) si se guardaron los empleados (-1) si no se guardaron
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    FILE* pFile = fopen(path, "w");
    int size = ll_len(pArrayListEmployee);
    int ret = -1;
    int id;
    char name[128];
    int hoursWorked;
    int salary;


    if(pFile == NULL)
    {
        printf("\n\n\t>>> Error al guardar el archivo <<<\n\n");
    }

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

            for(int i=0; i<size; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                employee_getId(pAuxEmployee,&id);
                employee_getName(pAuxEmployee,name);
                employee_getHoursWorked(pAuxEmployee,&hoursWorked);
                employee_getSalary(pAuxEmployee,&salary);

                fprintf(pFile, "%d,%s,%d,%d\n",id,name,hoursWorked,salary);
            }
            printf("\n\n\t>>> Archivo guardado exitosamente <<<\n\n");
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    fclose(pFile);

    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* La ruta donde se guardara el archivo
 * \param pArrayListEmployee LinkedList* La lista de empleados a guardar
 * \return int (1) si se guardaron los empleados (-1) si no se guardaron
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pAuxEmployee;
    FILE* pFile = fopen(path, "wb");
    int size = ll_len(pArrayListEmployee);
    int ret = -1;


    if(pFile == NULL)
    {
        printf("\n\n\t>>> Error al guardar el archivo <<<\n\n");
    }

    if(ll_isEmpty(pArrayListEmployee) == 0)
    {
        if(pArrayListEmployee != NULL)
        {
            for(int i=0; i<size; i++)
            {
                pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
                fwrite(pAuxEmployee, sizeof(Employee), 1, pFile);

            }
            printf("\n\n\t>>> Archivo guardado exitosamente <<<\n\n");
        }
    }
    else
    {
        printf("\n\n\t>>> No se cargaron datos <<<\n\n");
    }
    fclose(pFile);

    return ret;
}


/** \brief Busca un empleado
 *
 * \param pArrayListEmployee LinkedList* La lista de empelados
 * \param id int El ID del empleado a buscar
 * \param index int* El indice que indica la posicion del empleado en la lista
 * \return int (1) si se encontro el empleado (-1) si no se encontro
 *
 */
int controller_employee_findOne(LinkedList* pArrayListEmployee, int id, int* index)
{
    int ok = -1;
    int size;
    int auxId;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
        size = ll_len(pArrayListEmployee);

        for(int i=0; i<size; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(auxEmployee, &auxId);

            if(auxEmployee != NULL && id == auxId)
            {
                *index = i;
                ok = 1;
                break;
            }
        }
    }

    return ok;
}

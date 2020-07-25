#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "validations.h"
#include "extras.h"
#include "menu.h"

// isEmpty? 1 = si = vacio
// isEmpty? 0 = no = ocupado


/** \brief Inicializa los campos de la estructura en 0 o vacio
 *
 * \param list[] La lista de empleados
 * \param int len El tamaño del array
 * \return int
 *
 */
int initEmployee(Employee list[], int len)
{
    for(int i=0; i<len; i++)
    {
        strcpy(list[i].name, " ");
        strcpy(list[i].lastName, " ");
        list[i].salary = 0;
        list[i].sector = 0;
        list[i].id = 0;
        list[i].isEmpty = 1;
    }
    return 0;
}

/** \brief Busca espacio libre para guardar informacion
 *
 * \param list[] La lista de empleados
 * \param int len El tamaño del array
 * \return int index 1 si hay lugar, -1 si no hay
 *
 */
int findFreeSpace(Employee list[], int len)
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Busca un empleado
 *
 * \param list[] El empleado
 * \param int len El tamaño del array
 * \param int id El id del empleado
 * \return int index -1 si no existe, la posicion si existe
 *
 */
int findEmployeeById(Employee list[], int len, int id)
{
    int index = -1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}



/** \brief Agrega elementos al array
 *
 * \param lista[] El empleado
 * \param int len El tamaño del array
* \param int id El id autoincremental
 * \return int (1) si pudo agregarse (0) si no se pudo
 *
 */
int addEmployee(Employee list[], int len, int id)
{
    Employee auxEmployee;
    int index = findFreeSpace(list, len);
    int ok = 0;

    system("cls");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system("pause");
    }
    else
    {
        auxEmployee.id = id;

        validations_getText(auxEmployee.name,"\n\tIngrese nombre: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 51, 4);
        validations_getText(auxEmployee.lastName,"\n\tIngrese apellido: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 51, 4);
        validations_getFloat(&auxEmployee.salary,"\n\tIngrese salario: ", "\n\t(!) Error. Ingrese un valor numerico flotante.\n",1,15,0,9999999,4);
        validations_getUnsignedInt(&auxEmployee.sector,"\n\tIngrese numero del sector: ", "\n\t(!) Error. Ingrese un valor numerico entero", 1, sizeof(int), 1, 99999, 4);
        auxEmployee.isEmpty = 0;

        list[index] = auxEmployee;
        printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
        system("pause");

        ok = 1;
    }
    return ok;
}


/** \brief Elimina un empleado de manera logica
 *
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \param int id El id del empleado
 * \return void
 *
 */
void removeEmployee(Employee list[], int len)
{
    int id;
    int index;
    int i=0;

    system("cls");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    if(list[i].isEmpty == 0)
    {
        printEmployees(list, len);

        validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,1001,-1,1001,4);

        index = findEmployeeById(list, len, id);

        if(index == -1)
        {
            printf("\n\n\t\t>>> No hay registro de un empleado con el ID: %d <<<\n\n\n", id);
            system("pause");
        }
        else
        {
            system("cls");
            printf("\n\t\tEl empleado que se dara de baja es:");
            printf("\n");
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR \n");
            printf("\t\t_______________________________________________________________\n");
            printOneEmployee(list[index]);
            printf("\n");

            if(confirm(2))
            {
                list[index].isEmpty = 1;
            }
        }
   }
    else
    {
        printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
    }

}


/** \brief Permite modificar los campos ingresados anteriormente
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \return void
 */
void modifyEmployee(Employee list[], int len)
{
    int id;
    int index;
    char newName[51];
    char newLastName[51];
    float newSalary;
    int newSector;
    int i=0;

    system("cls");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    if(list[i].isEmpty == 0)
    {
        printEmployees(list, len);

        validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,1001,-1,1001,9);

        index = findEmployeeById(list, len, id);

        if(index == -1)
        {
            printf("\n\n\t\t>>> No hay registro de un empleado con el ID: %d <<<\n\n\n", id);
            system("pause");
        }
        else
        {
            system("cls");
            printf("\n\t\tEl empleado que se modificara es:");
            printf("\n");
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR \n");
            printf("\t\t_______________________________________________________________\n");
            printOneEmployee(list[index]);
            printf("\n");

            switch(menu_employeeModify())
            {
                case 1:
                    validations_getText(newName,"\n\tIngrese nuevo nombre: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 51, 4);
                    if(confirm(3))
                    {
                        strcpy(list[index].name, newName);
                    }
                    break;
                case 2:
                    validations_getText(newLastName,"\n\tIngrese nuevo apellido: ", "\n\t(!) Error. Caracteres invalidos.\n", 1, 51, 4);
                    if(confirm(3))
                    {
                        strcpy(list[index].lastName, newLastName);
                    }
                    break;
                case 3:
                    validations_getFloat(&newSalary,"\n\tIngrese nuevo salario: ", "\n\t(!) Error. Ingrese un valor numerico flotante.\n",1,sizeof(float),0,9999999,4);
                    if(confirm(3))
                    {
                        list[index].salary = newSalary;
                    }
                    break;
                case 4:
                    validations_getUnsignedInt(&newSector,"\n\tIngrese nuevo sector: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",1,sizeof(int),0,9999,4);
                    if(confirm(3))
                    {
                        list[index].sector = newSector;
                    }
                    break;
            }

            printf("\n");
            printf("\t\t_______________________________________________________________\n");
            printf("\t\t ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR \n");
            printf("\t\t_______________________________________________________________\n");
            printOneEmployee(list[index]);
            printf("\n");

            system("pause");
        }
    }
    else
    {
        printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
    }
}




/** \brief Imprime el array de empleados de forma encolumnada
 *
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \return int
 *
 */
void printEmployees(Employee list[], int len)
{
    int flag = 0;

    printf("\t\t_______________________________________________________________\n");
    printf("\t\t ID\tNOMBRE\t\tAPELLIDO\tSALARIO\t\tSECTOR \n");
    printf("\t\t_______________________________________________________________\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printOneEmployee(list[i]);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

/** \brief Imprime un solo empleado
 *
 * \param list[] El empleado
 * \param int len El tamaño del array
 * \return void
 *
 */
void printOneEmployee(Employee oneEmployee)
{
    printf("\n\t\t %d  %10s        %10s        %.2f             %d\n\n", oneEmployee.id, oneEmployee.name, oneEmployee.lastName, oneEmployee.salary, oneEmployee.sector);
}


/** \brief Permite que el usuario seleccione que quiere ver y lo muestra
 *
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \return void
 *
 */
void informEmployee(Employee list[], int len)
{
    int i=0;
    int option;
    int order;

    system("cls");
    printf("\n\t*** INFORMAR ****************************************************************************\n\n");

    if(list[i].isEmpty == 0)
    {
        option = menu_inform();
        switch(option)
        {
            case 1:
                    printEmployees(list, len);
                    break;
            case 2:
                    order = menu_order();
                    sortEmployees(list, len, order);
                    printEmployees(list, len);
                    break;
            case 3:
                    printSalaries(list, len);
                    break;
        }
    }
    else
    {
        printf("\n\n\t\t>>> Es necesario dar de alta para continuar <<<\n\n\n");
    }

}

/** \brief Ordena los empleados por apellido y sector de manera ascendente y descendente
 *
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \param int order El orden el cual se quiere ordenar y mostrar
 * \return int
 *
 */
void sortEmployees(Employee list[], int len, int order)
{
    int i, j;
    Employee aux;

    if(order == 1)//ASC
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) < 0)
                {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                }
                else
                {
                    if((strcmp(list[j].lastName, list[i].lastName) == 0) && (list[i].sector > list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
    }
    else//DESC
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName, list[i].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else
                {
                    if((strcmp(list[j].lastName, list[i].lastName) == 0) && (list[i].sector < list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
    }
}

/** \brief Imprime los salarios con la informacion solicitada
 *
 * \param list[] El listado de empleados
 * \param int len El tamaño del array
 * \return void
 *
 */
void printSalaries(Employee list[], int len)
{
    int i;
    float salariesAccumulator = 0;
    float salariesAverage = 0;
    int salariesCounter = 0;
    int highestSalariesCounter = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            salariesAccumulator = salariesAccumulator + list[i].salary;
            salariesCounter++;
        }
    }

    salariesAverage = (salariesAccumulator) / (salariesCounter);

    for(i=0; i<len; i++)
    {
        if((list[i].isEmpty == 0) && (list[i].salary > salariesAverage))
        {
            highestSalariesCounter++;
        }
    }

    printf("\n\tTotal de los salarios: %.2f", salariesAccumulator);
    printf("\n\tPromedio de los salarios: %.2f", salariesAverage);
    printf("\n\tCantidad de empleados que superan el salario promedio: %d\n\n", highestSalariesCounter);
}


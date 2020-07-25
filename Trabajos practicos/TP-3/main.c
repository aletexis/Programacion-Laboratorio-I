#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "extras.h"
#include "menu.h"


int main()
{
    char cont = 's';
    LinkedList* employeeList = ll_newLinkedList();

    do{
        switch(menu_main())
        {
            case 1:
                controller_loadFromText("data.csv",employeeList);
                break;
            case 2:
               controller_loadFromBinary("data.bin",employeeList);
                break;
            case 3:
                controller_addEmployee(employeeList);
                break;
            case 4:
                controller_removeEmployee(employeeList);
                break;
            case 5:
                controller_editEmployee(employeeList);
                break;
            case 6:
                controller_listEmployee(employeeList);
                break;
            case 7:
                controller_sortEmployee(employeeList);
                break;
            case 8:
                controller_saveAsText("data.csv",employeeList);
                break;
            case 9:
                controller_saveAsBinary("data.bin",employeeList);
                break;
            case 10:
                if(confirm(10) == 1)
                {
                    cont = 'n';
                }
                ll_deleteLinkedList(employeeList);
                break;
        }
    }while(cont == 's');
    return 0;
}

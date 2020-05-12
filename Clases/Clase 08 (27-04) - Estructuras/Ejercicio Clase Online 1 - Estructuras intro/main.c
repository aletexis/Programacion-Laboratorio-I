#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "extras.h"
#include "menu.h"
#include "sectors.h"
#define SIZE 8
#define HARDCODESIZE 8

int main()
{
    eEmployee list[SIZE];
    char cont = 's';

    employee_initializate(list, SIZE);

    employee_hardcode(list, HARDCODESIZE);
    //nextID += 5;

    do{
        switch(menu_main())
        {
            case 1:
                employee_load(list, SIZE);
                break;
            case 2:
                employee_delate(list, SIZE);
                break;
            case 3:
                employee_modify(list, SIZE);
                break;
            case 4:
                employee_show(list,SIZE);
                employee_sort(list, SIZE, 0);
                employee_show(list,SIZE);
                employee_sort(list, SIZE, 1);
                employee_show(list, SIZE);
                break;
            case 5:
                employee_show(list,SIZE);
                system("pause");
                break;
            case 6:

                break;
            case 7:
                if(confirm(7) == 1)
                {
                    cont = 'n';
                }
                break;
        }
    }while(cont == 's');

    return 0;
}

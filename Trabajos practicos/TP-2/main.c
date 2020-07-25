#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menu.h"
#include "extras.h"

#define LEN 1000
int main()
{
    Employee listEmployees[LEN];
    initEmployee(listEmployees, LEN);
    int nextID = 0;
    char cont = 's';

    do
    {
        switch(menu_main())
        {
            case 1:
                if(addEmployee(listEmployees, LEN, nextID)== 1)
                {
                     nextID++;
                }
                break;
            case 2:
                removeEmployee(listEmployees, LEN);
                break;
            case 3:
                modifyEmployee(listEmployees, LEN);
                break;
            case 4:
                informEmployee(listEmployees, LEN);
                break;
            case 5:
                if(confirm(5) == 1)
                {
                    cont = 'n';
                }
                break;
          }
    }while(cont == 's');

    return 0;
}

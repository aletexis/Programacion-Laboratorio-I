/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "extras.h"
#include "menu.h"


int main()
{
    /**Etapa 1: desarrollo de las funciones y testing**/
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort

    /**Etapa 2: aplicacion usando Linked List y sus funciones**/
    char cont = 's';
    LinkedList* employeeList = ll_newLinkedList();

    do
    {
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
    }
    while(cont == 's');

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "sector.h"
#include "informs.h"
#include "food.h"
#include "lunch.h"

#define SIZE 10
#define SIZESEC 5
#define SIZEFOOD 5
#define SIZELUN 50

#define CANTHARDCODE 9
#define EMPTY 0
#define TAKEN 1

int getMenuOption();

int main()
{
    char cont = 's';
    int nextID = 1000;
    int nextIDLunch = 20000;

    eEmployee list[SIZE];
    eSector sectors[SIZESEC] = {{1, "Sistemas"}, {2, "RRHH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"}};
    eFood foods[SIZEFOOD] = {{100, "Milanesa", 150}, {102, "Fideos", 120}, {103, "Pizza", 140}, {104, "Ensalada", 200}, {105, "Arroz", 135}};
    eLunch lunches[SIZELUN];

    initializateEmployee(list, SIZE);
    lunch_initializate(lunches, SIZELUN);

    hardcodearEmployees(list, CANTHARDCODE);//hardcodeamos
    nextID += CANTHARDCODE;//acualizamos la variable para que siga desde 1005

    do{
        switch(getMenuOption())
        {
            case 1:
                if(altaEmployee(nextID, list, SIZE, sectors, SIZESEC) == 1)
                {
                    nextID++;
                }
                break;
            case 2:
                bajaEmployee(list, SIZE, sectors, SIZESEC);
                break;
            case 3:
                printf("\nModificacion proximamente");
                break;
            case 4:
                showEmployees(list, SIZE, sectors, SIZESEC);
                sortEmployees(list, SIZE, 0, sectors, SIZESEC);
                showEmployees(list, SIZE, sectors, SIZESEC);
                sortEmployees(list, SIZE, 1, sectors, SIZESEC);
                break;
            case 5:
                showEmployees(list, SIZE, sectors, SIZESEC);
                break;
            case 6:
                printf("\nInformes");
                break;
            case 7:
                if(lunch_load(nextIDLunch, lunches, SIZELUN, list, SIZE, sectors, SIZESEC, foods, SIZEFOOD) == 1)
                {
                    nextIDLunch++;
                }
                break;
            case 8:
                lunch_show(lunches, SIZELUN, list, SIZE, foods, SIZEFOOD);
                break;
            case 9:
                printf("\nInformes");
                break;
            case 10:
                printf("\nSaliendo...");
                cont = 'n';
                break;
        }

    }while(cont == 'y');

    return 0;
}

int getMenuOption()
{
    int option;

    printf("\n\n\t\t************** ABM **************\n\t\t\n");
    printf("\t\t    1. Alta\n");
    printf("\t\t    2. Baja\n");
    printf("\t\t    3. Modificacion\n");
    printf("\t\t    4. Ordenar\n");
    printf("\t\t    5. Listar\n");
    printf("\t\t    6. Informes\n");
    printf("\t\t    7. Alta almuerzo\n");
    printf("\t\t    8. Listar almuerzo\n");
    printf("\t\t    9. Salir\n\t\t\n");
    printf("\t\t*****************************************\n");

    printf("\n\nIngrese una opcion: ");
    setbuf(stdin,NULL);
    scanf("%d", &option);

    return option;
}


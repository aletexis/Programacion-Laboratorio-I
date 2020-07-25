#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moto.h"
//#include "dataWarehouse.h"

#include "validations.h"
#include "menu.h"
#include "extras.h"

#define EMPTY 0
#define TAKEN 1

void moto_hardcode(eMoto motorcycles[], int motorcyclesToHardcode)
{
    int ids[] = {1000,1001,1002,1003,1004};
    char brands[][20] = {"Honda", "Suzuki", "Harley", "Yamaha", "Kawasaki"};
    int idsType[] = {1000,1001,1002,1003,1004};
    int idsColor[] = {10000,10001,10002,10003,10004};
    int cilindradas[] = {50,125,500,600,750};
    int idsClient[] = {0,1,2,3,4};
    int idsPatent[] = {10,11,12,13,14};

    for(int i=0; i<motorcyclesToHardcode; i++)
    {
        motorcycles[i].id = ids[i];
        strcpy(motorcycles[i].brand, brands[i]);
        motorcycles[i].idType = idsType[i];
        motorcycles[i].idColor = idsColor[i];
        motorcycles[i].cilindrada =  cilindradas[i];
        motorcycles[i].idClient =  idsClient[i];
        motorcycles[i].idPatent =  idsPatent[i];
        motorcycles[i].state = TAKEN;
    }
}
void moto_initializate(eMoto motorcycles[], int sizeMotorcycles)
{
     for(int i=0; i<sizeMotorcycles; i++)
     {
         motorcycles[i].state = EMPTY;
     }
}
int moto_findFreeSpace(eMoto motorcycles[], int sizeMotorcycles)
{
    int ret = -1;

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == EMPTY)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
int moto_findOne(int id, eMoto motorcycles[], int sizeMotorcycles)
{
    int ret = -1;

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].id == id && motorcycles[i].state == TAKEN)
        {
            ret = i;
            break;
        }
    }

    return ret;
}




int moto_load(int id, eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    eMoto auxMoto;
    int index = moto_findFreeSpace(motorcycles, sizeMotorcycles);
    int ok = 0;
    //int id;
    //int exists;

    system_clear("linux");
    printf("\n\t*** ALTA ************************************************************************************\n\n");

    if(index == -1)
    {
        printf("\n\n\t\t>>> Sistema completo <<<\n\n\n");
        system_pause("linux");
    }
    else
    {
//        validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",0,999999,0,999999,4);
//
//        exists = moto_findOne(id, motorcycles, sizeMotorcycles);
//
//        if(exists != -1)
//        {
//            printf("\n\n\t\t>>> El ID ya existe <<<\n\n\n");
//            system_pause("linux");
//        }
//        else
//        {

            auxMoto.id = id;

            validations_getText(auxMoto.brand,"\n\tIngrese la marca: ", "\n\t(!) Error. Caracteres invalidos.\n", 2, 20, 4);

            type_show(types, sizeTypes);
            validations_getUnsignedInt(&auxMoto.idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1000-1003\n",1,1003,1000,1003,4);

            color_show(colors, sizeColors);
            validations_getUnsignedInt(&auxMoto.idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 10000-10004\n",1,10004,10000,10004,4);

            validations_getUnsignedInt(&auxMoto.cilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 50-2500\n",1, 2500,50,2500,4);

            client_show(clients, sizeClients);
            validations_getUnsignedInt(&auxMoto.idClient,"\n\tIngrese ID del cliente: ", "\n\t(!) Error. Ingrese un valor numerico entero. Rango: 1-5\n",1,4,0,4,4);

            patent_show(patents, sizePatents);
            validations_getUnsignedInt(&auxMoto.idPatent,"\n\tIngrese ID de patente: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,14,10,14,4);

            auxMoto.state = TAKEN;

            motorcycles[index] = auxMoto;

            printf("\n\n\t\t>>> Cargado exitosamente <<<\n\n\n");
            system_pause("linux");
            ok = 1;
        //}
    }
    return ok;
}

void moto_delate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int id;
    int index;

    system_clear("linux");
    printf("\n\t*** BAJA ************************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = moto_findOne(id, motorcycles, sizeMotorcycles);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el ID: %d <<<\n\n\n", id);
        system_pause("linux");
    }
    else
    {
        system_clear("linux");
        printf("\n\t\tLa moto que se dara de baja es:");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        if(confirm(2))
        {
            motorcycles[index].state = EMPTY;
        }
    }
}

void moto_modify(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int id;
    int index;
    int newCilindrada;
    int newIDColor;

    system_clear("linux");
    printf("\n\t*** MODIFICACION ****************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);

    validations_getUnsignedInt(&id,"\n\tIngrese ID: ", "\n\t(!) Error. Ingrese un valor numerico entero\n",0,999999,0,999999,4);

    index = moto_findOne(id, motorcycles, sizeMotorcycles);

    if(index == -1)
    {
        printf("\n\n\t\t>>> No hay registro de una moto con el ID: %d <<<\n\n\n", id);
        system_pause("linux");
    }
    else
    {
        system_clear("linux");
        printf("\n\t\tLa moto que se modificara es:");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        switch(menu_motoModify())
        {
            case 1:
                color_show(colors, sizeColors);
                validations_getUnsignedInt(&newIDColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);
                if(confirm(3))
                {
                    motorcycles[index].idColor = newIDColor;
                }
                break;
            case 2:
                validations_getUnsignedInt(&newCilindrada,"\n\tIngrese la cilindrada: ", "\n\t(!) Error. Ingrese un valor numerico entero desde 50 hasta 2500.\n",1,2500,50,2500,4);
                if(confirm(3))
                {
                    motorcycles[index].cilindrada = newCilindrada;
                }
                break;
        }

        printf("\n");
        printf("\n\t\t _________________________________________________________________________________________________________\n");
        printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
        printf("\n\t\t ________________________________________________________________________________________________________\n");
        moto_showOne(motorcycles[index], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
        printf("\n\t\t ________________________________________________________________________________________________________\n\n");

        system_pause("linux");
    }
}

void moto_show(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag = 0;

    printf("\n\t\t _________________________________________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
    printf("\n\t\t ________________________________________________________________________________________________________\n");
     moto_sort(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == TAKEN)
        {
            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            flag = 1;
        }
    }
    printf("\n");
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay elementos para mostrar <<<\n\n\n");
    }
}

void moto_showOne(eMoto x, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    char typeDescription[20];
    char colorName[20];
    char clientName[20];
    char patentDescription[20];

    moto_loadTypeDescription(typeDescription, x.idType, types, sizeTypes);
    moto_loadColorName(colorName, x.idColor, colors, sizeColors);
    moto_loadClientName(clientName, x.idClient, clients, sizeClients);
    moto_loadPatentDescription(patentDescription, x.idPatent, patents, sizePatents);

    printf("\n\t\t    %5d  %15s   %15s  %10s         %5d    %15s        %-15s\n", x.id, x.brand, typeDescription, colorName, x.cilindrada, clientName, patentDescription);
}

void moto_sort(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    eMoto auxMoto;

    for(int i=0; i<sizeMotorcycles-1; i++)
    {
        for(int j=i+1; i<sizeMotorcycles; i++)
        {
            if(motorcycles[i].idType > motorcycles[j].idType)
            {
                auxMoto = motorcycles[i];
                motorcycles[i] = motorcycles[j];
                motorcycles[j] = auxMoto;
            }
            else if(motorcycles[i].idType == motorcycles[j].idType && motorcycles[i].id > motorcycles[j].id)
            {
                auxMoto = motorcycles[i];
                motorcycles[i] = motorcycles[j];
                motorcycles[j] = auxMoto;
            }
        }
    }
}

void moto_sortPatent(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    eMoto auxMoto;

    for(int i=0; i<sizeMotorcycles-1; i++)
    {
        for(int j=i+1; i<sizeMotorcycles; i++)
        {
            if(motorcycles[i].idPatent > motorcycles[j].idPatent)
            {
                auxMoto = motorcycles[i];
                motorcycles[i] = motorcycles[j];
                motorcycles[j] = auxMoto;
            }
        }
    }
}



int moto_loadTypeDescription(char description[], int id, eType types[], int sizeTypes)
{
    int ok = 0;

    for(int i=0; i<sizeTypes; i++)
    {
        if(types[i].id == id)
        {
            strcpy(description, types[i].description);
            ok = 1;
        }
    }

    return ok;
}

int moto_loadColorName(char colorName[], int id, eColor colors[], int sizeColors)
{
    int ok = 0;

    for(int i=0; i<sizeColors; i++)
    {
        if(colors[i].id == id)
        {
            strcpy(colorName, colors[i].colorName);
            ok = 1;
        }
    }

    return ok;
}

int moto_loadClientName(char clientName[], int id, eClient clients[], int sizeClients)
{
    int ok = 0;

    for(int i=0; i<sizeClients; i++)
    {
        if(clients[i].id == id)
        {
            strcpy(clientName, clients[i].name);
            ok = 1;
        }
    }

    return ok;
}

int moto_loadPatentDescription(char patentDescription[], int id, ePatent patents[], int sizePatents)
{
    int ok = 0;

    for(int i=0; i<sizePatents; i++)
    {
        if(patents[i].id == id)
        {
            strcpy(patentDescription, patents[i].description);
            ok = 1;
        }
    }

    return ok;
}

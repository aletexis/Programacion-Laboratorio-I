#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moto.h"
#include "type.h"
#include "color.h"
#include "service.h"
#include "work.h"
#include "client.h"
#include "informs.h"
#include "patent.h"

#include "menu.h"
#include "extras.h"
#include "validations.h"

void inform(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eService services[], int sizeServices, eWork works[], int sizeWorks, eClient clients[], int sizeClients, eColor_MostChosen colors_mostChosen[], ePatent patents[], int sizePatents, eClient_MasMotos CCMMlist[])
{
    char cont = 's';

    system_clear("linux");
    printf("\n *** INFORMES ***************************************************************************");

     do{

        switch(menu_inform())
        {
            case 1:
                inform_motoXcolor(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 2:
                inform_motoXtype(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 3:
                inform_motoWithHigherCilindrada(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 4:
                inform_motoXAllTypes(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 5:
                inform_motoCountByColorAndType(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors);
                break;
            case 6:
                inform_colorMostChosenByClients(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, colors_mostChosen, patents, sizePatents);
                break;
            case 7:
                inform_motoAndWorks(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 8:
                inform_sumOfAmountsOfWorks(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 9:
                inform_serviceAndMotos(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 10:
                inform_serviceXdate(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 11:
                inform_EnduroConCilindradaMayorA300(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 12:
                inform_motosConPatentes(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 13:
                inform_motosNegras(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 14:
                inform_motoXPatente(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 15:
                inform_ClienteConMasMotos(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, CCMMlist, patents, sizePatents);
                break;
            case 16:
                inform_motosDeClientesMujeres(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                break;
            case 17:
                inform_promedioServicios(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 18:
                 inform_limpiezas(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, works, sizeWorks, services, sizeServices, patents, sizePatents);
                break;
            case 19:
                cont = 'n';
                break;
        }

    }while(cont == 'y');
}

void inform_motoXcolor(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idColor;

    system_clear("linux");
    printf("\n *** MOTOS POR COLOR *****************************************************************************\n\n");

    color_show(colors, sizeColors);
    validations_getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1 && motorcycles[i].idColor == idColor)
        {
            printf("\n\t\t _________________________________________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
            printf("\n\t\t ________________________________________________________________________________________________________\n");

            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\n\t\t>>> No hay motos de ese color <<<\n");
    }
}
void inform_motoXtype(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idType;

    system_clear("linux");
    printf("\n *** MOTOS POR TIPO *****************************************************************************\n\n");

    type_show(types, sizeTypes);
    validations_getUnsignedInt(&idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1 && motorcycles[i].idType == idType)
        {
            printf("\n\t\t _________________________________________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
            printf("\n\t\t ________________________________________________________________________________________________________\n");

            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\n\t\t>>> No hay motos de ese tipo <<<\n");
    }
}
void inform_motoWithHigherCilindrada(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int higherCilindrada = 0;

    system_clear("linux");
    printf("\n *** MAYOR CILINDRADA *********************************************\n\n");

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1)
        {
            if(motorcycles[i].cilindrada > higherCilindrada)
            {
                higherCilindrada = motorcycles[i].cilindrada;
            }
        }
    }
    printf("\nLa mayor cilindrada es %d y la/s motos son: ", higherCilindrada);

	printf("\n\t\t _____________________________________________________________________________________________\n");
    printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE     ");
    printf("\n\t\t _____________________________________________________________________________________________\n");

	for(int i=0; i<sizeMotorcycles; i++)
	{
		if(motorcycles[i].cilindrada == higherCilindrada)
		{
			moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
		}
	}
}
void inform_motoXAllTypes(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag;

    system_clear("linux");
    printf("\n *** MOTOS DE TODOS LOS TIPOS *********************************************\n\n");

    for(int i=0; i<sizeTypes; i++)
    {
        flag = 0;
        printf("\n\n\n\n\nTipo: %s", types[i].description);

        for(int j=0; j<sizeMotorcycles; j++)
        {
            if(motorcycles[j].state == 1 && motorcycles[j].idType == types[i].id)
            {
                printf("\n\t\t _____________________________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE     ");
                printf("\n\t\t _____________________________________________________________________________________________\n");
                moto_showOne(motorcycles[j], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\n\t\t>>> No hay motos de este tipo <<<\n");
        }
    }
}
void inform_motoCountByColorAndType(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors)
{
    int flag = 0;
    int idColor;
    int idType;
    int indexColor;
    int indexType;
    int counter = 0;

    system_clear("linux");
    printf("\n *** CONTADOR DE MOTOS POR COLOR Y TIPO *****************************************************************************\n\n");

    color_show(colors, sizeColors);
    validations_getUnsignedInt(&idColor,"\n\tIngrese ID del color: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,100000,10000,100000,4);

    type_show(types, sizeTypes);
    validations_getUnsignedInt(&idType,"\n\tIngrese ID del tipo: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,10000,1000,10000,4);

    indexColor = color_findOne(idColor, colors, sizeColors);
    indexType = type_findOne(idType, types, sizeTypes);

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1 && motorcycles[i].idColor == idColor && motorcycles[i].idType == idType)
        {
            counter++;
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\n\n\t\t>>> No hay motos de ese color y tipo <<<\n");
    }
    else
    {
        printf("\n\n\t\t>>> Hay %d motos del color %s y del tipo %s <<<\n", counter, colors[indexColor].colorName, types[indexType].description);
        system_pause("linux");
    }
}
void inform_colorMostChosenByClients(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eColor_MostChosen CMClist[], ePatent patents[], int sizePatents)
{
	int counter;
	int indexCMC = 0;
	int flag = 0;
	int indexColor;
	eColor_MostChosen auxCMClist;


	system_clear("linux");
    printf("\n *** COLOR MAS ELEGIDO POR LOS CLIENTES *****************************************************************************\n\n");

	for(int c=0; c<sizeColors; c++)//recorro colores
	{
		counter = 0;

		for(int m=0; m<sizeMotorcycles; m++)//recorro motos
		{
			if(motorcycles[m].state == 1 && motorcycles[m].idColor == colors[c].id)//si la moto tiene el id de ese color
			{
				counter++;//se cuenta como una vez que eligieron una moto de ese color
			}
		}

		CMClist[indexCMC].idColor = colors[c].id;  //en ese elemento de la lista va a quedar guardado color: tal, veces que lo eligieron: tal
		CMClist[indexCMC].quantity = counter;
		CMClist[indexCMC].state = 1;

		indexCMC++; //ya se setearon los datos de un color, asi que se pasa al elemento siguiente de la lista para guardar los de otro
		//el contador vuelve a 0 para contar las veces que eligieron al color que sigue

	}

	for(int i=0; i<sizeColors; i++)
	{
		if(flag == 0)
		{
			auxCMClist = CMClist[i]; //en la posicion 0 auxCMClist va a tener cargado el color mas elegido
			flag = 1;
		}
		else if(CMClist[i].quantity > auxCMClist.quantity && CMClist[i].state == 1)
		{
			auxCMClist = CMClist[i];//cuando termina el for auxCMClist va a tener cargado el color mas elegido
		}
	}

	printf("Los colores mas elegidos son: \n\n");
	printf("\t\t\t ID              Descripcion\n\n");

	for(int i=0; i<sizeColors; i++)
	{
		if(auxCMClist.quantity == CMClist[i].quantity && CMClist[i].state == 1)
		{
			indexColor = color_findOne(CMClist[i].idColor, colors, sizeColors);//obtengo el indice del color mas elegido
			color_showOne(colors[indexColor]);//lo muestro
		}
	}

}


void inform_motoAndWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idMoto;

    system_clear("linux");
    printf("\n *** TODOS LOS TRABAJOS DE UNA MOTO *****************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
    validations_getUnsignedInt(&idMoto,"\n\tIngrese ID de la moto: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idMoto == idMoto)
        {
            printf("\n\t\t ________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
            printf("\n\t\t ________________________________________________________________________\n");
            work_showOne(works[i],motorcycles,sizeMotorcycles,services,sizeServices);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay trabajos realizados en esta moto <<<\n");
    }
}
void inform_sumOfAmountsOfWorks(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idMoto;
    float sum;

    system_clear("linux");
    printf("\n *** SUMA DE IMPORTES DE LOS SERVICIOS *****************************************************************************\n\n");

    moto_show(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
    validations_getUnsignedInt(&idMoto,"\n\tIngrese ID de la moto: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 1000\n",1,10000,1000,10000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idMoto == idMoto)
        {
            sum += services[works[i].idService-20000].price;
            flag = 1;
        }
    }

    printf("\n\t\tLa suma de los importes de la moto seleccionada es: %.2f", sum);

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay servicios realizados en esta moto <<<\n");
    }
}
void inform_serviceAndMotos(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idService;

    system_clear("linux");
    printf("\n *** MOTOS CON SERVICIOS REALIZADOS *****************************************************************************\n\n");

    service_show(services,sizeServices);
    validations_getUnsignedInt(&idService,"\n\tIngrese ID del servicio: ", "\n\t(!) Error. Ingrese un valor numerico entero a partir de 20000\n",1,30000,20000,30000,4);

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idService == idService)
        {
            work_showOne(works[i],motorcycles,sizeMotorcycles,services,sizeServices);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos a las que se les haya realizado ese servicio <<<\n");
    }
}
void inform_serviceXdate(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    int flag = 0;
    eWork auxWork;

    system_clear("linux");
    printf("\n *** SERVICIOS POR FECHA *****************************************************************************\n\n");

    validations_getUnsignedInt(&auxWork.date.day,"\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero. Dia inexistente.\n",1,31,1,31,4);
    validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero. Mes inexistente.\n",1,12,1,12,4);
    validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero. El anio debe ser entre 1990 y 2020.\n",1,2020,1,2020,4);

    while(validations_getDate(auxWork.date.day, auxWork.date.month, auxWork.date.year, 1990, 2020)==0)
    {
        printf("\n\t(!) Error. Fecha no valida. \n");
        validations_getUnsignedInt(&auxWork.date.day,"\n\n\tIngrese dia: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,31,1,31,4);
        validations_getUnsignedInt(&auxWork.date.month,"\n\tIngrese mes: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,12,1,12,4);
        validations_getUnsignedInt(&auxWork.date.year,"\n\tIngrese año: ", "\n\t(!) Error. Ingrese un valor numerico entero entre 1990 y 2020.\n",1,2020,1,2020,4);
    }

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && (works[i].date.day == auxWork.date.day) && (works[i].date.month == auxWork.date.month) && (works[i].date.year == auxWork.date.year))
        {
            work_showOne(works[i], motorcycles, sizeMotorcycles, services, sizeServices);
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\n\t\t>>> No se realizaron servicios en esa fecha <<<\n");
    }
}



void inform_EnduroConCilindradaMayorA300(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag;

    system_clear("linux");
    printf("\n *** MOTOS ENDURO CON CILINDRADA MAYOR A 300 *****************************************************************************\n\n");

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1)
        {
            if(motorcycles[i].cilindrada > 300 && motorcycles[i].idType == 1000)
            {
                printf("\n\t\t _________________________________________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
                printf("\n\t\t ________________________________________________________________________________________________________\n");
                moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                printf("\n\t\t ________________________________________________________________________________________________________\n\n");
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos enduro con cilindrada mayor a 300 <<<\n");
    }
}
///motos y patentes ordenadas no por la primer letra sino por el orden en el que estan hardcodeadas (idPatent)
void inform_motosConPatentes(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    system_clear("linux");
    printf("\n *** MOTOS CON PATENTES *****************************************************************************\n\n");

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1)
        {
            moto_sortPatent(motorcycles, sizeMotorcycles, types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            printf("\n\t\t _________________________________________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
            printf("\n\t\t ________________________________________________________________________________________________________\n");
            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            printf("\n\t\t ________________________________________________________________________________________________________\n\n");
        }
    }
}
void inform_motosNegras(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag;

    system_clear("linux");
    printf("\n *** MOTOS NEGRAS *****************************************************************************\n\n");

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1)
        {
            if(motorcycles[i].idColor == 10001)
            {
                printf("\n\t\t _________________________________________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
                printf("\n\t\t ________________________________________________________________________________________________________\n");
                moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                printf("\n\t\t ________________________________________________________________________________________________________\n\n");
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos negras <<<\n");
    }
}
void inform_motoXPatente(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag = 0;
    int idPatent;

    system_clear("linux");
    printf("\n *** MOTOS POR PATENTE *****************************************************************************\n\n");

    patent_show(patents, sizePatents);
    validations_getUnsignedInt(&idPatent,"\n\tIngrese ID de la patente: ", "\n\t(!) Error. Ingrese un valor numerico entero.\n",1,14,10,14,4);

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1 && motorcycles[i].idPatent == idPatent)
        {
            printf("\n\t\t _________________________________________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
            printf("\n\t\t ________________________________________________________________________________________________________\n");

            moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
            flag = 1;
        }
    }
    if(flag == 0)
    {
         printf("\n\t\t>>> No hay motos con esa patente <<<\n");
    }
}
void inform_ClienteConMasMotos(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eClient_MasMotos CCMMlist[], ePatent patents[], int sizePatents)
{
	int counter;
	int indexCCMM = 0;
	int flag = 0;
	int indexClient;
	eClient_MasMotos auxCCMMlist;


	system_clear("linux");
    printf("\n *** CLIENTE CON MAS MOTOS *****************************************************************************\n\n");

	for(int c=0; c<sizeClients; c++)
	{
		counter = 0;

		for(int m=0; m<sizeMotorcycles; m++)
		{
			if(motorcycles[m].state == 1 && motorcycles[m].idClient == clients[c].id)
			{
				counter++;
			}
		}

		CCMMlist[indexCCMM].idClient = clients[c].id;
		CCMMlist[indexCCMM].quantity = counter;
		CCMMlist[indexCCMM].state = 1;

		indexCCMM++;

	}

	for(int i=0; i<sizeClients; i++)
	{
		if(flag == 0)
		{
			auxCCMMlist = CCMMlist[i];
			flag = 1;
		}
		else if(CCMMlist[i].quantity > auxCCMMlist.quantity && CCMMlist[i].state == 1)
		{
			auxCCMMlist = CCMMlist[i];
		}
	}

	printf("El/Los cliente/s con mas motos son: \n\n");
	printf("\t\t\t ID              Nombre\n\n");

	for(int i=0; i<sizeClients; i++)
	{
		if(auxCCMMlist.quantity == CCMMlist[i].quantity && CCMMlist[i].state == 1)
		{
			indexClient = client_findOne(CCMMlist[i].idClient, clients, sizeClients);
			client_showOne(clients[indexClient]);
		}
	}

}
void inform_motosDeClientesMujeres(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, ePatent patents[], int sizePatents)
{
    int flag = 0;

    system_clear("linux");
    printf("\n *** MOTOS DE CLIENTES MUJERES *****************************************************************************\n\n");

    for(int i=0; i<sizeMotorcycles; i++)
    {
        if(motorcycles[i].state == 1)
        {
            if(motorcycles[i].idClient == clients[i].id && clients[i].gender == 'f')
            {
                printf("\n\t\t _________________________________________________________________________________________________________\n");
                printf("\n\t\t     ID              MARCA              TIPO       COLOR        CILINDRADA        CLIENTE        PATENT    ");
                printf("\n\t\t ________________________________________________________________________________________________________\n");
                moto_showOne(motorcycles[i], types, sizeTypes, colors, sizeColors, clients, sizeClients, patents, sizePatents);
                printf("\n\t\t ________________________________________________________________________________________________________\n\n");
                flag = 1;
            }
        }
    }
    if(flag == 0)
    {
        printf("\n\t\t>>> No hay motos de clientes mujeres <<<\n");
    }

}
void inform_promedioServicios(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    float sum;
    float average;

    system_clear("linux");
    printf("\n *** PROMEDIO LOS SERVICIOS *****************************************************************************\n\n");

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1)
        {
            sum += services[works[i].idService-20000].price;
            average = (sum / sizeServices);
        }
    }

    printf("\n\t\tEl promedio de los servicios realizados a todas las motos es: %.2f", average);
}
void inform_limpiezas(eMoto motorcycles[], int sizeMotorcycles, eType types[], int sizeTypes, eColor colors[], int sizeColors, eClient clients[], int sizeClients, eWork works[], int sizeWorks, eService services[], int sizeServices, ePatent patents[], int sizePatents)
{
    int flag = 0;

    system_clear("linux");
    printf("\n *** MOSTRAR LAS LIMPIEZAS REALIZADAS *****************************************************************************\n\n");

    for(int i=0; i<sizeWorks; i++)
    {
        if(works[i].state == 1 && works[i].idService == 20000)
        {
            printf("\n\t\t ________________________________________________________________________\n");
            printf("\n\t\t     ID              MARCA           SERVICIO            FECHA          ");
            printf("\n\t\t ________________________________________________________________________\n");
            work_showOne(works[i],motorcycles,sizeMotorcycles,services,sizeServices);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("\n\t\t>>> No hay limpiezas realizadas <<<\n");
    }
}

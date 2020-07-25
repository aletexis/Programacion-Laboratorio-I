#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validations.h"

void system_clear(char operativeSystem[])
{
    if(strcmp(operativeSystem, "windows")==0)
    {
        system("cls");
    }
    else if(strcmp(operativeSystem, "linux")==0)
    {
        system("clear");
    }
}

void system_pause(char operativeSystem[])
{
    if(strcmp(operativeSystem, "windows")==0)
    {
        system("pause");
    }
    else if(strcmp(operativeSystem, "linux")==0)
    {
        printf("\nPresione 'Enter' para continuar...");
        while (getchar() != '\n');
    }
}

int getOption(int maxOption)
{
    int option;

    validations_getUnsignedInt(&option, "\n\tIntroduzca una opcion: ", "\n\t(!) Error. Opcion inexistente\n", 1, sizeof(int),0, maxOption,4);

    return option;
}


int confirm(int menuOption)
{
    char option;
    int confirmed = 0;


    switch(menuOption)
    {
        case 4:
                validations_getChar(&option,"\n\tConfirma la baja? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la baja? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro dado de baja exitosamente <<<<<\n\n\n");
                    system_pause("linux");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue dado de baja <<<<<\n\n\n");
                    system_pause("linux");
                }
                break;

        case 5:
                validations_getChar(&option,"\n\tConfirma la modificacion? (s/n): ", "\n\t(!) Error. Caracter invalido.\n\tConfirma la modificacion? (s/n): ",4);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                    printf("\n\n\t\t>>>>> Registro modificado exitosamente <<<<<\n\n\n");
                    system_pause("linux");
                }
                else
                {
                    printf("\n\n\t\t>>>>> El registro no fue modificado <<<<<\n\n\n");
                    system_pause("linux");
                }
                break;
        case 10:
                validations_getChar(&option,"\n\tLos datos no guardados se eliminaran\n\tEsta seguro que desea salir? (s/n): ", "\n\t (!) Error. Caracter invalido.\n\tEsta seguro que desea salir? (s/n): ",2);

                if(option == 's' || option == 'S')
                {
                    confirmed = 1;
                }
                break;
    }
    return confirmed;
}

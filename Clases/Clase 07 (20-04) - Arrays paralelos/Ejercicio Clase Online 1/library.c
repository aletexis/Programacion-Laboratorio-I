#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"



void showStudents(int legajos[], char names[][20], char surnames[][20], char genders[], int firstExamNotes[], int secondExamNotes[], float averages[], int size)
{
    printf("\n ************************ LISTADO DE NOTAS ************************");
    printf("\n  LEG\t  NOMBRE\t APELLIDO\t SEXO\t NOTA P1    NOTA P2 \t PROMEDIO");
    printf("\n");

    for(int i=0; i<size; i++)
    {
        showOneStudent(legajos[i], names[i], surnames[i], genders[i], firstExamNotes[i], secondExamNotes[i], averages[i]);

    }
    printf("\n");

}

void showOneStudent(int legajo, char name[], char surname[], char gender, int firstExamNote, int secondExamNote, float average)
{
    printf("\n %4d %10s       %10s         %c\t    %2d       %2d  \t   %.2f", legajo, name, surname, gender, firstExamNote, secondExamNote, average);
}

void sortInt(int array[], int size, int mode)
{
    int aux;

    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[i] < array[j] && mode) //criterio de ordenamiento
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
            else if(array[i] > array[j] && !mode)
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void sortFloat(float array[], int size, int mode)
{
    float aux;

    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[i] < array[j] && mode) //criterio de ordenamiento
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
            else if(array[i] > array[j] && !mode)
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void sortChar(char array[], int size, int mode)
{
    char aux;

    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[i] < array[j] && mode) //criterio de ordenamiento
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
            else if(array[i] > array[j] && !mode)
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void sortString(char array[][20], int size, int mode)
{
    char auxString[50];

    for(int i=0; i<size-1; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(strcmp(array[i], array[j]) > 0 && mode)
            {
                strcpy(auxString, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], auxString);
            }
            else if(strcmp(array[i], array[j]) < 0 && !mode)
            {
                strcpy(auxString, array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], auxString);
            }
        }
    }
}

void sortStudents(int legajos[], char names[][20], char surnames[][20], char genders[], int firstExamNotes[], int secondExamNotes[], float averages[], int size)
{
    int mode;
    int option;
    char cont = 'y';

    option = getOption();

    while(cont == 'y')
    {
        switch(option)
        {
            case 1:
                mode = getMode();
                sortInt(legajos, size, mode);
                break;
            case 2:
                mode = getMode();
                sortString(names, size, mode);
                break;
            case 3:
                mode = getMode();
                sortString(surnames, size, mode);
                break;
            case 4:
                mode = getMode();
                sortChar(genders, size, mode);
                break;
            case 5:
                mode = getMode();
                sortInt(firstExamNotes, size, mode);
                break;
            case 6:
                mode = getMode();
                sortInt(secondExamNotes, size, mode);
                break;
            case 7:
                mode = getMode();
                sortFloat(averages, size, mode);
                break;
            case 8:
                cont = 'n';
                break;
            default:
                printf("\nLa opcion ingresada no es valida");
                break;
        }
    }
}

int getOption()
{
    int option;

    printf("\n******************** ORDENAMIENTO ********************\n");
    printf("\n        1. Ordenar por legajo");
    printf("\n        2. Ordenar por nombre");
    printf("\n        3. Ordenar por apellido");
    printf("\n        4. Ordenar por sexo");
    printf("\n        5. Ordenar por nota del primer parcial");
    printf("\n        6. Ordenar por nota del segundo parcial");
    printf("\n        7. Ordenar por promedio");
    printf("\n        8. Volver");
    printf("\n\n******************************************************\n");

    printf("\nIngrese una opcion: ");
    scanf("%d", &option);

    return option;
}

int getMode()
{
    int option;
    char cont = 'y';

    while(cont =='y');
    {
        printf("\n******************** ORDENAMIENTO ********************\n");
        printf("\n               0. Orden ascendente");
        printf("\n               1. Orden descendente");
        printf("\n\n******************************************************\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &option);

        cont = 'n';
    }

    return option;
}

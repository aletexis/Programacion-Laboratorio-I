#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

#define SIZE 5
#define COLUMNS 20

int main()
{
    int legajos[SIZE] = {1234, 2121, 3245, 1822, 9213};
    char names[SIZE][COLUMNS] = {"Zoilo", "Hernan", "Andrea", "Lautaro", "Mia"};
    char surnames[SIZE][COLUMNS] = {"Perez", "Garcia", "Gonzalez", "Suarez", "Morales"};
    char genders[SIZE] = {'m', 'm', 'f', 'm', 'f'};
    int firstExamNotes[SIZE] = {7, 2, 2, 10, 6};
    int secondExamNotes[SIZE] = {8, 2, 7, 9, 5};
    float averages[SIZE] = {7.5, 2, 4.5, 9.5, 5.5};
    //float auxFloat;
    //char auxChar;
    //int auxInt;
    //char auxString[50];


    /*for(int i=0; i<SIZE; i++)
    {
        printf("\nIngrese el legajo del alumno: ");
        scanf("%d", &legajos[i]);

        printf("\nIngrese el nombre del alumno: ");
        setbuf(stdin, NULL);
        gets(names);

        printf("\nIngrese el apellido del alumno: ");
        setbuf(stdin, NULL);
        gets(surnames);

        printf("\nIngrese el sexo del alumno: ");
        setbuf(stdin, NULL);
        gets(genders);

        printf("\nIngrese las notas del primer parcial: ");
        scanf("%d", &firstExamNotes[i]);

        printf("\nIngrese las notas del segundo parcial: ");
        scanf("%d", &secondExamNotes[i]);

        averages[i] = (float) (firstExamNotes[i] + secondExamNotes[i]) / 2;
    }*/

   showStudents(legajos, names, surnames, genders, firstExamNotes, secondExamNotes, averages, SIZE);

    /*for(int i=0; i<SIZE-1; i++)
    {
        for(int j=i+1; j<SIZE; j++)
        {
            if(genders[i] > genders[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxChar = genders[i];
                genders[i] = genders[j];
                genders[j] = auxChar;

                auxInt = firstExamNotes[i];
                firstExamNotes[i] = firstExamNotes[j];
                firstExamNotes[j] = auxInt;

                auxInt = secondExamNotes[i];
                secondExamNotes[i] = secondExamNotes[j];
                secondExamNotes[j] = auxInt;

                auxFloat = averages[i];
                averages[i] = averages[j];
                averages[j] = auxFloat;

                strcpy(auxString, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], auxString);

                strcpy(auxString, surnames[i]);
                strcpy(surnames[i], surnames[j]);
                strcpy(surnames[j], auxString);
            }
            else if(genders[i] == genders[j] && averages[i] < averages[j]) //doble criterio de ordenamiento
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxChar = genders[i];
                genders[i] = genders[j];
                genders[j] = auxChar;

                auxInt = firstExamNotes[i];
                firstExamNotes[i] = firstExamNotes[j];
                firstExamNotes[j] = auxInt;

                auxInt = secondExamNotes[i];
                secondExamNotes[i] = secondExamNotes[j];
                secondExamNotes[j] = auxInt;

                auxFloat = averages[i];
                averages[i] = averages[j];
                averages[j] = auxFloat;

                strcpy(auxString, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], auxString);

                strcpy(auxString, surnames[i]);
                strcpy(surnames[i], surnames[j]);
                strcpy(surnames[j], auxString);
            }
        }
    }
    */

    sortStudents(legajos, names, surnames, genders, firstExamNotes, secondExamNotes, averages, SIZE);

    showStudents(legajos, names, surnames, genders, firstExamNotes, secondExamNotes, averages, SIZE);


    return 0;
}

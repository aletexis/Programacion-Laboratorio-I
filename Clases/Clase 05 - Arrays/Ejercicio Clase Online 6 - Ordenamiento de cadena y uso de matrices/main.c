#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 20

int main()
{
    char letter = 'a';
    char name[COLUMNS] = "Juan";
    char names[ROWS][COLUMNS] = {"Zoilo", "Hernan", "Andrea", "Lautaro", "Mia"}; //cinco nombres de 20 caracteres
    char auxString[COLUMNS];

    /**caracteres**/

    //printf("\n%c", letter);
    //printf("\n%c", name[1]);//muestro un caracter dentro de un array
    //printf("\n%c", names[3][3]);//muestro un caracter dentro de una matriz

    /**cadenas**/
    //printf("\n%s", name);
    //printf("\n%s", names[2]);//indico que fila quiero mostrar


    /*for(int i=0; i<ROWS; i++)
    {
        printf("\nIngrese nombre: ");
        setbuf(stdin, NULL);
        gets(names[i]);
    }*/

    printf("\nDesordenados\n");

    for(int i=0; i<ROWS; i++)
    {
        printf("\n%s", names[i]);//muestro todos
    }

    printf("\n\n-------------\n");

    for(int i=0; i<ROWS-1; i++)
    {
        for(int j=i+1; j<ROWS; j++)
        {
            if(strcmp(names[i], names[j]) > 0)
            {
                strcpy(auxString, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], auxString);
            }
        }
    }

    printf("\nOrdenados\n");

    for(int i=0; i<ROWS; i++)
    {
        printf("\n%s", names[i]);//muestro todos
    }

    printf("\n");

    return 0;
}

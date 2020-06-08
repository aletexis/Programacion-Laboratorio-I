#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyString(char[], char[]);

int main()
{
    char string1[5];
    char auxString[100];

    printf("Ingrese su nombre: ");
    setbuf(stdin,NULL);
    gets(auxString);
    //fgets(string1, 4, stdin);


    while(strlen(auxString) >= 5)
    {
        printf("\nNombre demasiado largo. Reingrese nombre: ");
        setbuf(stdin, NULL);
        gets(auxString);
    }

    strcpy(string1, auxString);


    printf("\nSu nombre es: %s", string1);



    return 0;
}

void copyString(char destinyString[], char originString[])
{
    int i = 0;

    while(originString[i] != '\0')
    {
        destinyString[i] = originString[i];
        i++;
    }

    destinyString[i] = originString[i];
}

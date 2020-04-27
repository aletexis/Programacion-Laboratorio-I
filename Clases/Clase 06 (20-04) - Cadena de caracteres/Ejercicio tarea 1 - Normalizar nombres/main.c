#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void namesNormalized(char[], char[], char[]);

int main()
{
    char name[20];
    char surname[20];
    char fullName[41];

    printf("\nIngrese nombre: ");
    setbuf(stdin, NULL);
    fgets(name, 20, stdin);
    name[strlen(name) - 1] = '\0';

    printf("\nIngrese apellido: ");
    setbuf(stdin, NULL);
    fgets(surname, 20, stdin);
    surname[strlen(surname) - 1] = '\0';

    namesNormalized(name, surname, fullName);

    printf("\nSu nombre es: %s", fullName);
    printf("\n");

    return 0;
}

void namesNormalized(char names[], char surnames[], char fullNames[])
{
    strcpy(fullNames, surnames);
    strcat(fullNames, ", ");
    strcat(fullNames, names);

    strlwr(fullNames);
    fullNames[0] = toupper(fullNames[0]);

    for(int i=0; fullNames[i] != '\0'; i++)
    {
        if(fullNames[i] == ' ')
        {
            fullNames[i+1] = toupper(fullNames[i+1]);
        }
    }
}

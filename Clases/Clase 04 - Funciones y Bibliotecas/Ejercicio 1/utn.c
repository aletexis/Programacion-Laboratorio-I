#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int getInt(char menssage[])
{
    int number;

    printf("%s", menssage);
    scanf("%d", &number);

    return number;
}
float getFloat(char menssage[])
{
    float number;

    printf("%s", menssage);
    scanf("%f", &number);

    return number;
}
char getChar(char menssage[])
{
    char character;

    printf("%s", menssage);
    setbuf(stdin, NULL);
    scanf("%c", &character);

    return character;
}

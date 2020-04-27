#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
 * \brief Solicita un numero entero al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El numero entero ingresado por el usuario
 *
 */
int getInt(char menssage[])
{
    int number;

    printf("%s", menssage);
    scanf("%d", &number);

    return number;
}

/**
 * \brief Solicita un numero flotante al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El numero flotante ingresado por el usuario
 *
 */
float getFloat(char menssage[])
{
    float number;

    printf("%s", menssage);
    scanf("%f", &number);

    return number;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param message Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char menssage[])
{
    char character;

    printf("%s", menssage);
    setbuf(stdin, NULL);
    scanf("%c", &character);

    return character;
}

/**
 * \brief Genera un número aleatorio
 * \param from Número aleatorio mínimo
 * \param to Número aleatorio máximo
 * \param start Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char getRandomNumber(int from, int to, int start)
{
    if(start)
    {
        srand (time(NULL));
    }
    return from + (rand() % (to + 1 - from)) ;
}

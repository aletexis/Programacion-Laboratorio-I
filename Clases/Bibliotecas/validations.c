#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

int myGets(char* string, int lenght)
{
	int ret = -1;
	char bufferString[2000]; //usar memoria dinamica
	//char* bufferString = malloc(sizeof(char)*lenght);

	if(string != NULL && lenght > 0)
	{
		setbuf(stdin, NULL);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strlen(bufferString) -1] == '\n')
			{
				bufferString[strlen(bufferString) -1] = '\0';
			}
			if(strlen(bufferString) <= lenght)
			{
				strncpy(string, bufferString, lenght);
				ret = 0;
			}
		}
	}

	return ret;
}

int getIntNumber(int* pResult, char message[], char errorMessage[], int min, int max, int tries)
{
    int ret = -1;
    int bufferInt;

    if(pResult != NULL && message != NULL && errorMessage != NULL && min <= max && tries >= 0)
    {
       do
       {
           printf("%s", message);

            if(getInt(&bufferInt) == 0 && bufferInt >= min && bufferInt <= max)
            {
                *pResult = bufferInt;
                ret = 0;
                break;
           }
           printf("%s", errorMessage);
           tries--;
       }while(tries >= 0);
    }

    return ret;
}

/** \brief Obtiene un numero entero
 * Solicita un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero.
 *
 * \param result[] int La cadena a convertir
 * \return int (0) si pudo pasarla (-1) si no pudo
 *
 */
int getInt(int* pResult)
{
    int ret = -1;
    char bufferString[50];

    if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && isNumericInt(bufferString, sizeof(bufferString)) == 1)
    {
        *pResult = atoi(bufferString);
        ret = 0;
    }

    return ret;
}

/** \brief  Recibe una cadena de caracteres y verifica que el texto este compuesto solo por números.
 *
 * \param string[] char La cadena a analizar
 * \return int (0) si son todos numeros (-1) si no son
 *
 */
int isNumericInt(char string[], int lenght)
{
    int ret = -1;//error

    if(string != NULL && lenght > 0)
    {
        ret = 1;//true
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if(i == 0 && (string[i] == '-' || string[i] == '+'))
            {
                continue;
            }
            if(string[i] < '0' || string[i] > '9')
            {
                ret = 0;//false
                break;
            }
        }
    }
    return ret;
}

int getFloatNumber(float* pResult, char message[], char errorMessage[], float min, float max, int tries)
{
	int ret = -1;
    float bufferFloat;

    if(pResult != NULL && message != NULL && errorMessage != NULL && min <= max && tries >= 0)
    {
       do
       {
           printf("%s", message);

            if(getFloat(&bufferFloat) == 0 && bufferFloat >= min && bufferFloat <= max)
            {
                *pResult = bufferFloat;
                ret = 0;
                break;
           }
           printf("%s", errorMessage);
           tries--;
       }while(tries >= 0);
    }

    return ret;
}

int getFloat(float* pResult)
{
    int ret = -1;
    char bufferString[50];

    if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && isNumericFloat(bufferString, sizeof(bufferString)) == 1)
    {
		*pResult = atof(bufferString);
		ret = 0;

    }
    return ret;
}

int isNumericFloat(char string[], int lenght)
{
	int ret = -1; //error
	int dotsCounter = 0;

	if(string != NULL && lenght > 0)
	{
		ret = 1;//true
		for(int i=0; i<lenght && string[i] != '\0'; i++)
		{
			if(i == 0 && (string[i] == '-' || string[i] == '+'))
			{
                  continue;
            }
			if(string[i] == '.')
            {
                dotsCounter++;
            }
			if(((string[i] < '0' || string[i] > '9') && string[i] != '.') || (dotsCounter > 1))
			{
                ret = 0;//false
                break;
            }
		}
	}
	return ret;
}

int getCharacter(char* pResult, char message[], char errorMessage[], int tries)
{
    int ret = -1;
    char bufferChar;

    if(pResult != NULL && message != NULL && errorMessage != NULL && tries >= 0)
    {
        do
        {
            printf("%s", message);
            setbuf(stdin, NULL);
            scanf("%c", &bufferChar);

            if((bufferChar > 'a' || bufferChar < 'z') && (bufferChar > 'A' || bufferChar < 'Z'))
            {
                *pResult = bufferChar;
                ret = 0;
                break;
            }
            printf("%s", errorMessage);
            tries--;
        }while(tries >= 0);
    }

    return ret;
}

int getText(char* pResult, char message[], char errorMessage[], int tries)
{
	int ret = -1;
    char bufferString[50];

    if(pResult != NULL && message != NULL && errorMessage != NULL && tries >= 0)
    {
       do
       {
            printf("%s", message);

            if(getString(bufferString) == 0)
            {
                strcpy(pResult, bufferString);
                ret = 0;
                break;
            }
            printf("%s", errorMessage);
            tries--;
       }while(tries >= 0);
    }

    return ret;
}

int getString(char* pResult)
{
    int ret = -1;
    char bufferString[50];

    if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && isString(bufferString, sizeof(bufferString)) == 1)
    {
		strcpy(pResult, bufferString);
		ret = 0;

    }
    return ret;
}

int isString(char string[], int lenght)
{
    int ret = -1;//error

    if(string != NULL && lenght > 0)
    {
        ret = 1;//true
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
            {
                ret = 0;//false
                break;
            }
        }
    }
    return ret;
}

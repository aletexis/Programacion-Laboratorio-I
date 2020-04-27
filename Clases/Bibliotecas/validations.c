#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"

int myGets(char* string, int lenght)
{
	int ret = -1;
	char bufferString[4096]; // *****************************

	if(string != NULL && lenght > 0)
	{
		setbuf(stdin, NULL);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) -1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) -1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= lenght)
			{
				strncpy(string, bufferString, lenght);
				ret=0;
			}
		}
	}

	//fgets(buffer, sizeof(buffer), stdin);
    //buffer[strlen(buffer)-1] = '\0';
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

           if(getInt(&bufferInt) == 0)
           {
               if(bufferInt >= min && bufferInt <= max)
               {
                   *pResult = bufferInt;
                    ret = 0;
                    break;
               }
           }
           printf("%s", errorMessage);
           tries--;
       }while(tries >= 0);
    }

    return ret;
}

/** \brief Solicita un texto al usuario, lo almacena como cadena, valida y convierte el texto a numero.
 *
 * \param result[] int La cadena a convertir
 * \return int (0) si pudo pasarla (-1) si no pudo
 *
 */
int getInt(int* pResult)
{
    int ret = -1;
    char bufferString[50];

    if(pResult != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && isNumericInt(bufferString, sizeof(bufferString)) == 0)
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
int isNumericInt(char string[])
{
    int ret = 0;

    if(string != NULL && strlen(string) > 0)
    {
        for(int i=0; string[i] != '\0'; i++)
        {
            if(i == 0 && (string[i] == '-' || string[i] == '+'))
            {
                continue;
            }
            if(string[i] < '0' || string[i] > '9')
            {
                ret = -1;
                break;
            }
        }
    }
    return ret;
}
/*
int getCharacter(char* result, char message[], char errorMessage[], char min, char max, int tries)
{
    int ret = -1;
    char bufferChar;

    if(*result != NULL && message != NULL && errorMessage != NULL && min <= max && tries >= 0)
    {
        do
        {
            printf("%s", message);
            setbuf(stdin, NULL);
            scanf("%c", &bufferChar);

            if(bufferChar >= min && bufferChar <= max)
            {
                *result = bufferChar;
                ret = 0;
                break;
            }
            printf("%s", errorMessage);
            tries--;
        }while(tries >= 0);
    }

    return ret;
}
*/
int getFloatNumber(float* pResult, char message[], char errorMessage[], float min, float max, int tries)
{
	float bufferFloat;
	int ret = -1;

	while(tries >= 0)
	{
		tries--;
		printf("%s",message);

		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= min && bufferFloat <= max)
			{
				*pResult = bufferFloat;
				ret = 0;
				break;
			}
		}
		printf("%s", errorMessage);
	}
	return ret;
}

int getFloat(float* pResult)
{
    int ret = -1;
    char buffer[64];

    if(pResult != NULL)
    {
    	if(myGets(buffer,sizeof(buffer)) == 0 && isNumericFloat(buffer))
    	{
			*pResult = atof(buffer);
			ret = 0;
		}
    }
    return ret;
}

int isNumericFloat(char string[])
{
	int ret = 0;
	int dotsCounter=0;

	if(string != NULL && strlen(string) > 0)
	{
		for(int i=0; string[i] != '\0'; i++)
		{
			if(i==0 && (string[i] == '-' || string[i] == '+'))
			{
				continue;
			}
			if(string[i] < '0' || string[i] > '9' )
			{
				if(string[i] == '.' && dotsCounter == 0)
				{
					dotsCounter++;
				}
				else
				{
					ret = -1;
					break;
                }
			}
		}
	}
	return ret;
}

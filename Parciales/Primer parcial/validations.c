#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include "validations.h"

int getString(char* message, char* messageError, int min, int max, int* tries, char* result)
{
    int ret = -1;
    char bufferString[max+10];

    if(result != NULL && message != NULL && messageError != NULL && min <= max && tries >= 0)
    {
        do
        {
            printf("%s", message);
            setbuf(stdin,NULL);
            fgets(bufferString,sizeof(bufferString),stdin);
            bufferString[strlen(bufferString)-1]='\0';

            if(strlen(bufferString) >= min && strlen(bufferString) <= max)    // tamaño (max) = cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(result,bufferString,max);
                ret = 0;
                //printf("\nEntro al if de getString");
                break;
            }
            printf("%s", messageError);
            (*tries)--;

        }while((*tries) >= 0);
    }

    return ret;
}


int validations_getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries)
{
    int ret = -1;
    char bufferString[maxSize];
    int auxInt;

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && min <= max && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString)) //==0 sin errores !0
            {
                //printf("\nEntro al if de getString == 0");
                if(isValidNumber(bufferString) == 1)//////////************
                {
                    /**input = atoi(bufferString);
                    if(*input >= min && *input <= max)
                    {
                        ret = 0;
                        //printf("\nEntro al if de is valid number");
                        break;
                    }*/
                    auxInt = atoi(bufferString);
                    if(auxInt >= min && auxInt <= max)
                    {
                        *input = auxInt;
                        ret = 0;
                        break;
                    }

                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidNumber(char* string)
{
    int ret = 1;//true

    for(int i=0; string[i]!='\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            ret = 0;//false
            break;
        }
    }
    return ret;
}


int validations_getSignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries)
{
    int ret = -1;
    char bufferString[maxSize];
    int auxInt;

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && min <= max && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString)) //==0 sin errores !0
            {
                if(isValidSignedNumber(bufferString, sizeof(bufferString)) == 1)
                {
                    /* *input = atoi(bufferString);
                    if(*input > min && *input < max)
                    {
                        ret = 0;
                        break;
                    }*/
                    auxInt = atoi(bufferString);
                    if(auxInt >= min && auxInt <= max)
                    {
                        *input = auxInt;
                        ret = 0;
                        break;
                    }

                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidSignedNumber(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < '0' || string[i] > '9') && (string[0] != '+' && string[0] != '-'))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


int validations_getFloat(float* input, char* message, char* messageError, int minSize, int maxSize, float min, float max, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && min <= max && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString)) //==0 sin errores !0
            {
                if(isValidFloatNumber(bufferString, sizeof(bufferString)) == 1)
                {
                    *input = atof(bufferString);
                    if(*input >= min && *input <= max)
                    {
                        ret = 0;
                        break;
                    }
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidFloatNumber(char* string, int lenght)
{
    int ret = -1;
    //nt dotsCounter = 0;

    if(string != NULL && lenght > 0)
	{
		ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            /*if(string[i] == '.')
            {
                dotsCounter++;
            }*/
            if(((string[i] < '0' || string[i] > '9') && string[i] != '.') /*|| (dotsCounter > 1)*/)
            {
                ret = 0;
                break;
            }
        }
	}
    return ret;
}


int validations_getChar(char* result, char* message, char* messageError, int tries)
{
    int ret = -1;
    char bufferChar[256];

    if(result != NULL && message != NULL && messageError != NULL && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,1,3,&tries,bufferChar))
            {
                if(isValidChar(bufferChar[0]) == 1)
                {
                    *result = bufferChar[0];
                    ret = 0;
                    break;
                }

                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidChar(char character)
{
    int ret = 1;

    if(character < 'A' || (character > 'Z' && character < 'a') || character > 'z')
    {
        ret = 0;
    }

    return ret;
}


int validations_getText(char* input, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize <= maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidText(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidText(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != ' '))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


int validations_getAlfanumeric(char* input, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize < maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidAlphanumeric(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
    }
    return ret;
}
int isValidAlphanumeric(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < '0' || string[i] > '9') && (string[i] < 'A' || string[i] > 'Z') && (string[i] < 'a' || string[i] > 'z'))//fijarse el espacio
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}

///EXTRAS

int validations_getName(char* result, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(result != NULL && message != NULL && messageError != NULL && minSize <= maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidName(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(result,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
    }
    return ret;
}
int isValidName(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < 'A' || string[i] > 'Z') && (string[i] < 'a' || string[i] > 'z'))// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


int validations_getTelephone(char* input, char* message, char* messageError, int tries)
{
    int minSize = 9; //telefono de casa con guion en el medio
    int maxSize = 11; //telefono celular sin espacios ni guiones
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize < maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidTelephone(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidTelephone(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < '0' || string[i] > '9') && (string[i] != '-'))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


int validations_getDNI(char* input, char* message, char* messageError, int tries)
{
    int maxSize = 11; //con puntos
    int minSize = 8;  // sin puntos
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize < maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidDNI(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidDNI(char* string, int lenght)
{
    int ret = -1;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if((string[i] < '0' || string[i] > '9') && (string[i] != '.'))
            {
                ret = 0;
                break;
            }
        }
    }
    return ret;
}


int validations_getCUIT(char* input, char* message, char* messageError, int tries)
{
    int maxSize = 14; //con guiones 13 elementos
    int minSize = 11;  //sin puntos
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize < maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidCUIT(bufferString) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidCUIT(char* string)
{
    int ret = 1;
    int i;
    int j;
    char buffer[14];
    int digits[10] = {2,3,4,5,6,7,2,3,4,5};
    int accumulated = 0;
    int checkDigit;

    strncpy(buffer,string,14);

    for(i=0; buffer[i]!='\0'; i++)
    {
        if((buffer[i] < '0' || buffer[i] > '9') && (buffer[i] != '-')) // chequeo que solo sean numeros o -
        {
            ret = 0;
            break;
        }

        if(buffer[i] == '-')  //elimino los -
        {
            for(j=i; buffer[j]!='\0'; j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    for(i=0; i<strlen(buffer-1); i++)
    {
        accumulated += buffer[i]*digits[i];
    }

    checkDigit = 11-(accumulated%11);

	if(checkDigit == 11)
	{
		checkDigit = 0;
	}

	if(buffer[11] != checkDigit)
    {
        ret = 0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return ret;
}


int validations_getEmail(char* input, char* message, char* messageError, int minSize, int maxSize, int tries)
{
    int ret = -1;
    char bufferString[maxSize];

    if(input != NULL && message != NULL && messageError != NULL && minSize < maxSize && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,minSize,maxSize,&tries,bufferString))
            {
                if(isValidEmail(bufferString, sizeof(bufferString)) == 1)
                {
                    strncpy(input,bufferString,maxSize);
                    ret = 0;
                    break;
                }
                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidEmail(char* string, int lenght)
{
    int ret = -1;
    int atsCounter = 0;

    if(string != NULL && lenght > 0)
    {
        ret = 1;
        for(int i=0; i<lenght && string[i] != '\0'; i++)
        {
            if(string[i] == '@')
            {
                atsCounter++;
            }
            if((string[i] < '0' || string[i] > '9') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && (string[i] != '-') && (string[i] != '_') && (string[i] != '.') && (string[i] != '@')) //|| atsCounter != 1)
            {
                if(atsCounter != 1)
                {
                    ret = 0;
                    break;
                }
            }
        }
    }
    return ret;
}


int validations_getGender(char* result, char* message, char* messageError, int tries)
{
    int ret = -1;
    char bufferChar[256];

    if(result != NULL && message != NULL && messageError != NULL && tries >= 0)
    {
        do
        {
            if(!getString(message,messageError,1,3,&tries,bufferChar))
            {
                if(isValidGender(bufferChar[0]) == 1)
                {
                    *result = bufferChar[0];
                    ret = 0;
                    break;
                }

                printf("%s",messageError);
                tries--;
            }
        }
        while(tries >= 0);
        showTriesOverMessage(tries);
    }
    return ret;
}
int isValidGender(char character)
{
    int ret = 1;

    if(character != 'f' && character != 'm' && character != 'F' && character != 'M')
    {
        ret = 0;
    }

    return ret;
}

int validations_getDate(int day, int month, int year, int minYear, int maxYear)
{
    int ret = 1;
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(year < minYear || year > maxYear)
    {
        ret = 0;
    }

    if (month < 1 || month > 12)
    {
        ret = 0;
    }

    if((month != 2) || (!isLeapYear (year)))	//si no es febrero o no es bisiesto
    {
        if (day < 1 || day > monthDays[month])
        {
            ret = 0;
        }
    }
    else if((month == 2) && (isLeapYear (year))) //si es febrero y es bisiesto
    {
        if (day < 1 || day > monthDays[2]+1) //pongo como dia maximo 28 + 1
        {
            ret = 0;
        }
    }

    return ret;
}
int isLeapYear(int year)
{
  int ret = 0;

    if((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    {
      ret = 1;
    }
  return ret;
}


////////

void showTriesOverMessage(int tries)
{
    if(tries == -1)
    {
            printf("\n\n\t\t(!) ERROR. NO HAY INTENTOS DISPONIBLES. LO INGRESADO NO SE CARGO CORRECTAMENTE (!)\n\n");
    }
}

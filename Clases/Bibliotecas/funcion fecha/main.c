#include <stdio.h>
#include <stdlib.h>

//#include "validations.h"

typedef struct
{
    int day;
    int month;
    int year;
}eDate;

int isLeapYear(int year);
int fecha_es_valida(eDate date, int minYear, int maxYear);

int main ()
{
    eDate date;

    printf("\nIngrese fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &date.day, &date.month, &date.year);


    if(!validations_getDate(date, 1990, 2020))
    {
       printf( "Fecha es invalida\n");
    }
    else
    {
         printf("LA FECHA ES %d/%d/%d  \n", date.day, date.month, date.year);
    }



  return 0;
}

int validations_getDate(eDate date, int minYear, int maxYear)
{
    int ret = 1;
    int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(date.year < minYear || date.year > maxYear)
    {
        ret = 0;
    }

    if (date.month < 1 || date.month > 12)
    {
            ret = 0;

    }
    if((date.month != 2) || (!isLeapYear (date.year)))	//si no es febrero o el anio no es bisiesto
    {
        if (date.day < 1 || date.day > monthDays[date.month])
        {
            ret = 0;
        }
    }
    else if((date.month == 2) && (isLeapYear (date.year)))
    {
        if (date.day < 1 || date.day > monthDays[2]+1) //si es febrero y el anio es bisiesto hago 28 + 1
        {
            ret = 0;
        }
    }

    return ret;
}

int isLeapYear (int year)
{
  int ret = 0;

  if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    {
      ret = 1;
    }
  return ret;
}


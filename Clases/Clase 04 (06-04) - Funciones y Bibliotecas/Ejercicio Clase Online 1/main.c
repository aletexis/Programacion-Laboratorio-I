#include <stdio.h>
#include <stdlib.h>

int getIntBetween200and500();
int getIntWithRange(char[], char[], int, int);
int getIntWithRangeAndCounter(char[], char[], int, int, int);
char getChar (char[], char[], char, char);

int main()
{
    int number;
    int number2;
    int number3;
    char sexo;
    char continuar;

    number = getIntBetween200and500();
    number2 = getIntWithRange("Ingrese edad entre 18 y 65: ", "Error.Ingrese edad entre 18 y 65: ", 18, 65);
    number3 = getIntWithRangeAndCounter("Ingrese numero entre 1 y 10 : ", "Error.Ingrese numero entre 1 y 10: ", 1, 10, 3);

    sexo = getChar("\nIngrese sexo f/m: ", "Error.Ingrese sexo f/m: ", 'f', 'm');
    continuar = getChar("\nDesea Continuar? s/n: ", "Error.Desea continuar? s/n: ", 's', 'n');

    printf("\nEl numero ingresado es: %d", number);
    printf("\nEl numero ingresado es: %d", number2);

    if(number3 < 1)
    {
        printf("Supero la cantidad de ingresos erroneos");
    }
    else
    {
        printf("\nEl numero ingresado es: %d", number3);
    }

    printf("\nEl sexo es: %c", sexo);

    if(continuar == 's')
    {
        printf("\nQuiere continuar");
    }
    else
    {
        printf("\nNo quiere continuar");
    }

    return 0;
}

int getIntBetween200and500()
{
    int number;

    printf("Ingrese un numero entre 200 y 500: ");
    fflush(stdin);
    scanf("%d", &number);

    while(number < 200 || number > 500)
    {
        printf("\nEl numero ingresado esta fuera de rango. Debe ser entre 200 y 500.");
        printf("\nIngrese un numero entre 200 y 500: ");
        scanf("%d", &number);
    }

    return number;
}

/** \brief Solicita un numero al usuario entre un rango
 *
 * \param message[] char Mensaje a darle al usuario para pedir el dato.
 * \param errorMessage[] char Mensaje a darle al usuario en caso de error.
 * \param lowLimit int limite inferior del rango.
 * \param highLimit int limite superior del rango.
 * \return int
 *
 */
int getIntWithRange(char message[], char errorMessage[], int lowLimit, int highLimit)
{
    int number;

    printf("%s", message);
    scanf("%d", &number);

    while(number < lowLimit || number > highLimit)
    {
        printf("%s", errorMessage);
        scanf("%d", &number);
    }

    return number;
}

/** \brief Solicita un numero al usuario entre un rango
 *
 * \param message[] char Mensaje a darle al usuario para pedir el dato.
 * \param errorMessage[] char Mensaje a darle al usuario en caso de error.
 * \param veces cantidad de veces que voy a pedir un dato
 * \param lowLimit int limite inferior del rango.
 * \param highLimit int limite superior del rango.
 * \return int el entero en el rango solicitado y en el caso que haya consumido las veces de repregunta devuelve un numero menos que el limite inferior
 *
 */
int getIntWithRangeAndCounter(char message[], char errorMessage[], int lowLimit, int highLimit, int counter)
{
    int number;

    printf("%s", message);
    scanf("%d", &number);

    while(number < lowLimit || number > highLimit)
    {
        counter --;
        if(counter == 0)
        {
            number = lowLimit - 1;
            break;
        }
        printf("%s", errorMessage);
        scanf("%d", &number);
    }

    return number;
}

/** \brief
 *
 * \param message[] char Mensaje a darle al usuario para pedir el dato.
 * \param errorMessage[] char Mensaje a darle al usuario en caso de error.
 * \param character1[] primer caracter valido
 * \param character2[] segundo caracter valido
 * \return caracter solicitado valido
 *
 */
char getChar (char message[], char errorMessage[], char character1, char character2)
{
    char solicitedCharacter;

     printf("%s", message);
     setbuf(stdin, NULL);
     scanf("%c", &solicitedCharacter);

     while((solicitedCharacter != character1) && (solicitedCharacter != character2))
     {
        printf("%s", errorMessage);
        setbuf(stdin, NULL);
        scanf("%c", &solicitedCharacter);
     }

    return solicitedCharacter;
}

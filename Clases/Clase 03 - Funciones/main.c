#include <stdio.h>
#include <stdlib.h>

/**
 1. Crear una función que permita ingresar un numero al usuario y lo retorne.
 2. Crear una función que reciba el radio de un círculo y retorne su área.
 3. Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
    el área de un círculo cuyo radio es ingresado por el usuario.
 4. Documentar las funciones al estilo Doxygen.
**/

float getNumber(void);
float getArea(float);

int main()
{
    float radio;
    float area;

    printf("Radio del circulo");
    radio = getNumber();
    area = getArea(radio);
    printf("\nArea del circulo");
    printf("\n\tEl area es: %.2f\n", area);

    return 0;
}

/** \brief Obtiene un numero ingresado por el usuario
 *
 * \param void
 * \return float El numero ingresado por el usuario
 *
 */
float getNumber(void)
{
    float number;

    printf("\n\tIngrese un numero: ");
    scanf("%f", &number);

    return number;
}

/** \brief Calcula el area de un circulo
 *
 * \param radio float El radio del circulo
 * \return float El area del circulo
 *
 */
float getArea(float radio)
{
    float area;

    area = (3.14 * radio * radio);

    return area;
}

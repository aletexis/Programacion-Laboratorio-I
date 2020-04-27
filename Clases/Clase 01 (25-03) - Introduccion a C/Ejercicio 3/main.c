#include <stdio.h>
#include <stdlib.h>

/**Agregar al programa adjunto la funcionalidad resaltada con un (*)

- Limpie la pantalla
- Solicite dos valores numéricos al usuario distintos de cero *
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
- Muestre por pantalla la leyenda "Resultado positivo" en caso de ser mayor *
- Muestre por pantalla la leyenda "Resultado negativo" si es menor que cero *
**/


int main(int argc, char *argv[])
{

	int numero1;
	int numero2;
	int resultado;

	do {
        printf("\nIngrese el numero 1: ");
        scanf("%d",&numero1);

        if(numero1 == 0)
        {
            printf("\nEl numero ingresado no puede ser cero\n");
        }
	}while(numero1 == 0);

    do{
        printf("\nIngrese el numero 2: ");
        scanf("%d",&numero2);

        if(numero2 == 0)
        {
            printf("\nEl numero ingresado no puede ser cero\n");
        }
    }while(numero2 == 0);

	resultado = numero1 - numero2;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);

	if(resultado > 0)
    {
        printf("\nResultado positivo \n");
	}

	if(resultado < 0)
    {
        printf("\nResultado negativo \n");
	}
	printf("______________________________________\n\n\n\n");


	return 0;
}

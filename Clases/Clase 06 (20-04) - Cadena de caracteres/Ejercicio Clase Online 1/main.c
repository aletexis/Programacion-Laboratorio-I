#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1[20];
    char string2[20];

    printf("Ingrese su nombre: ");
    setbuf(stdin,NULL);
    gets(string1);

    srtcpy(string2, string1);

    printf("Su nombre es: %s", string2);



    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int age;
    float weight;
}ePerson;

int main()
{
    FILE* f = fopen("archivo.txt","wb");
    //int x = 1234;
    //char c;
    //char cadena[100];
    ePerson per = {"juan", 20, 45.7};

    if(f == NULL)
    {
        printf("\n\n\t >>> Problemas al abrir el archivo <<<\n\n");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, "%d", x);

    //fwrtite(&x, sizeof(int), 1, f);

    /*while(!feof(f))
    {
        c = fgetc(f);
        printf("%c", c);
    }*/

   /*while(!feof(f))
    {
        fgets(cadena, 100, f);
        printf("%s", cadena);
    }*/

    fwrite(&per,sizeof(ePerson), 1, f);

    fclose(f);

    return 0;
}

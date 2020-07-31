#include "LinkedList.h"

#ifndef country_H_INCLUDED
#define country_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}Country;

Country* country_new();
Country* country_newParameters(int id,char* nombre,int recuperados,int infectados,int muertos);
Country* country_newParametersStr(char* idStr,char* nombreStr,char* recuperadosStr, char* infectadosStr, char* muertosStr);
void country_delete();

int country_setId(Country* this,int id);
int country_getId(Country* this,int* id);

int country_setNombre(Country* this,char* nombre);
int country_getNombre(Country* this,char* nombre);

int country_setRecuperados(Country* this,int recuperados);
int country_getRecuperados(Country* this,int* recuperados);

int country_setInfectados(Country* this,int infectados);
int country_getInfectados(Country* this,int* infectados);

int country_setMuertos(Country* this,int muertos);
int country_getMuertos(Country* this,int* muertos);

int country_printOne(Country*);

int country_sortById(void*, void*);
int country_sortByNombre(void*, void*);
int country_sortByRecuperados(void*, void*);
int country_sortByInfectados(void*, void*);
int country_sortByMuertos(void*, void*);

void* country_map(void* this);


#endif // country_H_INCLUDED

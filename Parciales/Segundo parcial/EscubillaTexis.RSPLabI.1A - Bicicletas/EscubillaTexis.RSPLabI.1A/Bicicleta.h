#include "LinkedList.h"

#ifndef bicicleta_H_INCLUDED
#define bicicleta_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    char tipo[128];
    int tiempo;
}eBicicleta;

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParameters(int id,char* nombre,char* tipo,int tiempo);
eBicicleta* bicicleta_newParametersStr(char* idStr,char* nombreStr,char* tipoStr, char* tiempoStr);
void bicicleta_delete();

int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_getId(eBicicleta* this,int* id);

int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_getNombre(eBicicleta* this,char* nombre);

int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_getTipo(eBicicleta* this,char* tipo);

int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);

int bicicleta_printOne(eBicicleta*);

int bicicleta_sortById(void*, void*);
int bicicleta_sortByNombre(void*, void*);
int bicicleta_sortByTipo(void*, void*);
int bicicleta_sortByTiempo(void*, void*);
int bicicleta_sortByTipoYTiempo(void*, void*);

void* bicicleta_map(void* this);


#endif // bicicleta_H_INCLUDED

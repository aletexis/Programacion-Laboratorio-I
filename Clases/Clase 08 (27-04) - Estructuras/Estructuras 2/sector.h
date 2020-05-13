#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;  //pk
    char description[20];
}eSector;

#endif // SECTOR_H_INCLUDED

void sector_show(eSector[], int);

#ifndef FOOD_H_INCLUDED
#define FOOD_H_INCLUDED

typedef struct
{
    int id;
    char description[20];
    float price;
}eFood;


#endif // FOOD_H_INCLUDED

void food_show(eFood foods[], int sizeFood);

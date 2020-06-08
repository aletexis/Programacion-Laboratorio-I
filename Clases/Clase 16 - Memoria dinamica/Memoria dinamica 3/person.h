#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct
{
    int id;
    char name[20];
    char gender;
    float weight;

}ePerson;


#endif // PERSON_H_INCLUDED

int initializatePeople(ePerson** list, int size);
int findFreeSpace(int* index, ePerson** list, int size);
int person_show(ePerson** list, int size);
int person_showOne(ePerson* person);


///////////////////////////////////////

ePerson* person_new();
ePerson* person_newParam(int id, char* name, char gender, float weight );

int person_setId(ePerson* person, int id);
int person_getId(ePerson* person, int* id);

int person_setName(ePerson* person, char* name);
int person_getName(ePerson* person, char* name);

int person_setGender(ePerson* person, char gender);
int person_getGender(ePerson* person, char* gender);

int person_setWeight(ePerson* person, float weight);
int person_getWeight(ePerson* person, float* weight);

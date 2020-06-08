#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

int initializatePeople(ePerson** list, int size)
{
    int ok = 0;

    if(list != NULL)
    {
        ok = 1;
        for(int i=0; i<size; i++) //inicializar el array de punteros en NULL
        {
            *(list + i) = NULL;
        }
    }

    return ok;
}

int findFreeSpace(int* index, ePerson** list, int size)
{
    int ok = 0;

    if(list != NULL && index != NULL)
    {
        *index = -1;
        ok = 1;
        for(int i=0; i<size; i++) //inicializar el array de punteros en NULL
        {
            if(*(list + i) == NULL)
            {
                *index = i;
                break;
            }
        }
    }

    return ok;
}

ePerson* person_new()
{
    ePerson* newPerson = (ePerson*) malloc(sizeof(ePerson));

    if(newPerson != NULL)
    {
        newPerson->id = 0;
        newPerson->weight = 0;
        newPerson->gender = ' ';
        strcpy(newPerson->name, " ");
    }

    return newPerson;
}

ePerson* person_newParam(int id, char* name, char gender, float weight )
{
    ePerson* newPerson = person_new();

    if(newPerson != NULL)
    {
        if(! (person_setId(newPerson, id) && person_setName(newPerson, name) && person_setGender(newPerson, gender) && person_setWeight(newPerson, weight)))
        {
            free(newPerson);
            newPerson = NULL;
        }
    }

    return newPerson;
}

int person_setId(ePerson* person, int id)
{
    int ok = 0;

    if(person != NULL && id >=0)
    {
        person->id = id;
        ok = 1;
    }

    return ok;
}

int person_getId(ePerson* person, int* id)
{
    int ok = 0;

    if(person != NULL && id != NULL)
    {
        *id = person->id;
        ok = 1;
    }

    return ok;
}

int person_setName(ePerson* person, char* name)
{
    int ok = 0;

    if(person != NULL && name != NULL && strlen(name) >= 3 && strlen(name) < 20)
    {
        strcpy(person->name, name);
        ok = 1;
    }

    return ok;
}

int person_getName(ePerson* person, char* name)
{
    int ok = 0;

    if(person != NULL && name != NULL)
    {
        strcpy(person->name, name);
        ok = 1;
    }

    return ok;
}

int person_setGender(ePerson* person, char gender)
{
    int ok = 0;

    if(person != NULL && (gender == 'f' || gender == 'm'))
    {
        person->gender = gender;
        ok = 1;
    }

    return ok;
}

int person_getGender(ePerson* person, char* gender)
{
    int ok = 0;

    if(person != NULL && gender != NULL)
    {
        *gender = person->gender;
        ok = 1;
    }

    return ok;
}

int person_setWeight(ePerson* person, float weight)
{
    int ok = 0;

    if(person != NULL &&  weight > 0)
    {
        person->weight = weight;
        ok = 1;
    }

    return ok;
}

int person_getWeight(ePerson* person, float* weight)
{
    int ok = 0;

    if(person != NULL && weight != NULL)
    {
        *weight = person->weight;
        ok = 1;
    }

    return ok;
}

int person_show(ePerson** list, int size)
{
    int ok = 0;

    if(list != NULL)
    {
        ok = 1;
        for(int i=0; i<size; i++) //inicializar el array de punteros en NULL
        {
            if(*(list + i) != NULL)
            {
                person_showOne(*(list + i));
            }
        }
    }

    return ok;
}

int person_showOne(ePerson* person)
{
    int ok = 0;

    if(person != NULL)
    {
        ok = 1;
        printf(" %d   %10s     %c    %.2f\n", person->id, person->name, person->gender, person->weight);
    }

    return ok;
}

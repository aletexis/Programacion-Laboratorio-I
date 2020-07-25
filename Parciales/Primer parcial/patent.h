#ifndef PATENT_H_INCLUDED
#define PATENT_H_INCLUDED

typedef struct
{
    int id;
    char description[20];
}ePatent;

#endif // PATENT_H_INCLUDED

/** \brief Muestra las patentes cargados en una lista
 *
 * \param patents[] ePatent El array de patentes
 * \param sizePatents int El tamaño del array
 * \return void
 *
 */
void patent_show(ePatent patents[], int sizePatents);

/** \brief Muestra una sola patente
 *
 * \param patent ePatent La patente a mostrar
 * \return void
 *
 */
void patent_showOne(ePatent patent);

/** \brief Verifica la existencia de otra patente con el mismo ID
 *
 * \param id int El ID a buscar
 * \param patents ePatent El array de patentes
 * \param sizePatents int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int patent_findOne(int id, ePatent patents[], int sizePatents);


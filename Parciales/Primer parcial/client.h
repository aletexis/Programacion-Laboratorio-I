#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

typedef struct
{
    int id;
    char name[20];
    char gender;
}eClient;


#endif // CLIENT_H_INCLUDED

/** \brief Muestra los clientes cargados en una lista
 *
 * \param clients[] eClient El array de clientes
 * \param sizeClients int EL tamaño del array
 * \return void
 *
 */
void client_show(eClient clients[], int sizeClients);

/** \brief Muestra solo un cliente
 *
 * \param client eClient El cliente a mostrar
 * \return void
 *
 */
void client_showOne(eClient client);

/** \brief Verifica la existencia de otro cliente con el mismo ID
 *
 * \param id int El ID a buscar
 * \param clients[] eClient El array de clientes
 * \param sizeClients int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int client_findOne(int id, eClient clients[], int sizeClients);

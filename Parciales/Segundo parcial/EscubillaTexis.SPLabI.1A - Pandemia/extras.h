#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED



#endif // EXTRAS_H_INCLUDED

/** \brief Vacia el contenido que se emuestra en la consola
 *
 * \param operativeSystem[] char El sistema operativo que se esta utilizando
 * \return void
 *
 */
void system_clear(char operativeSystem[]);

/** \brief Hace una pausa en la consola
 *
 * \param operativeSystem[] char El sistema operativo que se esta utilizando
 * \return void
 *
 */
void system_pause(char operativeSystem[]);

/**
 * \brief Solicita un numero de opcion y lo valida
 * \param int maxOption La opcion maxima que se puede introducir
 * \return La opcion validada
 */
int getOption(int);

/**
 * \brief Solicita el numero de opcion de un menu para confirmar los cambios de acuerdo a ese menu
 * \param int menuOption El numero de la opcion del menu
* \param int flag La bandera que indicara si se guardaron los datos en el archivo
 * \return (1) si se confirmaron los cambios, (0) si no se confirmaron
 * Le paso el numero de la opcion del menu y muestra el mensaje de confirmacion adecuado para la accion que vaya a realizar
 */
int confirm(int, int flag);


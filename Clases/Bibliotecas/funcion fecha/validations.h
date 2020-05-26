#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

/// PRINCIPALES

/** \brief Obtiene un string
 *
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error a mostrar
 * \param min int El tamaño minimo
 * \param max int El temaño maximo
 * \param tries int* Intentos que tiene el usuario para ingresar el dato correctamente
 * \param result char* Donde se guardara el string obtenido
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int getString(char* message, char* messageError, int min, int max, int* tries, char* result);


/** \brief Obtiene un numero entero sin signo
 *
 * \param input int* Donde se guardara el int obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero maximo del rango que se puede ingresar
 * \param max int El numero minimo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
/** \brief Valida numeros enteros sin signo de una cadena
 *
 * \param string char* La cadena a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidNumber(char* string);

/** \brief Obtiene un numero entero con signo
 *
 * \param input int* Donde se guardara el int obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero maximo del rango que se puede ingresar
 * \param max int El numero minimo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getSignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
/** \brief Valida numeros enteros con signo de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidSignedNumber(char* string, int lenght);

/** \brief Obtiene un numero flotante
 *
 * \param input float* Donde se guardara el float obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min float El numero minimo del rango que se puede ingresar
 * \param max float El numero maximo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getFloat(float* input, char* message, char* messageError, int minSize, int maxSize, float min, float max, int tries);
/** \brief Valida numeros flotantes de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidFloatNumber(char* string, int lenght);

/** \brief Obtiene un numero caracter
 *
 * \param result char* Donde se guardara el caracter obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getChar(char* result, char* message, char* messageError, int tries);
/** \brief Valida caracteres de una cadena
 *
 * \param string char* La cadena a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidChar(char character);

/** \brief Obtiene un texto
 *
 * \param input char* Donde se guardara el texto obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getText(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida texto de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidText(char* string, int lenght);

/** \brief Obtiene un alfanumerico
 *
 * \param input char* Donde se guardara el alfanumerico obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getAlfanumeric(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida alfanumericos de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidAlphanumeric(char* string, int lenght);

///EXTRAS

/** \brief Obtiene un nombre
 *
 * \param result char* Donde se guardara el nombre obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getName(char* result, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida un nombre de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidName(char* string, int lenght);

/** \brief Obtiene un telefono
 *
 * \param input char* Donde se guardara el telefono obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getTelephone(char* input, char* message, char* messageError, int tries);
/** \brief Valida un telefono de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidTelephone(char* string, int lenght);

/** \brief Obtiene un DNI
 *
 * \param input char* Donde se guardara el DNI obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getDNI(char* input, char* message, char* messageError, int tries);
/** \brief Valida un dni de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidDNI(char* string, int lenght);

/** \brief Obtiene un CUIT
 *
 * \param input char* Donde se guardara el CUIT obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getCUIT(char* input, char* message, char* messageError, int tries);
/** \brief Valida un cuit de una cadena
 *
 * \param string char* La cadena a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidCUIT(char* string);

/** \brief Obtiene un email
 *
 * \param input char* Donde se guardara el email obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getEmail(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
/** \brief Valida un email de una cadena
 *
 * \param string char* La cadena a validar
 * \param int lenght El largo de la cadena
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidEmail(char* string, int lenght);

/** \brief Obtiene un telefono
 *
 * \param result char* Donde se guardara el telefono obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si pudo obtenerlo (-1) si no pudo
 *
 */
int validations_getGender(char* result, char* message, char* messageError, int tries);
/** \brief Valida un genero de una cadena
 *
 * \param char El caracter a validar
 * \return int (1) si es valida (0) si no lo es
 *
 */
int isValidGender(char character);


///

/** \brief Muestra el mensaje que indica que no hay mas intentos disponibles
 *
 * \param tries int Si la variable tries de la funcion que la llama es -1, se muestra el mensaje de esta funcion
 * \return void
 *
 */
void showTriesOverMessage(int tries);
#endif // VALIDATIONS_H_INCLUDED

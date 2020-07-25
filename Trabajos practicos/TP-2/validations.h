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
 * \return int (0) si pudo conseguir el numero (-1) si no pudo
 *
 */
int getString(char* message, char* messageError, int min, int max, int* tries, char* result);


/** \brief Obtiene un numero entero sin signo
 *
 * \param input int* Donde se guardara el entero obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero maximo del rango que se puede ingresar
 * \param max int El numero minimo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);

/** \brief Verifica que sea un numero entero sin signo valido
 *
 * \param string char* La cadena con el contenido a validar
 * \return int (1) si es valido (0) si no lo es
 *
 */
int isValidNumber(char* string);

/** \brief Obtiene un numero entero con signo
 *
 * \param input int* Donde se guardara el entero obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero maximo del rango que se puede ingresar
 * \param max int El numero minimo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getSignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);

/** \brief Verifica que sea un numero entero con signo valido
 *
 * \param string char* La cadena con el contenido a validar
 * \param lenght int
 * \return int int (1) si es valido (0) si no lo es
 *
 */
int isValidSignedNumber(char* string, int lenght);

/** \brief Obtiene un numero flotante
 *
 * \param input float* Donde se guardara el flotante obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param min int El numero maximo del rango que se puede ingresar
 * \param max int El numero minimo del rango que se puede ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getFloat(float* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);

/** \brief Verifica que sea un numero flotante valido
 *
 * \param string char* La cadena con el contenido a validar
 * \param lenght int
 * \return int int (1) si es valido (0) si no lo es
 *
 */
int isValidFloatNumber(char* string, int lenght);

/** \brief Obtiene un caracter
 *
 * \param input char* Donde se guardara el caracter obtenido
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getChar(char* result, char* message, char* messageError, int tries);

/** \brief Varifica que sea un caracter de letras
 *
 * \param character char El caracter a validar
 * \return int (1) si es valido (0) si no lo es
 *
 */
int isValidChar(char character);

/** \brief Obtiene una cadena de caracteres
 *
 * \param input char* Donde se guardara el texto
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getText(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);

/** \brief Verifica que sea texto valido
 *
 * \param string char* La cadena con el contenido a validar
 * \param lenght int
 * \return int int (1) si es valido (0) si no lo es
 *
 */
int isValidText(char* string, int lenght);

/** \brief Obtiene una cadena de caracteres alfanumericos
 *
 * \param input char* Donde se guardara el texto
 * \param message char* El mensaje a mostrar
 * \param messageError char* El mensaje de error
 * \param minSize int La cantidad minima de digitos a ingresar
 * \param maxSize int La cantidad maxima de digitos a ingresar
 * \param tries int La cantidad de intentos
 * \return int (0) si se pudo (-1) si no se pudo
 *
 */
int validations_getAlfanumeric(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);

/** \brief Verifica que sea texto alfanumerico valido
 *
 * \param string char* La cadena con el contenido a validar
 * \param lenght int
 * \return int int (1) si es valido (0) si no lo es
 *
 */
int isValidAlphanumeric(char* string, int lenght);

///EXTRAS

int validations_getName(char* result, char* message, char* messageError, int minSize, int maxSize, int tries);
int isValidName(char* string, int lenght);

int validations_getTelephone(char* input, char* message, char* messageError, int tries);
int isValidTelephone(char* string, int lenght);

int validations_getDNI(char* input, char* message, char* messageError, int tries);
int isValidDNI(char* string, int lenght);

int validations_getCUIT(char* input, char* message, char* messageError, int tries);
int isValidCUIT(char* string);

int validations_getEmail(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
int isValidEmail(char* string, int lenght);

int validations_getGender(char* result, char* message, char* messageError, int tries);
int isValidGender(char character);

///

/** \brief Muestra un mensaje cuando ya no hay mas intentos
 *
 * \param tries int el numero de intentos a comprobar
 * \return void
 *
 */
void showTriesOverMessage(int tries);
#endif // VALIDATIONS_H_INCLUDED

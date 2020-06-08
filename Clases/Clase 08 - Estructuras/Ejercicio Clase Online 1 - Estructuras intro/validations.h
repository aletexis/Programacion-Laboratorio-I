#ifndef VALIDATIONS_H_INCLUDED
#define VALIDATIONS_H_INCLUDED

/// PRINCIPALES

int getString(char* message, char* messageError, int min, int max, int* tries, char* result);

int validations_getUnsignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
int isValidNumber(char* string);

int validations_getSignedInt(int* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
int isValidSignedNumber(char* string, int lenght);

int validations_getFloat(float* input, char* message, char* messageError, int minSize, int maxSize, int min, int max, int tries);
int isValidFloatNumber(char* string, int lenght);

int validations_getChar(char* result, char* message, char* messageError, int tries);
int isValidChar(char character);

int validations_getText(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
int isValidText(char* string, int lenght);

int validations_getAlfanumeric(char* input, char* message, char* messageError, int minSize, int maxSize, int tries);
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



#endif // VALIDATIONS_H_INCLUDED

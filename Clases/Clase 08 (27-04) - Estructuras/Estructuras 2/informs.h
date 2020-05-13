//cualquier cosa probar con descomentar estos includes para que reconozca las estructuras
//#include "employee.h"
//#include "sector.h"

#ifndef INFORMS_H_INCLUDED
#define INFORMS_H_INCLUDED


#endif // INFORMS_H_INCLUDED

int informMenu();

void inform(eEmployee[], int, eSector[], int);
void inform_employeesXyear(eEmployee list[], int size, eSector[], int);
void inform_employeesXmen(eEmployee list[], int size, eSector[], int);
void inform_totalsalaries(eEmployee list[], int size);
void inform_employeesXsector(eEmployee list[], int size, eSector sectors[], int sizeSec);
void inform_employeeXallsectors(eEmployee list[], int size, eSector sectors[], int sizeSec);
void inform_totalSalariesXsector(eEmployee list[], int size, eSector sectors[], int sizeSec);

//mostrar el mayor sueldo de un sector definido por el usuario $$$
//de todos tengo que ver cual es el sueldo mas grande y mostrar eso
void inform_higherSalarySector(eEmployee list[], int size, eSector sectors[], int sizeSec);
//mostrar al empleado o empleados que mas gana en un sector definido por el usuario
//si hay empate me tiene que mostrar los dos empleados
void inform_higherSalaryEmployeeSector(eEmployee list[], int size, eSector sectors[], int sizeSec);
void inform_aumentarSueldoSectorPorcentaje(eEmployee list[], int size, eSector sectors[], int sizeSec);

void inform_sectorThatCollectMore(eEmployee list[], int size, eSector sectors[], int sizeSec);
//devuelve  la suma de todos los sueldos de los empleados de ese sector
float getTotalSalariesSector(int idSector, eEmployee list[], int size);

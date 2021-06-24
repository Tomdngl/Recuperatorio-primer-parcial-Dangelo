#include "Contribuyentes.h"
#include "Recaudaciones.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int Informes_MostrarTodosCon(eContribuyente array[], int TAM);
void Informes_MostrarUnoCon(eContribuyente Con);

int Informes_MostrarTodosRec(eRecaudacion array[], int TAM);
void Informes_MostrarUnoRec(eRecaudacion Con);

int Informes_MostrarContribuyentes(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM);
int Informes_MostrarRecaudaciones(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM);

#endif

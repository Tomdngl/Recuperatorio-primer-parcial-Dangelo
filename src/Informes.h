#include "Contribuyentes.h"
#include "Recaudaciones.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int Informes_MostrarTodosCon(eContribuyente array[], int TAM);
void Informes_MostrarUnoCon(eContribuyente Con);

int Informes_MostrarTodosRec(eRecaudacion array[], int TAM);
void Informes_MostrarUnoRec(eRecaudacion Con);

void Informes_menu(int *opc);
int Informes_opc1(eRecaudacion arrayRec[], eContribuyente arrayCon[], int CON_TAM, int REC_TAM);
int Informes_opc2(eRecaudacion array[], int TAM);

int Informes_opc4(eRecaudacion arrayRec[], eContribuyente arrayCon[], int CON_TAM, int REC_TAM);

#endif

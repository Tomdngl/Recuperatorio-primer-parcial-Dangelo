#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int eCon_Baja(eContribuyente arrayCon[], eRecaudacion arrayRec[],int TAM);
int eRec_Alta(eRecaudacion arrayRec[], eContribuyente arrayCon[], int TAM, int* idRec);
int eRec_Baja(eRecaudacion array[], int TAM, eContribuyente Con[]);
int eRec_CambiarEstado(eRecaudacion arrayRec[], eContribuyente arrayCon[], int TAM, int estado, char* mensaje);

int Informes_MostrarContribuyentes(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM);
int Informes_MostrarRecaudaciones(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM);
int Informes_BuscarIndex(eRecaudacion arrayRec[], eContribuyente Con, int TAM);
int Informes_MostrarTodosRecIndex(eRecaudacion array[], int TAM, eContribuyente Con[]);

#endif /* FUNCIONES_H_ */

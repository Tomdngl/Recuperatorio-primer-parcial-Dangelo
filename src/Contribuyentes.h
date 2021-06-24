#ifndef CONTRIBUYENTES_H_
#define CONTRIBUYENTES_H_

#define STR_LEN 40

typedef struct{
	char nombre[STR_LEN];
	char apellido[STR_LEN];
	char cuil[STR_LEN];
	int id;
	int isEmpty;
}eContribuyente;

void contribuyentes_menu(int* opc);

int eCon_Inicializar(eContribuyente arrayCon[], int TAM);
int eCon_ObtenerIndexLibre(eContribuyente arrayCon[], int TAM);
int eCon_BuscarPorID(eContribuyente arrayCon[], int TAM, int* idCon);
int eCon_Empty(eContribuyente arrayCon[], int TAM);

eContribuyente eCon_CargarDatos(int* flagCarga);
int eCon_Alta(eContribuyente arrayCon[], int TAM, int* id);
int eCon_Modificacion(eContribuyente arrayCon[], int TAM);
//int eCon_Baja(eContribuyente arrayCon[], eRecaudacion arrayRec[],int TAM);

#endif

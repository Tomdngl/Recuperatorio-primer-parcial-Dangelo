#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

#define SALDADO 0;
#define REFINANCIADO 1;

typedef struct
{
	int idCon;
	int mes;
	int tipo;
	float importe;
	int id;
	int isEmpty;
	int estado;
}eRecaudacion;

int eRec_Inicializar(eRecaudacion arrayRec[], int TAM);
int eRec_ObtenerIndexLibre(eRecaudacion arrayRec[], int TAM);
int eRec_BuscarPorID(eRecaudacion arrayRec[], int TAM, int idRec);

eRecaudacion eRec_CargarDatos(void);

#endif

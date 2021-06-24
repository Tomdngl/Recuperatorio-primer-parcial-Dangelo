#include <stdio.h>
#include <stdlib.h>
#include "Recaudaciones.h"
#include "Contribuyentes.h"
#include "Informes.h"
#include "utn.h"

int eRec_Inicializar(eRecaudacion arrayRec[], int TAM)
{
	int i;
	int rtn = 0;

	if(arrayRec != NULL && TAM > 0)
	{
		rtn = 1;
		for (i = 0; i < TAM; i++)
		{
			arrayRec[i].isEmpty = 0;
		}
	}
	return rtn;
}

int eRec_ObtenerIndexLibre(eRecaudacion arrayRec[], int TAM)
{
	int rtn = -1;
	int i;

	if (arrayRec != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arrayRec[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eRec_BuscarPorID(eRecaudacion arrayRec[], int TAM, int idRec)
{
	int rtn = -1;
	int i;

	if (arrayRec != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (arrayRec[i].id == idRec && arrayRec[i].isEmpty == 1) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

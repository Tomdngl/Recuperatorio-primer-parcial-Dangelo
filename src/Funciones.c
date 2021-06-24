#include "Contribuyentes.h"
#include "Recaudaciones.h"
#include "Funciones.h"
#include "Informes.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eCon_Baja(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM)
{
	int rtn = 0;
	int idCon;
	int index;
	int reintentos = 0;
	int confirmacion;

	Informes_MostrarTodosCon(arrayCon, TAM);
	do{
		utn_getNumero(&idCon, "\nIngrese el ID del contribuyente que dar de baja: ", "ID invalido.\n", 1000, 1050, 1);
		index = eCon_BuscarPorID(arrayCon, TAM, &idCon);
		if(index==-1)
		{
			printf("No se ha encontrado ese ID");
		}
		reintentos++;
	}while(index==-1 && reintentos < 3);

	Informes_MostrarTodosRecIndex(arrayRec, TAM, arrayCon);
	printf("\n");

	if((utn_getNumero(&confirmacion, "¿Esta seguro de realizar la baja?\n[1. Si] [2. No]: ", "Opcion inválida.", 1, 2, 2)) == 0 && confirmacion == 1 && index != -1)
	{
		arrayCon[index].isEmpty = -1;
		eRec_Baja(arrayRec, TAM, arrayCon);
		rtn = 1;
	}
	return rtn;
}

int eRec_Baja(eRecaudacion arrayRec[], int TAM, eContribuyente arrayCon[])
{
	int rtn = 0;
	int i;
	int j;

	if (arrayRec != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arrayRec[i].isEmpty == 1)
			{
				for(j = 0 ; j < TAM; j++)
					{
						if(arrayRec[i].idCon == arrayCon[j].id)
						{
							arrayRec[i].isEmpty = 0;
						}
					}
				rtn = 1;
			}
		}
	}

	return rtn;
}

int eRec_Alta(eRecaudacion arrayRec[], eContribuyente arrayCon[], int TAM, int* idRec)
{
	int rtn = 0;
	int confirmacion = 0;
	int indexRec;
	int indexCon;
	int idCon;
	int flagCarga = 0;
	int reintentos = 0;
	eRecaudacion auxRec;

	indexRec = eRec_ObtenerIndexLibre(arrayRec, TAM);

	if (indexRec != -1)
	{
		Informes_MostrarTodosCon(arrayCon, TAM);
		do{
			utn_getNumero(&idCon, "\nIngrese el ID del contribuyente: ", "ID invalido.\n", 1000, 1050, 1);
			indexCon = eCon_BuscarPorID(arrayCon, TAM, &idCon);
			if(indexCon==-1)
			{
				printf("No se ha encontrado ese ID");
			}
			reintentos++;
		}while(indexCon==-1 && reintentos < 3);

		if(utn_getNumero(&auxRec.mes, "Ingrese mes en el cual se va a realizar la recaudacion\n[En numero 1-12]: ", "Error\n", 1, 12, 2)== 0 &&
		utn_getNumeroFlotante(&auxRec.importe, "Ingrese el valor de la recaudación: ", "Error\n", 0, 500000, 2) == 0 &&
		utn_getNumero(&auxRec.tipo, "[1- ARBA]\n[2- IIBB]\n[3- GANANCIAS]\nIngrese el numero que corresponde al tipo de recaudacion: ", "Opcion inválida.\n", 1, 3, 2) == 0)
		{
			flagCarga = 1;
		}
		auxRec.idCon = indexCon;
		auxRec.estado = SALDADO;
		auxRec.id = *idRec;
		auxRec.isEmpty= 1;

		if(flagCarga == 1)
		{
		if((utn_getNumero(&confirmacion, "¿Esta seguro de realizar el alta?\n[1. Si] [2. No]: ", "Opcion inválida.", 1, 2, 2)) == 0 && confirmacion == 1)
			{
				arrayRec[indexRec] = auxRec;
				rtn = 1;
				*idRec=*idRec+1;
			}
		}
	}
	if(rtn == 1)
	{
		printf("\n%4s %10s %10s %15s %15s\n\n", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");
	Informes_MostrarUnoRec(arrayRec[indexRec]);
	}
	return rtn;
}

int eRec_CambiarEstado(eRecaudacion arrayRec[], eContribuyente arrayCon[], int TAM, int estado, char* mensaje)
{
	int rtn = 0;
	int reintentos = 0;
	int id;
	int confirmacion;
	int indexRec;

	Informes_MostrarTodosRec(arrayRec, TAM);
	do{
		utn_getNumero(&id, "\nIngrese el ID de la recaudación: ", "ID inválido.\n", 100, 150, 1);
		indexRec = eRec_BuscarPorID(arrayRec, TAM, id);
		if(indexRec==-1)
		{
			printf("No se ha encontrado ese ID");
		}
		reintentos++;
	}while(indexRec==-1 && reintentos < 3);

	if(indexRec != -1)
	{
		printf("La recaudacion pertenece al contribuyente:\n");
		printf("\n%4s %10s %10s %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL");
		Informes_MostrarUnoCon(arrayCon[arrayRec[indexRec].idCon]);
		printf("\n");
		if(utn_getNumero(&confirmacion, mensaje, "Opción inválida.\n", 1, 2, 3) == 0 && confirmacion == 1)
		{
			arrayRec[indexRec].estado = estado;
			rtn = 1;
		}
	}
	return rtn;
}

int Informes_MostrarContribuyentes(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM)
{
	int i;
	int j;
	int rtn = 0;

	puts("\n\tLista de contribuyentes");

	if (arrayCon != NULL && arrayRec != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arrayCon[i].isEmpty == 1)
			{
				printf("----------------------------------------------------------\n");
				printf("\t");
				Informes_MostrarUnoCon(arrayCon[i]);
				printf("\n\t\t RECAUDACIONES \t\n");
				printf("%4s %10s %10s %15s %15s\n\n", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");
				for(j = 0; j < TAM; j++)
				{
					if(arrayRec[j].idCon == i && arrayRec[j].isEmpty == 1)
					{
						Informes_MostrarUnoRec(arrayRec[j]);
					}
				}
				rtn = 1;
			}
		}
		printf("\n----------------------------------------------------------\n");
	}
	return rtn;
}

int Informes_MostrarRecaudaciones(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM)
{
	int rtn = 0;
	int index;
	int i;

	puts("\n\tLista de recaudaciones saldadas");
	if (arrayCon != NULL && arrayRec != NULL && TAM > 0)
	{
		printf("%10s %10s %4s %10s %10s %15s %15s\n\n", "CUIL", "NOMBRE", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");
		for (i = 0; i < TAM; i++)
		{
			if(arrayRec[i].estado == 0 && arrayRec[i].isEmpty == 1)
			{
				index = arrayRec[i].idCon;
				printf("%10s %10s", arrayCon[index].cuil, arrayCon[index].nombre);
				Informes_MostrarUnoRec(arrayRec[i]);
				rtn = 1;
			}
		}
	}
	return rtn;
}

int Informes_MostrarTodosRecIndex(eRecaudacion arrayRec[], int TAM, eContribuyente Con[])
{
	int i;
	int j;
	int rtn = 0;
	int cantidad = 0;
	int index;

	printf("Recaudaciones correspondientes al contribuyente:\n");
	printf("%4s %10s %10s %15s %15s\n\n", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");

	if (arrayRec != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arrayRec[i].isEmpty == 1)
			{
				for(j = 0 ; j < TAM; j++)
					{
						if(arrayRec[i].idCon == Con[j].id)
						{
							index = i;
						}
					}
				Informes_MostrarUnoRec(arrayRec[index]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

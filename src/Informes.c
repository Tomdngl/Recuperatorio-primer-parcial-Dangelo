#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudaciones.h"
#include "Informes.h"
#include "utn.h"

void Informes_MostrarUnoCon(eContribuyente Con)
{
	printf("%4d %10s %10s %15s\n", Con.id, Con.nombre, Con.apellido, Con.cuil);
}

void Informes_MostrarUnoRec(eRecaudacion Rec)
{
   char tipo[10];
   char estado[20];

   if (Rec.estado == 0) {
		strcpy(estado, "SALDADO");
   }
   else
   {
	   strcpy(estado, "REFINANCIADA");
   }

	switch(Rec.tipo){
		case 1:
		strcpy(tipo, "ARBA");
		break;
		case 2:
		strcpy(tipo, "IIBB");
		break;
		case 3:
		strcpy(tipo, "GANANCIAS");
		break;
	}
	printf("%4d %10d %10s %15.2f %15s \n", Rec.id, Rec.mes, tipo, Rec.importe, estado);
}

int Informes_MostrarTodosRec(eRecaudacion array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\tLista de recaudaciones");
	printf("%4s %10s %10s %15s %15s\n\n", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");

	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == 1)
			{
				Informes_MostrarUnoRec(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int Informes_MostrarTodosCon(eContribuyente array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\tLista de contribuyentes");
	printf("%4s %10s %10s %15s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL");

	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == 1)
			{
				Informes_MostrarUnoCon(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

void Informes_menu(int *opc)
{
    printf("\n                    ###   Informes   ###\n");
    printf("\n\n");
    printf("1. Contribuyentes con más recaudaciones en estado “refinanciar”.\n");
    printf("2. Cantidad de recaudaciones saldadas de importe mayor a 1000.\n");
    printf("3. Contribuyentes segun tipo de recaudación.\n");
    printf("4. Contribuyentes que pagaron impuestos en el mes de Febrero.\n");
    printf("5. Salir.\n");

	utn_getNumero(opc, "Seleccione una opcion: ", "Error, ", 1, 5, 3);
}

int Informes_opc1(eRecaudacion arrayRec[], eContribuyente arrayCon[], int CON_TAM, int REC_TAM)
{
	int rtn = 0;
	int i;
	int j;
	int maxRec=0;
	int contadorRef;
	int flagMax = 0;

	if (arrayRec != NULL && arrayCon != NULL && CON_TAM > 0 && REC_TAM > 0)
	{
		for (i = 0; i < REC_TAM; i++)
		{
			if(arrayCon[i].isEmpty == 1)
			{
				for(j = 0 ; j < CON_TAM; j++)
				{
					if(arrayRec[i].idCon == arrayCon[j].id)
					{
						if(arrayRec[i].estado == 1)
						{
							contadorRef++;
							if(maxRec > contadorRef || flagMax == 0)
							maxRec = i;
							flagMax = 1;
						}
						else
						{
							printf("No hay contribuyentes con recaudaciones refinanciadas.");
							break;
							break;
						}
					}
				}
			}
		}
	}

	if(maxRec!=0)
	{
	Informes_MostrarUnoCon(arrayCon[maxRec]);
	}

	return rtn;
}

int Informes_opc2(eRecaudacion array[], int TAM)
{
	int rtn = 0;
	int cantidad = 0;
	int i;

	puts("\n\tLista de recaudaciones con importe mayor a 1000");
	printf("%4s %10s %10s %15s %15s\n\n", "ID", "MES", "TIPO", "IMPORTE", "ESTADO");

	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == 1 && array[i].importe>1000 && array[i].estado==0)
			{
				Informes_MostrarUnoRec(array[i]);
				cantidad++;
			}
		}
	}

	return rtn;
}

/*
int Informes_opc3(eContribuyente arrayCon[], eRecaudacion arrayRec[], int TAM, int tipoIngresado)
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
					if(arrayRec[j].idCon == i && arrayRec[j].isEmpty == 1 && arrayRec[j].tipo==tipoIngresado)
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
*/

int Informes_opc4(eRecaudacion arrayRec[], eContribuyente arrayCon[], int CON_TAM, int REC_TAM)
{
	int rtn = 0;
	int i;
	int j;

	printf("Lista de contribuyentes que pagaron en el mes de febrero: \n");

	if (arrayRec != NULL && arrayCon != NULL && CON_TAM > 0 && REC_TAM > 0)
		{
			for (i = 0; i < REC_TAM; i++)
			{
				if(arrayCon[i].isEmpty == 1)
				{
					for(j = 0 ; j < CON_TAM; j++)
					{
						if(arrayRec[i].idCon == arrayCon[j].id)
						{
							if(arrayRec[j].mes == 2)
							{
								printf("%10s: %10s %10s: %10s", "NOMBRE", arrayCon[i].nombre ,"CUIL", arrayCon[i].cuil);
								rtn = 1;
							}
						}
					}
				}
			}
		}

	return rtn;
}

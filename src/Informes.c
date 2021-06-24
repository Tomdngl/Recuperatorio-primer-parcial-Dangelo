#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"
#include "Recaudaciones.h"

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

	puts("\n\tLista de contribuyentes");
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
				Informes_MostrarUnoCon(arrayCon[i]);
				printf("\t\t RECAUDACIONES \t\n");
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

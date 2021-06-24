#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudaciones.h"
#include "Informes.h"

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


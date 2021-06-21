#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"

void Informes_MostrarUnoCon(eContribuyente Con) {

	printf("%4d %10s %10s %15s\n", Con.id, Con.nombre, Con.apellido, Con.cuil);
}

int Informes_MostrarTodosCon(eContribuyente array[], int TAM) {
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

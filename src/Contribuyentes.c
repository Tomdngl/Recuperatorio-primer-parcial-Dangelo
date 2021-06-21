#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"
#include "utn.h"

void contribuyentes_menu(int *opc)
{
    printf("\n                    ###   Menu   ###\n");
    printf("\n\n");
    printf("1. Alta de contribuyente.\n");
    printf("2. Modificar datos del contribuyente.\n");
    printf("3. Baja de contribuyente.\n");
    printf("4. Recaudación.\n");
    printf("5. Refinanciar Recaudación.\n");
    printf("6. Saldar Recaudación.\n");
    printf("7. Imprimir contribuyentes.\n");
    printf("8. Imprimir Recaudación.\n");
    printf("10. Salir\n\n");
	utn_getNumero(opc, "Seleccione una opcion: ", "Error, ", 0, 10, 3);
}

int eCon_Inicializar(eContribuyente arrayCon[], int TAM)
{
	int i;
	int rtn = 0;

	if(arrayCon != NULL && TAM > 0)
	{
		rtn = 1;
		for (i = 0; i < TAM; i++)
		{
			arrayCon[i].isEmpty = 0;
		}
	}
	return rtn;
}

int eCon_ObtenerIndexLibre(eContribuyente arrayCon[], int TAM)
{
	int rtn = -1;
	int i;

	if (arrayCon != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (arrayCon[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

eContribuyente eCon_CargarDatos(void)
{
	eContribuyente aux;

	utn_getNombre(aux.nombre, STR_LEN, "Ingrese el nombre del contribuyente: ", "Nombre invalido.\n", 2);
	utn_getNombre(aux.apellido, STR_LEN, "Ingrese el apellido del contribuyente: ", "Apellido invalido.\n", 2);
	utn_getCuil(aux.cuil, 13, "Ingrese el cuil del contribuyente [Solo numeros]: ", "Cuil invalido.\n", 2);

	return aux;
}

int eCon_Alta(eContribuyente arrayCon[], int TAM, int* idCon)
{
	int rtn = 0;
	int confirmacion = 0;
	eContribuyente auxCon;

	int index = eCon_ObtenerIndexLibre(arrayCon, TAM);

	if (index != -1)
	{
		auxCon = eCon_CargarDatos();
		auxCon.id = *idCon;
		auxCon.isEmpty= 1;

		if((utn_getNumero(&confirmacion, "¿Esta seguro de realizar el alta?\n[1. Si] [2. No]: ", "Opcion inválida.", 1, 2, 2)) == 0 && confirmacion == 1)
			{
				arrayCon[index] = auxCon;
				rtn = 1;
				*idCon=*idCon+1;
			}
	}
	return rtn;
}

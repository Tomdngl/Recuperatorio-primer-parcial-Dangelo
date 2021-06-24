#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuyentes.h"
#include "utn.h"
#include "Informes.h"

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
	utn_getNumero(opc, "Seleccione una opcion: ", "Error, ", 1, 10, 3);
}

void edit_con_menu(int *opc, eContribuyente arrayCon)
{

	printf("\n                    ###   Modificaciones   ###\n");
	printf("\n");
	Informes_MostrarUnoCon(arrayCon);
    printf("\n1. Modificar nombre.\n");
    printf("2. Modificar apellido.\n");
    printf("3. Modificar cuil.\n");
    printf("4. Aplicar cambios.\n");
    printf("10. Salir\n");

	utn_getNumero(opc, "Seleccione una opcion: ", "Error, ", 1, 10, 3);
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

int eCon_BuscarPorID(eContribuyente arrayCon[], int TAM, int* idCon)
{
	int rtn = -1;
	int i;

	if (arrayCon != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (arrayCon[i].id == *idCon && arrayCon[i].isEmpty == 1) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eCon_Alta(eContribuyente arrayCon[], int TAM, int* idCon)
{
	int rtn = 0;
	int confirmacion = 0;
	int flagCarga = 0;
	eContribuyente auxCon;

	int index = eCon_ObtenerIndexLibre(arrayCon, TAM);

	if (index != -1)
	{
		if(utn_getNombre(auxCon.nombre, STR_LEN, "Ingrese el nombre del contribuyente: ", "Nombre invalido.\n", 2) == 0 &&
		utn_getNombre(auxCon.apellido, STR_LEN, "Ingrese el apellido del contribuyente: ", "Apellido invalido.\n", 2) == 0 &&
		utn_getCuil(auxCon.cuil, 13, "Ingrese el cuil del contribuyente [Solo numeros]: ", "Cuil invalido.\n", 2) == 0)
		{
			flagCarga = 1;
		}
		auxCon.id = *idCon;
		auxCon.isEmpty= 1;

		if(flagCarga == 1)
		{
			if((utn_getNumero(&confirmacion, "¿Esta seguro de realizar el alta?\n[1. Si] [2. No]: ", "Opcion inválida.", 1, 2, 2)) == 0 && confirmacion == 1)
				{
					arrayCon[index] = auxCon;
					rtn = 1;
					*idCon=*idCon+1;
				}
		}
	}
	if(rtn == 1)
	{
	printf("\n%4s %10s %10s %10s\n\n", "ID", "NOMBRE", "APELLIDO", "CUIL");
	Informes_MostrarUnoCon(arrayCon[index]);
	}

	return rtn;
}

int eCon_Modificacion(eContribuyente arrayCon[], int TAM)
{
	int rtn = 0;
	int reintentos = 0;
	int opc;
	int idCon;
	int index;

	eContribuyente aux;

	Informes_MostrarTodosCon(arrayCon, TAM);
	do{
		utn_getNumero(&idCon, "\nIngrese el ID del contribuyente que desea modificar: ", "ID invalido.\n", 1000, 1050, 1);
		index = eCon_BuscarPorID(arrayCon, TAM, &idCon);
		if(index==-1)
		{
			printf("No se ha encontrado ese ID");
		}
		reintentos++;
	}while(index==-1 && reintentos < 3);

	if(index!=-1)
	{
		aux = arrayCon[index];
		do{
			edit_con_menu(&opc, aux);
			switch (opc)
			{
				case 1:
					utn_getNombre(aux.nombre, STR_LEN, "Ingrese el nuevo nombre: ", "Nombre invalido.\n", 2);
					break;
				case 2:
					utn_getNombre(aux.apellido, STR_LEN, "Ingrese el nuevo apellido: ", "Apellido invalido.\n", 2);
					break;
				case 3:
					utn_getCuil(aux.cuil, 13, "Ingrese el nuevo cuil del contribuyente [Solo numeros]: ", "Cuil invalido.\n", 2);
					break;
				case 4:
					arrayCon[index] = aux;
					printf("Se han aplicado las modificaciones\n");
					rtn = 1;
					break;
				case 10:
					break;
				default:
					printf("Opcion invalida.");
					break;
			}
		}while(opc != 10);
	}
	return rtn;
}

/*
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

	Informes_MostarRecaudacionesCon(arrayRec, arrayCon[index], TAM);

	if((utn_getNumero(&confirmacion, "¿Esta seguro de realizar la baja?\n[1. Si] [2. No]: ", "Opcion inválida.", 1, 2, 2)) == 0 && confirmacion == 1 && index != -1)
	{
		arrayCon[index].isEmpty = -1;
		rtn = 1;
	}
	return rtn;
}
*/

int eCon_Empty(eContribuyente arrayCon[], int TAM)
{
	int rtn = 0;
	int i;
	for(i = 0; i < TAM; i++)
	{
		if(arrayCon[i].isEmpty==1)
		{
			rtn = 1;
			break;
		}
	}
	return rtn;
}

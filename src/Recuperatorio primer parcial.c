#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"
#include "Recaudaciones.h"
#include "Informes.h"
#include "Funciones.h"

#define CON_TAM 50
#define REC_TAM 50

eContribuyente arrayCon[CON_TAM];
eRecaudacion arrayRec[REC_TAM];

int main(void) {
	setbuf(stdout, NULL);
	int opc;
	int id_con = 1000;
	int id_rec = 100;

	if(eCon_Inicializar(arrayCon, CON_TAM) && eRec_Inicializar(arrayRec, REC_TAM))
	{
		printf("Arrays inicializados correctamente.\n");
	}
	else
	{
		printf("\nNo hay suficiente memoria disponible para ejecutar el programa, libere memoria e intentelo nuevamente.");
		exit(-1);
	}

	do{
		contribuyentes_menu(&opc);
		switch (opc) {
			case 1:
				if(eCon_Alta(arrayCon, CON_TAM, &id_con)== 1)
				{
					printf("\nAlta de contribuyente exitosa.\n");
				}
				else
				{
					printf("\nAlta de contribuyente cancelada.\n");
				}
				break;
			case 2:
				if(eCon_Empty(arrayCon, CON_TAM) == 1)
				{
					if(eCon_Modificacion(arrayCon, CON_TAM) == 1)
					{
						printf("\nContribuyente modificado con éxito.\n");
					}
					else
					{
						printf("\nModificacion cancelada.\n");
					}
				}
				else
				{
					printf("Aun no ha ingresado ningun contribuyente.\n");
				}
				break;
			case 3:
				if(eCon_Baja(arrayCon, arrayRec, CON_TAM) == 1)
				{
					printf("\nBaja de contribuyente exitosa..\n");
				}
				else
				{
					printf("\nBaja cancelada.\n");
				}
				break;
			case 4:
				if(eRec_Alta(arrayRec, arrayCon, REC_TAM, &id_rec) == 1)
				{
					printf("\nAlta de recaudación exitosa.\n");
				}
				else
				{
					printf("Alta de recaudación cancelada.\n");
				}
				break;
			case 5:
				if(eRec_CambiarEstado(arrayRec, arrayCon, REC_TAM, 1, "¿Desea refinanciar esta recaudación? [1. Si] [2. No]: ") == 1)
				{
					printf("Recaudacion refinanciada con éxito.\n");
				}
				else
				{
					printf("Cambio de estado cancelado.\n");
				}
				break;
			case 6:
				if(eRec_CambiarEstado(arrayRec, arrayCon, REC_TAM, 0, "¿Desea saldar esta recaudación? [1. Si] [2. No]: ") == 1)
				{
					printf("Recaudacion saldada con éxito.\n");
				}
				else
				{
					printf("Cambio de estado cancelado.\n");
				}
				break;
			case 7:
				if(Informes_MostrarContribuyentes(arrayCon, arrayRec, CON_TAM) == 0)
				{
					printf("No hay contribuyentes para listar.\n");
				}
				break;
			case 8:
				if(Informes_MostrarRecaudaciones(arrayCon, arrayRec, CON_TAM) == 0)
				{
					printf("No hay recaudaciones para listar.\n");
				}
				break;
			case 10:
				printf("Gracias por usar este programa.");
				break;
			default:
				printf("Opcion inválida.");
				break;
		}
	}while(opc!=10);

	return 0;
}

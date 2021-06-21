#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"
#include "Recaudaciones.h"
#include "Informes.h"

#define CON_TAM 50
#define REC_TAM 50

eContribuyente arrayCon[CON_TAM];

int main(void) {
	setbuf(stdout, NULL);
	int opc;
	int id_con = 1000;

	if(eCon_Inicializar(arrayCon, CON_TAM))
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
					printf("\nContribuyente dado de alta con éxito.");
				}
				else
				{
					printf("\nOcurrió un error al intentar dar el alta el contribuyente.");
				}
				break;
			case 2:
				//Revisar que exista un alta o bucle infinito ¿Funcion con_arrayEmpty?
				if(eCon_Modificacion(arrayCon, CON_TAM) == 1)
				{
					printf("\nContribuyente modificado con éxito.");
				}
				else
				{
					printf("\nModificacion cancelada.");
				}
				break;
			case 3:
				if(eCon_Baja(arrayCon, CON_TAM) == 1)
				{
					printf("\nContribuyente dado de baja con éxito.");
				}
				else
				{
					printf("\nBaja cancelada.");
				}
				break;
			case 7:
				//Completar
				Informes_MostrarTodosCon(arrayCon, CON_TAM);
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

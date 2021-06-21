#include <stdio.h>
#include <stdlib.h>
#include "Contribuyentes.h"
#include "Recaudaciones.h"

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
					puts("\nOcurrió un error al intenta dar el alta el contribuyente.");
				}

				break;
			case 2:
				break;
			case 10:
				printf("Gracias por usar este programa.");
				break;
			default:
				printf("Opcion invalida.");
				break;
		}
	}while(opc!=10);

	return 0;
}

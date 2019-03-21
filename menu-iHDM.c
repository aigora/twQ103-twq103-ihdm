#include <stdio.h>
#include <cstdlib>

int main() {
	int i;
	char opcion, opcion2;
	char nombre[50];
	int contra;
	
	system("color 70");
	printf("\tBIENVENIDO A LA LIBRERIA MAJADA\n");
	
	do{
		printf("\t ________________________\n");
		printf("\t|                        |\n");
		printf("\t| A-Registrarse          |\n");
		printf("\t| B-Iniciar sesion       |\n");
		printf("\t| C-Libros               |\n");
		printf("\t| D-Historial            |\n");
		printf("\t| E-Fin del programa     |\n");
		printf("\t|________________________|\n");
		printf("\n\n");
		printf ("Introduce la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion);
		
		switch (opcion){
			case 'A': 
				/*printf("Introduce tu nombre y apellido\n");
				gets(nombre);*/
				
				break;
			case 'B':
				/*printf("Introduce tu nombre y apellido:\n");
				gets(nombre);*/
				
				break;
			default:
				printf ("Opcion incorrecta\n");
		}
		
	/*	printf("Introduce tu nombre y apellido:\n");
				gets(nombre);
				printf("Introduce tu contraseña:\n");
				scanf("%d", &contra);
				do {
					printf("\t\t\tA-Libros");
					printf("\t\t\tB-Historial");
					printf("\t\t\tC-Fin del programa");
					printf ("Introduce la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion2);
				}*/
	} while(opcion!='B');
}

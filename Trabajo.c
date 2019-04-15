#include <stdio.h>

struct Usuario{
	char nombre[50];
	char password[10];
};

int main() {
	FILE *puntero;
	struct Usuario usuario[100];
	int i;
	char opcion, opcion2;
	char nombreLibro[50];
	char autorLibro[50];
	
	system("color 70");
	printf("\tBIENVENIDO A LA LIBRERIA MAJADA\n");
	
	do{
		printf("\t ________________________\n");
		printf("\t|                        |\n");
		printf("\t| A-Registrarse          |\n");
		printf("\t| B-Iniciar sesion       |\n");
		printf("\t| C-Salir del programa   |\n");
		printf("\t|________________________|\n");
		printf("\n\n");
		printf ("Introduce la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion);
		
		switch (opcion){
			case 'A': 
				printf("Introduce tu nombre y apellido:\n");
				fflush(stdin);
				gets(usuario[i].nombre);
				printf("Introduce tu contraseña:\n");
				fflush(stdin);
				gets(usuario[i].password);
				
				do {
					printf("\t\t\tA-Libros\n");
					printf("\t\t\tB-Historial\n");
					printf("\t\t\tC-Fin del programa\n");
					printf ("Introduce la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion2);
				} while(opcion2<'A'||opcion2>'C');
				
				if(opcion2=='A'){
					do {
						//Misterio, Ciencia ficción, Romantica, Terror, Poesía
						printf("\t\t\tA-Misterio\n");
						printf("\t\t\tB-Ciencia ficcion\n");
						printf("\t\t\tC-Romantica\n");
						printf("\t\t\tD-Terror\n");
						printf("\t\t\tE-Poesia\n");
						printf("\t\t\tF-Fin del programa\n");
						printf ("Introduce la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion3);
					} while(opcion3<'A'||opcion3>'F');
					
					puntero = fopen("novelas.txt", "r");
					if(puntero==NULL){
						printf("No se ha podido abrir el fichero\n");
						return -1;
					}
					
					i=0;
					while(fscanf(puntero, "%s %s", nombreLibro, autorLibro)!=EOF){
						fprintf(puntero, "%s %s \n", nombreLibro, autorLibro);
						i++;
					}
					fclose(puntero);
				}
				
				break;
			case 'B':
				/*
				puntero = fopen("usuarios.txt", "r");
				if(puntero==NULL){
					printf("No se ha podido abrir el fichero\n");
					return -1;
				}
				
				i=0;
				while(fscanf(puntero, "%s %s", usuario[i].nombre, usuario[i].password)!=EOF){
					printf(puntero, "%d %s %s \n", i+1, usuario[i].nombre, usuario[i].password);
					i++;
				}
				fclose(puntero);
				*/
				do {
					printf("\t\t\tA-Libros\n");
					printf("\t\t\tB-Historial\n");
					printf("\t\t\tC-Fin del programa\n");
					printf ("Introduce la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion2);
				}while(opcion2!='A'&&opcion2!='B'&&opcion2!='C');
				break;
			case 'C':
				printf("Fin del programa.\n");
				break;
			default:
				printf ("Opcion incorrecta\n");
				break;
		}
	} while(opcion!='C');
}
/*
puntero = fopen("usuarios.txt", "w");
				if(puntero==NULL){
					printf("No se ha podido abrir el fichero\n");
					return -1;
				}
				
				i=0;
				while(fscanf(puntero, "%s %s", usuario[i].nombre, usuario[i].password)!=EOF){
					fprintf(puntero, "%d %s %s \n", i+1, usuario[i].nombre, usuario[i].password);
					i++;
				}
				fclose(puntero);
*/

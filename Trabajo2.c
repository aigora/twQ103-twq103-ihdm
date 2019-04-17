#include <stdio.h>

struct Usuario{
	char nombre[50];
	char password[10];
};

int main() {
	FILE *punteroU;
	FILE *punteroM;
	struct Usuario usuario[100];
	int i;
	char opcion, opcion2;
	int opcion3, opcion4;
	char nombreLibro[50];
	char nombreAutor[50];
	
	system("color 70");
	printf("\tBIENVENIDO A LA BIBLIOTECA MAJADA\n");
	
	do{
		system("cls");
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
	} while(opcion!='A'&&opcion!='B'&&opcion!='C');
	
	do{
		/*system("cls");
		printf("\t ________________________\n");
		printf("\t|                        |\n");
		printf("\t| A-Registrarse          |\n");
		printf("\t| B-Iniciar sesion       |\n");
		printf("\t| C-Salir del programa   |\n");
		printf("\t|________________________|\n");
		printf("\n\n");
		printf ("Introduce la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion);*/
		
		switch (opcion){
			case 'A': 
				printf("Introduce nombre de usuario:\n");
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
						printf("\t\t\t1-Misterio\n");
						printf("\t\t\t2-Ciencia ficcion\n");
						printf("\t\t\t3-Romantica\n");
						printf("\t\t\t4-Terror\n");
						printf("\t\t\t5-Poesia\n");
						printf("\t\t\t6-Fin del programa\n");
						printf ("Introduce la opcion: \n");
						fflush(stdin);
						scanf("%d", &opcion3);
					
					
						if(opcion3==1){
							printf("\n\n\t\tMISTERIO\n\n");
							punteroM = fopen("misterio.txt", "r");
							if(punteroM==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=0;
							while(fscanf(punteroM, "%s\t%s", nombreLibro, nombreAutor)!=EOF){
								printf("%d\t%s\t%s\n", i+1, nombreLibro, nombreAutor);
								i++;
							}
							printf("\n");
							
							printf("Escoge un libro\n");
							scanf("%d", &opcion4);
							if(i==opcion4){
								printf("%s\t%s", nombreLibro[i], nombreAutor[i]);
							}
							fclose(punteroM);
						}
						else if(opcion3==2){
							
						}
						else if(opcion3==3){
							
						}
						else if(opcion3==4){
							
						}
						else if(opcion3==5){
							
						}
						else if(opcion3==6){
							printf("Fin del programa\n");
							break;
						}
					} while(opcion3<'1'||opcion3>'6');
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
	} while(opcion2!='C');
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

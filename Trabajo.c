#include <stdio.h>
#define MAX_USUSUARIOS 100
#define MAX_LIBROS 15

struct Usuario{
	char nombre[50];
	char password[10];
	int identificador;
};

struct Libro{
	char nombreLibro[50];
	char nombreAutor[50];
};

int main() {
	FILE *fichero;
	FILE *fichero2;
	struct Usuario usuario[MAX_USUSUARIOS];
	struct Libro misterio[MAX_LIBROS], ciencia_ficcion[MAX_LIBROS], romantica[MAX_LIBROS], terror[MAX_LIBROS], poesia[MAX_LIBROS];
	int i, j;
	char opcion, opcion2;
	int opcion3, opcion4;
	int numUsuarios=0;
	
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
		
		switch (opcion){
			case 'A': 
				fichero = fopen("usuario.txt", "r");
				if (fichero == NULL) {
					printf("No se ha podido abrir el fichero\n");
					return -1; 
				}
				i=0;
				while (fscanf(fichero, "%d %s %s", &usuario[i].identificador, usuario[i].nombre, usuario[i].password)!=EOF) {
					i++;
				}
				fclose(fichero);
				
				printf("Nombre usuario:\n");
				usuario[i].identificador=i;
				fflush(stdin);
				gets(usuario[i].nombre);
				printf("Contrasena usuario:\n");
				fflush(stdin);
				gets(usuario[i].password);
				i++;
				system("cls");
				
				fichero = fopen("usuario.txt", "w");
	
				if (fichero == NULL) {
					printf("No se ha podido abrir el fichero\n");
					return -1;
				}
					
				
				for(j=0;j<i;j++){
					fprintf(fichero,"%d\t%s\t%s\n", usuario[j].identificador, usuario[j].nombre, usuario[j].password);
				}
					
				fclose(fichero);
				
				do {
					printf("\n\t\t\tA-Libros\n");
					printf("\t\t\tB-Historial\n");
					printf("\t\t\tC-Fin del programa\n");
					printf ("Introduce la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion2);
				} while(opcion2<'A'||opcion2>'C');
				system("cls");
				
				if(opcion2=='A'){
					do {
						//Misterio, Ciencia ficción, Romantica, Terror, Poesía
						printf("\t\t\t1-Misterio\n");
						printf("\t\t\t2-Ciencia ficcion\n");
						printf("\t\t\t3-Romantica\n");
						printf("\t\t\t4-Terror\n");
						printf("\t\t\t5-Poesia\n");
						printf("\t\t\t6-Vuelta al menu\n");
						printf ("Introduce la opcion: \n");
						fflush(stdin);
						scanf("%d", &opcion3);
						system("cls");
					
						if(opcion3==1){
							printf("\n\n\t\tMISTERIO\n\n");
							fichero2 = fopen("misterio.txt", "r");
							if(fichero2==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=1;
							while(fscanf(fichero2, "%s\t%s", misterio[i].nombreLibro, misterio[i].nombreAutor)!=EOF){
								printf("\t%d\t%s\t%s\n", i, misterio[i].nombreLibro, misterio[i].nombreAutor);
								i++;
							}
							fclose(fichero2);
							printf("\n");
							
							do{
								printf("Escoge un libro\n");
								scanf("%d", &opcion4);
							}while(opcion4<1||opcion4>15);
							system("cls");
							printf("\n\tSu eleccion ha sido:\n\n"); 
							printf("\t\t%s de %s.\n\n", misterio[opcion4].nombreLibro, misterio[opcion4].nombreAutor);	
							printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
							printf("\tGracias por usar el sistema.\n\n");
						}
						else if(opcion3==2){
							printf("\n\n\t\tCIENCIA FICCION\n\n");
							fichero2 = fopen("ciencia_ficcion.txt", "r");
							if(fichero2==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=1;
							while(fscanf(fichero2, "%s\t%s", ciencia_ficcion[i].nombreLibro, ciencia_ficcion[i].nombreAutor)!=EOF){
								printf("\t%d\t%s\t%s\n", i, ciencia_ficcion[i].nombreLibro, ciencia_ficcion[i].nombreAutor);
								i++;
							}
							fclose(fichero2);
							printf("\n");
							
							do{
								printf("Escoge un libro\n");
								scanf("%d", &opcion4);
							}while(opcion4<1||opcion4>15);
							system("cls");
							printf("\n\tSu eleccion ha sido:\n\n"); 
							printf("\t\t%s de %s.\n\n", ciencia_ficcion[opcion4].nombreLibro, ciencia_ficcion[opcion4].nombreAutor);	
							printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
							printf("\tGracias por usar el sistema.\n\n");
						}
						else if(opcion3==3){
							printf("\n\n\t\tROMANTICA\n\n");
							fichero2 = fopen("romantica.txt", "r");
							if(fichero2==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=1;
							while(fscanf(fichero2, "%s\t%s", romantica[i].nombreLibro, romantica[i].nombreAutor)!=EOF){
								printf("\t%d\t%s\t%s\n", i, romantica[i].nombreLibro, romantica[i].nombreAutor);
								i++;
							}
							fclose(fichero2);
							printf("\n");
							
							do{
								printf("Escoge un libro\n");
								scanf("%d", &opcion4);
							}while(opcion4<1||opcion4>15);
							system("cls");
							printf("\n\tSu eleccion ha sido:\n\n"); 
							printf("\t\t%s de %s.\n\n", romantica[opcion4].nombreLibro, romantica[opcion4].nombreAutor);	
							printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
							printf("\tGracias por usar el sistema.\n\n");
						}
						else if(opcion3==4){
							printf("\n\n\t\tTERROR\n\n");
							fichero2 = fopen("terror.txt", "r");
							if(fichero2==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=1;
							while(fscanf(fichero2, "%s\t%s", terror[i].nombreLibro, terror[i].nombreAutor)!=EOF){
								printf("\t%d\t%s\t%s\n", i, terror[i].nombreLibro, terror[i].nombreAutor);
								i++;
							}
							fclose(fichero2);
							printf("\n");
							
							do{
								printf("Escoge un libro\n");
								scanf("%d", &opcion4);
							}while(opcion4<1||opcion4>15);
							system("cls");
							printf("\n\tSu eleccion ha sido:\n\n"); 
							printf("\t\t%s de %s.\n\n", terror[opcion4].nombreLibro, terror[opcion4].nombreAutor);	
							printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
							printf("\tGracias por usar el sistema.\n\n");
						}
						else if(opcion3==5){
							printf("\n\n\t\tPOESIA\n\n");
							fichero2 = fopen("poesia.txt", "r");
							if(fichero2==NULL){
								printf("No se ha podido abrir el fichero\n");
								return -1;
							}
							
							i=1;
							while(fscanf(fichero2, "%s\t%s", poesia[i].nombreLibro, poesia[i].nombreAutor)!=EOF){
								printf("\t%d\t%s\t%s\n", i, poesia[i].nombreLibro, poesia[i].nombreAutor);
								i++;
							}
							fclose(fichero2);
							printf("\n");
							
							do{
								printf("Escoge un libro\n");
								scanf("%d", &opcion4);
							}while(opcion4<1||opcion4>15);
							system("cls");
							printf("\n\tSu eleccion ha sido:\n\n"); 
							printf("\t\t%s de %s.\n\n", poesia[opcion4].nombreLibro, poesia[opcion4].nombreAutor);	
							printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
							printf("\tGracias por usar el sistema.\n\n");
						}
						else if(opcion3==6){
							printf("Fin del programa\n");
						}
					} while(opcion3<1||opcion3!=6||opcion3>6);
				}
				else if(opcion2=='B'){
					
				}
				
				break;
			case 'B':
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
	/*
	fichero = fopen("usuario.txt", "w");
	
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1;
	}
		
	
	for(j=0;j<i;j++){
		fprintf(fichero,"%d\t%s\t%s\n", usuario[j].identificador, usuario[j].nombre, usuario[j].password);
	}
		
	fclose(fichero); */
}

#include <stdio.h>
#include <string.h>
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

int usuarios(char opcion);
int libros(char nombre[], struct Libro tipoLibro[]);

int main() {
	struct Usuario usuario[MAX_USUSUARIOS];
	struct Libro misterio[MAX_LIBROS], ciencia_ficcion[MAX_LIBROS], romantica[MAX_LIBROS], terror[MAX_LIBROS], poesia[MAX_LIBROS];
	char opcion, opcion2;
	int opcion3;
	
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
				usuarios('A');
				break;
			case 'B':
				usuarios('B');
				break;
			case 'C':
				printf("Fin del programa.\n");
				return -1;
			default:
				printf ("Opcion incorrecta\n");
				break;
		}
	} while(opcion<'A'||opcion>'C');
	
	do {
		printf("\t\t\tA-Libros\n");
		printf("\t\t\tB-Informacion general\n");
		printf("\t\t\tC-Fin del programa\n");
		printf ("Introduce la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion2);
		system("cls");
		
		switch (opcion2){
			case 'A':
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
						libros("misterio", misterio);
					}
					else if(opcion3==2){
						printf("\n\n\t\tCIENCIA FICCION\n\n");
						libros("ciencia_ficcion", ciencia_ficcion);
					}
					else if(opcion3==3){
						printf("\n\n\t\tROMANTICA\n\n");
						libros("romantica", romantica);
					}
					else if(opcion3==4){
						printf("\n\n\t\tTERROR\n\n");
						libros("terror", terror);
					}
					else if(opcion3==5){
						printf("\n\n\t\tPOESIA\n\n");
						libros("poesia", poesia);
					}
					else if(opcion3<1||opcion3>6){
						printf("Opcion incorrecta.\n");
					}
				} while(opcion3!=6);
				break;
			case 'B':
				printf("_____________________________________________________________________________________________________________________________\n\n");
				printf("\t\tDireccion: Ronda de Valencia, 3\n");
				printf("\t\t           28012 Madrid\n");
				printf("\t\t           Spain\n");
				printf("\t\t           Tel.: 912 458 258\n");
				printf("_____________________________________________________________________________________________________________________________\n\n");
				printf("\t\tTransporte: Metro y cercanias: Embajadores\n");
				printf("\t\t            Autobuses: 54, 113, 27 y C1\n");
				printf("_____________________________________________________________________________________________________________________________\n\n");
				printf("\t\tHorarios: De Lunes a Viernes de 9:00 a 21:00 h\n");
				printf("\t\t          Todos los dias los servicios de prestamo y acceso a internet finalizaran 15 minutos antes del cierre.\n");
				
				getchar();
				printf("\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
				printf("Pulse enter para continuar\n");
				getchar();
				system("cls");
				break;
			case 'C':
				printf("Fin del programa\n");
				break;
		}
	} while(opcion2!='C');
	system("cls");
}

int usuarios(char opcion){
	FILE *fichero;
	struct Usuario usuario[MAX_USUSUARIOS];
	int i, j;
	int numUsuarios=0;
	int nombreIgual=0;
	
	fichero = fopen("usuario.txt", "r");
	if (fichero == NULL) {
		printf("No se ha podido abrir el fichero\n");
		return -1; 
	}
	i=0;
	while (fscanf(fichero, "%d %s %s", &usuario[i].identificador, usuario[i].nombre, usuario[i].password)!=EOF) {
		numUsuarios++;
		i++;
	}
	fclose(fichero);
	
	if (opcion=='A'){
		printf("Nombre usuario:\n");
		usuario[i].identificador=i+1;
		fflush(stdin);
		gets(usuario[i].nombre);
		printf("Contrasena usuario:\n");
		fflush(stdin);
		gets(usuario[i].password);
		system("cls");
		for(j=0; j<i; j++){
			for(i=0; i<numUsuarios; i++){
				if(strcmp(usuario[i].nombre, usuario[numUsuarios].nombre)==0||strlen(usuario[numUsuarios].nombre)<4||strlen(usuario[numUsuarios].nombre)>16||
				strlen(usuario[numUsuarios].password)<4||strlen(usuario[numUsuarios].password)>16){
					if(strcmp(usuario[i].nombre, usuario[numUsuarios].nombre)==0){
						printf("Este usuario ya existe, utilice otro:\n\n");
					}
					else if(strlen(usuario[numUsuarios].nombre)<4||strlen(usuario[numUsuarios].nombre)>16||strlen(usuario[numUsuarios].password)<4||
					strlen(usuario[numUsuarios].password)>16){
						printf("Error; el usuario y contrasena tienen que tener una longitud mayor de 4 caracteres y menor de 16, intentelo de nuevo:\n\n");
					}
					printf("Nombre usuario:\n");
					fflush(stdin);
					gets(usuario[numUsuarios].nombre);
					printf("Contrasena usuario:\n");
					fflush(stdin);
					gets(usuario[numUsuarios].password);
					system("cls");
				}
			}
		}
		i++;
		
		fichero = fopen("usuario.txt", "w");

		if (fichero == NULL) {
			printf("No se ha podido abrir el fichero\n");
			return -1;
		}
			
		
		for(j=0;j<i;j++){
			fprintf(fichero,"%d\t%s\t%s\n", usuario[j].identificador, usuario[j].nombre, usuario[j].password);
		}
			
		fclose(fichero);
	}
	else if(opcion=='B'){
		do{
			printf("Nombre usuario:\n");
			usuario[i].identificador=i+1;
			fflush(stdin);
			gets(usuario[i].nombre);
			printf("Contrasena usuario:\n");
			fflush(stdin);
			gets(usuario[i].password);
			system("cls");
			for(i=0; i<numUsuarios; i++){
				if(strcmp(usuario[i].password, usuario[numUsuarios].password)==0&&strcmp(usuario[i].nombre, usuario[numUsuarios].nombre)==0){
					nombreIgual++;
				}
				system("cls");
			}
			if(nombreIgual==0){
				printf("Usuario o contrasena incorrecta\n\n");
			}
		}while(nombreIgual!=1);
		i++;
	}
}

int libros(char nombre[], struct Libro tipoLibro[]){
	FILE *fichero2;
	char ficheroLibro[5];
	int i;
	int opcion4;
	
	strcpy(ficheroLibro, nombre);
	strcat(ficheroLibro, ".txt");
	
	fichero2 = fopen(ficheroLibro, "r");
	if(fichero2==NULL){
		printf("No se ha podido abrir el fichero\n");
		return -1;
	}
	
	i=1;
	while(fscanf(fichero2, "%s\t%s", tipoLibro[i].nombreLibro, tipoLibro[i].nombreAutor)!=EOF){//->
		printf("\t%d\t%s\t%s\n", i, tipoLibro[i].nombreLibro, tipoLibro[i].nombreAutor);
		i++;
	}
	fclose(fichero2);
	printf("\n\t0-Volver a las secciones de libros\n\n");
	
	do{
		printf("Escoge un libro\n");
		scanf("%d", &opcion4);
	}while(opcion4<0||opcion4>15);
	system("cls");
	
	if(opcion4!=0){
		printf("\n\tSu eleccion ha sido:\n\n"); 
		printf("\t\t%s de %s.\n\n", tipoLibro[opcion4].nombreLibro, tipoLibro[opcion4].nombreAutor);	
		printf("\tDirigete a recepcion para recoger tu libro. \n\tDevolucion maxima de un mes.\n");
		printf("\tGracias por usar el sistema.\n\n");
		getchar();
		printf("_ _ _\n");
		printf("Pulse enter para continuar\n");
		getchar();
	}
	system("cls");
}

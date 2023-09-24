#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void menu();
void comprobarArchivo(char stringDir[]);
int cantidadDatos(char stringDir[]);
float obtenerDatos(char *line);
void inicializarArreglo(float a[]);
void conversionX(float a[]);
void modPobEc(float a[], float b[]);
void imprimirDatos(float a[], float b[]);

FILE *entrada;
FILE *salida;                                                                                                                    

int c=0, m=0, i = 0;

int main(int argc, char *argv[]){
	
	char line [50];
	printf("%s",argv[1]);
	comprobarArchivo(argv[1]);
	system("cls");
	printf("Bienvenidx usuarix, este es un sistema de an%clisis de estad%csticas de empleo en M%cxico en su versi%cn 1.0.0.\nFavor de leer el manual adjunto para el correcto manejo del programa\n", 160, 161, 130,162);
	system("pause");
	system("cls");
	menu();
	m = cantidadDatos(argv[1]);
	float valoresX[m];
	float valoresY[m];
	inicializarArreglo(valoresX);
	inicializarArreglo(valoresY);
	
	if(c == 1){
		entrada = fopen(argv[1], "r");
		for (i=1;i<=m;i++){
			fgets(line,sizeof(line),entrada);
			line[strlen(line)] = '\0'; 
			valoresX[i] = obtenerDatos(line);
		}
		conversionX(valoresX);
		modPobEc(valoresY,valoresX);
		imprimirDatos(valoresX,valoresY);
		fclose(entrada);
	}	
	return 0;
}

void menu(){
	do{
		system("cls");
		printf("Men%c: \n",163);
		printf("Elija la opci%cn deseada:\n1: Iniciar procesamiento de datos \n2: Saber m%cs sobre el programa \n\n",162,160);
		scanf("%i", &c);
		if(c == 2){
			system("cls");
			printf("Chava: Hola, soy Chava, y ayud%c a Fer, Gus, Mitzy y Emilio a identificar errores en este programa, un placer y gracias por usar nuestro programa.\n",130);
			printf("\nChava: Ahora, perm%cteme contarte c%cmo funciona este programa...\n",161,162);
			printf("Funciona, leyendo los datos de tu archivo csv, los cuales deben ser datos del INEGI(A%cos espec%cficamente) sobre la poblaci%cn econ%cmicamente activa en M%cxico.\n",164,161,162,162,130);
			printf("}nPosteriormente los procesa usando una f%crmula obtenida mediante una regresi%cn polinomica de grado 2, la cual procesa desde 1983 hasta n a%co soportado por el compilador.\n",162,162,164);
			printf("Para as%c tener una predicci%cn de las personas econ%cmicamente activas y puede complementarlo con otras estad%csticas como poblaci%cn total o empleo/desempleo para mejorar su interpretaci%cn y extrapolaci%cn de los datos\n",161,162,162,161,162,162,162);
			printf("\nPara terminar, no se descarta agregar otras variables o estad%csticas a predecir en alguna futura versi%cn del programa.\nGracias por su atenci%cn y espero sea de su agrado\n",161,162,162);
			system("pause");
			c = 1;
		}
	}while(c<1 || c>=2);
}
void comprobarArchivo(char stringDir[]){
	
	entrada = fopen(stringDir, "r");
	if(entrada==NULL){
		printf("\nNo se pudo leer el archivo, finalizando programa... \n");
		system("pause");
		exit(1);
	}
	else{
		fclose(entrada);
	}
}

int cantidadDatos(char stringDir[]){
	entrada = fopen(stringDir, "r");
	int n = 1;
	char lec = fgetc(entrada);
	while(!feof(entrada)){
		if(lec == '\n'){
			n++; 
		}
		lec = fgetc(entrada);
	}
	fclose(entrada);
	if(n<=2 || n>100){
		printf("Cantidad de datos inv%clida, finalizando programa... \n");
		exit(1);
	}
	return n;
}

float obtenerDatos(char *line){
	char num[50];
	float datoX = 0;
	int j=0, k=0;
	while(line[k]!='\0'){
		num[j] = line[k];
		k++;
		j++;
	}
	datoX = atoi(num);
	return datoX;
}
void inicializarArreglo(float a[]){
    for(i=1; i<=m; i++){
        a[i]=0;
    }
}

void conversionX(float a[]){
	for(i=1; i<=m; i++){
		if(a[i] < 1983){
			printf("Dato en X incorrecto, finalizando programa... \n");
			exit(1);
		}
		a[i] = a[i] - 1983;
	}
}

void modPobEc(float a[], float b[]){
	int adv = 1;
	for(i=1; i<=m; i++){
		if(b[i]>=22 && b[i]<=39 && adv == 1){
			printf("Algunos datos ingresados, son parte de la estad%cstica del INEGI con la que se plante%c el modelo matem%ctico, por lo que los datos son una aproximaci%cn.\n",161, 162, 160,162);
			printf("Si desea ver los datos originales, puede encontrarlos en: https://www.inegi.org.mx/temas/empleo/ \n");
			system("pause");
			adv++;
		}
		a[i] = -(9416.378*(pow(b[i],2))) + (1367075.374)*(b[i]) + 18571531.72;
	}
}

void imprimirDatos(float a[], float b[]){
	system("cls");
	salida = fopen("datosProcesados.csv","w");
	printf("A%co | Poblaci%cn econ%cmicamente activa \n\n", 164,162,162);
	fprintf(salida,"A%co | Poblaci%cn econ%cmicamente activa \n\n", 164,162,162);
	for(i=1;i<=m;i++){
		fprintf(salida,"%.3f  %.3f\n", a[i]+1983, b[i]);
		printf("%.0f  %.3f\n",a[i]+1983, b[i]);
	}
	fclose(salida);
}



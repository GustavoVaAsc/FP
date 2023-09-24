#include<stdio.h>

//Declaraciones globales

//Variables globales
int m=0, n=0, i=0, j=0;
//Fin variables globales
void Dimensiones();
void Inicializar();
void leerMatriz();
void imprimirMatrices();

int main (){
	
	//InicioAlgoritmo
	Dimensiones();
	int mA[m][n];
	Inicializar();
	leerMatriz();
	imprimirMatrices();

    //FinAlgoritmo
	return 0;	
}

void Dimensiones(){
	do{
		printf("Escriba el n%cmero de filas: ",163);
		scanf("%i",&m);
		printf("Escriba el n%cmero de columnas: ",163);
		scanf("%i",&n);
	}
	while(m<=1 || n<=1);
}
void Inicializar(){
	int mA[m][n];
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
 			mA[i][j]=0;
        }
    }
}
void leerMatriz(){
	int mA[m][n];
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
 			printf("Escriba el n%cmero [%i][%i]: ",163,i,j);
			scanf("%i",&mA[i][j]);
        }
    }
}
void imprimirMatrices(){
	int mA[m][n];
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
 			printf("%i\t ",mA[i][j]);
        }
        printf("\n");
    }
	printf("\n");
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
 			printf("%i\t ",mA[j][i]);
        }
        printf("\n");
    }
}


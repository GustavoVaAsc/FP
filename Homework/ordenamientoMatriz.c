#include <stdio.h>

//Inicio declaraciones globales
void iniMat(int m[4][3]);
void datosM(int m[4][3]);
void fila();
void sort(int m[4][3]);
void imprimirM(int m[4][3]);
//Variables globales
int f=0, i=0, j=0;
//Fin declaraciones globales

int main (){
	//Dec. variables locales
	int mA[4][3];
	//Fin dec. variables locales
	
	//Inicio Algoritmo
	iniMat(mA);
	datosM(mA);
	fila();
	sort(mA);
	imprimirM(mA);
	
	return 0;
}

void iniMat(int m[4][3]){
	
	for(i=0;i<4;i++){
        for(j=0;j<3;j++){
 			m[i][j]=0;
        }
    }
}

void datosM(int m[4][3]){
	
	for(i=0;i<4;i++){
        for(j=0;j<3;j++){
 			printf("Escriba el n%cmero [%i][%i]: ",163,i,j);
			scanf("%i",&m[i][j]);
        }
    }
}

void fila(){
	do{
		printf("Ingrese la fila a ordenar: ");
		scanf("%i",&f);
	}while(f<0 || f>4);
}

void sort(int m[4][3]){
	int min=0, piv = 0;
	for(i=0;i<3;i++){
		min = i;
        for(j=i+1;j<3;j++){
        	if(m[f][j] < m[f][min]){
 				min = j;
			}
        }
        piv = m[f][i];
        m[f][i] = m[f][min];
        m[f][min] = piv;
    }
}

void imprimirM(int m[4][3]){
	for(i=0;i<3;i++){
 		printf("%i \t", m[f][i]);
    }	
}

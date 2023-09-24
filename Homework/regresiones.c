#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void menu();
void inicializarArreglo(float a[]);
void recolectarDatos(float a[]);
float sumatoriaA(float a[]);
void rLineal();

int i=0, j=0, n=0, c=0;

int main(){
    menu();
    rLineal();
    return 0;
}

void menu(){
    do{
        printf("Ingrese el tipo de regresi%cn que le gusatr%ca realizar ",162,161);
        scanf("%i", &c);
    }while(c<1 || c>4);
    do{
        printf("Ingrese la cantidad de datos a recibir: ");
        scanf("%i", &n);
    }while(n<=1);
}

void inicializarArreglo(float a[]){
    for(i=1; i<=n; i++){
        a[i]=0;
    }
}

void recolectarDatos(float a[]){
    for(i=1; i<=n; i++){
        printf("Ingrese el valor [%i]: ", i);
        scanf("%f", &a[i]);
    }
}

float sumatoriaA(float a[]){
    float sum=0;
    for(i=1; i<=n; i++){
        sum = sum + a[i];
    }
    return sum;
}

void rLineal(){
    float sumX=0, sumY=0, sumXY=0, sumX2=0, sumY2, m=0, b=0, r=0;
    float vX[n];
    float vY[n];
    float vXY[n];
    float vX2[n];
    float vY2[n];

    inicializarArreglo(vX);
    inicializarArreglo(vY);
    inicializarArreglo(vXY);
    inicializarArreglo(vX2);
    inicializarArreglo(vY2);
    
    printf("Ingrese los datos para las abscisas: ");
    system("pause");
    recolectarDatos(vX);
    printf("Ingrese los datos para las ordenadas: ");
    system("pause");
    recolectarDatos(vY);

    for(i=1; i<=n; i++){
        vXY[i]= vX[i]*vY[i];
    }
    for(i=1; i<=n; i++){
        vX2[i]= pow(vX[i],2);
    }
    for(i=1; i<=n; i++){
        vY2[i]= pow(vY[i],2);
    }
    sumX = sumatoriaA(vX);
    sumY = sumatoriaA(vY);
    sumXY = sumatoriaA(vXY);
    sumX2 = sumatoriaA(vX2);
    sumY2 = sumatoriaA(vY2);

    m = (sumXY - ((sumX*sumY)/n)) / (sumX2 - ((pow(sumX,2))/n));
    b = (sumY/n)-m*(sumX/n);
    r = (n*(sumXY-(sumX*sumY))) / (sqrt((n*(sumX2-(pow(sumX,2))))*(n*(sumY2-(pow(sumY,2))))));

    printf("El modelo matem%ctico est%c dado por: \n",160,160);
    printf("m = %.4f \n",m);
    printf("b = %.4f \n",b);
    printf("r = %.4f \n",r);
    printf("Siendo m: Pendiente, b: Ordenada al origen, r: Coeficiente de correlaci%cn",162);
}

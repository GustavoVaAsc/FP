#include <stdio.h>
#include <string.h>

int main(){
	FILE *ficheroOg;
	FILE *ficheroEn;
	char frase[50];
	int i=0, j=0;
	ficheroOg = fopen("mensajesincifrar.txt", "wt");
	printf(" PROGRAMA para ESCRIBIR y almacenar FRASES.\n" "Cuando quiera salir, simplemente pulse \"Intro\".\n\n");
	
    if (i == 0){
        puts("\nEscriba una FRASE:\n(o pulse \"Intro\"). \n");
    }
    else{
        puts("\nEscriba otra FRASE:\n(o pulse \"Intro\"). \n");
    }
    gets(frase);
    fputs(frase, ficheroOg);
    
	fclose(ficheroOg);
	
	ficheroOg = fopen("mensajesincifrar.txt", "rt");
	ficheroEn = fopen("mensajecifrado.txt", "wt");
	
	fgets(frase, 50, ficheroOg);
	for(i=0;i<50;i++){
		if(frase[i]!='\0'){
			frase[i]= frase[i]+3;
		}
	}
	puts("\nEl nuevo mensaje es:\n");
	fputs(frase, ficheroEn);
	puts(frase);
	fclose(ficheroOg);
	fclose(ficheroEn);	
	return 0;
}

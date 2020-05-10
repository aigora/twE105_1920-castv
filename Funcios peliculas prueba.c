#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{//Estructura tiempo
    char hora[3], min[3];
}tiempo;


typedef struct{//Estructura película
	char titulo[40];
	tiempo t;
	char tematica[15];
	char year[5];
}pelicula;


int abrepeliculas(pelicula p[]){


    FILE *pf;
	int e,i, nLineas=1;
	char x,Ruta; 
	
	
	    pf=fopen("peliculas/peliculas.txt","r");
	    if (pf==NULL){
         printf ("Error abriendo el fichero");
        return -1;
         }
    else{ 
         while (fscanf(pf, "%c", &x) != EOF){
         if (x == '\n'){
		 
         ++nLineas;}
       }
        fclose(pf);
         pf = fopen("peliculas/peliculas.txt","r");
    for(i=0;i<nLineas;i++){
      fscanf(pf, "%[^;];%[^:]:%[^;];%[^:]:%3[^\n]",// Hay que limitar el número de caracteres que se lee con [^\n]
         p[e].titulo,
         p[e].t.hora,
         p[e].t.min,
         p[e].tematica,
         p[e].year);
    }
    fclose(pf); 
	return nLineas;           
  }
  printf("%c %c %c %c %c \n",p[e].titulo,
         p[e].t.hora,
         p[e].t.min,
         p[e].tematica,
         p[e].year);
}

int main(){
	
   abrepeliculas();
    
  return 0;	
}

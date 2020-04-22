#include <stdio.h>
#include <string.h>

typedef struct{
    int hora, min;
}time;

 
typedef struct{
    
    time ti, tf;
    char titulo[60];
    char descripcion[300];
}canal;

 
typedef struct{
    canal c1[30], c2[30], c3[30], c4[30], c5[30];
}dia;

void meteprograma(const char fichero[],dia c)
{
	 FILE *pf;
	 int cont=0,i;
	 char x;
			pf = fopen(fichero,"r");
			if(fscanf(pf,"%s",&x)=='\n')
				cont++;
				cont--;
			for(i=0;i<cont;i++){
			fscanf(pf,"%[^;];%[^:]:[^;];[^:]:[^;];%[^\n] \n",c.c1[i].titulo,c.c1[i].ti.hora,c.c1[i].ti.min,c.c1[i].tf.hora,c.c1[i].tf.min,c.c1[i].descripcion); 
			}
			fclose(pf);
}


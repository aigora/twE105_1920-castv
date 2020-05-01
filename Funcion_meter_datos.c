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


 

int meteprograma(dia c){
     FILE *pf;
     int i;
     char x;
            pf = fopen("domingo.lasexta.txt","r");
            if (pf==NULL){
                            printf ("Error abriendo el fichero");
                            return -1;
                            }
            else{  
			     printf("asdf") ; 
                for(i=0;i<15;i++){
                	printf("eeee\n");
                fscanf(pf,"%[^;];%[^:]:[^;];[^:]:[^;];%[^\n] \n",c.c1[i].titulo,c.c1[i].ti.hora,c.c1[i].ti.min,c.c1[i].tf.hora,c.c1[i].tf.min,c.c1[i].descripcion);
			    
                }
                fclose(pf);
                return 0;
            }
}

 

int main(){
    FILE *pf;
    dia domingo;
    int i,x=0;
     meteprograma(domingo);
    for(x=0;x<15;x++){
    	printf("%s,%d,%s,%s,%s,%s\n",domingo.c1[x].titulo,domingo.c1[x].ti.hora,domingo.c1[x].ti.min,domingo.c1[x].tf.hora,domingo.c1[x].tf.min,domingo.c1[x].descripcion);
	}
            
     return 0;
    
}

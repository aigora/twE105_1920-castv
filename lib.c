#include "lib.h"

typedef struct{//Estrcura serie
	char capitulo[12];
	char titulo[50];
	char descripcion[500];
}serie;

void EscribeNombre(){//Título 
    printf("        CCCCCCCCCCCCC                               TTTTTTTTTTTTTTTTTTTTTTT   \n");
    printf("     CCC::::::::::::C                               T:::::::::::::::::::::T \n");
    printf("   CC:::::::::::::::C                               T:::::::::::::::::::::T\n");
    printf("  C:::::CCCCCCCC::::C                               T:::::TT:::::::TT:::::T\n");
    printf(" C:::::C       CCCCCC  aaaaaaaaaaaaa      ssssssssssTTTTTT  T:::::T  TTTTTTvvvvvvv           vvvvvvv\n");
    printf("C:::::C                a::::::::::::a   ss::::::::::s       T:::::T         v:::::v         v:::::v\n");
    printf("C:::::C                aaaaaaaaa:::::ass:::::::::::::s      T:::::T          v:::::v       v:::::v\n");
    printf("C:::::C                         a::::as::::::ssss:::::s     T:::::T           v:::::v     v:::::v\n");
    printf("C:::::C                  aaaaaaa:::::a s:::::s  ssssss      T:::::T            v:::::v   v:::::v\n");
    printf("C:::::C                aa::::::::::::a   s::::::s           T:::::T             v:::::v v:::::v\n");
    printf("C:::::C               a::::aaaa::::::a      s::::::s        T:::::T              v:::::v:::::v\n");
    printf(" C:::::C       CCCCCCa::::a    a:::::assssss   s:::::s      T:::::T               v:::::::::v\n");
    printf("  C:::::CCCCCCCC::::Ca::::a    a:::::as:::::ssss::::::s   TT:::::::TT              v:::::::v\n");
    printf("   CC:::::::::::::::Ca:::::aaaa::::::as::::::::::::::s    T:::::::::T               v:::::v\n");
    printf("     CCC::::::::::::C a::::::::::aa:::as:::::::::::ss     T:::::::::T                v:::v \n");
    printf("        CCCCCCCCCCCCC  aaaaaaaaaa  aaaa sssssssssss       TTTTTTTTTTT                 vvv\n");
	printf("\n\n\n");
}

int abreSerie(serie s[],const char *RutaSerie){//Funcion que guarda la serie y la muestra por pantalla
	FILE *pf;
	int a,nLineas=1;
	char x;
	
	 pf=fopen(RutaSerie,"r");
	    if (pf==NULL){
         printf ("Error abriendo el fichero");
        return -1;}
        
    else{
    	  while (fscanf(pf, "%c", &x) != EOF){
         if (x == '\n'){
		 
         ++nLineas;}
     	 }
   		 fclose(pf);
   		 pf=fopen(RutaSerie,"r");
   		 printf("\tALERTAS DE SPOILERS!!!!!!!\n\n");
	   		 for(a=0;a<2*nLineas;a++){
	      		fscanf(pf, "%[^;];%[^;];%500[^\n]\n", s[a].capitulo,s[a].titulo,s[a].descripcion);
	     		printf("\t%s: %s.\n\t%s\n\n",s[a].capitulo,s[a].titulo,s[a].descripcion);
	    		a++;
		 }
	    fclose(pf); 
		return nLineas; 	
		}                 
}

	



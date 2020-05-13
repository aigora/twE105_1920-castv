#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct{//Estructura tiempo
    char hora[3], min[3];
}tiempo;

typedef struct{//Estructura canal
    tiempo ti, tf;
    char titulo[60];
    char descripcion[300];
}canal;


typedef struct{//Estructura dia
    canal c[30];
}dia;





int MetePrograma(char *Ruta, const char *NombreCanal, dia d[], int e){//Función para traspasar datos de fichero a variables
  FILE *pf;
  int i,nLineas=1;
  char x, NombreRuta[50];
  
  strcpy(NombreRuta,Ruta);
  strcat(NombreRuta,NombreCanal);//Creo el nombre de la ruta
  
  pf = fopen(NombreRuta,"r");
  if (pf==NULL){
    printf ("Error abriendo el fichero");
    return -1;
  }
  else{ 
    while (fscanf(pf, "%c", &x) != EOF){
      if (x == '\n')
    ++nLineas;
  }
    fclose(pf);

    pf = fopen(NombreRuta,"r");
    for(i=0;i<nLineas;i++){
      fscanf(pf, "%[^;];%[^:]:%[^;];%[^:]:%3[^\n]\n",// Hay que limitar el número de caracteres que se lee con [^\n]
         d[e].c[i].titulo,
         d[e].c[i].ti.hora,
         d[e].c[i].ti.min,
         d[e].c[i].tf.hora,
         d[e].c[i].tf.min);
    }
    fclose(pf); 
	return nLineas;           
  }
                
}


int MetePrograma2(char *Ruta, const char *NombreCanal, dia d[], int e){//Provisional hasta que cambiemos los ficheros
  FILE *pf;
  int i,nLineas=1;
  char x, NombreRuta[35];
  
  strcpy(NombreRuta,Ruta);
  strcat(NombreRuta,NombreCanal);//Creo el nombre de la ruta
  
  pf = fopen(NombreRuta,"r");
  if (pf==NULL){
    printf ("Error abriendo el fichero");
    return -1;
  }
  else{ 
    while (fscanf(pf, "%c", &x) != EOF){
      if (x == '\n')
    ++nLineas;
  }
    fclose(pf);

    pf = fopen(NombreRuta,"r");
    for(i=0;i<nLineas;i++){
      fscanf(pf, "%[^;];%[^:]:%[^;];%[^:]:%[^;];%300[^\n]\n",
         d[e].c[i].titulo,
         d[e].c[i].ti.hora,
         d[e].c[i].ti.min,
         d[e].c[i].tf.hora,
         d[e].c[i].tf.min,
		 d[e].c[i].descripcion);
    }
    fclose(pf); 
	return nLineas;           
  }
                
}


void ProgramacionCompleta(const char *NombreDia, dia c[], int Lineas[]){//Funcion para meter los datos de un dia completo
	char day[20],Ruta[50]={"programacion/"};
	int i=0,x;
	
	strcpy(day,NombreDia); //Realizamos concatenaciones para crear el nombre del fichero y carpeta correspondiente
	strcat(day,"/");
	strcat(day,NombreDia);
	strcat(Ruta,day);
	
		Lineas[i]=MetePrograma(Ruta,".canal1.txt",c,i);
		i++;
	    Lineas[i]=MetePrograma(Ruta,".neox.txt",c,i);
        i++;
		Lineas[i]=MetePrograma(Ruta,".mega.txt",c,i);
        i++;
        Lineas[i]=MetePrograma2(Ruta,".dmax.txt",c,i);
        i++;
        Lineas[i]=MetePrograma(Ruta,".boing.txt",c,i);
        i++;
        Lineas[i]=MetePrograma2(Ruta,".lasexta.txt",c,i);
       
}

int main()
{
	  int x=0,z=0,op1=0, op2=0, op3=0, op4=0, op5=0, op6=0,op7=0,op8=0,op9=0,//Operadores que utilizamos en bucles
	  	  ContReg=0, i, x1, x2, x3,//Se utilizan en condicionales para el registro
	  	  ContBanco=0,//Se utilizan en condicionales para el registro de la cuenta bancaria
		  DiaActual=0,//Almacena numericamente el dia del sistema 
		  NL[6], NM[6], NX[6], NJ[6], NV[6], NS[6], ND[6],//Numero de programas que tiene cada canal en cada dia
		  NPC, NPP, NPG,//Almacenamos el numero de películas de cada tipo
		  NumeroPelicula;
		  
		  dia L[6], M[6], X[6], J[6], V[6], S[6], D[6];
		  
		  
	    ProgramacionCompleta("lunes",L,NL);//Introducimos el dia para guaradar los datos en la varibale correspondiente al dia 
                                           //y ya de paso guardar sus lineas para posteriores interacciones
       ProgramacionCompleta("martes",M,NM);
        ProgramacionCompleta("miercoles",X,NX);
        ProgramacionCompleta("jueves",J,NJ);
        ProgramacionCompleta("viernes",V,NV);
        ProgramacionCompleta("sabado",S,NS);
        ProgramacionCompleta("domingo",D,ND);
         for(z=0;z<6;z++){
         		
        		
			if(z==0){
			
        		printf("\tLa 1\n");
        	}
        	else if(z==1){
			
		
				    printf("\tNeox\n");
				}
				else if(z==2){
				
        			printf("\tMega\n");
        		}
        		else if(z==3){
				
        		
				    printf("\tDiMax\n");
				}
				else if(z==4){
				
				
				    printf("\tBoing\n");
		}else if(z==5){
		
				    printf("\tLa sexta\n"); 
				}
			
			
    
		 
		 for(x=0;x<NL[z];x++)
        {
        
        	printf(" %s %s:%s-%s:%s  \n ",L[z].c[x].titulo,
         L[z].c[x].ti.hora,
         L[z].c[x].ti.min,
         L[z].c[x].tf.hora,
         L[z].c[x].tf.min);
         
		}
		printf("\n \n");
		
		
	}
		return 0;
}






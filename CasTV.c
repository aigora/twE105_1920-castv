#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct{//Estructura auxiliar para la cuenta bancaria
	char cuenta;
	char pass;
}CuentaBanco;

typedef struct{//Estructura de registro de usuario
	char nombre[15];
	char password[15];
	char DNI[10];
	CuentaBanco x;
}usuario;

typedef struct{
    int hora, min;
}tiempo;
 
typedef struct{
    tiempo ti, tf;
    char titulo[60];
    char descripcion[300];
}canal;

typedef struct{
    canal c1[30], c2[30], c3[30], c4[30], c5[30];
}dia;

int ingreso(usuario nombre){//Función ingreso
     FILE *pf,*cont;
	 int i,ContReg,x=1,intentos=0,y;
     usuario registro[5],password; //Esto depende del numero maximo de registros que deseamos poner
     
	     cont = fopen("contador.txt", "r");
		 fscanf(cont,"%d",&ContReg); 
		 fclose(cont);
		 pf = fopen("registro.txt", "r"); 
			for (i=0;i<ContReg;i++)
	    	 	fscanf(pf, "%[^;];%[^;];%[^\n]\n", registro[i].nombre, registro[i].password,registro[i].DNI);
	     fclose(pf);
	     i=0;
			while (x!=0){
				x=strcmp(nombre.nombre,registro[i].nombre);
				i++;
				if(i>5){
					x=0;
					printf("Lo sentimos vuelva a escribir el nombre, no hay ninguna coincidencia. \n");  
					return 1;
					}
				else if (x==0){
					i--;
					printf("Oportunidades para introducir la contrasena: 3 \n");
					do {
				        if (intentos==3)
				        {
				        	printf("Las contrasenas no coinciden. Pulse 1 si desea recuperarla o cualquier tecla para acabar el programa. \n");
				        	scanf("%d",&y);
				        	if (y==1){
				        		printf("Introduzca su DNI para verificar:");
				        		scanf("%s",&password.DNI);
				        		if(strcmp(password.DNI,registro[i].DNI)!=0){
				        			printf("Lo sentimos no podemos facilitarle la contrasena.");
				        			exit(1);
								}
				        		else{
				        			printf("La contrasena es: %s \n",registro[i].password);
								}				        		
							}
							else exit(1);
				        }
				        if (intentos>3)
				        	printf("Le recuerdo que se contrasena es %s \n",registro[i].password);
				        printf("Introduzca password:");
				        scanf("%s",password.password);
				        strcpy(nombre.password,password.password);
				   	    intentos++;
  					} while (strcmp(nombre.password,registro[i].password)!=0);			
				printf("Enhorabuena ha pasado la prueba de registro, puede disfrutar de CasTv \n");
				return 0;	
				}			
			}
}  

int main (){//Programa principal
  EscribeNombre();
  //VARIABLES QUE VAMOS A UTILIZAR POSTERIORMENTE
	  tiempo HoraActual;//Almacena la hora del sistema
	  int op1=0,op2=0,op3=0,op4=0,//Operadores que utilizamos en bucles
	  	  ContReg=0,i,x1,x2,//Se utilizan en condicionales para el registro
		  DiaActual=0;//Almacena numericamente el dia del sistema 
	  char tecla1[10]="salir",tecla2[10];//Bucle global del programa
	  FILE *pf,*cont;//Punteros que apuntan a los ficheros donde guardamos los datos de los registrados
	  usuario registro,CompReg[5];//Necesarios para registrarse
  
  do{
  printf("\tDispone de una cuenta CasTV? \n");
  printf("\tPulse 1 si ya esta registrado: \n");
  printf("\tPulse 2 si no tiene cuenta: \n");
  scanf("%d",&op1);
  if((op1!=1) && (op1!=2))
  	printf("No es una opcion valida. pruebe de nuevo. \n\n");
  if(op1==1){
	  printf("Verifique que esta registrado, inserte su nombre de usuario: \n");
		  do{
			  scanf("%s",registro.nombre);
			  op4=ingreso(registro);
		  }while(op4);
	  } 
 }while((op1!=1) && (op1!=2));

do{
	  time_t t = time(NULL);//Se obtiene la hora del sistema por cada repeticion del bucle.
 	  struct tm tiempoLocal = *localtime(&t);
 switch(op1){//El usuario ya está registrado
 	case 1:
	 	//Menú, si qiuere salir deberá escribir "salir"
	 	 printf("  Menu \n");
	 	 printf("  Guia televisiva: 1 \n");
		 printf("  Catalogo: 2 \n");
	     printf("  Recomendacion: 3 \n");
		 scanf("%d",&op2);
		
		 switch(op2){
			    case 1:
						   DiaActual= tiempoLocal.tm_wday;
						   HoraActual.hora= tiempoLocal.tm_hour;
						   HoraActual.min= tiempoLocal.tm_min;
					//El usuario elige un apartado del menú
			    	//Muestra la emision en directo de los canales TDT
			    	//Aqui iria un menu para elegir el programa
			      break;
			    case 2:
			    	printf("Estas son las peliculas por tematicas disponibles: \n");
			    	//Aqui metemos abrimos ficheros y esas cosas para printear
			    	printf("Desea buscar alguna pelicula en concreto? Pulse 1 \n");
			    	printf("Desea ampliar su catalogo? Pulse 2 \n");
			    	//Muestra el catálogo de películas entero con posibilidad de eleccion autónoma
			    	//Estarán sorteadas por temáticas
			      break;
			    case 3:
			        //Aqui se relizará un filtrado de de gustos para mejor la busqueda y sugerencia
	        	break;
			    }
			    printf("Desea salir del programa? teclee salir \n");
			    scanf("%s",tecla2);
		break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case 2://El usuario no está registrado
		printf("Pulse 1 si quiere registrarse o 2 si quiere ver el catalogo: ");
		scanf("%d",&op3);	
		switch(op3){
			case 1://Registro
				 pf = fopen("registro.txt", "r"); 
			  	 if (pf==NULL){
			                printf ("Error abriendo el fichero");
			                return -1;
							}
	   			 else{
		   			cont = fopen("contador.txt", "r");
		   			fscanf(cont,"%d",&ContReg);
		   			fclose(cont);
							for (i=0;i<ContReg;i++)
		    	 				fscanf(pf, "%[^;];%[^\n]\n", CompReg[i].nombre, CompReg[i].password);
	    	 		fclose(pf);
	    	
				    ContReg++;
						 if(ContReg>5){
						     ContReg=5;
						     printf("Lo sentimos se ha alcanzado el numero maximo de registros (%d). Solo puede ver el la guia televisiva.\n",ContReg);
						 }
						 else {
						 	 x2=1;
							 while(x2){
								 i=0;
								 printf("Ingrese nombre de usuario:");
				   				 scanf("%s",registro.nombre);
				    		 	 do{
									 x1=strcmp(registro.nombre,CompReg[i].nombre);
					  		 		 i++;
					  		 		 if(x1==0)
					  					 printf("No pueden existir dos usuarios con el mismo nombre, pruebe con otro \n");	 
					  		 			 if(i>5){
						  		 		 x1=0;
						  		 		 x2=0;
							 			 }
					  	 		}while(x1!=0);
							}	
						 	 printf("Ingrese clave: ");
				     		 scanf("%s",registro.password); 
				     		 printf("Introduzca su DNI para verificar su identidad en caso de extraviar su contrasena: ");
				   			 scanf("%s",registro.DNI);
							 pf = fopen("registro.txt", "a"); 
						  	 fprintf(pf, "%s;%s;%s\n",registro.nombre, registro.password, registro.DNI);
						  	 fclose(pf);
						  	 
						  	 printf("si desea continuar una vez registrado pulse 1, si no pulse cualquier valor para finalizar el programa \n");
						     scanf("%d",&op1);
							 if(op1!=1) strcpy(tecla2,tecla1);
						 }
		   			 	 cont = fopen("contador.txt", "w");
						 fprintf(cont, "%d",ContReg);
						 fclose(cont);
					}
			break;
			case 2://Guia televisiva
				printf("si esta registrado y quiere acceder a los servivios completos pulse 1, si no pulse cualquier valor para finalizar el programa \n");
				scanf("%d",&op1);
				if(op1!=1) strcpy(tecla2,tecla1);
				if(op1==1){
	 				printf("Verifique que esta registrado, inserte su nombre de usuario: \n");
		 			do{
			  			scanf("%s",registro.nombre);
			  			op4=ingreso(registro);
		  			}while(op4);
	 			} 
			break;
		}
	break;	
	}	
}while(strcmp(tecla1,tecla2));
return 0;
}

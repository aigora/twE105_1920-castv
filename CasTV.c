#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

typedef struct{//Estructura auxiliar para la cuenta bancaria
	char cuenta[20];
	char pass[5];
	int saldo;
}CuentaBanco;

typedef struct{//Estructura de registro de usuario
	char nombre[15];
	char password[15];
	char DNI[10];
	CuentaBanco x;
}usuario;

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

//dia[0]= Canal 1
//dia[1]= Neox
//dia[2]= Mega
//dia[3]= Discovery Max
//dia[4]= Boing
//dia[5]= La Sexta

typedef struct{//Estructura película
	char titulo[40];
	tiempo t;
	char tematica[15];
	char year[5];
}pelicula;

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
	int i=0;
	
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

int programaciondia(int a[], dia b[]){
     
	int x=0,z=0;
	 dia L[6], M[6], X[6], J[6], V[6], S[6], D[6];//Variables en las que se almacenarán los programas de cada día
	  
	  int op1=0, op2=0, op3=0, op4=0, op5=0, op6=0,op7=0,op8=0,//Operadores que utilizamos en bucles
	  	  ContReg=0, i, x1, x2, x3,//Se utilizan en condicionales para el registro
	  	  ContBanco=0,//Se utilizan en condicionales para el registro de la cuenta bancaria
		  DiaActual=0,//Almacena numericamente el dia del sistema 
		  NL[6], NM[6], NX[6], NJ[6], NV[6], NS[6], ND[6],//Numero de programas que tiene cada canal en cada dia
		  NPC, NPP, NPG;//Almacenamos el numero de películas de cada tipo
		  
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
	      	}
		    else if(z==5){
			 printf("\tLa sexta\n"); 
			}	
		 for(x=0;x<a[z];x++)
        {
        
        	printf(" %s %s:%s-%s:%s  \n ",b[z].c[x].titulo,
         b[z].c[x].ti.hora,
         b[z].c[x].ti.min,
         b[z].c[x].tf.hora,
         b[z].c[x].tf.min);
         
		}
		printf("\n \n");	
	}
	
}

int abrepeliculas(pelicula p[],const char *NombreRuta){//funcion que guarda las peliculas y las muestra por pantalla (solo el titulo)
    FILE *pf;
	int i, nLineas=1, e;
	char x; 
	
	
	    pf=fopen(NombreRuta,"r");
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
   		 
	    pf=fopen(NombreRuta,"r");
    	e = fscanf(pf, "%c", &x);
	    
	    if(e==-1){
	    	printf("No hemos encontrado ninguna compra todavia\n\n");
	    	fclose(pf);
	    	nLineas=0;
	    	return nLineas;
		}   
	    else {
	    	 fclose(pf);
	       	 pf = fopen(NombreRuta,"r");
	   		 for(i=0;i<nLineas;i++){
	      	 fscanf(pf, "%[^;];%[^:]:%[^;];%[^;];%5[^\n]\n", p[i].titulo,
	        	 p[i].t.hora,
	          	 p[i].t.min,
	    	     p[i].tematica,
		         p[i].year);
	     printf("%d-Titulo: %s\n\n",i+1,p[i].titulo);
	    	 }
	    fclose(pf); 
		return nLineas; 	
		}            
    }
}

void detallespeliculas(pelicula p[],int i){//Funcion que despliega los detalles de la pelicula
	int precio;
	precio=calculaprecio(p,i);
	printf("\n%d-Titulo: %s\t\t\tDuracion: %sh y %smin\tTematica: %s\tPrecio: %d\tAno de estreno: %s\n\n",i,p[i-1].titulo, 
		 p[i-1].t.hora,
         p[i-1].t.min,
         p[i-1].tematica,
         precio,
         p[i-1].year);
}

int calculaprecio(pelicula p[],int i){//Atribuye un precio por la temática de la película
	int precio,x;
		if(strcmp(p[i-1].tematica,"accion")==0) x=1; if(strcmp(p[i-1].tematica,"animacion")==0) x=2; if(strcmp(p[i-1].tematica,"aventuras")==0) x=1;
		if(strcmp(p[i-1].tematica,"historico")==0) x=1; if(strcmp(p[i-1].tematica,"terror")==0) x=1;
	
	switch(x){
		case 1: precio=20; break; case 2: precio=15; break; case 3: precio=12; break; case 4: precio=18; break; case 5: precio=13; break;
		case 6: precio=20; break; case 7: precio=20; break; case 8: precio=20; break; case 9: precio=20; break; case 10: precio=20; break;
	}
return precio;
}

int main (){//Programa principal

  EscribeNombre(); 
   
  
  //VARIABLES QUE VAMOS A UTILIZAR POSTERIORMENTE//
  
	  tiempo HoraActual;//Almacena la hora del sistema
	 
    
	  
	  pelicula Pcompradas[50], Ppago[50], Pgratis[150];//Las usaremos para almecenar las películas
	  
	  dia L[6], M[6], X[6], J[6], V[6], S[6], D[6];//Variables en las que se almacenarán los programas de cada día
	  
	  int op1=0, op2=0, op3=0, op4=0, op5=0, op6=0,op7=0,op8=0,//Operadores que utilizamos en bucles
	  	  ContReg=0, i, x1, x2, x3,//Se utilizan en condicionales para el registro
	  	  ContBanco=0,//Se utilizan en condicionales para el registro de la cuenta bancaria
		  DiaActual=0,//Almacena numericamente el dia del sistema 
		  NL[6], NM[6], NX[6], NJ[6], NV[6], NS[6], ND[6],//Numero de programas que tiene cada canal en cada dia
		  NPC, NPP, NPG,//Almacenamos el numero de películas de cada tipo
		  NumeroPelicula,x,y;
		  
	  char tecla1[10]="salir", tecla2[10],//Bucle global del programa
	  	   RutaSaldo[30]={"saldo/"},minuto[10],hora[10],//La utilizo para crear la ruta del fichero que alberga el saldo de cada usuario
		   RutaPeliculasCompradas[60]={"peliculas/peliculascompradas/"};//Lo utilizo para crear la ruta de las peliculas compradas por cada usuario
	
	  FILE *pf, *cont, *pfbanco, *contbanco, *saldobanco, *pelicomprada;//Punteros que apuntan a los ficheros donde guardamos los datos de los registrados
		   	        
	  usuario registro, CompReg[5] , CompRegBanco[5];//Necesarios para registrarse


        ProgramacionCompleta("lunes",L,NL);//Introducimos el dia para guaradar los datos en la varibale correspondiente al dia 
                                           //y ya de paso guardar sus lineas para posteriores interacciones
        ProgramacionCompleta("martes",M,NM);
        ProgramacionCompleta("miercoles",X,NX);
        ProgramacionCompleta("jueves",J,NJ);
        ProgramacionCompleta("viernes",V,NV);
        ProgramacionCompleta("sabado",S,NS);
        ProgramacionCompleta("domingo",D,ND);
        
       	    
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
			  scanf("%s",registro.nombre); //Pasaremos a usar el programa bajo el nombre de la persona registrada
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
		x=tiempoLocal.tm_hour;
		y=tiempoLocal.tm_min;
		sprintf(hora,"%d",x);
		sprintf(minuto,"%d",y);
		printf("%s:%s",hora,minuto);
		
			      printf("Si desea ver la programación completa pulse 1, si desea ver la de el dia actual pulse 2, si desea ver el programa de la hora actual pulse 3");
			    	     scanf("%d",&op7);
			    	     switch(op7){
			    	     	case 1:
			    	     	printf("lunes\n Martes\n Miercoles\n Jueves\n Viernes\n Sabado\n Domingo\n");
			    	     	printf("pulse 1 para lunes, 2 para martes, 3 para miercoles, 4 para jueves, 5 para viernes, 6 para sabado, 7 para domingo ");
			    	     	    scanf("%d",&op8);
			    	     	switch(op8){
			    	     	    printf("pulse 1 para lunes, 2 para martes, 3 para miercoles, 4 para jueves, 5 para viernes, 6 para sabado, 7 para domingo ");
			    	     	    scanf("%d",&op8);
			    	     	    case 1: 
			    	     	    programaciondia(NL,L);
			    	     	    break;
			    	     	    case 2:
			    	     	    programaciondia(NM,M);
			    	     	    break;
			    	     	    case 3:
			    	     	    programaciondia(NX,X);
			    	     	    break;
			    	     	    case 4:
			    	     	    programaciondia(NJ,J);
			    	     	    break;
			    	     	    case 5:
			    	     	    programaciondia(NV,V);
			    	     	    break;
			    	     	    case 6:
			    	     	    programaciondia(NS,S);
			    	     	    break;
			    	     	    case 7:
			    	     	    programaciondia(ND,D);	
			    	     	    break;
			    	     	    
			    	     	
			    	     	    	
							 }
						 }
					//El usuario elige un apartado del menú
			    	//Muestra la emision en directo de los canales TDT
			    	//Aqui iria un menu para elegir el programa
			      break;
			    case 2:
			    	printf("Pulse 1 para acceder al contenido gratuito(peliculas y serie). Pulse 2 si quiere aumentar el contenido: ");
			    	scanf("%d",&op5);
			    	printf("\n");
			    	switch(op5){
			    		case 1:
			    		   
			    	       printf("Estas son las peliculas por tematicas disponibles: \n");
			    	       //Aqui metemos abrimos ficheros y esas cosas para printear
			    	       printf("Desea buscar alguna pelicula en concreto? Pulse 1 \n");
			    	       printf("Desea ampliar su catalogo? Pulse 2 \n");
						   
			    	       //Muestra el catálogo de películas entero con posibilidad de eleccion autónoma
			    	       //Estarán sorteadas por temáticas
			    	       break;
			    	   case 2:
					       printf("Ha accedido a la adquisicion de contenido de pago. Le recordamos que debe disponer de una cuenta de banco. \n");
					       printf("Pasamos a verificar si su usuario ya dispone de ella... \n \n");
					       
					     	  	contbanco = fopen("contadorbanco.txt", "r");
		   						fscanf(contbanco,"%d",&ContBanco);
		   						fclose(contbanco);

								pfbanco = fopen("registrobanco.txt", "r");
								for (i=0;i<ContBanco;i++)
		    	 					fscanf(pfbanco,"%[^;];%[^;];%5[^\n]\n", CompRegBanco[i].nombre, CompRegBanco[i].x.cuenta, CompRegBanco[i].x.pass);
	    	 					fclose(pfbanco);
	    	 					
								i=0; 	
								do{
									 x3=strcmp(registro.nombre,CompRegBanco[i].nombre);
									 i++;
									 if(i>ContBanco)
									 x3=0;
									 
					  	 	    }while(x3!=0);

					  	 	    if (i<=ContBanco){
					  	 	    	printf("Hemos encontrado su cuenta bancaria en el registro. \n\n");
					  	 	    	
					  	 	    	strcat(RutaSaldo,registro.nombre);
							        strcat(RutaSaldo,".txt");
					  	 	    	saldobanco = fopen(RutaSaldo, "r");
							    	fscanf(saldobanco,"%d",&registro.x.saldo);
							    	fclose(saldobanco);
							    	printf("SALDO DE LA CUENTA: %d EUROS\n\n",registro.x.saldo);
					  	 	    	
					  	 	    	strcat(RutaPeliculasCompradas,registro.nombre);
							    	strcat(RutaPeliculasCompradas,".txt");
							    	pelicomprada = fopen(RutaPeliculasCompradas, "a");
							    	fclose(pelicomprada);
									printf("Estas son las peliculas anteriormente compradas: \n");
									
									NPC=abrepeliculas(Pcompradas,RutaPeliculasCompradas);
									/*printf("Desea ver las caracteristicas de alguna pelicula? Introduzca su numero: ");
									scanf("%d",&NumeroPelicula);
									detallespeliculas(Pcompradas,NumeroPelicula);*/
					  	 	    	
								   	printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////// \n");
					  	 	    	printf("El precio de las peliculas: \n");
					  	 	    	printf("\t Peliculas de accion: 20EUROS \n");
					  	 	    	printf("\t Peliculas documentales: 12EUROS \n");
					  	 	    	printf("\t Peliculas de animacion: 15EUROS \n");
					  	 	    	printf("\t Peliculas de Ciencia Ficcion: 25EUROS \n");
					  	 	    	printf("\t Peliculas historicas: 18EUROS \n");
					  	 	    	printf("\t Peliculas de terror: 13EUROS \n");
					  	 	    	printf("\t Peliculas de comedia: 14EUROS \n");
					  	 	    	printf("\t Peliculas musicales: 8EUROS \n");
					  	 	    	printf("\t Peliculas de aventuras: 12EUROS \n");
					  	 	    	printf("\t Peliculas romanticas: 22EUROS \n");
					  	 	    	printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////// \n\n");
					  	 	    	printf("Listado de peliculas que puede comprar: \n\n");
					  	 	    	NPP=abrepeliculas(Ppago,"peliculas/peliculaspago.txt");
								}
								else if (i>ContBanco){
									ContBanco++;
									
									printf("Aun no se ha facilitado los datos de su cuenta bancaria. Por favor indiquelos a continuacion: \n");
									pfbanco = fopen("registrobanco.txt", "a");
		   							printf("ingrese su numero de cuenta: (alguno inventado) \n");
		   							scanf("%s",registro.x.cuenta);
		   							printf("ingrese la contrasena (4 digitos) \n");
		   							scanf("%s",registro.x.pass);
		   						
		   						do{
		   							registro.x.saldo=0;
									printf("Ingrese el saldo de su cuenta (maximo inical 100 EUROS):");
		   							scanf("%d",&registro.x.saldo);
							    }while(registro.x.saldo>100);
							    
							    //creamos un fichero unicamente para el saldo de cada persona para poder extraer el dato como un entero
							    
							    strcat(RutaSaldo,registro.nombre);
							    strcat(RutaSaldo,".txt");
							    
							    saldobanco = fopen(RutaSaldo, "w");
							    fprintf(saldobanco,"%d",registro.x.saldo);
							    fclose(saldobanco);
									
		   					    fprintf(pfbanco,"%s;%s;%s\n",registro.nombre, registro.x.cuenta, registro.x.pass);
						  		fclose(pfbanco);
						  		
						  		contbanco = fopen("contadorbanco.txt", "w");
						  		fprintf(contbanco,"%d",ContBanco);
						  		fclose(contbanco);
									
								} 
						   break;
					}
			      break;
			    	      
			    case 3:
			        //Aqui se relizará un filtrado de de gustos para mejor la busqueda y sugerencia
	        	break;
			    }
			    printf("Desea salir del programa? teclee salir \n");
			    printf("Para volver al menu pulse cualquier tecla \n");
			    scanf("%s",tecla2);
		break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case 2://El usuario no está registrado
		printf("Pulse 1 si quiere registrarse o 2 si quiere ver la guía: ");
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

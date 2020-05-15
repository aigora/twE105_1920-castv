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
				printf("\nEnhorabuena ha pasado la prueba de registro, puede disfrutar de CasTv \n\n");
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

void programaciondia(int a[], dia b[]){//Abre la programacion del dia escogido
     
	int i=0,j=0;
	printf("\n");	  
	for(j=0;j<6;j++){
			if(j==0)
             printf("La 1\n");
        	if(j==1)
		     printf("Neox\n");
			if(j==2)	
        	 printf("Mega\n");
        	if(j==3)	
			 printf("Discovery Max\n");
			if(j==4)
			 printf("Boing\n");
		    if(j==5)
			 printf("La sexta\n"); 
			 	
		 for(i=0;i<a[j];i++){
         printf("\t\t%s %s:%s-%s:%s  \n ",b[j].c[i].titulo,
         b[j].c[i].ti.hora,
         b[j].c[i].ti.min,
         b[j].c[i].tf.hora,
         b[j].c[i].tf.min);
         
		}
		printf("\n\n");	
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
	    nLineas--;
	    
	    if(e==-1){
	    	printf("No hemos encontrado ninguna compra todavia\n\n");
	    	fclose(pf);
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
		if(strcmp(p[i-1].tematica,"accion")==0) x=1; if(strcmp(p[i-1].tematica,"animacion")==0) x=2; if(strcmp(p[i-1].tematica,"aventuras")==0) x=3;
		if(strcmp(p[i-1].tematica,"historico")==0) x=4; if(strcmp(p[i-1].tematica,"terror")==0) x=5; if(strcmp(p[i-1].tematica,"ciencia ficcion")==0) x=6;
		if(strcmp(p[i-1].tematica,"documental")==0) x=7; if(strcmp(p[i-1].tematica,"comedia")==0) x=8; if(strcmp(p[i-1].tematica,"musical")==0) x=9;
		if(strcmp(p[i-1].tematica,"romantica")==0) x=10;
	
	switch(x){
		case 1: precio=20; break; case 2: precio=15; break; case 3: precio=12; break; case 4: precio=18; break; case 5: precio=13; break;
		case 6: precio=25; break; case 7: precio=12; break; case 8: precio=14; break; case 9: precio=8; break; case 10: precio=22; break;
	}
return precio;
}

void retrocederprograma(char tecla2[]){//Pregunta al usuario si quiere seguir usando el programa
	printf("Desea salir del programa? teclee salir \n");
	printf("Para volver al menu pulse cualquier tecla \n");
    scanf("%s",tecla2);
}

void CopiarFichero(const char *Fichero1, const char *Fichero2){//Copia un fichero a otro
		FILE *qf, *pf;
		int e, data1=0;
		char x;
		
		qf=fopen(Fichero2,"r");
		e = fscanf(qf, "%x", &x);
	    
	    if(e==-1){
	    	fclose(qf);	
	    	pf = fopen(Fichero1,"r");
	    	qf = fopen(Fichero2,"w");
	    
	   		while ((data1 = fgetc (pf)) != EOF) {
       			fputc (data1,qf);
    		}
    		fclose(qf);
    		fclose(pf);
 		}
		else {
			fclose(qf);
		}
}

int CompraPelicula(pelicula p[],int i,const char *RutaPeliculasCompradas, const char *RutaPeliculasGratuitas,const char *nombre, int saldo){//Funcion para la compra de peliculas y guardarlas en su nuevo fichero
	FILE *pf, *qf;
	int precio;
	char RutaSaldo[40]={"saldo/"};
	
	strcat(RutaSaldo,nombre);
	strcat(RutaSaldo,".txt");
	
	printf("Usted ha comprado la siguiente pelicula: \n");
	detallespeliculas(p,i);
	precio=calculaprecio(p,i);
	i--;
	pf=fopen(RutaPeliculasCompradas,"a");
	qf=fopen(RutaPeliculasGratuitas,"a");
		fprintf(pf, "%s;%s:%s;%s;%s\n", p[i].titulo,
	       	 p[i].t.hora,
	       	 p[i].t.min,
    	     p[i].tematica,
	         p[i].year);
     	fprintf(qf, "%s;%s:%s;%s;%s\n", p[i].titulo,
	       	 p[i].t.hora,
	       	 p[i].t.min,
    	     p[i].tematica,
		     p[i].year);
	fclose(pf);
	fclose(qf);
	
	saldo-=precio;
	pf=fopen(RutaSaldo,"w");
	fprintf(pf,"%d",saldo);
	fclose(pf);
	printf("Despues de realizar la compra le queda un total de: %d EUROS \n\n",saldo);
	
return saldo;
}

int main (){//Programa principal

  EscribeNombre(); 
   
  
  ////////////////////////////////////////////VARIABLES QUE VAMOS A UTILIZAR POSTERIORMENTE////////////////////////////////////////////
  
	  tiempo HoraActual;//Almacena la hora del sistema
	  
	  pelicula Pcompradas[50], Ppago[50], Pgratis[150];//Las usaremos para almecenar las películas
	  
	  dia L[6], M[6], X[6], J[6], V[6], S[6], D[6];//Variables en las que se almacenarán los programas de cada día
	  
	  int op1=0, op2=0, op3=0, op4=0, op5=0, op6=0, op7=0, op8=0, op9=0, op10=0,//Operadores que utilizamos en bucles
	  	  ContReg=0, i, i2, x1, x2, x3, x4,//Se utilizan en condicionales para el registro
	  	  ContBanco=0,//Se utilizan en condicionales para el registro de la cuenta bancaria
		  DiaActual=0,//Almacena numericamente el dia del sistema 
		  NL[6], NM[6], NX[6], NJ[6], NV[6], NS[6], ND[6],//Numero de programas que tiene cada canal en cada dia
		  NPC, NPP, NPG,//Almacenamos el numero de películas de cada tipo
		  precio,//Guarda el precio de las peliculas
		  Hora,Min,//Almacena la hora del sistema como enteros
		  y, intentos, ingresosaldo;//Bucles para meter dinero
		  
	  char tecla1[10]="salir", tecla2[10],//Bucle global del programa
	  	   RutaSaldo[30]={"saldo/"},//La utilizo para crear la ruta del fichero que alberga el saldo de cada usuario
		   MinutoSys[10],HoraSys[10],//Guarda la hora del sistema como cadena de caracteres
		   RutaPeliculasCompradas[60]={"peliculas/peliculascompradas/"},//Lo utilizo para crear la ruta de las peliculas compradas por cada usuario
		   RutaPeliculasGratuitas[60]={"peliculas/peliculas/"},//ruta de las peliculas totales que posee un usuario
		   ContrasenaBanco[5], DNIusuario[10];//Proceso de verificacion de datos
		   	
	  FILE *pf, *cont, *pfbanco, *contbanco, *saldobanco, *pelicomprada;//Punteros que apuntan a los ficheros donde guardamos los datos de los registrados
		   	        
	  usuario registro, CompReg[5] , CompRegBanco[5];//Necesarios para registrarse
	  
	  
 /////////////////////////////////////////////////////FIN DE LAS VARIABLES/////////////////////////////////////////////////////


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
 
  //CREO NOMBRES DE RUTAS QUE POSTERIORMENTE VOY A USAR
 		strcat(RutaPeliculasGratuitas,registro.nombre);
		strcat(RutaPeliculasGratuitas,".txt");
					
		strcat(RutaSaldo,registro.nombre);
		strcat(RutaSaldo,".txt");
					
		strcat(RutaPeliculasCompradas,registro.nombre);
		strcat(RutaPeliculasCompradas,".txt");

do{
	  time_t t = time(NULL);//Se obtiene la hora del sistema por cada repeticion del bucle.
 	  struct tm tiempoLocal = *localtime(&t);
 	  
 switch(op1){//El usuario ya está registrado
 	case 1:
	 	//Menú, si qiuere salir deberá escribir "salir"
	 	 printf("  Menu \n");
	 	 printf("  \tGuia televisiva: 1 \n");
		 printf("  \tCatalogo: 2 \n");
	     printf("  \tRecomendacion: 3 \n");
		 scanf("%d",&op2);
		
		 switch(op2){
			    case 1:
			    	
					DiaActual= tiempoLocal.tm_wday;	
					Hora=tiempoLocal.tm_hour;
					Min=tiempoLocal.tm_min;
					sprintf(HoraSys,"%d",Hora);
					sprintf(MinutoSys,"%d",Min);
					printf("%s:%s",HoraSys,MinutoSys);
		
			        printf("\nPara acceder a la programacion completa separada por dias pulse 1 \n");
			        printf("Para acceder a la programacion del dia actual pulse 2 \n");
			        printf("Para acceder a la programacion en directo pulse 3 \n\n");
			    	     scanf("%d",&op10);
			    	     switch(op10){
			    	     	case 1:
				    	     	printf(" \nTeclee el numero del dia que quiera ver la programacion: \n");
				    	     	printf("1. lunes \n");
				    	     	printf("2. martes \n");
				    	     	printf("3. miercoles \n");
				    	     	printf("4. jueves \n");
				    	     	printf("5. viernes \n");
				    	     	printf("6. sabado \n");
				    	     	printf("7. domingo \n");
				    	     	scanf("%d",&op9);
			    	     	
								switch(op9){
				    	     	    case 1: programaciondia(NL,L); break;
				    	     	    case 2: programaciondia(NM,M); break;
				    	     	    case 3: programaciondia(NX,X); break;
				    	     	    case 4: programaciondia(NJ,J); break;
				    	     	    case 5: programaciondia(NV,V); break; 
				    	     	    case 6: programaciondia(NS,S); break;
				    	     	    case 7: programaciondia(ND,D); break;
			    	     		}
			    	     		retrocederprograma(tecla2);
			    	     	break;
							case 2:
								retrocederprograma(tecla2);
							break;
							case 3:
								retrocederprograma(tecla2);
							break;	
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
			          	   pelicomprada = fopen(RutaPeliculasGratuitas, "a");
			          	   fclose(pelicomprada);
			          	   CopiarFichero("peliculas/peliculas.txt",RutaPeliculasGratuitas);
						   
			    	       NPG=abrepeliculas(Pgratis,RutaPeliculasGratuitas);
			    	       printf("Escriba el numero de una pelicula si quiere saber mas detalles.\n\n");
					       do{
				    	    	scanf("%d",&op7);
					  			if(op7>NPG || op7<0)
				 	    			printf("Esa pelicula no existe. Pruebe con otro numero");
					  	 	    else if(op7!=0) detallespeliculas(Pgratis,op7);	
					  	 	    printf("\n\nSi desea volver al menu escriba menu.\n");
					  	 	    printf("Si desea acabar el programa escriba salir.\n");
					  	 	    printf("Y cualquier otra tecla para obtener mas detalles de otra pelicula\n");
					  	 	    scanf("%s",tecla2);
						   }while(strcmp(tecla1,tecla2)<0);
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
	    	 					
	    	 					cont = fopen("contador.txt", "r");
		   						fscanf(cont,"%d",&ContReg);
		   						fclose(cont);
	    	 					
	    	 					pf = fopen("registro.txt", "r"); 
								for (i=0;i<ContReg;i++)
	    	 						fscanf(pf, "%[^;];%[^;];%[^\n]\n", CompReg[i].nombre, CompReg[i].password, CompReg[i].DNI);
	     						fclose(pf);
	    	 					
								i=0; 	
								do{
									 x3=strcmp(registro.nombre,CompRegBanco[i].nombre);
									 i++;
									 if(i>ContBanco)
									 x3=0;	 
					  	 	    }while(x3!=0);
					  	 	    i2=0;
					  	 	    do{
									 x4=strcmp(registro.nombre,CompReg[i2].nombre);
									 i2++;
									 if(i2>ContReg)
									 x4=0;	 
					  	 	    }while(x4!=0);
					  	 	    
					  	 	    

					  	 	    if (i<=ContBanco){
					  	 	    	printf("Hemos encontrado su cuenta bancaria en el registro. \n\n");
					  	 	    	
					  	 	    	saldobanco = fopen(RutaSaldo, "r");
							    	fscanf(saldobanco,"%d",&registro.x.saldo);
							    	fclose(saldobanco);
							    	printf("SALDO DE LA CUENTA: %d EUROS\n\n",registro.x.saldo);
					  	 	    	
							    	pelicomprada = fopen(RutaPeliculasCompradas, "a");
							    	fclose(pelicomprada);
									printf("Estas son las peliculas anteriormente compradas: \n");
									
									NPC=abrepeliculas(Pcompradas,RutaPeliculasCompradas);
									/*printf("Desea ver las caracteristicas de alguna pelicula? Introduzca su numero: ");
									scanf("%d",&NumeroPelicula);
									detallespeliculas(Pgratis,NumeroPelicula);*/
					  	 	    	
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
					  	 	    	printf("Escriba el numero de una pelicula si quiere saber mas detalles, si quiere comprar alguna directamente escriba 0 \n\n");
					  	 	    	do{
					  	 	    		scanf("%d",&op7);
					  	 	    		if(op7>NPP || op7<0)
					  	 	    			printf("Esa pelicula no existe. Pruebe con otro numero o 0 si desea comprar alguna sin mirar sus detalles");
					  	 	    		else if(op7!=0) detallespeliculas(Ppago,op7);	
									}while(op7);
										printf("Indique el numero de la pelicula que desea comprar: \n");
										scanf("%d",&op7);
									    precio=calculaprecio(Ppago,op7);
									    
									if(registro.x.saldo<precio){
										printf("El saldo de su cuenta es insuficiente. No puede realizar la compra \n\n");
										do{
											printf("Si quiere probar con otra pelicula pulse 1\n");
											printf("si quiere aumentar el saldo de su cuenta pulse 2\n");
											printf("si quiere volver al menu pulse 3\n");
											scanf("%d",&op8);
											if(op8==1){
												printf("Indique el numero de la pelicula que desea comprar: \n");
												scanf("%d",&op7);
									    		precio=calculaprecio(Ppago,op7);
									    		if(registro.x.saldo>precio){
													printf("Esta pelicula si esta a su alsance. Preparamos el proceso de compra \n\n");
									    			registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);
												}
											}
											if(op8==2){
												printf("Bienvenido al operador bancario: \n\n");
												intentos=0;
												do {
				      							  if (intentos==3){
				        				    	  printf("Las contrasenas no coinciden. Pulse 1 si desea recuperarla o cualquier tecla para acabar el programa. \n");
				        						  scanf("%d",&y);
				        	                    	if (y==1){
				        		 						printf("Introduzca su DNI para verificar:");
				        								scanf("%s",DNIusuario);
				        								if(strcmp(DNIusuario,CompReg[i2-1].DNI)){
				        									printf("Lo sentimos no podemos facilitarle la contrasena.");
				        									exit(1);
														}
				        								else{
				        									printf("La contrasena es: %s \n",CompRegBanco[i-1].x.pass);
														}				        		
													}
													else exit(1);
				       							}
				     						   	if (intentos>3)
				        						printf("Le recuerdo que se contrasena es %s \n",CompRegBanco[i-1].x.pass);
				        							printf("Introduzca la contrasena de la cuenta bajo el nombre de %s: ",registro.nombre);
				       								 scanf("%s",ContrasenaBanco);
				   	   							 intentos++;
  												} while (strcmp(ContrasenaBanco,CompRegBanco[i-1].x.pass)!=0);
  												printf("\n");
  												printf("INGRESO MAXIMO 50 EUROS \n");
  												printf("INGRESO MINIMO 10 EUROS \n\n");
  												printf("Su saldo actual es: %d EUROS. Indique la cantidad a incorporar a su saldo: ",registro.x.saldo);
  												do {
												  scanf("%d",&ingresosaldo);
												  if(ingresosaldo>50 || ingresosaldo<10)
												  	printf("Cantidad no valida");
												}while(ingresosaldo>50 || ingresosaldo<10);
												registro.x.saldo+=ingresosaldo;
												
					  	 	    				saldobanco = fopen(RutaSaldo, "w");
							    				fprintf(saldobanco,"%d",registro.x.saldo);
										    	fclose(saldobanco);
										    	
										    	printf("Su nuevo saldo es: %d EUROS \n\n",registro.x.saldo);
										    	if(registro.x.saldo>25){
										    		printf("Ya dispone de suficiente saldo. Podemos pasar a realizar la compra de la pelicula. \n\n");
										    		printf("inserte el numero de la pelicula que quiere comprar: ");
										    		scanf("%d",&op7);
												    precio=calculaprecio(Ppago,op7);
												    registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);    		
												}	
										     }
										     if(op8==3)
										     	precio=-1;
										}while(registro.x.saldo<precio);
										retrocederprograma(tecla2);
									}
									else{
										printf("Pasamos a realziar la compra de la pelicula... \n\n");
										registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);
										retrocederprograma(tecla2);
									}
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
							    
							    saldobanco = fopen(RutaSaldo, "w");
							    fprintf(saldobanco,"%d",registro.x.saldo);
							    fclose(saldobanco);
									
		   					    fprintf(pfbanco,"%s;%s;%s\n",registro.nombre, registro.x.cuenta, registro.x.pass);
						  		fclose(pfbanco);
						  		
						  		contbanco = fopen("contadorbanco.txt", "w");
						  		fprintf(contbanco,"%d",ContBanco);
						  		fclose(contbanco);
									
								retrocederprograma(tecla2);
								} 
						break;
					}
			    break;
			    	      
			    case 3:
			        printf("Bienvenido al apartado de sugerencias.");
			        printf("Vamos a realizar un filtrado segun sus gustos para ahorrarle tiempo en la eleccion de su contenido multimedia.");
			        printf("Bienvenido al apartado de sugerencias.");
					//Aqui se relizará un filtrado de de gustos para mejor la busqueda y sugerencia
			        retrocederprograma(tecla2);
	        	break;
			    }
	break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case 2://El usuario no está registrado
		printf("Pulse 1 si quiere registrarse o 2 si quiere ver la guia: ");
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
						     printf("\nLo sentimos se ha alcanzado el numero maximo de registros (%d). Solo puede ver la guia televisiva.\n",ContReg);
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
					printf("bienvenido a la guia televisiva!! \n\n");
					retrocederprograma(tecla2);
			break;
		}
	break;	
	}	
}while(strcmp(tecla1,tecla2));
return 0;
}

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
	char tematica[25];
	char year[5];
}pelicula;

typedef struct{//Estrcura serie
	char capitulo[12];
	char titulo[50];
	char descripcion[500];
}serie;

int main (){//Programa principal

  EscribeNombre(); 
   
  
  ////////////////////////////////////////////VARIABLES QUE VAMOS A UTILIZAR POSTERIORMENTE////////////////////////////////////////////
  
	  tiempo HoraActual;//Almacena la hora del sistema
	  
	  pelicula Pcompradas[50], Ppago[50], Pgratis[150], *PeliculaFiltro, PeliculasDuracion[150];//Las usaremos para almecenar las películas
	  
	  dia L[6], M[6], X[6], J[6], V[6], S[6], D[6];//Variables en las que se almacenarán los programas de cada día
	  
	  int op1=0, op2=0, op3=0, op4=0, op5=0, op6=0, op7=0, op8=0, op9=0, op10=0, op11=0, op12=0, //Operadores que utilizamos en bucles
	  	  ContReg=0, i, j, i2, x1, x2, x3, x4,//Se utilizan en condicionales para el registro
	  	  ContBanco=0,//Se utilizan en condicionales para el registro de la cuenta bancaria
		  DiaActual=0,//Almacena numericamente el dia del sistema 
		  NL[6], NM[6], NX[6], NJ[6], NV[6], NS[6], ND[6],//Numero de programas que tiene cada canal en cada dia
		  NPC, NPP, NPG,//Almacenamos el numero de películas de cada tipo
		  PeliculaComprada,//Se utiliza para asegurarse que una pelicula no se compra dos veces
		  precio,//Guarda el precio de las peliculas
		  Hora,Min,//Almacena la hora del sistema como enteros
		  y, intentos, ingresosaldo,//Bucles para meter dinero
		  CoincidenciaTematica, contadorduracion,//Usados en el proceso de filtrado
		  temporada,//Para elegir la temporada de la serie 
		  longh=0,longmin=0;

		  
	  char tecla1[10]="salir", tecla2[10], cero[]="0",//Bucle global del programa
	  	   RutaSaldo[30]={"saldo/"},//La utilizo para crear la ruta del fichero que alberga el saldo de cada usuario
		   MinutoSys[3]="0",HoraSys[3]="0",//Guarda la hora del sistema como cadena de caracteres
		   RutaPeliculasCompradas[60]={"peliculas/peliculascompradas/"},//Lo utilizo para crear la ruta de las peliculas compradas por cada usuario
		   RutaPeliculasGratuitas[60]={"peliculas/peliculas/"},//ruta de las peliculas totales que posee un usuario
		   ContrasenaBanco[5], DNIusuario[10],//Proceso de verificacion de datos
		   HoraCompara1[3], MinutoCompara1[3], HoraCompara2[3], MinutoCompara2[3],//Para el filtrado por duración
		   *zero,*sero;
		   	
	  FILE *pf, *cont, *pfbanco, *contbanco, *saldobanco, *pelicomprada, *tema;//Punteros que apuntan a los ficheros donde guardamos los datos de los registrados
		   	        
	  usuario registro, CompReg[5] , CompRegBanco[5];//Necesarios para registrarse
	  
	  serie s1[11],s2[11],s3[11],s4[11],s5[11],s6[11],s7[11],s8[11];//Cada temporada de la serie
	  
	  
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
		
		pelicomprada = fopen(RutaPeliculasGratuitas, "a");
		fclose(pelicomprada);
	    CopiarFichero("peliculas/peliculas.txt",RutaPeliculasGratuitas);

do{
	sero=(char*)malloc(3*sizeof(char));
	zero=(char*)malloc(3*sizeof(char));
	strcpy(sero,"0");
	strcpy(zero,"0");
	  time_t t = time(NULL);//Se obtiene la hora del sistema por cada repeticion del bucle.
 	  struct tm tiempoLocal = *localtime(&t);
 	   DiaActual= tiempoLocal.tm_wday;	
		Hora=tiempoLocal.tm_hour;
		Min=tiempoLocal.tm_min;
		sprintf(HoraSys,"%d",Hora);
		//sprintf(MinutoSys,"%d",Min);
		MinutoSys[0]='4';
		longh=strlen(HoraSys);
		longmin=strlen(MinutoSys);
		//printf("%d, %d\t", longh, longmin);
		if(longh==1){
			strcat(zero,HoraSys);
			strcpy(HoraSys,zero);	
		}
			if(longmin==1){
			strcat(sero,MinutoSys);
			strcpy(MinutoSys,sero);
			}
		
		printf("%s:%s",HoraSys,MinutoSys);
 	  free(zero);
 	  free(sero);
 	  
 	  
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
			    	
					
		            printf("¡Bienvenido a la guia televisiva!");
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
								printf("Esta es la programacion del dia actual");
								if(DiaActual==1){
									programaciondia(NL,L);
								}
								else if(DiaActual==2){
									programaciondia(NM,M);
								}
								else if(DiaActual==3){
									programaciondia(NX,X);
								}
								else if(DiaActual==4){
									programaciondia(NJ,J);
								}
								else if(DiaActual==5){
									programaciondia(NV,V);
								}
								else if(DiaActual==6){
									programaciondia(NS,S);
								}
								else if(DiaActual==0){
									programaciondia(ND,D);
								}
								retrocederprograma(tecla2);
							break;
							case 3:
								 printf("Programacion en directo por cada canal: \n\n");
                               
                                switch(DiaActual){
                                    case 1:
                                        ProgramacionActual(L,NL,HoraSys,MinutoSys);
                                    break;
                                    case 2:
                                    	ProgramacionActual(M,NM,HoraSys,MinutoSys);
                                    break;
                                    case 3:
                                    	ProgramacionActual(X,NX,HoraSys,MinutoSys);
                                    break;
                                    case 4:
                                    	ProgramacionActual(J,NJ,HoraSys,MinutoSys);
                                    break;
                                    case 5:
                                        ProgramacionActual(V,NV,HoraSys,MinutoSys);
                                    break;
                                    case 6:
                                    	ProgramacionActual(S,NS,HoraSys,MinutoSys);
                                    break;
                                    case 0:
                                    	ProgramacionActual(D,ND,HoraSys,MinutoSys);
                                    break;
						}
							
							
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
			    		case 1://Gratuito
			    	
						printf("Pulse 1 para acceder a las peliculas. Pulse 2 para acceder a la serie: ");
			    		scanf("%d",&op12);
			    		printf("\n");
			    		   
			    		switch(op12){
			    			
			    		case 1: //Películas gratuitas
			    		   
			    	       printf("Estas son todas las peliculas que disponemos. Si quiere realizar un filtrado dirijase al apartado recomendacion en el menu principal: \n\n");
			    	       NPG=abrepeliculas(Pgratis,RutaPeliculasGratuitas);
			    	       
			    	       printf("Pulse 1 si desea buscar alguna pelicula por el titulo o 2 si desea saber los detalles de alguna\n");
					       do{
					       	    printf("Escriba el numero de una pelicula si quiere saber mas detalles.\n\n");
				    	    	scanf("%d",&op7);
					  			if(op7>NPG || op7<0)
				 	    			printf("Esa pelicula no existe. Pruebe con otro numero");
					  	 	    else if(op7!=0) detallespeliculas(Pgratis,op7);	
					  	 	    printf("\n\nSi desea volver al menu escriba menu.\n");
					  	 	    printf("Si desea acabar el programa escriba salir.\n");
					  	 	    printf("O Z para obtener mas detalles de otra pelicula\n");
					  	 	    scanf("%s",tecla2);
						   }while(strcmp(tecla1,tecla2)<0);
			    	       //Muestra el catálogo de películas entero con posibilidad de eleccion autónoma
			    	       //Estarán sorteadas por temáticas
			    	   break;
			    	   
			    	   case 2://serie
			    	   printf("\tTenemos en exclusiva la exitosa serie Juego de Tronos\n\tElija que temporada quiere ver entre la 1 y la 8:	");
			    	scanf("%d",&temporada);
			    switch(temporada){
			    	case 1:
			    		abreSerie(s1,"juego de tronos/Temporada 1/1.txt");break;
			    	case 2:
			    		abreSerie(s2,"juego de tronos/Temporada 2/2.txt");break;
			    	case 3:
			    		abreSerie(s3,"juego de tronos/Temporada 3/3.txt");break;
			    	case 4:
			    		abreSerie(s4,"juego de tronos/Temporada 4/4.txt");break;
			    	case 5:
			    		abreSerie(s5,"juego de tronos/Temporada 5/5.txt");break;
			    	case 6:
			    		abreSerie(s6,"juego de tronos/Temporada 6/6.txt");break;
			    	case 7:
			    		abreSerie(s7,"juego de tronos/Temporada 7/7.txt");break;
			    	case 8:
			    		abreSerie(s8,"juego de tronos/Temporada 8/8.txt");break;
				}
					retrocederprograma(tecla2);
					break;
			    }
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
					  	 	    	if(NPP==NPC){
					  	 	    		printf("\n\nUsted ya ha adquirido todo el contenido de pago disponible.\n");
					  	 	    		retrocederprograma(tecla2);
									}
					  	 	    	else {
						  	 	    	printf("Escriba el numero de una pelicula si quiere saber mas detalles, si quiere comprar alguna directamente escriba 0 \n\n");
						  	 	    	do{
						  	 	    		scanf("%d",&op7);
						  	 	    		if(op7>NPP || op7<0)
						  	 	    			printf("Esa pelicula no existe. Pruebe con otro numero o 0 si desea comprar alguna sin mirar sus detalles");
						  	 	    		else if(op7!=0) detallespeliculas(Ppago,op7);	
										}while(op7);
											
										printf("Indique el numero de la pelicula que desea comprar: \n");
										scanf("%d",&op7);
										
										PeliculaComprada=0;	
										for(j=0;j<NPC;j++){
											if(strcmp(Ppago[op7-1].titulo,Pcompradas[j].titulo)==0)
												PeliculaComprada++;
										}	
										
										if(PeliculaComprada>0){
											printf("\nEsta pelicula ya fue adquirida anteriormente\n");
											retrocederprograma(tecla2);
										}
										else {
											precio=calculaprecio(Ppago,op7);
											if(registro.x.saldo<precio){
												printf("El saldo de su cuenta es insuficiente. No puede realizar la compra \n\n");
												do{
													printf("Si quiere probar con otra pelicula pulse 1\n");
													printf("si quiere aumentar el saldo de su cuenta pulse 2\n");
													scanf("%d",&op8);
													if(op8==1){
														printf("Indique el numero de la pelicula que desea comprar: \n");
														scanf("%d",&op7);
														
														PeliculaComprada=0;	
														for(j=0;j<NPC;j++){
															if(strcmp(Ppago[op7-1].titulo,Pcompradas[j].titulo)==0)
																PeliculaComprada++;
														}
														if(PeliculaComprada>0)
															printf("\nEsta pelicula ya fue adquirida anteriormente\n");
														else {
												    		precio=calculaprecio(Ppago,op7);
												    		if(registro.x.saldo>precio){
																printf("Esta pelicula si esta a su alcance. Preparamos el proceso de compra \n\n");
												    			registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);
												    			precio=-1;
															}
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
												    		
												    		PeliculaComprada=0;	
															for(j=0;j<NPC;j++){
																if(strcmp(Ppago[op7-1].titulo,Pcompradas[j].titulo)==0)
																	PeliculaComprada++;
															}
															if(PeliculaComprada>0)
																printf("\nEsta pelicula ya fue adquirida anteriormente\n");
															else{
																precio=calculaprecio(Ppago,op7);
															    registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);
																precio=-1;    
															}		
														}	
												     }
												}while(registro.x.saldo<precio);
												retrocederprograma(tecla2);
											}
											else{
												printf("Pasamos a realziar la compra de la pelicula... \n\n");
												registro.x.saldo=CompraPelicula(Ppago,op7,RutaPeliculasCompradas,RutaPeliculasGratuitas,registro.nombre,registro.x.saldo);
												retrocederprograma(tecla2);
											}
										}
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
			        printf("\nBienvenido al apartado de sugerencias. \n");
			        printf("Vamos a realizar un filtrado segun sus gustos para ahorrarle tiempo en la eleccion de su contenido multimedia.\n\n");
			        printf("Estas son todas las peliculas que vamos a tener en cuenta para realizar el filtrado: \n\n");
			        NPG=abrepeliculas(Pgratis,RutaPeliculasGratuitas);
			        printf("\nLa sugerencia la realizaremos mediante un filtrado de tematicas y duracion\n\n");
			        printf("Pulse 1 si quiere filtrar unicamente por tematica.\n");
			        printf("Pulse 2 si quiere filtrar unicamente por duracion.\n");
			        printf("Pulse 3 si quiere filtrar por tematica y duracion.\n\n");
			        do{
						scanf("%d",&op11);
						if(op11!=1 && op11!=2 && op11!=3)
							printf("Esta opcion no esta permitida, intenetelo de nuevo. \n\n");
			        	switch(op11){
			        		case 1: 
			        			printf("Indique la tematica o tematicas que mas le gusten. Escribalo exactemente como aparece abajo uno por uno\n");
			        			printf("Ejemplo: 'accion' \n\n");
			        			MuestraTematicas();
			        			
					  	    	CoincidenciaTematica=SelectorTematica(NPG,Pgratis);
					  	    	
			        			PeliculaFiltro=(pelicula*)malloc(CoincidenciaTematica*sizeof(pelicula));
			        			abrepeliculas(PeliculaFiltro,"peliculas/tematicas.txt");
			        			tema = fopen("peliculas/tematicas.txt", "w");
			        			fclose(tema);
			        			
								retrocederprograma(tecla2);		
			        					
			        		break;
			        		case 2:
			        		printf("Introduzca el intervalo de duracion de la pelicula \n");
			        			printf("Ejemplo: Hora: 01 , Minutos: 45 \n\n");
			        			printf("Introduzca la duracion minima \n");
			        			printf("Horas: \n"); scanf("%s",HoraCompara1);
			        			printf("Minutos: \n"); scanf("%s",MinutoCompara1);
			        			printf("Introduzca la duracion maxima \n");
			        			printf("Horas: \n"); scanf("%s",HoraCompara2);
			        			printf("Minutos: \n"); scanf("%s",MinutoCompara2);
			        			
			        			contadorduracion=0;
			        			for(i=0;i<NPG;i++){
			        				if(strcmp(Pgratis[i].t.hora,HoraCompara1)>0 && strcmp(Pgratis[i].t.hora,HoraCompara2)<=0){
			        					if(strcmp(Pgratis[i].t.min,MinutoCompara2)<=0){
											printf("%d- %s.\tDuracion: %s:%s \n\n",contadorduracion+1,Pgratis[i].titulo,Pgratis[i].t.hora,Pgratis[i].t.min);
											contadorduracion++;
										}
									}
									if(strcmp(Pgratis[i].t.hora,HoraCompara1)==0 && strcmp(Pgratis[i].t.hora,HoraCompara2)<0){
			        					if(strcmp(Pgratis[i].t.min,MinutoCompara1)>=0){
											printf("%d- %s.\tDuracion: %s:%s \n\n",contadorduracion+1,Pgratis[i].titulo,Pgratis[i].t.hora,Pgratis[i].t.min);
											contadorduracion++;
										}
									}
									if(strcmp(Pgratis[i].t.hora,HoraCompara1)==0 && strcmp(Pgratis[i].t.hora,HoraCompara2)==0){
										if(strcmp(Pgratis[i].t.min,MinutoCompara1)>=0 && strcmp(Pgratis[i].t.min,MinutoCompara2)<=0){
											printf("%d- %s.\tDuracion: %s:%s \n\n",contadorduracion+1,Pgratis[i].titulo,Pgratis[i].t.hora,Pgratis[i].t.min);
											contadorduracion++;
										}
									}
								}
									
			        			retrocederprograma(tecla2);
			        		break;
			        		case 3:
			        			retrocederprograma(tecla2);
			        		break;
						}
					}while(op11!=1 && op11!=2 && op11!=3);
			        
					//Aqui se relizará un filtrado de de gustos para mejor la busqueda y sugerencia
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
								printf("Esta es la programacion del dia actual");
								if(DiaActual==1){
									programaciondia(NL,L);
								}
								else if(DiaActual==2){
									programaciondia(NM,M);
								}
								else if(DiaActual==3){
									programaciondia(NX,X);
								}
								else if(DiaActual==4){
									programaciondia(NJ,J);
								}
								else if(DiaActual==5){
									programaciondia(NV,V);
								}
								else if(DiaActual==6){
									programaciondia(NS,S);
								}
								else if(DiaActual==0){
									programaciondia(ND,D);
								}
								retrocederprograma(tecla2);
							break;
							case 3:
								 printf("Programacion en directo por cada canal: \n\n");
                               
                                switch(DiaActual){
                                    case 1:
                                        ProgramacionActual(L,NL,HoraSys,MinutoSys);
                                    break;
                                    case 2:
                                    	ProgramacionActual(M,NM,HoraSys,MinutoSys);
                                    break;
                                    case 3:
                                    	ProgramacionActual(X,NX,HoraSys,MinutoSys);
                                    break;
                                    case 4:
                                    	ProgramacionActual(J,NJ,HoraSys,MinutoSys);
                                    break;
                                    case 5:
                                        ProgramacionActual(V,NV,HoraSys,MinutoSys);
                                    break;
                                    case 6:
                                    	ProgramacionActual(S,NS,HoraSys,MinutoSys);
                                    break;
                                    case 0:
                                    	ProgramacionActual(D,ND,HoraSys,MinutoSys);
                                    break;
								}
							retrocederprograma(tecla2);
							break;
						}
 			break;
		}
	break;
}
}while(strcmp(tecla1,tecla2));
return 0;
}

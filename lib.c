#include "lib.h"

typedef struct{//Estrcura serie
	char capitulo[12];
	char titulo[50];
	char descripcion[500];
}serie;

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

typedef struct{//Estructura película
	char titulo[40];
	tiempo t;
	char tematica[25];
	char year[5];
}pelicula;

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
	     		printf("%s: %s.\n%s\n\n",s[a].capitulo,s[a].titulo,s[a].descripcion);
	    		a++;
		 }
	    fclose(pf); 
		return nLineas; 	
		}                 
}

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
				        	printf("Le recuerdo que su contrasena es %s \n",registro[i].password);
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
	switch (j) {
		case 0:
             printf("\tLa 1\n");
             break;
        case 1:
             printf("\tNeox\n");
             break;
		case 2:
            printf("\tMega\n");
             break;
		case 3:
             printf("\tDiscovery Max\n");
             break;
		case 4:
             printf("\tBoing\n");
             break;
        case 5:
             printf("\tLa sexta\n"); 
             break;	
}
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
		if(strcmp(p[i-1].tematica,"historico")==0) x=4; if(strcmp(p[i-1].tematica,"terror")==0) x=5; if(strcmp(p[i-1].tematica,"ciencia_ficcion")==0) x=6;
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

void ProgramacionActual(dia d[],int nd[],char *HoraSys,char *MinutoSys){//Función que nos muestra la programación actual en todas los canales
    int i=0,j=0,stop;
        printf("\n");
        printf("Se esta emitiendo a las %s:%s en: \n\n", HoraSys, MinutoSys);
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
             
             i=0;
            
            stop=1;
        	while(stop){
        		i++;
                if(strcmp(d[j].c[i].ti.hora,HoraSys)==0 && strcmp(d[j].c[i].tf.hora,HoraSys)==0){
                	if(strcmp(d[j].c[i].ti.min,MinutoSys)<0){
	                    printf("\tPrograma actual---->\t");
	                    printf("%s\tHa empieza a las %s:%s\n",d[j].c[i].titulo,d[j].c[i].ti.hora,d[j].c[i].ti.min);
	                    printf("\tSiguiente programa---->\t");
	                    printf("%s\tEmpieza a las %s:%s\n\n\n",d[j].c[i+1].titulo,d[j].c[i+1].ti.hora,d[j].c[i+1].ti.min);  
						stop--; 
					}
                }    
				if(strcmp(d[j].c[i].ti.hora,HoraSys)==0 && strcmp(d[j].c[i].tf.hora,HoraSys)>0){
					printf("\tPrograma actual---->\t");
	                printf("%s\tHa empieza a las %s:%s\n",d[j].c[i].titulo,d[j].c[i].ti.hora,d[j].c[i].ti.min);
	                printf("\tSiguiente programa---->\t");
	            	printf("%s\tEmpieza a las %s:%s\n\n\n",d[j].c[i+1].titulo,d[j].c[i+1].ti.hora,d[j].c[i+1].ti.min);  
					stop--; 
				}
				if(strcmp(d[j].c[i].ti.hora,HoraSys)<0 && strcmp(d[j].c[i].tf.hora,HoraSys)>0){
					printf("\tPrograma actual---->\t");
	                printf("%s\tHa empieza a las %s:%s\n",d[j].c[i].titulo,d[j].c[i].ti.hora,d[j].c[i].ti.min);
	                printf("\tSiguiente programa---->\t");
	            	printf("%s\tEmpieza a las %s:%s\n\n\n",d[j].c[i+1].titulo,d[j].c[i+1].ti.hora,d[j].c[i+1].ti.min);  
					stop--; 
				}
				if(strcmp(d[j].c[i].ti.hora,HoraSys)<0 && strcmp(d[j].c[i].tf.hora,HoraSys)==0){
					if(strcmp(d[j].c[i].tf.min,MinutoSys)>0){
						printf("\tPrograma actual---->\t");
	               		printf("%s\tHa empieza a las %s:%s\n",d[j].c[i].titulo,d[j].c[i].ti.hora,d[j].c[i].ti.min);
	                	printf("\tSiguiente programa---->\t");
	            		printf("%s\tEmpieza a las %s:%s\n\n\n",d[j].c[i+1].titulo,d[j].c[i+1].ti.hora,d[j].c[i+1].ti.min);  
						stop--; 		
					}
				}
				if(i==nd[j])
					stop--;
            }
        }
}

void MuestraTematicas(){//Muestra el formato correcto para que el usuario escriba las tematicas
	printf("TEMATICAS:\n");
	printf("\t accion\n");
	printf("\t documental\n");
	printf("\t animacion\n");
	printf("\t ciencia_ficcion\n");
	printf("\t historico\n");
	printf("\t terror\n");
	printf("\t comedia\n");
	printf("\t musical\n");
	printf("\t aventuras\n");
	printf("\t romantica\n");
}

int SelectorTematica(int nLineas, pelicula Pgratis[]){//Funcion para realizar un filtrado por tematicas
	int i, j, CopiaValorStrcmp, CoincidenciaTematica[10]={0}, CoincidenciaTotal=0;
	char *tecla3, comparacion[20];
	FILE *tema;
	
	do{
		tecla3=(char*)malloc(20*sizeof(char));
		scanf("%s",tecla3);
		if(strcmp(comparacion,tecla3)==0){
			printf("\nPor favor no repita la misma tematica. Ya la hemos almacenado correctamente.");
			printf("\nEscriba a continuacion otra tematica o bien salir si no quiere anadir mas tematicas: \n\n");
		}
		else{
			tema = fopen("peliculas/tematicas.txt", "a");							
		    for(i=0;i<nLineas;i++){
				if(strcmp(Pgratis[i].tematica,tecla3)==0){
		    		fprintf(tema,"%s;%s:%s;%s;%s\n",
					Pgratis[i].titulo,
					Pgratis[i].t.hora,
					Pgratis[i].t.min,
					Pgratis[i].tematica,
					Pgratis[i].year);
					CoincidenciaTematica[j]++;
				}
			}
			CoincidenciaTotal+=CoincidenciaTematica[j];
			fclose(tema);
			CopiaValorStrcmp=strcmp(tecla3,"salir");
			strcpy(comparacion,tecla3);
			free(tecla3);
			
			if(CopiaValorStrcmp){
				if(CoincidenciaTematica[j]==0)
					printf("No hay ninguna categoria como esa o no disponemos de peliculas de dicha categoria\n");
					printf("\nEscriba a continuacion otra tematica o bien salir si no quiere anadir mas tematicas: \n\n");
				}
			}
		j++;
		}while(CopiaValorStrcmp);
		
return CoincidenciaTotal;
}	

void FiltradoDuracion(pelicula Pgratis[],int NPG,char *HoraCompara1,char *HoraCompara2, char *MinutoCompara1,char *MinutoCompara2){
 	int contadorduracion=0, i;
 	
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
 }

void borrar( void ){
	system("cls||clear");
		EscribeNombre();
}


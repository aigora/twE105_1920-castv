#include <stdio.h>
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
typedef struct{//Estructura de registro de usuario
	char nombre[15];
	char password[15];
}usuario;
void ingreso(usuario x){//Función ingreso
	FILE *pf;
  	pf = fopen("registro.txt", "r");
    usuario clave;
    int intentos=0;
    printf("Ingrese nombre de usuario:");
    scanf("%s",clave.nombre);
    printf("Ingrese clave:");
    scanf("%s",clave.password);      
}

int main (){//Programa principal
  EscribeNombre();
  int op1,op2,op3,i;
  char tecla[10];
  usuario registro;
 	FILE *pf;
  	pf = fopen("registro.txt", "a");
  printf("\t¿Dispone de una cuenta CasTV? \n");
  printf("\tPulse 1 si ya esta registrado: \n");
  printf("\tPulse 2 si no tiene cuenta: \n");
  scanf("%d",&op1);

 switch(op1){//El usuario ya está registrado
 	case 1:
 	 do {//Menú, si qiuere salir deberá escribir "salir"
 	 printf("  Menu \n");
 	 printf("  Guía televisiva: 1 \n");
	 printf("  Catalogo: 2 \n");
     printf("  Recomendacion: 3 \n");
	 scanf("%d",&op2);
	
	 switch(op2){
		    case 1://El usuario elige un apartado del menú
		    	//Muestra la emision en directo de los canales TDT
		    	//Aqui iria un menu para elegir el programa
		      break;
		    case 2:
		    	//Muestra el catálogo de películas entero con posibilidad de eleccion autónoma
		    	//Estarán sorteadas por temáticas
		      break;
		    case 3:
		        //Aqui se relizará un filtrado de de gustos para mejor la busqueda y sugerencia
        	break;
		    }
		    printf("Desea repetir el programa? Pulse si\n");
		    scanf("%s",tecla);
		}while (strcmp(tecla,"si")==0);
	break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case 2://El usuario no está registrado
	printf("Pulse 1 si quire registrase o 2 si quiere ver el catalogo: ");
	scanf("%d",&op3);	
	switch(op3){
	case 1://Registro
  	 if (pf==NULL){
                printf ("Error abriendo el fichero");
                return -1;
				}
    else{
	printf("Ingrese nombre de usuario:");
     scanf("%s",registro.nombre);
     printf("Ingrese clave:");
     scanf("%s",registro.password);  
  	 fprintf(pf, "%s;%s\n", registro.nombre, registro.password);
  	 fclose(pf);
  	 return 0;
}
	break;
	case 2://Catálogo
	break;
}
	break;	
}
}


#include <stdio.h>

void main ()
{
  int op1,op2;
  char tecla[10];

  printf("		       CasTV \n");
  printf("	     	Bienvenido \n");
  printf("Tu operador telem�tico de confinza \n");
 //En un futuro aqui se pedira al usuario que introduzca sus datos(nombre completo, edad, fecha de nacimiento,etc)
  printf("�Dispone de una cuenta CasTV? \n");
  printf("pulse 1 si ya est� registrado: \n");
  printf("pulse 2 si no tiene cuenta: \n");
  scanf("%d",&op1);

 switch(op1){//Si esta registrado (opcion1) ya dispone de todas las acciones que permite el programa
 			 
 	case 1: 
 	//while hasta que sea correcto el registro
 	//if...(comprobar el registro)
	 printf("Esciba su nombre de usuario y contrase�a: \n");
 	 //scanf para nombre  y contrae�a
 	 do {
 	 printf("Men� \n");
 	 printf("Gu�a televisiva:1 \n");
	 printf("Cat�logo:2 \n");
     printf("Recomendaci�n:3 \n");
	 scanf("%d",&op2);
		 	  switch(op2)
		    {
		    case 1:
		    	//Muestra la emision en directo de los canales TDT
		    	//Aqui iria un menu para elegir el programa
		      break;
		    case 2:
		    	//Muestra el cat�logo de pel�culas entero con posibilidad de eleccion aut�noma
		    	//Estar�n sorteadas por tem�ticas
		      break;
		    case 3:
		        //Aqui se relizar� un filtrado de de gustos para mejor la busqueda y sugerencia
        	break;
		    }
		    printf("Desea repetir el programa? Pulse 'si'\n");
		    scanf("%s",tecla);
		    _strupr(tecla);
		}while(tecla=="SI");
	break;
	case 2://Si NO est� registrado le permitiremos ver solo el cat�logo
 		   //Aqui iria un menu para elegir el programa
	break;	
 	}
}


#include <stdio.h>
#include <string.h>

typedef struct{
  char hora[3], min[3];//Deben ser char[], dado que al leer con  %[^] se obtiene una cadena de caracteres.
}time;
 
typedef struct{
    time ti, tf;
    char titulo[60];
    char descripcion[300];
}canal;

typedef struct{
    canal c1[30], c2[30], c3[30], c4[30], c5[30];
}dia;


int meteprograma(dia *c)//El paso del argumento debe ser por referencia, con puntero, para que pueda modificar.
{
  FILE *pf;
  int i,nLineas=1;
  char x;
  pf = fopen("domingo/domingo.canal1.txt","r");//Ruta de un dia cualquiera
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
	
    pf = fopen("domingo/domingo.canal1.txt","r");//Ruta de un dia cualquiera
    for(i=0;i<nLineas;i++){
      fscanf(pf, "%[^;];%[^:]:%[^;];%[^:]:%3[^\n]",// Hay que limitar el número de caracteres que se lee con [^\n], y no hace falta poner \n después.
         c->c1[i].titulo,
         c->c1[i].ti.hora,
         c->c1[i].ti.min,
         c->c1[i].tf.hora,
         c->c1[i].tf.min,
         c->c1[i].descripcion);
    }
    return nLineas;
    fclose(pf);            
  }
                
}

 

int main()
{
  dia domingo;
  int i = 0, x;
  FILE *pf;

  x=meteprograma(&domingo);//Paso por referencia
  for (i = 0; i < x ; i++)
    printf("%s \n %s:%s %s:%s %s\n",
       domingo.c1[i].titulo,
       domingo.c1[i].ti.hora,
       domingo.c1[i].ti.min,
       domingo.c1[i].tf.hora,
       domingo.c1[i].tf.min,
       domingo.c1[i].descripcion);

  return 0;   
}


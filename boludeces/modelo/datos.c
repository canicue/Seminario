#include "datos.h"
#include <stdio.h>
#include <stdlib.h>
void conectar(char* nombre)
{

	estado=sqlite3_open("basesita.sqlite",&base);
	printf("estado=%d",estado);

}
void desconectar()
{


}
int crear_tabla(columna** columnas) 
{

}
columna** pedir_datos()
{
columna** columnas;
int i;
int ncols;
printf("Ingrese nro de columnas\n");
scanf("%d",&ncols);
columnas=malloc(sizeof(columna)*ncols);
for(i=0;i<ncols;i++)
{
columnas[i]=malloc(sizeof(columna));
printf("Nombre:\n");
scanf("%s",&columnas[i]->nombre);
}

for(i=0;i<ncols;i++)
{
	printf("%s",&columnas[i]->nombre);

}
return columnas;

}




#include "formularios.h"


CDKMATRIX *formulario_alta(char *tabla)
{

char *error;
conectar(BASE);
char *plantilla="SELECT * FROM '%s' limit 1";
char consulta[255];
sprintf(consulta,plantilla,tabla);
//printf(consulta);
sqlite3_exec(conexion,consulta,call_alta,tabla,&error);
 activateCDKMatrix(matriz, 0);
desconectar();
return matriz;

}

CDKMATRIX *formulario_modificacion(char *tabla,char *columna,char *valor)
{

char *error;
conectar(BASE);
char *plantilla="SELECT * FROM %s WHERE %s='%s'";
char consulta[255];
sprintf(consulta,plantilla,tabla,columna,valor);
//printf(consulta);
sqlite3_exec(conexion,consulta,call_modificacion,tabla,&error);
//printf("%s------------",error);
desconectar();
return matriz;

}
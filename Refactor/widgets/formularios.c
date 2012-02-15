
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
desconectar();
return matriz;

}
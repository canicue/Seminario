#include "preparadas.h"
sqlite3 *conectar(char *base)
{
	sqlite3_open(base,&conexion);	
return conexion;
}
void leer_registros(char *base,char *tabla)
{
		sqlite3_stmt *cons;
char *nombre;
char *sql="SELECT * FROM persona where ?<?";
rc=	sqlite3_prepare(conexion,sql,-1,&cons,NULL);
sqlite3_bind_text(cons,1,"id",-1,0);
sqlite3_bind_int(cons,2,100);
while (sqlite3_step(cons)==SQLITE_ROW) {
		printf("sadf");
	nombre=sqlite3_column_text(cons,1);
printf("%s\n",nombre);


}


}

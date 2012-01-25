//#include <sqlite3.h>
#include "formularios.h"
#include <stdio.h>
#include <cdk.h>
#include "callbacks.h"
//#define set_col(n, width, string)  coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED
//#define set_row(n, string)  rowtitle[n] = "</B/6>" string

/*sqlite3  *conectar()
{
	sqlite3 *db;
	char *base="base.sqlite";
	sqlite3_open(base,&db);

return db;
}*/
void ver_tabla(char *nombre)
{
char *error;
sqlite3 *db=conectar(BASE);
char *plantilla="SELECT * FROM '%s' limit 1";
char consulta[255];
sprintf(consulta,plantilla,nombre);
//printf(consulta);
sqlite3_exec(db,consulta,call_tabla,nombre,&error);
}

void formulario(char *tabla)
{

ver_tabla(tabla);


}/*
void ver_columnas(char *tabla)
{
	char *error;
	int res;
	sqlite3 *db;
	char plantilla[]="PRAGMA table_info(%s)";
	char consulta[255];
//	sprintf(consulta,plantilla,tabla);
	sprintf(consulta,"select * from '%s' limit 1",tabla);
	db=conectar("base.sqlite");
	res=sqlite3_exec(db,consulta,call_columnas,tabla,&error);

}*/
/*int main(int argc, const char *argv[])
{
//		ver_tabla("cliente");
//		columnas("cliente");
formulario("cliente");
formulario("proveedor");
formulario("RMP");
		return 0;
}*/


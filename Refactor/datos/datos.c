#include "datos.h"



#include <stdio.h>
#include <alphalist.h>


#include "datos.h"
sqlite3 *
conectar (char *nombre)
{
  // int err=0;

  sqlite3_open (nombre, &conexion);
  //printf("%d",err);
  return conexion;
//sqlite3_stmt *stmt;


}

void
desconectar ()
{
  sqlite3_close (conexion);

}

void
buscar_registro (char *tabla, char *nombre, char *valor, void *callback,
		 void *extra)
{
  conectar (BASE);
  char consulta[255];
  sprintf (consulta, BUSCAR_REGISTRO, tabla, nombre, valor);
  printf (consulta);
  sqlite3_exec (conexion, consulta, callback, extra, &error);
  desconectar ();

}

void
borrar_registro (char *tabla, char *columna, char *valor)
{




}

void
listar_registros (char *tabla, void *callback, void *extra)
{

  conectar (BASE);
  char consulta[255];
  sprintf (consulta, LISTAR_REGISTROS, tabla);
  sqlite3_exec (conexion, consulta, callback, extra, &error);
  desconectar ();

}

void
ver_tabla (char *nombre, int limite, char *visible, void *callback,
	   void *extra)
{
  conectar (BASE);
  sqlite3_stmt *stmt;
  char consulta[256];
  sprintf (consulta, LISTAR_REGISTROS, nombre);
  sqlite3_exec (conexion, consulta, callback, extra, &error);

  //sqlite3_prepare(conexion, consulta, -1, &stmt, NULL);
  desconectar ();


}

/*static int callback(void *NotUsed, int argc, char **argv, char **azColName){

    printf("%d-------------",argc);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s ", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");
    return 0;
}*/

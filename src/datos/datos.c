#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "datos.h"
#include <stdio.h>
#include <cdk/alphalist.h>

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
//  printf (consulta);
  sqlite3_exec (conexion, consulta, callback, extra, &error);
  desconectar ();

}

int
borrar_registro (char *tabla, char *columna, char *valor, void *callback)
{
  int res = 0;
  conectar (BASE);
  char consulta[512];
  sprintf (consulta, BORRAR_REGISTRO, tabla, columna, valor);
  sqlite3_exec (conexion, consulta, callback, 0, &error);


  res = sqlite3_exec (conexion, consulta, callback, 0, &error);

  desconectar ();
  return res;
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
//  sqlite3_stmt *stmt;
  char consulta[256];
  sprintf (consulta, LISTAR_REGISTROS, nombre);
  sqlite3_exec (conexion, consulta, callback, extra, &error);

  //sqlite3_prepare(conexion, consulta, -1, &stmt, NULL);
  desconectar ();


}

int
modificar_registro (char *tabla, char **columnas, char *identificador,
		    char *valor, char **nuevos, int nro)
{

  conectar (BASE);
  char consulta[1024];
  int res = 0;
  int i;
  char tmp[1024] = "UPDATE %s SET ";
  sprintf (consulta, tmp, tabla);
  for (i = 0; i < nro; i++)
    {
      i == nro - 1 ? sprintf (tmp, "%s='%s' WHERE ", columnas[i],
			      nuevos[i]) : sprintf (tmp, "%s='%s',",
						    columnas[i], nuevos[i]);
      strcat (consulta, tmp);
    }
  sprintf (tmp, "%s='%s'", identificador, valor);
  strcat (consulta, tmp);
  conectar (BASE);
  res = sqlite3_exec (conexion, consulta, NULL, NULL, &error);
  desconectar ();
  return (res);

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
int
guardar_cosa (char *tabla, char **columnas, char **valores, int nro)
{

  int res = 0;
  int i;
  char tmp[1024] = "INSERT INTO %s (";
  char consulta[1024];
  for (i = 0; i < nro; i++)
    {
      strcat (tmp, columnas[i]);
      // strcat(tmp,", ");
      i == nro - 1 ? strcat (tmp, ") VALUES ('") : strcat (tmp, ", ");
    }
  //strcat(tmp,") VALUES (");
  for (i = 0; i < nro; i++)
    {
      strcat (tmp, valores[i]);
      i == nro - 1 ? strcat (tmp, "') ") : strcat (tmp, "','");
    }

  sprintf (consulta, tmp, tabla);
//  endCDK();
//  printf(consulta);
//  exit(0);
  conectar (BASE);
  res = sqlite3_exec (conexion, consulta, NULL, NULL, &error);
  // endCDK ();
  // printf (error);
  // exit (0);

  desconectar ();
  return (res);



}

int
modificar_cosa ()
{
  return 0;
}



#include "formularios.h"

CDKMATRIX *
formulario_alta (char *tabla, PROCESSFN prep)
{

  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM '%s' limit 1";
  char consulta[255];
  sprintf (consulta, plantilla, tabla);
//printf(consulta);
  sqlite3_exec (conexion, consulta, call_alta, tabla, &error);
  setCDKMatrixPreProcess (matriz, (PROCESSFN) prep, 0);
  // activateCDKMatrix (matriz, 0);

  desconectar ();
  return matriz;

}

CDKMATRIX *
formulario_modificacion (char *tabla, char *columna, char *valor,
			 PROCESSFN prep)
{

  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM %s WHERE %s='%s'";
  char consulta[255];
  sprintf (consulta, plantilla, tabla, columna, valor);
//printf(consulta);
  sqlite3_exec (conexion, consulta, call_modificacion, tabla, &error);
//printf("%s------------",error);
  desconectar ();
  char *aa[] = { "asdf" };

  setCDKMatrixPreProcess (matriz, prep, aa);
  return matriz;

}

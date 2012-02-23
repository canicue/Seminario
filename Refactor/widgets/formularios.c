#include "formularios.h"

CDKMATRIX *
formulario_alta (char *tabla, char *identificador, PROCESSFN prep,
		 PROCESSFN post)
{

  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM '%s' ORDER BY %s DESC LIMIT 1";
  char consulta[255];
  sprintf (consulta, plantilla, tabla, identificador);
//printf(consulta);
  sqlite3_exec (conexion, consulta, call_alta, tabla, &error);
//  setCDKMatrixCell(matriz,1,1,(char*)buscar_ultimo(tabla,identificador,call_id));
  setCDKMatrixPreProcess (matriz, (PROCESSFN) prep, 0);
  // activateCDKMatrix (matriz, 0);
  setCDKMatrixPostProcess (matriz, (PROCESSFN) post, 0);
  desconectar ();
  return matriz;

}

CDKMATRIX *
formulario_modificacion (char *tabla, char *columna, char *valor,
			 PROCESSFN prep, PROCESSFN post)
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
  char *aa = copyChar (getCDKMatrixCell (matriz, 1, 1));

  setCDKMatrixPreProcess (matriz, prep, aa);
  setCDKMatrixPostProcess (matriz, (PROCESSFN) post, aa);
  return matriz;

}

#include "formularios.h"
char *tmp[2];			//ajuera tiene que estar esta merda
CDKMATRIX *
formulario_alta (char *tabla, char *identificador, PROCESSFN prep,
		 PROCESSFN post)
{
  int proximo = 0;
  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM '%s' ORDER BY %s DESC LIMIT 1";
  char consulta[255];
//  char *tmp[2];
  sprintf (consulta, plantilla, tabla, identificador);
  tmp[0] = tabla;
  sqlite3_exec (conexion, consulta, call_alta, tmp, &error);
  proximo = atoi (copyChar (getCDKMatrixCell (matriz, 1, 1)));
  tmp[1] = (char *) malloc (sizeof (char *));
  sprintf (tmp[1], "%d", proximo);


  setCDKMatrixPreProcess (matriz, (PROCESSFN) prep, (void *) tmp);

  proximo++;
  setCDKMatrixPostProcess (matriz, (PROCESSFN) post, (void *) tmp);
  desconectar ();
  return matriz;

}

CDKMATRIX *
formulario_modificacion (char *tabla, char *columna, char *valor,
			 PROCESSFN prep, PROCESSFN post)
{

//  char *tmp[2];
  tmp[0] = copyChar (tabla);
  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM %s WHERE %s='%s'";
  char consulta[255];
  sprintf (consulta, plantilla, tabla, columna, valor);
//printf(consulta);
  sqlite3_exec (conexion, consulta, call_modificacion, tmp, &error);
//printf("%s------------",error);
  desconectar ();

  tmp[1] = copyChar (getCDKMatrixCell (matriz, 1, 1));
//  endCDK ();
//  printf ("%s,%s", data[0], data[1]);
//  exit (0);
  //char *aa = copyChar (getCDKMatrixCell (matriz, 1, 1));
  setCDKMatrixPreProcess (matriz, prep, (void *) tmp);
  setCDKMatrixPostProcess (matriz, post, (void *) tmp);
//  setCDKMatrixPreProcess (matriz, prep, aa);
//  setCDKMatrixPostProcess (matriz, (PROCESSFN) post, aa);
  return matriz;

}

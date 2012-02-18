
#include "dialogos.h"


CDKDIALOG *
dialogo_borrado (char *tabla, char *columna, char *valor)
{
  char *error;
  conectar (BASE);
  char *plantilla = "SELECT * FROM %s WHERE %s='%s'";
  char consulta[255];
  sprintf (consulta, plantilla, tabla, columna, valor);
//printf(consulta);
  sqlite3_exec (conexion, consulta, call_borrado, tabla, &error);
//printf("%s------------",error);
  desconectar ();

  return dialogo;

}

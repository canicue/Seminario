#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "listados.h"

CDKSCROLL *
listado (char *tabla, char *columna)
{
  char *algo[] = { "dfdf", "sdf" };
  char *formato = "<C></32>%s<!32>\n";
  char titulo[128];
  sprintf (titulo, formato, tabla);
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  lista_scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 15,
			       titulo, NULL, 0, TRUE, A_REVERSE, TRUE, FALSE);

  ver_tabla (tabla, NULL, columna, call_lista, columna);

  return lista_scroll;




}

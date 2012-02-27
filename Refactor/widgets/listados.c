#include "listados.h"

CDKSCROLL *
listado (CDKSCREEN * pantalla, char *tabla, char *columna)
{
  // char *algo[] = { "dfdf", "sdf" };
  char *formato = "<C></32>%s<!32>\n";
  char titulo[128];
  sprintf (titulo, formato, tabla);
  // initscr ();
  // CDKSCREEN *pantalla = initCDKScreen (stdscr);
  lista_scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 15,
			       titulo, NULL, 0, TRUE, A_REVERSE, TRUE, FALSE);

  ver_tabla (tabla, NULL, columna, call_lista, columna);

  return lista_scroll;




}

void
mostrar_referencias (CDKMATRIX * matriz, char *tabla, char *columna)
{
  char *formato = "<C></32>%s<!32>\n";
  char titulo[128];
  sprintf (titulo, formato, tabla);
  // initscr ();
  // CDKSCREEN *pantalla = initCDKScreen (stdscr);
  lista_scroll = newCDKScroll (ScreenOf (matriz), 2, 2, RIGHT, 10, 15,
			       titulo, NULL, 0, TRUE, A_REVERSE, TRUE, FALSE);

  ver_tabla (tabla, NULL, columna, call_lista, columna);

  int elegido = 0;
  //lista = (CDKSCROLL *) listado (ScreenOf(matriz),tabla,columna);

  moveCDKScroll (lista_scroll, CENTER, CENTER, FALSE, TRUE);
  elegido = activateCDKScroll (lista_scroll, 0);
  setCDKMatrixCell (matriz, matriz->crow, 1,
		    (char *) chtype2Char (lista_scroll->item[elegido]));
  drawCDKMatrix (matriz, TRUE);


}

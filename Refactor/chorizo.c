#include <stdio.h>
#include <curses.h>
#include <cdk/cdk.h>
int
main (int argc, char **argv)
{

  initscr ();
  noecho ();
  curs_set (0);

  CDKSCREEN *ventana = initCDKScreen (stdscr);
  char *palabra = "hola";
  WINDOW *sub = subwin (stdscr, 100, 100, 0, 0);
  waddstr (stdscr, palabra);
  drawLine (stdscr, 8, 10, 5, 10, 1);
  refresh ();
  box (stdscr, 0, 0);
  getch ();
  return 0;
}

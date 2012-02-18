#include<cdk.h>
//BINDFN_PROTO(driver_matriz);
int
driver_matriz (EObjectType cdkType GCC_UNUSED, void *object,
	       void *clientData GCC_UNUSED, chtype input)
{
  char **a;
  printf ("asdfadsf");
  a[0] = "asdf";
  getch ();

  return 0;

//  menu_botones ("insumos");

}

int
main (int argc, const char *argv[])
{
//char *coltitle[10], *rowtitle[10], *mesg[10];
  int colwidth[10], colvalue[10];
  char *titulo = "dios";
  char *rowtitle[] = { "a", "b" };
  char *coltitle[] = { "d", "x" };
  int filas = 1;
  int columnas = 1;
  int vrows = 1;
  int vcols = 1;

  initscr ();

  box (stdscr, 0, 0);
  CDKSCREEN *cdkScreen = initCDKScreen (stdscr);
  CDKMATRIX *matriz;

  matriz = newCDKMatrix (cdkScreen,
			 CENTER,
			 CENTER,
			 filas, columnas, vrows, vcols,
			 titulo, rowtitle, coltitle,
			 colwidth, colvalue,
			 -1, -1, '.', COL, TRUE, FALSE, FALSE);
  setCDKMatrixPreProcess (matriz, driver_matriz, 0);
  activateCDKMatrix (matriz, 0);


  return 0;
}

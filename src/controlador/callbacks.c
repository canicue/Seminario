#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <cdk/cdk.h>
#include <cdk/matrix.h>
#include "callbacks.h"

int
call_alta (void *nombre, int argc, char **argv, char **azColName)
{
  char tmp[255];
  char *formato = "<L></B>%s";
  char *coltitle[argc], *rowtitle[argc];
  int colwidth[argc], colvalue[argc];
  int i = 0;
  char titulo[255];
  CDKSCREEN *pantalla;
  initscr ();
  pantalla = initCDKScreen (stdscr);
  sprintf (titulo, formato, ((char **) nombre)[0]);

  for (i = 0; i < argc; i++)
    {
      sprintf (tmp, formato, azColName[i]);
      rowtitle[i + 1] = (char *) copyChar (tmp);

    }



  set_col (1, 44, titulo);	// habia un 77 pero no anda en netbook
  // set_readonly(1,44,titulo);

  matriz = newCDKMatrix (pantalla,
			 CENTER,
			 CENTER,
			 argc,
			 1,
			 argc,
			 1,
			 "",
			 rowtitle,
			 coltitle,
			 colwidth,
			 colvalue, -1, -1, '.', COL, TRUE, FALSE, FALSE);

  int algo = atoi (copyChar (argv[0]));
  char *temp = (char *) malloc (sizeof (char *));
  sprintf (temp, "%d", ++algo);
  setCDKMatrixCell (matriz, 1, 1, temp);
  return 0;


}


int
call_modificacion (void *nombre, int argc, char **argv, char **azColName)
{
  ((char **) nombre)[1] = argv[0];
  int i;
  call_alta (nombre, argc, argv, azColName);
  for (i = 0; i < argc; i++)
    {
      // i==0?armar_prefijo(nombre,argv[0]):
      //  printf("%s= %s\n",azColName[i],argv[i]) ;
      //setCDKMatrixCell (matriz, i + 1, 1, copia[i]);
      setCDKMatrixCell (matriz, i + 1, 1, argv[i]);

    }
  return 0;
}

int
call_lista (void *nombre, int argc, char **argv, char **azColName)
{

  int tmp, i = 0;
  for (i = 0; i < argc; i++)
    {
      if (!strcmp (((char *) nombre), azColName[i]))
	{

	  tmp = i;

	}
    }


  addCDKScrollItem (lista_scroll, argv[tmp]);

  return 0;

}

int
call_borrado (void *nombre, int argc, char **argv, char **azColName)
{
  char *BORRAR_CANCELAR[] = { "BORRAR", "CANCELAR" };
  initscr ();
  curs_set (0);
  CDKSCREEN *pantalla = initCDKScreen (stdscr);

  dialogo = newCDKDialog (pantalla,
			  CENTER,
			  CENTER,
			  argv, argc, BORRAR_CANCELAR, 2,
			  COLOR_PAIR (2) | A_REVERSE, TRUE, TRUE, FALSE);

}

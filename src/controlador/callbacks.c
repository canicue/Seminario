#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <cdk/cdk.h>
#include <cdk/cdkscreen.h>
#include <cdk/matrix.h>
#include "callbacks.h"
#include "orden_pedido_producto.h"
#include "drivers_post.h"

int
call_alta (void *nombre, int argc, char **argv, char **azColName)
{
  char tmp[255];
  char *formato = "<L></B/32>%s<!32>";
  char *coltitle[argc], *rowtitle[argc];
  int colwidth[argc], colvalue[argc];

  int i = 0;
  //char *titulo="<L></B/5>%s";
  char titulo[255];

  CDKSCREEN *pantalla;
  initscr ();
  pantalla = initCDKScreen (stdscr);
  // CDKMATRIX *matriz;
  sprintf (titulo, formato, ((char **) nombre)[0]);


  for (i = 0; i < argc; i++)
    {
      sprintf (tmp, formato, azColName[i]);
      rowtitle[i + 1] = (char *) copyChar (tmp);

      //        printf(tmp);
      //      set_row(i+1,azColName[i]);
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

	  //     endCDK();
	  //printf("nombre %s",azColName[i]);
	  //    exit(0);
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
  return 0;
}

int
call_cantidad (void *matriz, int argc, char **argv, char **azColName)
{







  CDKMATRIX *mat = (CDKMATRIX *) matriz;
  popupLabel (ScreenOf (mat), azColName, argc);
  CDKMATRIX *otra =
    (CDKMATRIX *) formulario_alta ("Orden_pedido_proveedor",
				   "Orden_pedido_proveedor_id", NULL,
				   driver_orden_pedido_proveedor_post);
  lowerCDKObject (vMATRIX, mat);
  activateCDKMatrix (otra, 0);
  if (otra->exitType == vNORMAL)
    {
      destroyCDKMatrix (otra);
      raiseCDKObject (vMATRIX, mat);
      drawCDKMatrix (mat, TRUE);
    }
  /*  WINDOW *sub=newwin(LINES-5,COLS-10,0,0);
     CDKSCREEN *pantalla=initCDKScreen(sub);
     box(sub,0,0);
     wrefresh(sub);
     char *mesg[5];



     mesg[0] = "<C><#HL(30)>";
     mesg[1] = "<C>This is a Cdk scrolling list";
     mesg[2] = "<C>inside a curses window.";
     mesg[3] = "<C><#HL(30)>";
     newCDKLabel (pantalla, CENTER, 0, mesg, 4, FALSE, FALSE);
     refreshCDKScreen(pantalla);

   */
  // popupLabel(pantalla,argv,argc);


  /*

     CDKMATRIX *mat=(CDKMATRIX* ) matriz;
     //lowerCDKObject(vMATRIX,mat);
     setCDKMatrixCell(mat,1,1,"asdfadsf");
     drawCDKMatrix(mat,FALSE);

     destroyCDKMatrix(mat);


     CDKMATRIX * matriz =
     (CDKMATRIX *) formulario_alta ("Orden_pedido_proveedor",
     "Orden_pedido_proveedor_id", NULL, driver_orden_pedido_proveedor_post);

     activateCDKMatrix (matriz, 0);
     if (matriz->exitType == vNORMAL)
     {

     guardar_matriz (matriz);

     }
     // activateCDKMatrix (matriz, 0);

     destroyCDKMatrix (matriz);


   */






}

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "principal.h"
#include "clientes.h"
#include "proveedores.h"
#include "insumos.h"
#include "producto_terminado.h"
#include "orden_produccion.h"
#include "orden_pedido_producto.h"
#include "orden_pedido_proveedor.h"
#include "RMPS.h"
#include "tecnicos.h"

int selection;
char *buttons[] = { " OK ", " Cancel " };

CDKSCREEN *cdkscreen = 0;

/*
 * This program demonstrates the Cdk buttonbox widget.
 */
void
login ()
{



  char *usuario;
  char *password;
  usuario = pedir_datos ("usuario");
  password = pedir_datos ("password");
  if (validar_usuario (usuario, password))
    {
      endCDK ();
      while (TRUE)
	{
	  entrada ();
	}


    }
  else
    {
      error_login ();
      //   error_login();
      printf ("mal");
    }
  printf ("usuario=%s pass=%s", usuario, password);

}

char *
pedir_datos (char *tipo)
{

  CDKBUTTONBOX *buttonWidget = 0;
  CDKENTRY *entry = 0;

  WINDOW *cursesWin = 0;
  char *info = 0;


  /* Set up CDK. */
  cursesWin = initscr ();
  curs_set (0);
  cdkscreen = initCDKScreen (cursesWin);

  box (cursesWin, 0, 0);
  /* Start color. */
  initCDKColor ();

  /* Create the entry widget. */



  if (strcmp (tipo, "usuario") == 0)
    {
      entry = newCDKEntry (cdkscreen, CENTER, CENTER,
			   "<C>Usuario", "Name ", A_NORMAL, '.', vMIXED,
			   40, 0, 256, TRUE, FALSE);
    }
  else
    {
      entry = newCDKEntry (cdkscreen, CENTER, CENTER,
			   "<C>Contraseña:", "<C>Password:", A_INVIS, '.',
			   vMIXED, 40, 0, 256, TRUE, FALSE);



    }
  if (entry == 0)
    {
      destroyCDKScreen (cdkscreen);
      endCDK ();

      fprintf (stderr, "Cannot create entry-widget\n");
      exit (EXIT_FAILURE);
    }


  /* Create the button box widget. */
  buttonWidget = newCDKButtonbox (cdkscreen,
				  getbegx (entry->win),
				  getbegy (entry->win) + entry->boxHeight - 1,
				  1, entry->boxWidth - 1,
				  0, 1, 2,
				  buttons, 2, A_REVERSE, TRUE, FALSE);
  if (buttonWidget == 0)
    {
      destroyCDKScreen (cdkscreen);
      endCDK ();

      fprintf (stderr, "Cannot create buttonbox-widget\n");
      exit (EXIT_FAILURE);
    }

  /* Set the lower left and right characters of the box. */
  setCDKEntryLLChar (entry, ACS_LTEE);
  setCDKEntryLRChar (entry, ACS_RTEE);
  setCDKButtonboxULChar (buttonWidget, ACS_LTEE);
  setCDKButtonboxURChar (buttonWidget, ACS_RTEE);

  /*
   * Bind the Tab key in the entry field to send a
   * Tab key to the button box widget.
   */
  bindCDKObject (vENTRY, entry, KEY_TAB, entryCB, buttonWidget);

  /* Activate the entry field. */
  drawCDKButtonbox (buttonWidget, TRUE);
  info = copyChar (activateCDKEntry (entry, 0));
  selection = buttonWidget->currentButton;
  if (selection == 1)
    {

      endCDK ();
      exit (0);

    }
  box (cursesWin, 0, 0);
  refreshCDKScreen (cdkscreen);
  /* Clean up. */
  destroyCDKButtonbox (buttonWidget);
  destroyCDKEntry (entry);
  destroyCDKScreen (cdkscreen);
  endCDK ();


  return info;

}

boolean
validar_usuario (char *usuario, char *password)
{

  if (strcmp (usuario, "admin") == 0 && strcmp (password, "admin") == 0)
    {
      return TRUE;
    }
  else
    {

      return FALSE;
    }
}

void
error_login ()
{
  char *buttons[] = { " OK " };
  char *message[10], *mesg[3], temp[100];
  message[0] = "<C>Login Incorrecto";
  message[1] = " ";
  message[2] = "<C>The dialog widget allows the programmer to create";
  message[3] = "<C>a popup dialog box with buttons. The dialog box";
  message[4] =
    "<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>";
  message[5] = "<R>and even be right justified.";
  message[6] = "<L>and left.";
  message[7] = "<L>and left.";
  /*
   *  CDKDIALOG *newCDKDialog (
   *  CDKSCREEN *cdkscreen,
   *  int xpos,
   *  int ypos,
   *  char ** message,
   *  int rows,
   *  char ** buttons,
   *  int buttonCount,
   *  chtype highlight,
   *  boolean separator,
   *  boolean box,
   *  boolean shadow);
   *
   * */
  CDKSCREEN *cdkscreen;
  cdkscreen = initCDKScreen (stdscr);

  CDKDIALOG *question = 0;
  question = newCDKDialog (cdkscreen,
			   CENTER,
			   CENTER,
			   message, 7, buttons, 1,
			   COLOR_PAIR (2) | A_REVERSE, TRUE, TRUE, FALSE);
  printf ("sdf2%d", (int) question);
  if (question == 0)
    {
      /* Shut down Cdk. */
      destroyCDKScreen (cdkscreen);
      endCDK ();

      /* Spit out a message. */
      printf
	("Oops. Can't seem to create the dialog box. Is the window too small?\n");
      exit (EXIT_FAILURE);
    }

  /* Activate the dialog box. */
  selection = activateCDKDialog (question, 0);

  /* Tell them what was selected. */
  if (question->exitType == vESCAPE_HIT)
    {
      mesg[0] = "<C>You hit escape. No button selected.";
      mesg[1] = "", mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 3);
    }
  else if (question->exitType == vNORMAL)
    {
      sprintf (temp, "<C>You selected button #%d", selection);
      mesg[0] = temp;
      mesg[1] = "";
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 3);
    }

  /* Clean up. */
  destroyCDKDialog (question);
  destroyCDKScreen (cdkscreen);

  endCDK ();





}

void
entrada ()
{
  char *opciones[] = { "ADMINISTRATIVA</B>", "TECNICA</B>", "SALIR</B>" };
  //  endCDK();
  initscr ();
  curs_set (0);

  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  initCDKColor ();
  CDKBUTTONBOX *botonera = newCDKButtonbox (pantalla,
					    CENTER,
					    TOP,
					    4, COLS,
					    "<C></32>SELECCIONAR AREA\n</B/!32>",
					    1, 3,
					    opciones, 3, A_REVERSE,
					    TRUE, FALSE);

  int rta = activateCDKButtonbox (botonera, 0);


  if (rta == 1)
    {
      destroyCDKButtonbox (botonera);

      area_tecnica ();
    }

  if (rta == 2)
    {


      destroyCDKScreen (pantalla);

      endCDK ();
      exit (0);

    }
  else
    {
      destroyCDKButtonbox (botonera);
      area_administrativa ();
    }

//    popupLabel(pantalla,opciones,2);
}

static int
entryCB (EObjectType cdktype GCC_UNUSED,
	 void *object GCC_UNUSED, void *clientData, chtype key)
{
  CDKBUTTONBOX *buttonbox = (CDKBUTTONBOX *) clientData;
  injectCDKButtonbox (buttonbox, key);
  return (TRUE);
}

void
area_tecnica ()
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);



  char *opciones[] = { "RMP</B>", "Insumos</B>", "Producto terminado</B>",
    "Orden de producción</B>",
    "Orden de pedido</B>", "Orden pedido proveedor", "Volver</B>"
  };
  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, CENTER, 10, 45,
			     "<C>Menu",
			     opciones, 7, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:
	  destroyCDKScroll (scroll);
	  menu_abm ("RMP", alta_RMP, baja_RMP, mod_RMP);
	  break;
	case 1:

	  destroyCDKScroll (scroll);

	  menu_abm ("INSUMOS", alta_insumo, baja_insumo, mod_insumo);

	  //  popupLabel (pantalla, opciones, 3);


	  //unregisterCDKObject(vSCROLL,scroll);
	  // refreshCDKScreen(cdkScreen);
	  //getch();
	  //           proveedores();
	  //  registerCDKObject(cdkScreen,vSCROLL,scroll);
	  //produccion();
	  break;
	case 2:
	  destroyCDKScroll (scroll);

	  menu_abm ("PRODUCTOS", alta_producto_terminado,
		    baja_producto_terminado, mod_producto_terminado);

	  //  popupLabel (pantalla, opciones, 3);
	  //             tecnicos();
	  //administracion();
	  break;
	case 3:
	  destroyCDKScroll (scroll);
	  menu_abm ("ORDEN PRODUCCION", alta_orden_produccion,
		    baja_orden_produccion, mod_orden_produccion);


	  //popupLabel (pantalla, opciones, 3);
	  //        mvwaddstr(cdkScreen->window,2,2,"dios");
	  // wrefresh(cdkScreen->window);
	  // getch();
	  //           clientes();
	  break;
	case 4:
	  destroyCDKScroll (scroll);
	  menu_abm ("ORDEN PEDIDO", alta_orden_pedido_producto,
		    baja_orden_pedido_producto, mod_orden_pedido_producto);
	  break;

	case 6:
	  // endCDK ();
	  destroyCDKScroll (scroll);
	  break;
	  //  exit (0);
	case 5:
	  destroyCDKScroll (scroll);
	  menu_abm ("ORDEN PEDIDO PROVEEDOR", alta_orden_pedido_proveedor,
		    baja_orden_pedido_proveedor, mod_orden_pedido_proveedor);


	}
    }
  while (elegido != 6);


  // getch ();

}

void
area_administrativa ()
{

  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);



  char *opciones[] =
    { "Proveedores</B>", "Tecnicos</B>", "Clientes</B>", "Volver</B>" };
  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 20,
			     "<C>Menu",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:

	  //  destroyCDKScroll(scroll);

	  //  popupLabel (pantalla, opciones, 3);
	  destroyCDKScroll (scroll);
	  eraseCDKScreen (pantalla);
	  refreshCDKScreen (pantalla);

	  // menu_proveedores ();
	  menu_abm ("PROVEEDORES", alta_proveedor, baja_proveedor,
		    mod_proveedor);
	  break;
	case 1:
	  destroyCDKScroll (scroll);
	  eraseCDKScreen (pantalla);
	  refreshCDKScreen (pantalla);

	  menu_abm ("TECNICOS", alta_tecnico, baja_tecnico, mod_tecnico);

	  //menu_tecnicos ();
	  //popupLabel (pantalla, opciones, 3);

	  break;
	case 2:

	  destroyCDKScroll (scroll);
	  eraseCDKScreen (pantalla);
	  refreshCDKScreen (pantalla);

	  menu_abm ("CLIENTES", alta_cliente, baja_cliente, mod_cliente);
	  // menu_clientes ();
	  //popupLabel (pantalla, opciones, 3);

	  break;
	case 3:

	  destroyCDKScroll (scroll);
	  break;
	  //  exit (0);

	}


    }
  while (elegido != 3);


  // getch ();

}

void
menu_administrativa ()
{


}

void
menu_tecnica ()
{





}

#include <cdk.h>

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
//#include "../widgets/menu.h"
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

  cursesWin = initscr ();
  curs_set (0);
  cdkscreen = initCDKScreen (cursesWin);
  box (cursesWin, 0, 0);
  initCDKColor ();
  if (strcmp (tipo, "usuario") == 0)
    {
      entry = newCDKEntry (cdkscreen, CENTER, CENTER,
			   "<C></32>Usuario", "Name ", A_NORMAL, '.', vMIXED,
			   40, 0, 256, TRUE, FALSE);
    }
  else
    {
      entry = newCDKEntry (cdkscreen, CENTER, CENTER,
			   "<C></32>Contraseña:", "Password:", A_INVIS, '.',
			   vMIXED, 40, 0, 256, TRUE, FALSE);



    }
  if (entry == 0)
    {
      destroyCDKScreen (cdkscreen);
      endCDK ();

      fprintf (stderr, "Cannot create entry-widget\n");
      exit (EXIT_FAILURE);
    }



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

  bindCDKObject (vENTRY, entry, KEY_TAB, entryCB, buttonWidget);


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
  message[0] = "<C></B/32>Login Incorrecto<!B!32>";
  message[1] = "<C></B>";
  message[2] = "<C></B>Mensaje de error";
  message[3] = "<C></B>Mensaje de error";


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
			   message, 4, buttons, 1,
			   COLOR_PAIR (2) | A_REVERSE, TRUE, TRUE, FALSE);
  //printf ("sdf2%d", (int) question);
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

  destroyCDKScreen (cdkscreen);

  destroyCDKDialog (question);
  destroyCDKScreen (cdkscreen);

  endCDK ();

  endCDK ();
  exit (0);
  /* Tell them what was selected. */


  /* Clean up. */






}

void
entrada ()
{
  char *opciones_[] = { "ADMINISTRATIVA</B>", "TECNICA</B>", "SALIR</B>" };
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
					    opciones_, 3, A_REVERSE,
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
  if (rta == 0)
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



  char *opciones_[] = { "RMP</B>", "Insumos</B>", "Producto terminado</B>",
    "Orden de producción</B>",
    "Orden de pedido</B>", "Orden pedido proveedor", "Volver</B>"
  };
  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 45,
			     "<C></B/32>MENU<!32>",
			     opciones_, 7, TRUE, A_REVERSE, TRUE, FALSE);
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
//  destroyCDKScroll(scroll);

  // getch ();

}

void
area_administrativa ()
{

  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);



  char *opciones_[] =
    { "Proveedores</B>", "Tecnicos</B>", "Clientes</B>", "Volver</B>" };
  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 20,
			     "<C></B/32>MENU<!32>",
			     opciones_, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:




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

  //destroyCDKScroll (scroll);
  // getch ();

}

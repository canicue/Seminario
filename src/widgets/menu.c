#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "menu.h"

void
menu_clientes ()
{

  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);




  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C></32>Clientes<!32>",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:
	  destroyCDKScroll (scroll);
	  alta_cliente ();
	  break;
	case 1:
	  destroyCDKScroll (scroll);
	  //popupLabel(pantalla, opciones, 3);
	  baja_cliente (pantalla);
	  break;
	case 2:
	  //  popupLabel (pantalla, opciones, 3);
	  //        mvwaddstr(cdkScreen->window,2,2,"dios");

	  destroyCDKScroll (scroll);
	  mod_cliente (pantalla);
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
menu_proveedores ()
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);




  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C></32>Proveedores<!32>",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);


      switch (elegido)
	{
	case 0:
	  destroyCDKScroll (scroll);
	  alta_proveedor ();



	  break;
	case 1:
	  destroyCDKScroll (scroll);
	  char *hola[] = { "sdfa", "adf" };

	  baja_proveedor (pantalla);


	  // popupLabel(pantalla, opciones, 3);


	  break;
	case 2:
	  destroyCDKScroll (scroll);

	  mod_proveedor (pantalla);

	  //popupLabel(pantalla, opciones, 3);

	  break;
	case 3:

	  destroyCDKScroll (scroll);
	  break;


	}


    }
  while (elegido != 3);
}

void
menu_tecnicos ()
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);




  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C></32>Técnicos<!32>",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);


      switch (elegido)
	{
	case 0:
	  destroyCDKScroll (scroll);
	  alta_tecnico ();



	  break;
	case 1:

	  destroyCDKScroll (scroll);
	  baja_tecnico ();
	  //     popupLabel(pantalla, opciones, 3);

	  break;
	case 2:
	  destroyCDKScroll (scroll);
	  mod_tecnico ();
	  //popupLabel(pantalla, opciones, 3);
	  break;
	case 3:

	  destroyCDKScroll (scroll);
	  break;


	}


    }
  while (elegido != 3);
}


void
menu_abm (char *titulo, void (*alta) (), void (*baja) (void *pantalla),
	  void (*modificacion) (void *pantalla))
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  char title[128];
  char *formato = "<C></32>%s<!32>";
  sprintf (title, formato, titulo);

  CDKSCROLL *scroll;
  int elegido;

  do
    {
      scroll = newCDKScroll (pantalla, CENTER, 2, RIGHT, 10, 35,
			     title,
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);


      switch (elegido)
	{
	case 0:
	  destroyCDKScroll (scroll);
	  alta ();



	  break;
	case 1:

	  destroyCDKScroll (scroll);
	  baja (pantalla);
	  //     popupLabel(pantalla, opciones, 3);

	  break;
	case 2:
	  destroyCDKScroll (scroll);
	  modificacion (pantalla);
	  //popupLabel(pantalla, opciones, 3);

	  break;
	case 3:

	  destroyCDKScroll (scroll);
	  break;


	}


    }
  while (elegido != 3);
}

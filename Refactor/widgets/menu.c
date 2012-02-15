
#include "menu.h"

void menu_clientes(){

    initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);



  
  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C>Menu",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:
            destroyCDKScroll(scroll);
            alta_cliente();
	  

	//  popupLabel (pantalla, opciones, 3);


	  //unregisterCDKObject(vSCROLL,scroll);
	  // refreshCDKScreen(cdkScreen);
	  //getch();
	  //           proveedores();
	  //  registerCDKObject(cdkScreen,vSCROLL,scroll);
	  //produccion();
	  break;
	case 1:
	  //   destroyCDKScroll(scroll);
	  popupLabel (pantalla, opciones, 3);
	  //             tecnicos();
	  //administracion();
	  break;
	case 2:
	  popupLabel (pantalla, opciones, 3);
	  //        mvwaddstr(cdkScreen->window,2,2,"dios");
	  // wrefresh(cdkScreen->window);
	  // getch();
	  //           clientes();
	  break;
	case 3:
	  // endCDK ();
	  destroyCDKScroll (scroll);
	  break;
	  //  exit (0);

	}


    }
  while (elegido != 3);


 // getch ();
}
void menu_proveedores(){   initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);




  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C>Menu",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:
            destroyCDKScroll(scroll);
            alta_cliente();


	//  popupLabel (pantalla, opciones, 3);


	  //unregisterCDKObject(vSCROLL,scroll);
	  // refreshCDKScreen(cdkScreen);
	  //getch();
	  //           proveedores();
	  //  registerCDKObject(cdkScreen,vSCROLL,scroll);
	  //produccion();
	  break;
	case 1:
	  //   destroyCDKScroll(scroll);
	  popupLabel (pantalla, opciones, 3);
	  //             tecnicos();
	  //administracion();
	  break;
	case 2:
	  popupLabel (pantalla, opciones, 3);
	  //        mvwaddstr(cdkScreen->window,2,2,"dios");
	  // wrefresh(cdkScreen->window);
	  // getch();
	  //           clientes();
	  break;
	case 3:
	  // endCDK ();
	  destroyCDKScroll (scroll);
	  break;
	  //  exit (0);

	}


    }
  while (elegido != 3);}
void menu_tecnicos(){   initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);




  CDKSCROLL *scroll;
  int elegido;
  do
    {
      scroll = newCDKScroll (pantalla, 2, 2, RIGHT, 10, 35,
			     "<C>Menu",
			     opciones, 4, TRUE, A_REVERSE, TRUE, FALSE);
      elegido = activateCDKScroll (scroll, 0);
      //refreshCDKScreen(cdkScreen);
      //
      //refresh();

      switch (elegido)
	{
	case 0:
            destroyCDKScroll(scroll);
            alta_cliente();


	//  popupLabel (pantalla, opciones, 3);


	  //unregisterCDKObject(vSCROLL,scroll);
	  // refreshCDKScreen(cdkScreen);
	  //getch();
	  //           proveedores();
	  //  registerCDKObject(cdkScreen,vSCROLL,scroll);
	  //produccion();
	  break;
	case 1:
	  //   destroyCDKScroll(scroll);
	  popupLabel (pantalla, opciones, 3);
	  //             tecnicos();
	  //administracion();
	  break;
	case 2:
	  popupLabel (pantalla, opciones, 3);
	  //        mvwaddstr(cdkScreen->window,2,2,"dios");
	  // wrefresh(cdkScreen->window);
	  // getch();
	  //           clientes();
	  break;
	case 3:
	  // endCDK ();
	  destroyCDKScroll (scroll);
	  break;
	  //  exit (0);

	}


    }
  while (elegido != 3);}
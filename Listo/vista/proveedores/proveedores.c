#include "proveedores.h"

void proveedores()
{

   // endCDK();

    CDKSCREEN *pantalla_proveedores;
    pantalla_proveedores=initCDKScreen(stdscr);
    box(stdscr,0,0);
    refreshCDKWindow(stdscr);


    menu_proveedores(pantalla_proveedores);
  //  char *mensaje[]={"cli0entes","tecagas"};
  //  popupLabel(pantalla_clientes,mensaje,2);

    cdkScreen=pantalla_proveedores;
    refresh();



}






 void alta_proveedor(CDKSCREEN *pantalla){

       char *msg[]={"no","si"};
   WINDOW *subWindow;
   subWindow = newwin (LINES-5, COLS-10, 2, 5);
    cdkScreen = initCDKScreen (subWindow);

   /* Box our window. */
   box (subWindow, ACS_VLINE, ACS_HLINE);
  // raiseCDKObject(vSWINDOW,(void*)subWindow);
   wrefresh (subWindow);
   refreshCDKScreen(cdkScreen);
   getch();










//       char *mensaje[]={"ALTA","CLIENTE"};
 //   popupLabel(pantalla,mensaje,2);


   }
   void baja_proveedor(CDKSCREEN *pantalla)
   {char *mensaje[]={"BAJA","CLIENTE"};
    popupLabel(pantalla,mensaje,2);}



void menu_proveedores(CDKSCREEN *pantalla)

{

/*    WINDOW *scrollwin;
    scrollwin=newwin(20,20,10,10);
    box(scrollwin,0,0);
    mvwaddstr(scrollwin,2,2,"dios");
    wrefresh
            (scrollwin);*/
   // refresh();
    char *opciones[]={"Alta","Baja","Modificacion","Volver"};
CDKSCROLL *scroll;
  int elegido;
do{

scroll=newCDKScroll (pantalla, 2, 2, RIGHT,10, 20,
				     "<C></B>proveedors",
        opciones
				     ,
                                     4,

				     TRUE,
				     A_REVERSE,
				     TRUE,
				     FALSE);
elegido=activateCDKScroll(scroll,0);
//refreshpantalla(cdkScreen);
//
//refresh();

switch(elegido)
{
    case 0:

        alta_proveedor(pantalla);
        break;
    case 1:
      //  baja_proveedor(pantalla);
        break;

    case 2:

          proveedores();
        break;
    case 3:
        cdkScreen=pantalla;
        //refresh();
        refreshCDKScreen(pantalla);

     //
}








}while(elegido!=3);
//getch(); mierda!!!!
}
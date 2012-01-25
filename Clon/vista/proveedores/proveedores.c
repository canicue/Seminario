#include "proveedores.h"
#include "form_prov.h"
#include "../../controlador/listados.h"
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


     curs_set(0);
 //    char *msg[]={"no","si"};
     WINDOW *subWindow;
 //    CDKENTRY *id_prov;

     //   CDKENTRY *nombre_prov;
  //   CDKENTRY *telefono_prov;
 //    CDKENTRY *direccion_prov;
  //   CDKENTRY *mail_prov;
     subWindow = newwin (LINES-5, COLS-10, 2, 5);
     cdkScreen = initCDKScreen (subWindow);
     
     //formulario("proveedor");
      form_prov(cdkScreen);


     /* Box our window. */
     box (subWindow, ACS_VLINE, ACS_HLINE);
  // raiseCDKObject(vSWINDOW,(void*)subWindow);
    wrefresh (subWindow);
    refreshCDKScreen(cdkScreen);
   // getch();

//    id_prov=newCDKEntry(cdkScreen,CENTER, CENTER, "id", "label", A_NORMAL, '.', vMIXED, 4, 0, 256,  TRUE, FALSE);
 //   nombre_prov=newCDKEntry(cdkScreen,CENTER, CENTER, "nombre", "Nombre:", A_NORMAL, '.', vMIXED, 40, 0, 256,  TRUE, FALSE);
  //  direccion_prov=newCDKEntry(cdkScreen,CENTER, CENTER, "direccion", "Nombre:", A_NORMAL, '.', vMIXED, 40, 0, 256,  TRUE, FALSE);
 //   activateCDKEntry(id_prov,0);
  //  refreshCDKScreen(cdkScreen);
 //   activateCDKEntry(nombre_prov,0);
 //   activateCDKEntry(direccion_prov,0);
    






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
				     "<C></B>proveedores",
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
 destroyCDKScroll(scroll);
      //  alta_proveedor(pantalla);

// cdkScreen=initCDKScreen(stdscr);


 CDKMATRIX *mat_prov=formulario("proveedor");
 destroyCDKMatrix(mat_prov);
        break;
    case 1:
destroyCDKScroll(scroll);
    //    listado_proveedores();
  CDKALPHALIST *lista=(CDKALPHALIST*)listados("proveedor");//Otra vez casteo cabron
  activateCDKAlphalist(lista,0);
  destroyCDKAlphalist(lista);
  //  baja_proveedor(pantalla);
        break;
destroyCDKScroll(scroll);
    //    listado_proveedores();
  CDKALPHALIST *lista_prov=(CDKALPHALIST*)listados("proveedor");//Otra vez casteo cabron
  activateCDKAlphalist(lista_prov,0);
  destroyCDKAlphalist(lista_prov);
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
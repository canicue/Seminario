#include "scroll.h"
#include "principal.h"

void menu_scroll(CDKSCREEN *cdkScreen)

{

/*    WINDOW *scrollwin;
    scrollwin=newwin(20,20,10,10);
    box(scrollwin,0,0);
    mvwaddstr(scrollwin,2,2,"dios");
    wrefresh
            (scrollwin);*/
   // refresh();
    char *opciones[]={"Proveedores","Tecnicos","Clientes","salir"};
CDKSCROLL *scroll;
  int elegido;
do{
scroll=newCDKScroll (cdkScreen, 2, 2, RIGHT,10, 20,
				     "<C>Menu",
        opciones
				     ,
                                     4,

				     TRUE,
				     A_REVERSE,
				     TRUE,
				     FALSE);
elegido=activateCDKScroll(scroll,0);
//refreshCDKScreen(cdkScreen);
//
//refresh();

switch(elegido)
{
        case 0:
            produccion();
            break;
        case 1:
            administracion();
            break;
        case 2:
      //        mvwaddstr(cdkScreen->window,2,2,"dios");
    // wrefresh(cdkScreen->window);
    // getch();
          clientes();
        break;
    case 3:
        endCDK();

        exit(0);

}








}while(elegido!=3);
getch();
}

void mostrar_scroll(CDKSCREEN *cdkScreen)
{
    char *lista[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
//    char** items[2];
 //   items[0]="asdf";
  //  items[1]="edfsdaf";
    char *titulo="dios";
    char salir;
    int elegido;
/*
  	CDKSCREEN *	 cdkscreen ,
		int		 xpos ,
		int		 ypos ,
		int		 spos ,
		int		 height ,
		int		 width ,
		char *		 title ,
		char **		 itemList ,
		int		 items ,
		boolean		 numbers ,
		chtype		 highlight ,
		boolean		 Box ,
		boolean		 shadow );
*/
    CDKSCROLL *menucito;
do
    {
    menucito=newCDKScroll(cdkScreen,
                        CENTER,
                         CENTER,
                        RIGHT,
                        10,
                        15,
                        titulo,
                        lista,
                        7,
                        FALSE,
                        A_REVERSE,
                        TRUE,
                        FALSE);
    elegido=activateCDKScroll(menucito,0);
 // destroyCDKScroll (menucito);





    popupLabel(cdkScreen,&lista[elegido],1);

  //  hacer(elegido);
   // break;


} while((salir=(getch())!='q'));
     destroyCDKScroll (menucito);
 //    mostrar_info(cdkScreen);
   // hacer(elegido);
     endCDK();
}
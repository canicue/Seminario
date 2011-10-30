#include "scroll.h"

void menu_scroll()

{

/*    WINDOW *scrollwin;
    scrollwin=newwin(20,20,10,10);
    box(scrollwin,0,0);
    mvwaddstr(scrollwin,2,2,"dios");
    wrefresh
            (scrollwin);*/
   // refresh();
    char *opciones[]={"uno","dos"};
CDKSCROLL *scroll=newCDKScroll (cdkScreen, 2, 2, RIGHT,10, 20,
				     "Scroll",
        opciones
				     ,
                                     2,
			     
				     TRUE,
				     A_REVERSE,
				     TRUE,
				     FALSE);
activateCDKScroll(scroll,0);
refreshCDKScreen(cdkScreen);
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
                        RIGHT,
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
} while((salir=(getch())!='q'));
     destroyCDKScroll (menucito);
     mostrar_info(cdkScreen);
  endCDK();
}
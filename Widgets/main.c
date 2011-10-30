#include <cdk/cdk.h>
#include "interfaz/scroll.h"
#include "interfaz/dialogo.h"
#include "interfaz/info.h"
#include "interfaz/menu.h"






int main (int argc,char** argv)
{
    initscr();
    noecho();
    cbreak();
cdkScreen=initCDKScreen(stdscr);
 
/*

    refresh();
//      WINDOW *scrollwin;
//    scrollwin=newwin(10,10,0,0);
//    box(scrollwin,0,0);

 //   wrefresh(scrollwin);
 //   refresh();
  //  getch();
//    endwin();
   
   waddstr(stdscr,"hoadfd");
   getch();
    curs_set(0);
    box(stdscr,0,0);
 //   WINDOW *v= newwin(50,50,2,2);
  //  waddstr(v,"hola");
   // box(v,0,0);
   // wrefresh(v);
    refreshCDKScreen(cdkScreen);
    getch();
    char* contenido[]={"hola","chau" };
    crear_dialogo(cdkScreen,contenido);

   menu_scroll();
   */

//    mostrar_info(cdkScreen);

  //  menu_scroll();
box(stdscr,0,0);
//refreshCDKScreen(cdkScreen);

mostrar_menu(cdkScreen);
mostrar_scroll(cdkScreen);
    getch();
    printf("hola");
    endCDK();


}


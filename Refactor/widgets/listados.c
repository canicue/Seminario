


#include "listados.h"

CDKSCROLL *listado(char *tabla,char *columna)
{
    char *algo[]={"dfdf","sdf"};
    char *formato="<C></32>%s<!32>";
    initscr();
    CDKSCREEN *pantalla=initCDKScreen(stdscr);
   lista_scroll = newCDKScroll(pantalla, 2, 2, RIGHT, 10, 5,
                "<C></32>Clientes<!32>",
                NULL, NULL, TRUE, A_REVERSE, TRUE, FALSE);

   ver_tabla(tabla,NULL,columna,call_lista,NULL);

   return lista_scroll;




}
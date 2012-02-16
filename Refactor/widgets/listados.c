


#include "listados.h"

CDKSCROLL *listado(char *tabla,char *columna)
{
    char *algo[]={"dfdf","sdf"};
    char *formato="<C></32>%s<!32>\n";
    char titulo[128];
    sprintf(titulo,formato,tabla);
    initscr();
    CDKSCREEN *pantalla=initCDKScreen(stdscr);
   lista_scroll = newCDKScroll(pantalla, 2, 2, RIGHT, 10, 5,
                titulo,
                NULL, NULL, TRUE, A_REVERSE, TRUE, FALSE);

   ver_tabla(tabla,NULL,columna,call_lista,NULL);

   return lista_scroll;




}
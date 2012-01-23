



#include <curses.h>
#include <cdk/cdkscreen.h>
#include "vista/config.h"
extern CDKSCREEN *cdkScreen;
void hacer(int opcion)
{

    switch(opcion)
    {
        case 0:
        waddstr(stdscr,"0000esuuaaa");
        destroyCDKScreen(cdkScreen);
        endCDK();
        exit(0);
        break;
        case 1:
        waddstr(stdscr,"111111esuuaaa");
        break;
    case 2:
        waddstr(stdscr,"222222esuuaaa");
        break;
    case 3:
        waddstr(stdscr,"33333esuuaaa");
        break;
    case 4:
        waddstr(stdscr,"4444444esaaa");
        break;
        case 5:
            waddstr(stdscr,"55555");
            break;
        default:
        waddstr(stdscr,"nada");

    }

}

#include <curses.h>
#include "principal.h"
void entrada()
{
    initscr();
    cdkScreen=initCDKScreen(stdscr);
    box(stdscr,0,0);
    getch();





}
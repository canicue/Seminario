#include <curses.h>
#include <panel.h>
WINDOW *win;
PANEL *panel;
int main(int argc,char** argv)
{
win=initscr();

panel=new_panel(win);
box(win,0,0);
getchar();

}

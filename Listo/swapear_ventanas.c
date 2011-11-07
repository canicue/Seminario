#include <cdk/cdk.h>
#include <curses.h>
int main(int argc, const char *argv[])
{
		initscr();
		noecho();
CDKSCREEN *pantalla,*otra;
WINDOW *subwin;
pantalla=initCDKScreen(stdscr);
box(stdscr,ACS_HLINE,ACS_BTEE);
getch();
subwin=newwin(1,1,20,120) ;
box(subwin,0,0);
refresh();
otra= initCDKScreen(subwin);
eraseCDKScreen(pantalla);
drawCDKScreen(otra);
refreshCDKScreen(otra);
getch();
	return 0;
}

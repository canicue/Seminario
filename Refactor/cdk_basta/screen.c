#include <cdk.h>
#include <curses.h>
int main(int argc, const char *argv[])
{
CDKLABEL *demo;	
char *palabra="hola";
		initscr();
WINDOW *win=newwin(0,0,300,300);
box(win,0,0);
CDKSCREEN *pantalla=initCDKScreen(stdscr);
CDKSCREEN *otra=initCDKScreen(stdscr);
char *label[2];
label[0]="dios";

   demo = newCDKLabel (otra, CENTER, CENTER, palabra, 4, TRUE, TRUE);
//raiseCDKObject();
	box(stdscr,0,0);
	getch();





destroyCDKScreen(pantalla);	
	





	return 0;
}

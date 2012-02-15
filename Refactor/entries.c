#include <cdk/cdk.h>
#include <curses.h>
void crear_entrada(CDKSCREEN *pantalla);

int main(int argc, const char *argv[])
{
		initscr();
		noecho();
		CDKSCREEN *pantalla=initCDKScreen(stdscr);
crear_entrada(pantalla);
//		getch();
		destroyCDKScreen(pantalla);




	return 0;
}
void crear_entrada(CDKSCREEN *pantalla)
{
	char *title="dios";
	char *label="diablo";
	char *xnombre[]={"asdf","asdf","erer","sss"};
	char *pt;
int nro=	lenCharList(xnombre);
	sprintf(pt,"qqq=%d",nro);
	mvwaddnstr(stdscr,12,12,pt,100);
	mvwaddnstr(stdscr,122,12,pt,100);
	getch();
	CDKENTRY *nombre;	
	nombre = newCDKEntry (pantalla, CENTER, CENTER, title, label, A_NORMAL, '.', vMIXED, 40, 0, 256,  TRUE, FALSE); 
	activateCDKEntry(nombre,0);

}

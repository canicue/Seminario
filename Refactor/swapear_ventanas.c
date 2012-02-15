#include <cdk/cdk.h>
#include <curses.h>
void cambiar_ventana()
{





}

void swaper()
{
		char c;
	do{

		switch(c){
			case 'a':
					cambiar_ventana();
				break;
			case 'c':
				break;
			default:
				break;
		
		}
		
		
		
		
			printf("a");	
	
	
		scanf("%c",&c);
	}

	while(c!='q');
getch();
}
int main(int argc, const char *argv[])
{
		swaper();/*
		initscr();
		noecho();
		curs_set(0);
CDKSCREEN *pantalla,*otra;
WINDOW *subwin;
char texto[12]="hola";
pantalla=initCDKScreen(stdscr);
box(stdscr,ACS_HLINE,ACS_BTEE);
getch();
subwin=newwin(LINES-5,COLS-5,2,2) ;
box(subwin,0,0);
refresh();
otra= initCDKScreen(subwin);
mvwaddstr(subwin,4,4,texto);
eraseCDKScreen(pantalla);
drawCDKScreen(otra);
refreshCDKScreen(otra);
getch();

drawCDKScreen(pantalla);
refreshCDKScreen(pantalla);
getch();
*/
	return 0;
}

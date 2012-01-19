#include <cdk.h>
CDKSCREEN *pantalla;
CDKALPHALIST *alphaList;
char *title="Clientesi\n";
char *label="Elija nomas";
char *lista[2]={"asdf","asdf"};
char *palabra;
char temp[123];
char *mesg[7];
int main(int argc, const char *argv[])
{
		initscr();
		noecho();
pantalla=		initCDKScreen(stdscr);
	
 alphaList = newCDKAlphalist (pantalla,CENTER, CENTER, 0, 0, title, label, lista , 2,'_', A_REVERSE, TRUE, FALSE);
 palabra=activateCDKAlphalist(alphaList,0);

  if (alphaList->exitType == vESCAPE_HIT)
	{ 
		mesg[0] = "<C>You hit escape. No word was selected.";
		mesg[1] = "";
		mesg[2] = "<C>Press any key to continue.";
		popupLabel (pantalla, mesg, 3);
											    }
  else if (alphaList->exitType == vNORMAL)
	    { 
	      mesg[0] = "<C>You selected the following";
    	  sprintf (temp, "<C>(%.*s)", (int)(sizeof (temp) - 10), palabra);
		  mesg[1] = temp;
		  mesg[2] = "";
		  mesg[3] = "<C>Press any key to continue.";
		  popupLabel (pantalla, mesg, 4);
		  }

 
 
 getch();
	return 0;
}






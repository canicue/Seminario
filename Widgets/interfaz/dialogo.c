#include "dialogo.h"
CDKDIALOG *crear_dialogo(CDKSCREEN *cdkScreen,char **contenido)
{
    char *buttons[]={"ok","cancel"};
int rows=    sizeof(contenido)/sizeof(void);
    CDKDIALOG *dialogo=newCDKDialog(cdkScreen,3,3,contenido,rows
           ,buttons,2,A_REVERSE,TRUE,TRUE,FALSE);

    /*
    CDKDIALOG *newCDKDialog (
		CDKSCREEN *	 cdkscreen ,
		int		 xPos ,
		int		 yPos ,
		char **		 message ,
		int		 Rows ,
		char **		 buttons ,
		int		 buttonCount ,
		chtype		 highlight ,
		boolean		 separator ,
		boolean		 Box ,
		boolean		 shadow );

*/

;


}
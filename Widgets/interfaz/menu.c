#include "menu.h"
void mostrar_menu(CDKSCREEN *cdkScreen)
{
    int submenusize[0], menuloc[4];
submenusize[0]=0;
menuloc[0]=LEFT;
menuloc[1]=RIGHT;
 static char *menulist[MAX_MENU_ITEMS][MAX_SUB_ITEMS];
 menulist[0][0]="</B>File<!B>"; menulist[0][1] = "</B>Save<!B>";
/*CDKMENU *newCDKMenu (
		CDKSCREEN *	 cdkscreen ,
		char *		 menulist  [MAX_MENU_ITEMS][MAX_SUB_ITEMS],
		int 		 menuitems ,
		int *		 subsize ,
		int *		 menuloc ,
		int		 menuPos ,
		chtype 		 titleattr ,
		chtype 		 subtitleattr );
*/
newCDKMenu(cdkScreen,menulist, 2,submenusize, menuloc,
		      TOP, A_UNDERLINE, A_REVERSE);


}
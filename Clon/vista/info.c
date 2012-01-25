

#include "info.h"

void mostrar_info(CDKSCREEN *cdkScreen) {

    char* buttons[] = {"a", "b"};
    char *title = "dios";
    char* info[] = {"uno", "dos", "tres"};
    viewInfo(cdkScreen, title, info, 3, buttons, 2, FALSE);
    /*int viewInfo (
     *
     *
                    CDKSCREEN *	 screen ,
                    char *		 title ,
                    char **		 info ,
                    int		 size ,
                    char **		 buttons ,
                    int		 buttonCount ,
                    boolean		 interpret );

     */


}

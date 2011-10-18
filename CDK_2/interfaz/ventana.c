
#include "ventana.h"
WINDOW *iniciar_curses()
{
    WINDOW *cursesWin;
    cursesWin=initscr();
    noecho();
    return  cursesWin;


}
void iniciar_cdk(WINDOW *cursesWin)
{
CDKSCREEN *cdkscreen     = 0;
cdkscreen=initCDKScreen(cursesWin);




}
void mostrar_dialogo()
{





}

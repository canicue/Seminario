#include <curses.h>
#include "principal.h"
#include "../vista/scroll.h"
#include "../vista/proveedores/form_prov.h"
#include "../vista/tecnicos/form_tec.h"
#include "../vista/clientes/form_cli.h"

void entrada() {
    initscr();
    cdkScreen = initCDKScreen(stdscr);
    box(stdscr, 0, 0);
    // getch();

    menu_scroll(cdkScreen);
    destroyCDKScreen(cdkScreen);
    endCDK();



}

void probador() {

    CDKSCREEN *pantalla;
    initscr();
    noecho();
    curs_set(0);
    pantalla = initCDKScreen(stdscr);
    //  form_prov(pantalla);
    //   form_tec(pantalla);
    form_cli(pantalla);
}

void produccion() {
    char *mensaje[] = {"tecagas", "tecagas"};
    popupLabel(cdkScreen, mensaje, 2);
}

void administracion() {
    char *buttons[] = {" OK ", " Cancel "};
    int selection;
    char *message[10], *mesg[3], temp[100];
    message[0] = "<C></U>Login Incorrecto";
    message[1] = " ";
    message[2] = "<C>The dialog widget allows the programmer to create";
    message[3] = "<C>a popup dialog box with buttons. The dialog box";
    message[4] = "<C>can contain </B/32>colours<!B!32>, </R>character attributes<!R>";
    message[5] = "<R>and even be right justified.";
    message[6] = "<L>and left.";
    message[7] = "<L>and left.";
    /*
     *  CDKDIALOG *newCDKDialog (
     *  CDKSCREEN *cdkscreen,
     *  int xpos,
     *  int ypos,
     *  char ** message,
     *  int rows,
     *  char ** buttons,
     *  int buttonCount,
     *  chtype highlight,
     *  boolean separator,
     *  boolean box,
     *  boolean shadow);
     *
     * */
    CDKSCREEN *cdkscreen;
    cdkscreen = initCDKScreen(stdscr);
    CDKDIALOG *question = 0;
    question = newCDKDialog(cdkscreen,
            CENTER,
            CENTER,
            message, 7, buttons, 2,
            COLOR_PAIR(2) | A_REVERSE,
            TRUE,
            TRUE,
            FALSE);
    //printf("sdf2%d",(int)question);
    if (question == 0) {
        /* Shut down Cdk. */
        destroyCDKScreen(cdkscreen);
        endCDK();

        /* Spit out a message. */
        printf("Oops. Can't seem to create the dialog box. Is the window too small?\n");
        exit(EXIT_FAILURE);
    }


    /* Activate the dialog box. */

    selection = activateCDKDialog(question, 0);
    question->boxHeight = 800;
    question->boxWidth = 800;
    /* Tell them what was selected. */


    if (question->exitType == vESCAPE_HIT) {
        mesg[0] = "<C>You hit escape. No button selected.";
        mesg[1] = "",
                mesg[2] = "<C>Press any key to continue.";
        popupLabel(cdkscreen, mesg, 3);
    }
    else if (question->exitType == vNORMAL) {
        sprintf(temp, "<C>You selected button #%d", selection);
        mesg[0] = temp;
        mesg[1] = "";
        mesg[2] = "<C>Press any key to continue.";
        popupLabel(cdkscreen, mesg, 3);
    }

    /* Clean up. */
    destroyCDKDialog(question);
    //destroyCDKScreen (cdkscreen);

    //endCDK();




}

/* $Id: buttonbox_ex.c,v 1.18 2005/12/30 09:50:48 tom Exp $ */


#include <string.h>

#include <cdk.h>
#include "login.h"
#include "../controlador/principal.h"
#ifdef HAVE_XCURSES
char *XCursesProgramName = "buttonbox_ex";
#endif
int selection;
char *buttons[] = {" OK ", " Cancel "};
CDKSCREEN *cdkscreen = 0;

/*
 * This program demonstrates the Cdk buttonbox widget.
 */
int login() {
    // CDKparseParams(argc, argv, &params, CDK_MIN_PARAMS);


    char* usuario;
    char* password;
    usuario = pedir_datos("usuario");
    password = pedir_datos("password");
    if (validar_usuario(usuario, password)) {

        entrada();

    } else {
        error_login();
        //   error_login();
        printf("mal");
    }
    printf("usuario=%s pass=%s", usuario, password);
    return 0;
}

char *pedir_datos(char *tipo) {
    /* Declare variables. */
    CDKBUTTONBOX *buttonWidget = 0;
    CDKENTRY *entry = 0;
    //   CDKENTRY *pass       = 0;
    WINDOW *cursesWin = 0;
    char *info = 0;


    /* Set up CDK. */
    cursesWin = initscr();
    cdkscreen = initCDKScreen(cursesWin);

    //   box(cursesWin,0,0);
    /* Start color. */
    initCDKColor();

    /* Create the entry widget. */



    if (strcmp(tipo, "usuario") == 0) {
        entry = newCDKEntry(cdkscreen, CENTER, CENTER,
                "<C>Usuario", "Name ", A_NORMAL, '.', vMIXED,
                40, 0, 256, TRUE, FALSE);
    } else {
        entry = newCDKEntry(cdkscreen, CENTER, CENTER,
                "<C>Contraseña:", "<C>Password:", A_INVIS, '.', vMIXED,
                40, 0, 256, TRUE, FALSE);



    }
    if (entry == 0) {
        destroyCDKScreen(cdkscreen);
        endCDK();

        fprintf(stderr, "Cannot create entry-widget\n");
        exit(EXIT_FAILURE);
    }


    /* Create the button box widget. */
    buttonWidget = newCDKButtonbox(cdkscreen,
            getbegx(entry->win),
            getbegy(entry->win) + entry->boxHeight - 1,
            1, entry->boxWidth - 1,
            0, 1, 2,
            buttons, 2, A_REVERSE,
            TRUE, FALSE);
    if (buttonWidget == 0) {
        destroyCDKScreen(cdkscreen);
        endCDK();

        fprintf(stderr, "Cannot create buttonbox-widget\n");
        exit(EXIT_FAILURE);
    }

    /* Set the lower left and right characters of the box. */
    setCDKEntryLLChar(entry, ACS_LTEE);
    setCDKEntryLRChar(entry, ACS_RTEE);
    setCDKButtonboxULChar(buttonWidget, ACS_LTEE);
    setCDKButtonboxURChar(buttonWidget, ACS_RTEE);

    /*
     * Bind the Tab key in the entry field to send a
     * Tab key to the button box widget.
     */
    bindCDKObject(vENTRY, entry, KEY_TAB, entryCB, buttonWidget);

    /* Activate the entry field. */
    drawCDKButtonbox(buttonWidget, TRUE);
    info = copyChar(activateCDKEntry(entry, 0));
    selection = buttonWidget->currentButton;
    if (selection == 1) {

        endCDK();
        exit(0);

    }
    box(cursesWin, 0, 0);
    refreshCDKScreen(cdkscreen);
    /* Clean up. */
    destroyCDKButtonbox(buttonWidget);
    destroyCDKEntry(entry);
    destroyCDKScreen(cdkscreen);
    endCDK();

    /* Spit out some info. */
    /*   printf ("You typed in (%s) and selected button (%s)\n",
           (info != 0) ? info : "<null>",
           buttons[selection]);
     */
    // freeChar (info);
    return info;
    //   ExitProgram (EXIT_SUCCESS);
}

boolean validar_usuario(char *usuario, char* password) {

    if (strcmp(usuario, "admin") == 0 && strcmp(password, "admin") == 0) {
        return TRUE;
    } else {

        return FALSE;
    }
}

void error_login()
 {
    char *buttons[] = {" OK "};
    char *message[10], *mesg[3], temp[100];
    message[0] = "<C>Login Incorrecto";
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
            message, 7, buttons, 1,
            COLOR_PAIR(2) | A_REVERSE,
            TRUE,
            TRUE,
            FALSE);
    printf("sdf2%d", (int) question);
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

    /* Tell them what was selected. */
    if (question->exitType == vESCAPE_HIT) {
        mesg[0] = "<C>You hit escape. No button selected.";
        mesg[1] = "",
                mesg[2] = "<C>Press any key to continue.";
        popupLabel(cdkscreen, mesg, 3);
    } else if (question->exitType == vNORMAL) {
        sprintf(temp, "<C>You selected button #%d", selection);
        mesg[0] = temp;
        mesg[1] = "";
        mesg[2] = "<C>Press any key to continue.";
        popupLabel(cdkscreen, mesg, 3);
    }

    /* Clean up. */
    destroyCDKDialog(question);
    destroyCDKScreen(cdkscreen);

    endCDK();





}

static int entryCB(EObjectType cdktype GCC_UNUSED,
        void *object GCC_UNUSED,
        void *clientData, chtype key) {
    CDKBUTTONBOX *buttonbox = (CDKBUTTONBOX *) clientData;
    injectCDKButtonbox(buttonbox, key);
    return (TRUE);
}

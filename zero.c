#include "cdk_test.h"
#include "mensajes.h"
CDKSCREEN *cdkscreen;
WINDOW *cursesWin;
CDKDIALOG  *question ;
   char     *buttons[40];
   char     *message[40];
   char     *info[5];
   char     *loginName;
   char     temp[256];
   int      selection;
   char *mesg[5];
static int dialogHelpCB (EObjectType cdktype GCC_UNUSED,
             void *object,
             void *clientData GCC_UNUSED,
             chtype key GCC_UNUSED)
{

   CDKDIALOG *dialog = (CDKDIALOG *) object;

};
   void *object;
int main(int argc, char *argv[])
{

		printf("unoa %s",uno);
		cursesWin=initscr();
		getch();
   CDK_PARAMS params;

   CDKparseParams(argc, argv, &params, CDK_MIN_PARAMS);

   /* Set up CDK. */
   cursesWin = initscr ();
   cdkscreen = initCDKScreen (cursesWin);
	initCDKColor();

      mesg[0] = "<C></U>Help for </U>Who<!U>.";
      mesg[1] = "<C>When this button is picked the name of the current";
      mesg[2] = "<C>user is displayed on the screen in a popup window.";
   buttons[0] = "Who";
   buttons[1] = "Time";
   buttons[2] = "Date";
   buttons[3] = "Quit";
   CDKDIALOG *dialog = (CDKDIALOG *) object;
   question = newCDKDialog (cdkscreen,
                CDKparamValue(&params, 'X', CENTER),
                CDKparamValue(&params, 'Y', CENTER),
                message, 3, buttons, 4, A_REVERSE,
                TRUE,
                CDKparamValue(&params, 'N', TRUE),
                CDKparamValue(&params, 'S', FALSE));

   bindCDKObject (vDIALOG, question, '?', dialogHelpCB, 0);
      selection = activateCDKDialog (question, (chtype *) 0);
	  popupLabel(ScreenOf(dialog),mesg,3);
	return 0;
}

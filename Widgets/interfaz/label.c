#include "label.h"
#include <stdio.h>
 CDKLABEL *crear_label (CDKSCREEN *cdkscreen,char** mensaje, int x, int y)
{
   static char *message[] = {
      "This is a simple label."
      ,"Is it simple enough?"
   };
   CDKLABEL *widget = newCDKLabel (cdkscreen, x,
           y, mensaje, numero_elementos(message), TRUE, TRUE);
   return widget;
}
void demo_label()
{
   /* Declare variables.        */
   CDKSCREEN    *cdkscreen;
   CDKLABEL     *demo;
   WINDOW       *cursesWin;
   char         *mesg[4];

   /* Set up CDK                */
   cursesWin = initscr();
   cdkscreen = initCDKScreen (cursesWin);

   /* Start CDK Colors          */
   initCDKColor();

   /* Set the labels up.        */
   mesg[0] = "<C><#UL><#HL(25)><#UR>";
   mesg[1] = "<C><#VL></R>This text should be boxed.<!R><#VL>";
   mesg[2] = "<C><#LL><#HL(25)><#LR>";
   mesg[3] = "<C>While this is not.";

   /* Declare the labels.       */
   demo = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 4, TRUE, TRUE);

   /* Is the label NULL???      */
   if (demo == (CDKLABEL *)NULL)
   {
      /* Clean up the memory.   */
      destroyCDKScreen (cdkscreen);

      /* End curses...          */
      endCDK();

      /* Spit out a message.    */
      printf ("Oops. Can't seem to create the label. Is the window too small?");
      exit(1);
   }

   /* Draw the CDK screen.      */
   refreshCDKScreen (cdkscreen);
   waitCDKLabel (demo, ' ');

   /* Clean up                  */
   destroyCDKLabel (demo);
   destroyCDKScreen (cdkscreen);
   delwin (cursesWin);
   endCDK();
   exit (0);
}
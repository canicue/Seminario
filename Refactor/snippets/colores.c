       #include <cdk/cdk.h>

       void main()
       {
          CDKSCREEN   *cdkscreen;
          CDKLABEL    *demo;
          WINDOW      *screen;
          char        *mesg[4];

          /* Initialize the Cdk screen.   */
          screen = initscr();
          cdkscreen = initCDKScreen (screen);

          /* Start CDK Colors */
          initCDKColor();

          /* Set the labels up.      */
          mesg[0] = "</31>This line should have a yellow foreground and a cyan background.<!31>";
          mesg[1] = "</05>This line should have a white  foreground and a blue background.<!05>";
          mesg[2] = "</26>This line should have a yellow foreground and a red  background.<!26>";
          mesg[3] = "<C>This line should be set to whatever the screen default is.";

          /* Declare the labels.     */
          demo   = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 4, TRUE, TRUE);

          /* Draw the label          */
          drawCDKLabel (demo, TRUE);
          waitCDKLabel (demo, ' ');

          /* Clean up           */
  destroyCDKLabel (demo);
          destroyCDKScreen (cdkscreen);
          endCDK();
          exit (0);
       }

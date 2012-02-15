 #include <cdk/cdk.h>

       void main()
       {
          CDKSCREEN    *cdkscreen;
          CDKLABEL     *demo;
          WINDOW       *screen;
          char         *mesg[5];

          /* Initialize the Cdk screen.  */
          screen = initscr();
          cdkscreen = initCDKScreen (screen);

          /* Start CDK Colors */
          initCDKColor();

          /* Set the labels up.  */
          mesg[0] = "<R></B/31>This line should have a yellow foreground and a blue background.<!31>";
          mesg[1] = "</U/05>This line should have a white  foreground and a blue background.<!05>";
          mesg[2] = "<B=+>This is a bullet.";
          mesg[3] = "<I=10>This is indented 10 characters.";
          mesg[4] = "<C>This line should be set to whatever the screen default is.";

          /* Declare the labels.  */
          demo = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 5, TRUE, TRUE);

          /* Draw the label */
          drawCDKLabel (demo, TRUE);
          waitCDKLabel (demo, ' ');

          /* Clean up */
          destroyCDKLabel (demo);
          destroyCDKScreen (cdkscreen);
          endCDK();
          exit (0);
}

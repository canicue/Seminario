#include <cdk.h>
#include<curses.h>
void
main ()
{
  CDKSCREEN *cdkscreen;
  CDKLABEL *demo;
  WINDOW *screen;
  char *mesg[4];
  char ch;
  /* Initialize the Cdk screen.        */
  screen = initscr ();
  cdkscreen = initCDKScreen (screen);

  /* Set the labels up.                */
  mesg[0] =
    "</1>This line should have a yellow foreground and a blue background.<!1>";
  mesg[1] =
    "</2>This line should have a white  foreground and a blue background.<!2>";
  mesg[2] =
    "</3>This line should have a yellow foreground and a red  background.<!3>";
  mesg[3] = "<C>This line should be set to whatever the screen default is.";

  printf ("%s\n");
  mvaddstr (10, 10, mesg[0]);
  getch ();
  /* Declare the labels.       */
  demo = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 4, TRUE, TRUE);

  /* Draw the label            */

  /* Clean up                  */


  //                             drawCDKLabel (demo, TRUE);
  //                           waitCDKLabel (demo, ' ');

/*
   while((ch=getch()!='q'))
	{
			printf("%s\n");
			mvaddstr(10,10,mesg[0]);
	switch(ch)
	{
			case 'a':
					exit(0);

   				drawCDKLabel (demo, TRUE);
   				waitCDKLabel (demo, ' ');
				
				break;
			
	
	}
		
	
	}

//   destroyCDKLabel (demo);
   destroyCDKScreen (cdkscreen);
   endCDK();
*/
  exit (0);
}

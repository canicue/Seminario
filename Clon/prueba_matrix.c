

/* $Id: matrix_ex.c,v 1.14 2005/12/26 22:04:35 tom Exp $ */

//#include <cdk_test.h>
#include <cdk/cdk.h>
#ifdef HAVE_XCURSES
char *XCursesProgramName = "matrix_ex";
#endif

/*
 * This program demonstrates the Cdk matrix widget.
 */
int main (int argc, char **argv)
{
   /* Declare local variables. */
   CDKSCREEN *cdkscreen     = 0;
   CDKMATRIX *form_prov    = 0;
   WINDOW *cursesWin        = 0;
   char *title          = 0;
   int rows         = 5;
   int cols         = 1;
   int vrows            = 5;
   int vcols            = 1;
   char *coltitle[10], *rowtitle[10], *mesg[10];
   int colwidth[10], colvalue[10];

 //  CDK_PARAMS params;

 //  CDKparseParams (argc, argv, &params, CDK_MIN_PARAMS);

   /* Set up CDK. */
   cursesWin = initscr();
   cdkscreen = initCDKScreen (cursesWin);

   /* Start CDK Colors. */
   initCDKColor();

   /* Create the horizontal and vertical matrix labels. */
#define set_col(n, width, string) \
   coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED

   set_col(1, 7, "</B/5>Proveedor");
   set_col(2, 7, "</B/33>Lec 1");
   set_col(3, 7, "</B/33>Lec 2");
   set_col(4, 7, "</B/33>Lec 3");
   set_col(5, 1, "</B/7>Flag");

#define set_row(n, string) \
   rowtitle[n] = "</B/8>" string

   set_row(1, "ID");
   set_row(2, "Nombre");
   set_row(3, "Apellido");
   set_row(4, "Correo");
   set_row(5, "Direccion");
   set_row(6, "Course 6");
   set_row(7, "Course 7");
   set_row(8, "Course 8");

   /* Create the title. */
   /* Create the matrix object. */
   form_prov = newCDKMatrix (cdkscreen,
                   CENTER,
                   CENTER,
                  rows, cols, vrows, vcols,
                  title, rowtitle, coltitle,
                  colwidth, colvalue,
                  -1, -1, '.',
                  COL, TRUE,
                  TRUE,
                   FALSE);

   /* Check to see if the matrix is null. */
   if (form_prov == 0)
   {
      /* Clean up. */
      destroyCDKScreen (cdkscreen);
      endCDK();

      /* Print out a little message. */
      printf ("Oops. Can't seem to create the matrix widget. Is the window too small ?\n");
      exit (EXIT_FAILURE);
   }

   /* Activate the matrix. */
   activateCDKMatrix (form_prov, 0);

   /* Check if the user hit escape or not. */
   if (form_prov->exitType == vESCAPE_HIT)
   {
      mesg[0] = "<C>You hit escape. No information passed back.";
      mesg[1] = "",
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 3);
   }
   else if (form_prov->exitType == vNORMAL)
   {
      char temp[80];

      sprintf(temp, "Current cell (%d,%d)", form_prov->crow, form_prov->ccol);
      mesg[0] = "<L>You exited the matrix normally.";
      mesg[1] = temp;
      mesg[2] = "<L>To get the contents of the matrix cell, you can";
      mesg[3] = "<L>use getCDKMatrixCell():";
      mesg[4] = getCDKMatrixCell(form_prov, form_prov->crow, form_prov->ccol);
      mesg[5] = "";
      mesg[6] = "<C>Press any key to continue.";
      popupLabel (cdkscreen, mesg, 7);
   }

   /* Clean up. */
   destroyCDKMatrix (form_prov);
   destroyCDKScreen (cdkscreen);
   endCDK();
   exit (EXIT_SUCCESS);
}

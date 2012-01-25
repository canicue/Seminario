#include "form_cli.h"
void form_cli(CDKSCREEN *cdkScreen)
{
set_col(1, 17, "<L></B/5>Cliente");
     //set_col(1, 7, "<C></B/5>Proveedor");
   // initCDKColor();

       set_row(1, "ID");
       set_row(2, "Nombre");
       set_row(3, "Apellido");
       set_row(4, "Direccion");
       set_row(5, "Telefono");
       set_row(6, "Correo");

   /* Create the title. */
   /* Create the matrix object. */
   matrix_cli = newCDKMatrix (cdkScreen,
                   CENTER,
                   CENTER,
                  filas, columnas, vrows, vcols,
                  titulo, rowtitle, coltitle,
                  colwidth, colvalue,
                  -1, -1, '.',
                  COL, TRUE,
                  FALSE,
                   FALSE);

activateCDKMatrix (matrix_cli, 0);

 if (matrix_cli->exitType == vESCAPE_HIT)
   {
      mesg[0] = "<C>You hit escape. No information passed back.";
      mesg[1] = "",
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkScreen, mesg, 3);
   }
   else if (matrix_cli->exitType == vNORMAL)
   {


 //      char **asa=info_matriz(ScreenOf(matrix_cli));
       
    //   char *asa[]={"dios","diablo"};
   popupLabel(ScreenOf(matrix_cli),(char**)info_matriz(ScreenOf(matrix_cli)),1);
       //info_matriz(ScreenOf(matrix_cli));
   //    char *hola[]={"aca","noes"};
    //   popupLabel(ScreenOf(matrix_cli),hola,2);
       /*
      char temp[80];

      sprintf(temp, "Current cell (%d,%d)", matrix_cli->crow, matrix_cli->ccol);
      mesg[0] = "<L>You exited the matrix normally.";
      mesg[1] = temp;
      mesg[2] = "<L>To get the contents of the matrix cell, you can";
      mesg[3] = "<L>use getCDKMatrixCell():";
      mesg[4] = getCDKMatrixCell(matrix_cli, matrix_cli->crow, matrix_cli->ccol);
      mesg[5] = "";
      mesg[6] = "<C>Press any key to continue.";
      popupLabel (cdkScreen, mesg, 7);*/
   }






}
#include  "form_prov.h"


void form_prov(CDKSCREEN *cdkScreen)
{

  //  filas=5;
   // vrows=5;
    set_col(1, 17, "<L></B/5>Proveedor");
     //set_col(1, 7, "<C></B/5>Proveedor");
   // initCDKColor();

       set_row(1, "ID");
   set_row(2, "Nombre");
   set_row(3, "Apellido");
   set_row(4, "Correo");
   set_row(5, "Direccion");


   /* Create the title. */
   /* Create the matrix object. */
   matrix_prov = newCDKMatrix (cdkScreen,
                   CENTER,
                   CENTER,
                  filas, columnas, vrows, vcols,
                  titulo, rowtitle, coltitle,
                  colwidth, colvalue,
                  -1, -1, '.',
                  COL, TRUE,
                  FALSE,
                   FALSE);

activateCDKMatrix (matrix_prov, 0);

 if (matrix_prov->exitType == vESCAPE_HIT)
   {
      mesg[0] = "<C>You hit escape. No information passed back.";
      mesg[1] = "",
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (cdkScreen, mesg, 3);
      destroyCDKMatrix(matrix_prov);
   }
   else if (matrix_prov->exitType == vNORMAL)
   {
      // matrix_prov->r
      
    //   info_matriz(matrix_prov);

     //  validar_matriz(matrix_prov,cdkScreen);

       destroyCDKMatrix(matrix_prov);
       refreshCDKScreen(cdkScreen);
       refreshCDKScreen((ScreenOf(matrix_prov)));
       /*     char temp[80];

      sprintf(temp, "Current cell (%d,%d)", matrix_prov->crow, matrix_prov->ccol);
      mesg[0] = "<L>You exited the matrix normally.";
      mesg[1] = temp;
      mesg[2] = "<L>To get the contents of the matrix cell, you can";
      mesg[3] = "<L>use getCDKMatrixCell():";
      mesg[4] = getCDKMatrixCell(matrix_prov, matrix_prov->crow, matrix_prov->ccol);
      mesg[5] = "";
      mesg[6] = "<C>Press any key to continue.";
      popupLabel (cdkScreen, mesg, 7);*/
   }






}
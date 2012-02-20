#include <matrix.h>
#include <scroll.h>
#include <buttonbox.h>
#include "drivers.h"
CDKSCROLL *lista;
int
prueba_binding (EObjectType cdkType GCC_UNUSED, void *object,
		void *clientData GCC_UNUSED, chtype input)
{

  CDKMATRIX *mat = (CDKMATRIX *) object;
  char *aa[] = { "asd", "asdf" };
  if (input == (chtype) 'g')
    {
      popupLabel (ScreenOf (mat), aa, 2);

      // getch();
    }

  return 1;

}


int
prueba_preprocess (EObjectType cdkType GCC_UNUSED, void *object,
		   void *clientData GCC_UNUSED, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;


  if (getCDKMatrixRow (matriz) == 2)
    {

      if (input == 'g')
	{

	  endCDK ();
	  printf ("mierda");
	  exit (0);


	}
    }



  return 1;

}


int
driver_borrado (EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype key)
{

  char *mierda[] = { "MIERDA ", "CARAJO" };



  CDKBUTTONBOX *buttonbox = (CDKBUTTONBOX *) clientData;
  popupLabel (ScreenOf (buttonbox), mierda, 2);
  injectCDKButtonbox (buttonbox, key);
  return (TRUE);
}
int 
driver_referencias_insumo(EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype input) {

  CDKMATRIX *matriz = (CDKMATRIX *) object;


  if (getCDKMatrixRow (matriz) == 14)
    {

      if (input == 'g')
	{

	  endCDK ();
	  printf ("mierda");
	  exit (0);


	}
    }



  return 1;

}
int
driver_referencias_producto_terminado(EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype input) {

  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row=getCDKMatrixRow (matriz);
  switch (row)
  {
      case 5:
     lista=(CDKSCROLL*)listado("RMP","producto_id");
    
     moveCDKScroll (
                      lista,
                       CENTER,
                       CENTER,
                      FALSE,
                     TRUE);
 int elegido=activateCDKScroll(lista,0);

 drawCDKMatrix(matriz,TRUE);



          break;
      case 6:
          break;
      case 10:

          break;




  }


  return 1;

}
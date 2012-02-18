#include "proveedores.h"
#include "callbacks.h"
#include "drivers.h"
#include "persistencia.h"
#include <matrix.h>
#include <scroll.h>
#include <matrix.h>
#include <buttonbox.h>
#include <cdk.h>
#include <curdefs.h>

CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
void
alta_proveedor ()
{
  matriz = (CDKMATRIX *) formulario_alta ("proveedor");

  //   activateCDKMatrix(matriz,0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



    }


  destroyCDKMatrix (matriz);

}

void
baja_proveedor ()
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "proveedor_id";
  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado ("proveedor", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("proveedor", "proveedor_id",
					       chtype2Char (lista->item
							    [elegido]));


      botones = newCDKButtonbox (ScreenOf (matriz),
				 getbegx (matriz->win),
				 getbegy (matriz->win) + matriz->boxHeight -
				 1, 1, matriz->boxWidth - 1, 0, 1, 2, boton,
				 2, A_REVERSE, TRUE, FALSE);



      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }
  bindCDKObject (vMATRIX, matriz, KEY_TAB, driver_borrado, botones);
  //activateCDKMatrix(matriz,0);
  drawCDKMatrix (matriz, TRUE);
  int elegido = activateCDKButtonbox (botones, 0);
  //drawCDKButtonbox(botones,TRUE);
  // traverseCDKScreen(ScreenOf(botones));
  // raiseCDKObject(vBUTTONBOX,botones);
  /*   if (matriz->exitType==vNORMAL)
     {



     char *a[]={"asdfsdf"};
     popupLabel(ScreenOf(matriz),a,1);


     } */

  if (elegido == 0)
    {

      exit (0);

    }

  destroyCDKButtonbox (botones);

  destroyCDKMatrix (matriz);
  //   popupLabel(ScreenOf(lista),cosa,1);


}

void
mod_proveedor ()
{

  CDKSCROLL *lista = (CDKSCROLL *) listado ("proveedor", "provedor_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("proveedor", "proveedor_id",
					       chtype2Char (lista->item
							    [elegido]));
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













  destroyCDKMatrix (matriz);






}

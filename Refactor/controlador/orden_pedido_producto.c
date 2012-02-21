
#include "orden_pedido_producto.h"
#include "callbacks.h"
#include "drivers.h"
#include "persistencia.h"
#include <matrix.h>
#include <scroll.h>
#include <matrix.h>
#include <buttonbox.h>
#include <cdk.h>


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_orden_pedido_producto ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("orden_pedido_producto", "orden_pedido_id",
				   driver_orden_pedido_pre);

  //   activateCDKMatrix(matriz,0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



    }
  activateCDKMatrix (matriz, 0);

  destroyCDKMatrix (matriz);

}

void
baja_orden_pedido_producto ()
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "orden_pedido_producto_id";
  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado ("orden_pedido_producto", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("orden_pedido_producto",
					       "orden_pedido_producto_id",
					       chtype2Char (lista->item
							    [elegido]),
					       driver_orden_pedido_pre);


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

  arrepentimiento (matriz, elegido);

  destroyCDKButtonbox (botones);

  destroyCDKMatrix (matriz);
  //   popupLabel(ScreenOf(lista),cosa,1);


}

void
mod_orden_pedido_producto ()
{

  CDKSCROLL *lista =
    (CDKSCROLL *) listado ("orden_pedido_producto", "provedor_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("orden_pedido_producto",
					       "orden_pedido_producto_id",
					       chtype2Char (lista->item
							    [elegido]),
					       driver_orden_pedido_pre);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













  destroyCDKMatrix (matriz);






}




#include "orden_pedido_producto.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include "../widgets/formularios.h"
#include "../widgets/listados.h"
#include <matrix.h>
#include <scroll.h>
#include <matrix.h>
#include <buttonbox.h>
#include <cdk.h>
#include <cdk_util.h>

CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_orden_pedido_producto ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("Orden_pedido_producto",
				   "Orden_pedido_producto_id",
				   driver_orden_pedido_producto_pre,
				   driver_orden_pedido_producto_post);

  int error = 0;
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      validar (matriz);
      error = guardar_matriz (matriz);
      if (error)
	{
	  tratar_error (ScreenOf (matriz), "Cliente");
	}

      destroyCDKMatrix (matriz);
    }
}

void
baja_orden_pedido_producto (CDKSCREEN * pantalla)
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Orden_pedido_Producto_id";
  //char *cosa[1];
  CDKSCROLL *lista =
    (CDKSCROLL *) listado (pantalla, "Orden_pedido_producto", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Orden_pedido_producto",
					       "Orden_pedido_Producto_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       NULL);


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
mod_orden_pedido_producto (CDKSCREEN * pantalla)
{

  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "Orden_pedido_producto",
					    "Orden_pedido_producto_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Orden_pedido_producto",
					       "Orden_pedido_producto_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]),
					       driver_orden_pedido_producto_pre,
					       driver_orden_pedido_producto_post);
      activateCDKMatrix (matriz, 0);
      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);
	  validar (matriz);
	  if (res)
	    {
	      tratar_error (ScreenOf (matriz), "Cliente");

	    }
	  destroyCDKMatrix (matriz);
	}
    }

}

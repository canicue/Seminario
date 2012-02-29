#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "orden_produccion.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include <cdk/buttonbox.h>
#include <cdk/scroll.h>
#include <cdk/matrix.h>
#include <cdk/buttonbox.h>
#include <cdk/cdk.h>


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_orden_produccion ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("Orden_produccion", "Orden_produccion_id",
				   driver_orden_produccion_pre,
				   driver_orden_produccion_post);

  int error = 0;
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);

      error = guardar_matriz (matriz);


    }
  if (error)
    {
      tratar_error (ScreenOf (matriz), "Orden_produccion");
    }

  activateCDKMatrix (matriz, 0);
  destroyCDKMatrix (matriz);

}

void
baja_orden_produccion (CDKSCREEN * pantalla)
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Orden_produccion_id";
  // char *cosa[1];
  CDKSCROLL *lista =
    (CDKSCROLL *) listado (pantalla, "Orden_produccion", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Orden_produccion",
					       columna,
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
mod_orden_produccion (CDKSCREEN * pantalla)
{

  CDKSCROLL *lista =
    (CDKSCROLL *) listado (pantalla, "Orden_produccion", "provedor_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Orden_produccion",
					       "Orden_produccion_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       NULL);
      activateCDKMatrix (matriz, 0);

      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);


	}
      if (res)
	{
	  tratar_error (ScreenOf (matriz), "Orden_produccion");

	}


    }













  destroyCDKMatrix (matriz);






}

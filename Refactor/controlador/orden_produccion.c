#include "orden_produccion.h"
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
alta_orden_produccion ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("Orden_produccion", "Orden_produccion_id",
				   NULL, driver_orden_produccion_post);

  //   activateCDKMatrix(matriz,0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



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

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













  destroyCDKMatrix (matriz);






}

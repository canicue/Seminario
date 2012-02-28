#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "proveedores.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include <cdk/buttonbox.h>
#include <cdk/scroll.h>
#include <cdk/buttonbox.h>
#include <cdk/matrix.h>
#include <cdk/cdk.h>


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_proveedor ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("proveedor", "proveedor_id",
				   driver_proveedores_pre,
				   driver_proveedores_post);

  activateCDKMatrix (matriz, 0);
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
							    [elegido]), NULL,
					       NULL);


      botones = newCDKButtonbox (ScreenOf (matriz),
				 getbegx (matriz->win),
				 getbegy (matriz->win) + matriz->boxHeight -
				 1, 1, matriz->boxWidth - 1, 0, 1, 2, boton,
				 2, A_REVERSE, TRUE, FALSE);

    }

  bindCDKObject (vMATRIX, matriz, KEY_TAB, driver_borrado, botones);
  drawCDKMatrix (matriz, TRUE);
  int elegido = activateCDKButtonbox (botones, 0);

  arrepentimiento (matriz, elegido);

  destroyCDKButtonbox (botones);

  destroyCDKMatrix (matriz);


}

void
mod_proveedor ()
{
  char *columna = "proveedor_id";
  lista = (CDKSCROLL *) listado ("proveedor", columna);
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("proveedor", columna,
					       chtype2Char (lista->item
							    [elegido]),
					       driver_proveedores_pre,
					       driver_proveedores_post);
      activateCDKMatrix (matriz, 0);


    }













  destroyCDKMatrix (matriz);






}

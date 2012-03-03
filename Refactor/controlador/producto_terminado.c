#include "producto_terminado.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include  "../widgets/formularios.h"
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
alta_producto_terminado ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("Producto_terminado",
				   "Producto_terminado_id",
				   driver_producto_terminado_pre,
				   driver_producto_terminado_post);
  char *msg = "Seleccione archivo...";
  setCDKMatrixCell (matriz, 7, 1, msg);
  setCDKMatrixCell (matriz, 8, 1, msg);
  //   activateCDKMatrix(matriz,0);
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
baja_producto_terminado (CDKSCREEN * pantalla)
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Producto_terminado_id";
  // char *cosa[1];
  CDKSCROLL *lista =
    (CDKSCROLL *) listado (pantalla, "Producto_terminado", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Producto_terminado",
					       "Producto_terminado_id",
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
mod_producto_terminado (CDKSCREEN * pantalla)
{

  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "Producto_terminado",
					    "Producto_terminado_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Producto_terminado",
					       "Producto_terminado_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       NULL);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













  destroyCDKMatrix (matriz);






}

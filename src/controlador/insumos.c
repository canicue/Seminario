#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "insumos.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include <cdk/buttonbox.h>
#include <cdk/scroll.h>
#include <cdk/buttonbox.h>
#include <cdk/cdk.h>



CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_insumo ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("insumo", "IR", driver_insumo_pre,
				   driver_insumos_post);

  //   activateCDKMatrix(matriz,0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



    }
  activateCDKMatrix (matriz, 0);

  destroyCDKMatrix (matriz);

}

void
baja_insumo ()
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "IR";
  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado ("insumo", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("insumo", "IR",
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
mod_insumo ()
{

  CDKSCROLL *lista = (CDKSCROLL *) listado ("insumo", "IR");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("insumo", "IR",
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       NULL);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }


  destroyCDKMatrix (matriz);






}

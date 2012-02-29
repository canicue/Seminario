
#include "RMPS.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include <matrix.h>
#include <scroll.h>
#include <matrix.h>
#include <buttonbox.h>
#include <cdk.h>
#include <cdk_util.h>
#include "../widgets/listados.h"


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_RMP ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("RMP", "Producto_id", driver_RMP_pre,
				   driver_RMP_post);
//  setear_id (matriz);
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);

    }

  // activateCDKMatrix (matriz, 0);
  destroyCDKMatrix (matriz);

}

void
baja_RMP (CDKSCREEN * pantalla)
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Producto_id";
  // char *cosa[1];
  lista = (CDKSCROLL *) listado (pantalla, "RMP", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("RMP", "Producto_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL);
      botones =
	newCDKButtonbox (ScreenOf (matriz), getbegx (matriz->win),
			 getbegy (matriz->win) + matriz->boxHeight - 1, 1,
			 matriz->boxWidth - 1, 0, 1, 2, boton, 2, A_REVERSE,
			 TRUE, FALSE);
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
mod_RMP (CDKSCREEN * pantalla)
{
  char *columna = "Producto_id";
  lista = (CDKSCROLL *) listado (pantalla, "RMP", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("RMP", columna,
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       driver_RMP_post);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);


      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);


	}
      if (res)
	{
	  tratar_error (ScreenOf (matriz), "RMP");

	}


    }

  destroyCDKMatrix (matriz);

}

void
validar_cantidad (CDKMATRIX * matriz)
{
  char *producto_id;
  char *cantidad;
  producto_id = copyChar (getCDKMatrixCell (matriz, 3, 1));
  cantidad = copyChar (getCDKMatrixCell (matriz, 4, 1));
  char *dos[2];
  dos[0] = producto_id;

  buscar_registro ("RMP", "Producto_id", producto_id, call_cantidad, matriz);
  //   popupLabel(ScreenOf(matriz),dos,2);

}

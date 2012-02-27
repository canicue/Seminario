#include "proveedores.h"
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
alta_proveedor ()
{
  matriz =
    (CDKMATRIX *) formulario_alta ("Proveedor", "Proveedor_id",
				   driver_proveedores_pre,
				   driver_proveedores_post);
  int e = 0;
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {


      e = guardar_matriz (matriz);


    }
  if (e)
    {
      tratar_error (ScreenOf (matriz), "Proveedor");
    }

  destroyCDKMatrix (matriz);

}

void
baja_proveedor (CDKSCREEN * pantalla)
{

  char *boton[] = { "BORRAR", "CANCELAR" };
  // popupLabel(pantalla,boton,2);
  char *columna = "Proveedor_id";


  // popupLabel(pantalla,boton,2);

  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "Proveedor", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Proveedor", "Proveedor_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       driver_proveedores_post);


      botones = newCDKButtonbox (ScreenOf (matriz),
				 getbegx (matriz->win),
				 getbegy (matriz->win) + matriz->boxHeight -
				 1, 1, matriz->boxWidth - 1, 0, 1, 2, boton,
				 2, A_REVERSE, TRUE, FALSE);





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
mod_proveedor (CDKSCREEN * pantalla)
{
  char *columna = "Proveedor_id";
  lista = (CDKSCROLL *) listado (pantalla, "Proveedor", columna);
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Proveedor", columna,
					       (char *)
					       chtype2Char (lista->item
							    [elegido]),
					       driver_proveedores_pre,
					       driver_proveedores_post);

      destroyCDKScroll (lista);
      refresh ();

      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);


	}
      if (res)
	{
	  tratar_error (ScreenOf (matriz), "Proveedor");

	}


    }

  destroyCDKMatrix (matriz);

}

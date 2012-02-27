#include "clientes.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "../widgets/formularios.h"
#include "../widgets/listados.h"
#include <matrix.h>
#include <scroll.h>
#include <cdk/scroll.h>


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;

void
alta_cliente ()
{
  int error = 0;
  CDKMATRIX *matriz =
    (CDKMATRIX *) formulario_alta ("Cliente", "Cliente_id", NULL,
				   driver_clientes_post);
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      error = guardar_matriz (matriz);



    }

  if (error)
    {
      tratar_error (ScreenOf (matriz), "Cliente");

    }

  destroyCDKMatrix (matriz);

  //



}

void
baja_cliente (CDKSCREEN * pantalla)
{

//  CDKSCROLL *lista = (CDKSCROLL *) listado ("Cliente", "Cliente_id");
  // activateCDKScroll (lista, 0);
  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Cliente_id";
  //char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "Cliente", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Cliente", "Cliente_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       driver_clientes_post);


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
mod_cliente (CDKSCREEN * pantalla)
{
//  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla,"Cliente", "Cliente_id");
//  activateCDKScroll (lista, 0);

  char *columna = "Cliente_id";
  lista = (CDKSCROLL *) listado (pantalla, "Cliente", columna);
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Cliente", columna,
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       driver_clientes_post);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }

  destroyCDKMatrix (matriz);


}

/*
 char *columna = "Proveedor_id";
  lista = (CDKSCROLL *) listado (pantalla,"Proveedor", columna);
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Proveedor", columna,
					       (char*)chtype2Char (lista->item
							    [elegido]),
					       driver_proveedores_pre,
					       driver_proveedores_post);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }

  destroyCDKMatrix (matriz);

 */

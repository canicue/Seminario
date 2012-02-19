#include "clientes.h"
#include "drivers.h"
#include <matrix.h>
#include <scroll.h>

CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
void
alta_cliente ()
{
  int error;
  CDKMATRIX *matriz = (CDKMATRIX *) formulario_alta ("cliente");
  // setCDKMatrixPreProcess(matriz,prueba_binding,0);
  if (matriz->exitType == vNORMAL)
    {

      error = guardar_matriz (matriz);



    }

  if (error)
    {
      tratar_error (ScreenOf (matriz), "cliente");

    }
  bindCDKObject (vMATRIX, matriz, 'g', prueba_binding, 0);

  activateCDKMatrix (matriz, 0);

}

void
baja_cliente ()
{
//  CDKSCROLL *lista = (CDKSCROLL *) listado ("cliente", "cliente_id");
  // activateCDKScroll (lista, 0);


  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "cliente_id";
  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado ("cliente", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("cliente", "cliente_id",
					       chtype2Char (lista->item
							    [elegido]));


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
mod_cliente ()
{
  CDKSCROLL *lista = (CDKSCROLL *) listado ("cliente", "cliente_id");
  activateCDKScroll (lista, 0);

}

#include "clientes.h"
#include "drivers.h"
#include <matrix.h>
#include <scroll.h>
#include <ncursesw/ncurses.h>

CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
int
pruebab (EObjectType cdkType GCC_UNUSED, void *object,
	 void *clientData GCC_UNUSED, chtype input)
{


  exit (1);

  return 1;


}

void
alta_cliente ()
{
  int error;
  CDKMATRIX *matriz = (CDKMATRIX *) formulario_alta ("cliente", NULL);
  setCDKMatrixPreProcess (matriz, pruebab, 0);
  bindCDKObject (vMATRIX, matriz, '?', pruebab, 0);
  if (matriz->exitType == vNORMAL)
    {

      error = guardar_matriz (matriz);



    }

  if (error)
    {
      tratar_error (ScreenOf (matriz), "cliente");

    }



  //

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
							    [elegido]), NULL);


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

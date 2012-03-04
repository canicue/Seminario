
#include "RMPS.h"
#include "callbacks.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
//#include <matrix.h>
//#include <scroll.h>
//#include <matrix.h>
//#include <buttonbox.h>
#include <cdk.h>
#include <cdk_util.h>
#include <cdk/cdk.h>
#include "../widgets/listados.h"
#include "orden_pedido_proveedor.h"


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_RMP ()
{
  int error = 0;
  matriz =
    (CDKMATRIX *) formulario_alta ("RMP", "Producto_id", driver_RMP_pre,
				   driver_RMP_post);
//  setear_id (matriz);

  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      validar (matriz);
      error = guardar_matriz (matriz);
      if (error)
	{
	  tratar_error (ScreenOf (matriz),"RMP");
	}

      destroyCDKMatrix (matriz);
    }

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
							    [elegido]),
					       driver_RMP_pre,
					       driver_RMP_post);
      activateCDKMatrix (matriz, 0);
      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);
	  validar (matriz);
	  if (res)
	    {
	      tratar_error (ScreenOf (matriz), "RMP");

	    }
	  destroyCDKMatrix (matriz);
	}
    }

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
  int condicion=1;
  if(condicion)
  {
      int rta=0;
      char *argv[5];
      argv[0]="<C>Generar Pedido";
      argv[1]="<C>La cantidad es insuficiente";
      argv[2]="<C>Desea realizar un pedido?";
  char *PEDIR_CANCELAR[] = { "PEDIR", "CANCELAR" };
 
 CDKDIALOG *dialogo = newCDKDialog (ScreenOf(matriz),
			  CENTER,
			  CENTER,
			  argv, 3, PEDIR_CANCELAR, 2,
			  COLOR_PAIR (2) | A_REVERSE, TRUE, TRUE, FALSE);

  rta=activateCDKDialog(dialogo,0);
 

  if(rta==0)
  {
   alta_orden_pedido_proveedor();
      


  }
   if(rta==1)
  {
   borrar_matriz(matriz);
  }
  destroyCDKMatrix(matriz);
  destroyCDKDialog(dialogo);
      /*
 
 // popupLabel (ScreenOf (mat), azColName, argc);
  CDKMATRIX *otra = (CDKMATRIX *) formulario_alta ("Orden_pedido_proveedor",
						   "Orden_pedido_proveedor_id",
						   driver_orden_pedido_proveedor_pre,
						   driver_orden_pedido_proveedor_post);
        desconectar();
  lowerCDKObject (vMATRIX, matriz);
  activateCDKMatrix (otra, 0);
  int error=0;
  if (otra->exitType == vNORMAL)
    {
      validar(otra);
      error=guardar_matriz(otra);
      if(error)
      {tratar_error(ScreenOf(otra),"Orden_pedido_proveedor");}
      destroyCDKMatrix (otra);
      raiseCDKObject (vMATRIX, matriz);
      drawCDKMatrix (matriz, TRUE);
  //    activateCDKMatrix(mat,0);

  }

*/

  }
//  buscar_registro ("RMP", "Producto_id", producto_id, call_cantidad, matriz);
  //   popupLabel(ScreenOf(matriz),dos,2);

}

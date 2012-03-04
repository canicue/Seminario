#include "tecnicos.h"
#include "drivers_pre.h"
#include "drivers_post.h"
#include "persistencia.h"
#include "../widgets/formularios.h"
#include "../widgets/listados.h"
#include <scroll.h>
#include <cdk_util.h>


CDKMATRIX *matriz;
CDKBUTTONBOX *botones;
CDKSCROLL *lista;
void
alta_tecnico ()
{

  matriz =
    (CDKMATRIX *) formulario_alta ("Tecnico", "Tecnico_id",
				   driver_tecnicos_pre, driver_tecnicos_post);
//  setear_id (matriz);

  int error = 0;
  activateCDKMatrix (matriz, 0);
  if (matriz->exitType == vNORMAL)
    {

      validar (matriz);
      error = guardar_matriz (matriz);
      if (error)
	{
	  tratar_error (ScreenOf (matriz), "Tecnico");
	}

      destroyCDKMatrix (matriz);
    }

}

void
baja_tecnico (CDKSCREEN * pantalla)
{
//  CDKSCROLL *lista = (CDKSCROLL *) listado ("Tecnico", "Tecnico_id");
//  activateCDKScroll (lista, 0);

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "Tecnico_id";
//  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "Tecnico", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Tecnico", "Tecnico_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       driver_tecnicos_post);


      botones = newCDKButtonbox (ScreenOf (matriz),
				 getbegx (matriz->win),
				 getbegy (matriz->win) + matriz->boxHeight -
				 1, 1, matriz->boxWidth - 1, 0, 1, 2, boton,
				 2, A_REVERSE, TRUE, FALSE);



      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }
  bindCDKObject (vMATRIX, matriz, KEY_TAB, driver_borrado, botones);
  
  drawCDKMatrix (matriz, TRUE);
  int elegido = activateCDKButtonbox (botones, 0);
  arrepentimiento (matriz, elegido);
  destroyCDKButtonbox (botones);
  destroyCDKMatrix (matriz);

}

void
mod_tecnico (CDKSCREEN * pantalla)
{



  lista = (CDKSCROLL *) listado (pantalla, "Tecnico", "Tecnico_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("Tecnico", "Tecnico_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]),
					       driver_tecnicos_pre,
					       driver_tecnicos_post);
      activateCDKMatrix (matriz, 0);
      int res = 0;
      if (matriz->exitType == vNORMAL)
	{
	  res = modificar_matriz (matriz);
	  validar (matriz);
	  if (res)
	    {
	      tratar_error (ScreenOf (matriz), "Tecnico");

	    }
	  destroyCDKMatrix (matriz);
	}
    }

}

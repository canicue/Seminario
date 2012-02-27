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
    (CDKMATRIX *) formulario_alta ("tecnico", "tecnico_id", NULL,
				   driver_tecnicos_post);
//  setear_id (matriz);

  activateCDKMatrix (matriz, 0);

  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



    }
  // activateCDKMatrix (matriz, 0);

  destroyCDKMatrix (matriz);


  //activateCDKMatrix(matriz,0);

}

void
baja_tecnico (CDKSCREEN * pantalla)
{
//  CDKSCROLL *lista = (CDKSCROLL *) listado ("tecnico", "tecnico_id");
//  activateCDKScroll (lista, 0);

  char *boton[] = { "BORRAR", "CANCELAR" };
  char *columna = "tecnico_id";
//  char *cosa[1];
  CDKSCROLL *lista = (CDKSCROLL *) listado (pantalla, "tecnico", columna);
  activateCDKScroll (lista, 0);
  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("tecnico", "tecnico_id",
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
  //activateCDKMatrix(matriz,0);
  drawCDKMatrix (matriz, TRUE);
  int elegido = activateCDKButtonbox (botones, 0);
  //drawCDKButtonbox(botones,TRUE);
  // traverseCDKScreen(ScreenOf(botones));
  // raiseCDKObject(vBUTTONBOX,botones);
  /*   if (matriz->exitType==vNORMAL)
     {



     char *a[]={"asdfsdf"};
     popupLabel(ScreenOf(matriz),a,1);


     } */

  arrepentimiento (matriz, elegido);
  destroyCDKButtonbox (botones);

  destroyCDKMatrix (matriz);
  //   popupLabel(ScreenOf(lista),cosa,1);








}

void
mod_tecnico (CDKSCREEN * pantalla)
{
  // CDKSCROLL *lista = (CDKSCROLL *) listado ("tecnico", "tecnico_id");
//  activateCDKScroll (lista, 0);

  lista = (CDKSCROLL *) listado (pantalla, "tecnico", "tecnico_id");
  activateCDKScroll (lista, 0);

  if (lista->exitType == vNORMAL)
    {
      int elegido = getCDKScrollCurrentItem (lista);
      matriz =
	(CDKMATRIX *) formulario_modificacion ("tecnico", "tecnico_id",
					       (char *)
					       chtype2Char (lista->item
							    [elegido]), NULL,
					       NULL);
      activateCDKMatrix (matriz, 0);

      //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













  destroyCDKMatrix (matriz);







}

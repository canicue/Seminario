#include "tecnicos.h"
#include <scroll.h>
#include <matrix.h>

void
alta_tecnico ()
{
  CDKMATRIX *matriz = (CDKMATRIX *) formulario_alta ("tecnico");

  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);



    }


  destroyCDKMatrix (matriz);


  //activateCDKMatrix(matriz,0);

}

void
baja_tecnico ()
{
  CDKSCROLL *lista = (CDKSCROLL *) listado ("tecnico", "tecnico_id");
  activateCDKScroll (lista, 0);

}

void
mod_tecnico ()
{
  CDKSCROLL *lista = (CDKSCROLL *) listado ("tecnico", "tecnico_id");
  activateCDKScroll (lista, 0);

}

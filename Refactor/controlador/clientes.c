

#include "clientes.h"
#include "drivers.h"

#include <matrix.h>
#include <scroll.h>
void
alta_cliente ()
{
  CDKMATRIX *matriz = (CDKMATRIX *) formulario_alta ("cliente");
  // setCDKMatrixPreProcess(matriz,prueba_binding,0);
  if (matriz->exitType == vNORMAL)
    {

      guardar_matriz (matriz);

    }


  bindCDKObject (vMATRIX, matriz, 'g', prueba_binding, 0);

  activateCDKMatrix (matriz, 0);

}

void
baja_cliente ()
{
  CDKSCROLL *lista = (CDKSCROLL *) listado ("cliente", "cliente_id");
  activateCDKScroll (lista, 0);
}

void
mod_cliente ()
{
  CDKSCROLL *lista = (CDKSCROLL *) listado ("cliente", "cliente_id");
  activateCDKScroll (lista, 0);

}

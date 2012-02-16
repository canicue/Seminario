

#include "clientes.h"
#include <matrix.h>
#include <scroll.h>
void alta_cliente(){
    CDKMATRIX *matriz=(CDKMATRIX*)formulario_alta("cliente");

    activateCDKMatrix(matriz,0);

}
void baja_cliente(){
  CDKSCROLL *lista=(CDKSCROLL*)listado("cliente","cliente_id");
    activateCDKScroll(lista,0);
}
void mod_cliente(){
  CDKSCROLL *lista=(CDKSCROLL*)listado("cliente","cliente_id");
    activateCDKScroll(lista,0);

}

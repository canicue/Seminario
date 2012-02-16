#include "proveedores.h"
#include <matrix.h>
#include <scroll.h>
void alta_proveedor(){
    CDKMATRIX *matriz=(CDKMATRIX*)formulario_alta("proveedor");

    activateCDKMatrix(matriz,0);

}
void baja_proveedor(){

    CDKSCROLL *lista=listado("proveedor","provedor_id");
    activateCDKScroll(lista,0);



}
void mod_proveedor(){

  CDKSCROLL *lista=listado("proveedor","provedor_id");
    activateCDKScroll(lista,0);




}
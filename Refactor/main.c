/* 
 * File:   main.c
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:16
 */

#include <stdio.h>

#include<cdk.h>

#include "controlador/principal.h"
#include "widgets/formularios.h"
#include "controlador/clientes.h"
void vale()
{
        login();
}
void test()
{
  CDKSCROLL *sc=  listado("cliente","cliente_id");
  activateCDKScroll(sc,0);
  //  formulario_alta("cliente");
 //   formulario_modificacion("producto_terminado","producto_terminado_id","PT001");
  //    formulario_modificacion("RMP","producto_id","RMP002");
  //  formulario_modificacion("cliente","Cliente_id","C001");
  //   formulario_modificacion("proveedor","Proveedor_id","P001");
  //    formulario_modificacion("tecnico","Tecnico_id","T001");
      formulario_modificacion("orden_pedido_producto","orden_pedido_producto_id","OPP");
  //  alta_cliente();
}
int main(int argc, char** argv) {
//    formulario_alta("cliente");
 //   formulario_alta("RMP");
  //  initscr();
  //  CDKSCREEN    *cdkScreen=initCDKScreen(stdscr);
    test();

    //vale();
//    while(TRUE)
 //   {entrada();}

    endCDK();
    return (EXIT_SUCCESS);
}





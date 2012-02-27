/* 
 * File:   main.c
 * Author: charlie
 *
 * Created on 14 de octubre de 2011, 18:16
 */

#include <stdio.h>
#include "pruebas.h"
#include "widgets/dialogos.h"
#include<cdk.h>
#include "controlador/principal.h"
#include "widgets/formularios.h"
#include "controlador/clientes.h"
#include "widgets/archivos.h"
void
vale ()
{
  login ();
}

void
test ()
{
//  CDKSCROLL *sc = (CDKSCROLL *) listado ("cliente", "cliente_id");
//  activateCDKScroll (sc, 0);
  //  formulario_alta("cliente");
  //   formulario_modificacion("producto_terminado","producto_terminado_id","PT001");
  //    formulario_modificacion("RMP","producto_id","RMP002");
  //  formulario_modificacion("cliente","Cliente_id","C001");
  //   formulario_modificacion("proveedor","Proveedor_id","P001");
  //    formulario_modificacion("tecnico","Tecnico_id","T001");
//  formulario_modificacion ("orden_pedido_producto",                      "orden_pedido_producto_id", "OPP");
  //  alta_cliente();
  CDKFSELECT *archivo = seleccionar_archivo ();

  //popupLabel(ScreenOf(archivo),&archivo->pathname,1);
  ver_archivo (archivo->pathname);
}

void
prueba ()
{
//    dialogo_borrado("cliente","cliente_id","C001");
//    activateCDKDialog(dialogo,0);
  char *texto_prueba[] = { "f" };	//,"prueba","asdfa","dfdf"};
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  ventanita_info (pantalla, texto_prueba);


}

int
main (int argc, char **argv)
{
//    formulario_alta("cliente");
  //   formulario_alta("RMP");
  //  initscr();
  //  CDKSCREEN    *cdkScreen=initCDKScreen(stdscr);

  //test();
  //  prueba();


  // vale ();

  //sin login







  // bindCDKObject(vMATRIX,matriz,'g',prueba_preprocess,0);


  //  buscar_ultimo("cliente","cliente_id",call_id);
//    generar_id("cC","cliente","cliente_id");

  //   printf("%d",strlen("dios"));
  //  printf ("%s-----", generar_id ("C", "cliente", "cliente_id"));

  while (TRUE)
    {
      entrada ();
    }
  // test ();
  endCDK ();
  return (EXIT_SUCCESS);
}

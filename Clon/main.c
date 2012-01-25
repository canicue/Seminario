/* 
 * File:   main.c
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:16
 */

#include <stdio.h>
#include "controlador/callbacks.h"
#include "vista/info.h"
#include <string.h>
#include <stdlib.h>
#include "datos/datos.h"
#include "datos/tipos.h"
#include "datos/clientes.h"
#include "vista/scroll.h"
#include "pruebas.h"
#include "vista/proveedores/proveedores.h"
#include "controlador/principal.h"
#include "controlador/formularios.h"

/*
 * 
 */


void prueba_clientes()
{
CLIENTE *cliente;
cliente=(CLIENTE*)malloc(sizeof(CLIENTE));
strcpy(cliente->cliente_id,"u0ULL");
strcpy(cliente->direccion,"dios");
strcpy(cliente->email,"asdf \\@dfdf");
strcpy(cliente->nombre,"nombre");
strcpy(cliente->telefono,"444555");
agregar_cliente(cliente);
}


int main(int argc, char** argv) {

  



    //   prueba_clientes();

 //-------------------------PRUEBAS-----------------------------//

  //  prueba_busqueda();

 //   prueba_vista_clientes();
  //  getch();
  
   
    // prueba_struct();
  //  lista_clientes();
//    ver_tabla("proveedor");
//    formulario("cliente");
 //   formulario("RMP");
 //-------------------------PRUEBAS-----------------------------//

//    prueba_clientes();
    //mostrar_info(cdkScreen);

//----------------IBA------------------------------//

 //   box(stdscr,0,0);
  //  refresh();
   // getch();

  //  login();
   // alta_proveedor(cdkScreen);
//    getch();
    //initscr();
   // CDKSCREEN *cdkScreen=initCDKScreen(stdscr);

 //   mostrar_info(cdkScreen);
//    entrada();
    buscar_registro("cliente","cliente_id","C001",callback_reg,NULL);
 // buscar_cliente("cliendte_id","C001");
 // listar_clientes();
//    probador();
    formulario("proveedor");




  //  formulario("cliente");
   // formulario("RMP");
//    endCDK();
  //  login();


    //    hacer(1);
    printf("hola");
//----------------IBA------------------------------//
 //mostrar_scroll(cdkScreen);
//menu_scroll(cdkScreen);

//esto va
 //   conectar("basesita.sqlite");
  //  login(argc,argv);
    return (EXIT_SUCCESS);
}


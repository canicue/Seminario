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
  //  formulario_alta("cliente");
    alta_cliente();
}
int main(int argc, char** argv) {
//    formulario_alta("cliente");
 //   formulario_alta("RMP");
  //  initscr();
  //  CDKSCREEN    *cdkScreen=initCDKScreen(stdscr);
   // test();
    vale();
//    while(TRUE)
 //   {entrada();}

    endCDK();
    return (EXIT_SUCCESS);
}


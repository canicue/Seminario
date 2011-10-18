/* 
 * File:   main.c
 * Author: canicue
 *
 * Created on 15 de octubre de 2011, 10:09
 */

#include <stdio.h>
#include <stdlib.h>
#include "datos/datos.h"
#include "interfaz/login.h"
#include "interfaz/ventana.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *usuario,*password=NULL;
    conectar("hola.db");

    //esto andaa
    //  mostrar_login();
    usuario=pedir_datos("usuario");
    password=pedir_datos("pass");
 //   printf("%s",usuario);
  //  printf("%s",password);
   // iniciar_curses();
    return (EXIT_SUCCESS);

}


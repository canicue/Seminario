/* 
 * File:   main.c
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:16
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "datos/datos.h"
#include "datos/tipos.h"
#include "datos/clientes.h"

/*
 * 
 */


void prueba_clientes()
{
CLIENTE *cliente;
cliente=(CLIENTE*)malloc(sizeof(CLIENTE));
strcpy(cliente->cliente_id,"N0ULL");
strcpy(cliente->direccion,"dios");
strcpy(cliente->email,"asdf \\@dfdf");
strcpy(cliente->nombre,"nombre");
strcpy(cliente->telefono,"444555");
agregar_cliente(cliente);
}
int main(int argc, char** argv) {

    prueba_clientes();

/*esto va
    conectar("basesita.sqlite");
    login(argc,argv);
    return (EXIT_SUCCESS);*/
}


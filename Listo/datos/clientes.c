#include <stdio.h>
#include <string.h>

#include "clientes.h"
#include "datos.h"
void mostrar()
{
}
void agregar_cliente(CLIENTE *cliente)

{
    char *error;
    char *consulta[255];
   
  sprintf(consulta,AGREGAR,cliente->cliente_id,cliente->nombre,cliente->telefono,cliente->direccion,cliente->email);
   printf(consulta);
   sqlite3* conexion=conectar(BASE);
   sqlite3_exec(conexion,consulta,mostrar,NULL,&error);
   
}

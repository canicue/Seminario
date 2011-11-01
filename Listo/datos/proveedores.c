#include <stdio.h>

#include "proveedores.h"
#include "tipos.h"
#include "datos.h"
void agregar_proveedor(PROVEEDOR *proveedor)
{
  char *error;
    char consulta[255]="";

  sprintf(consulta,AGREGAR_PROVEEDOR,proveedor->proveedor_id,
          proveedor->nombre,proveedor->telefono,
          proveedor->direccion,proveedor->email);
   printf(consulta);
   sqlite3* conexion=conectar(BASE);
  // sqlite3_exec(conexion,consulta,mostrar,NULL,&error);
     sqlite3_exec(conexion,consulta,0,0,&error);
   printf("%s",error);

}
void borrar_proveedor(int proveedor_id)
{


}
void buscar_proveedor(char *campo,char *valor){}
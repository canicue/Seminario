#include <stdio.h>
#include <string.h>

#include "clientes.h"
#include "datos.h"
int mostrar()
{
    printf("mostrando");
}
 int vuelta(void *NotUsed, int argc, char **argv, char **azColName){
     printf("asdfadsf");
    printf("%d-------------",argc);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s ", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");
    return 0;
}




void agregar_cliente(CLIENTE *cliente)

{
    char *error;
    char consulta[255]="SELECT * FROM cliente";
   
/*  sprintf(consulta,AGREGAR_CLIENTE,cliente->cliente_id,
          cliente->nombre,cliente->telefono,
          cliente->direccion,cliente->email);
   printf(consulta);*/
   conexion=conectar(BASE);
//   consulta="SELECT * FROM cliente";
   int res=  sqlite3_exec(conexion,consulta,vuelta,0,&error);
   //  sqlite3_exec(conexion,consulta,0,0,&error);
   printf("%s",error);
   //desconectar();
}
void borrar_cliente(char *cliente_id)
{
    char *error;
    char consulta[255]="";
    int res;
    sprintf(consulta,BORRAR_CLIENTE,cliente_id);
    res=sqlite3_exec(conexion,consulta,0,0,&error);

}
void modificar_cliente(char *cliente_id,CLIENTE *nuevo)
{
    char *error;
    char consulta[255]="";
    sprintf(consulta,MODIFICAR_REGISTRO_CHAR,"cliente");

}

CLIENTE *buscar_cliente(char *campo,char *valor){}
#include <stdio.h>
#include <string.h>

#include "clientes.h"
#include "datos.h"
int mostrar(void *NotUsed, int argc, char **argv, char **azColName)
{
       printf("%d-------------",argc);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s  \n", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");

    printf("mostrando");
    return 0;
}
 int vuelta(void *NotUsed, int argc, char **argv, char **azColName){
    
    printf("%d-------------",argc);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s  \n", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");
    return 0;
}

 CLIENTE *listar_clientes()
 {
 char *error;
 char consulta[255]="";
 CLIENTE *lista;
 sprintf(consulta,LISTAR_REGISTROS,"cliente");
 int res;
 conexion=conectar(BASE);
 int argumento;
 res=sqlite3_exec(conexion,consulta,vuelta,0,&error);
 
 return lista;
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

void buscar_cliente(char *campo,char *valor){

    //printf("mierdacarao");
    char *error;
    char consulta[255]="";
    int res;
    sprintf(consulta,BUSCAR_REGISTRO,"cliente",campo,valor);
    printf(consulta);
    res=sqlite3_exec(conexion,consulta,mostrar,0,&error);
    printf("error=%c",error);


}

CLIENTE fila_a_cliente(char **fila)
{
    CLIENTE cliente;
    strcpy(cliente.cliente_id,fila[0]);
    strcpy(cliente.nombre,fila[1]);
    strcpy(cliente.direccion,fila[0]);
    strcpy(cliente.email,fila[1]);

    return cliente;




}
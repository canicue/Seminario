#include <stdio.h>

#include "datos.h"
sqlite3 *conectar(char* nombre)
{
    int err=0;
   
    sqlite3_open(nombre,&conexion);
    //printf("%d",err);
    return conexion;
;

}
void desconectar()
{
    sqlite3_close(conexion);

}
void buscar_registro(char *tabla,char *nombre,char *valor)
{




}
void borrar_registro(char *tabla,char *id)
{




}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){

    printf("%d-------------",argc);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s ", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");
    return 0;
}
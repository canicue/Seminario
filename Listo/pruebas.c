#include "pruebas.h"
#include "datos/clientes.h"
#include "vista/clientes/clientes.h"
#define nro_elemtos(a) (sizeof(*a)/sizeof(a[0]))
int callback(void *NotUsed, int argc, char **argv, char **azColName){

    printf("%d-------------%s\n",argc,(char*)NotUsed);
    int i=0;
    for(  i=0; i<argc;i++){
        printf("%s  \n", argv[i] ? argv[i] : "NULL");
    }
    printf("%d",sizeof(argv[0]));
    printf("\n");
    printf("hola");

    for (i=0;i<argc;i++)
    {
     
        printf("columa %s\n",azColName[i]);
    }
    return 0;
}

void lista_clientes()
{
    char* puntero="dios";
    char *error;
    conexion=conectar(BASE);
    int res;

    char consulta[255];
   
    sprintf(consulta,LISTAR_REGISTROS,"cliente");

    res=sqlite3_exec(conexion,consulta,callback,puntero,&error);
    if(res!=SQLITE_OK)
    {printf("%s\n",error);}
 
    desconectar();
   
   
   
}
void ver_tablas(char *tabla)
{
    char *error;
    conexion=conectar(BASE);
    int res;
    char plantilla[]="PRAGMA table_info(%s)";
    char consulta[255];
    printf("%s",&consulta);
    sprintf(consulta,plantilla,tabla);
    
    res=sqlite3_exec(conexion,consulta,callback,0,&error);
    printf("%s\n",&error);
    desconectar();

}
int columnas_callback(void *lista, int argc, char **argv, char **azColName){

    lista=&azColName;
    printf("%s",(char*)(&lista+4));
   // printf("%s",(char*)lista[0]);
    return 0;
}
void lista_columnas(char *tabla,char **lista)
{
    char *error;
    int res;
    conexion=conectar(BASE);
    char consulta[]="SELECT * FROM cliente LIMIT 2";
    res=sqlite3_exec(conexion,consulta,columnas_callback,lista,&error);
 if(res!=SQLITE_OK)
    {printf("%s\n",error);}

}

void prueba_columnas()
{
    char *lista[]={"a","b"};
     printf("%d\n",sizeof(lista));
    lista_columnas("cliente",lista);
    int i;
    for(i=0;i<3;i++)
    {
    printf("%d\n",sizeof(lista));
    }


}
 int callback_clientes(void *lista, int argc, char **argv, char **azColName)
{
     // printf("%d\n",nro_elemtos(azColName));
    //lista=*azColName[0];
     
     lista=*argv;
    printf("%s\n",lista);
/*   int i;
    for(i=0;i<argc;i++)
    {
        printf("%s=%s\n",azColName[i],argv[i]);

    }
*/


    return 0;
}


char ** busqueda(char **lista)
{
   
    int res;
    CLIENTE cliente;
    char consulta[255];
    char *error;
    conexion=conectar(BASE);
    sprintf(consulta,BUSCAR_REGISTRO,"cliente","'1'","1");
   // printf("%s",&consulta);
    res=sqlite3_exec(conexion,consulta,callback_clientes,lista,&error);
 if(res!=SQLITE_OK)
    {printf("%s\n",error);}
    return lista;
}
void prueba_busqueda()
{
    char **listita;
    char **listado;//="hola" ;
 //   printf("%d\n",nro_elemtos(listado));
    printf("%s\n",listado);
    listita=busqueda(listado);
    printf("%s\n",listado);
printf("ISTITA%s\n",**listita);

}
char** cosa;
int call_struct(void *cliente, int argc, char **argv, char **azColName)
{

    cosa=azColName;
    int i;
    for(i=0;i<argc;i++)
    {

    printf("%s",argv[i]);


    }
    return 0;
}

void lista_struct(CLIENTE *cliente)
{


  conexion=conectar(BASE);
    char *consulta="SELECT * FROM cliente";
    char *error;
    char *lista;
    int res;

    res=sqlite3_exec(conexion,consulta,call_struct,cliente,&error);

    if(res!=SQLITE_OK)
    {
        printf("Sucedio un error %s=",error);
    }
    printf("\n%s\n",cosa[0]);
    printf("\n%s\n",cosa[1]);
     printf("\n%s\n",cosa[2]);
      printf("\n%s\n",cosa[3]);
}
void imprimir_cliente(CLIENTE *cliente)
{

    printf("id=%s\n",cliente->cliente_id);
    printf("nombre=%s\n",cliente->nombre);
    printf("direccion=%s\n",cliente->direccion);
    printf("telefono=%s\n",cliente->telefono);
    printf("email=%s\n",cliente->email);

}
void prueba_struct()
{
    CLIENTE *cliente;
    lista_struct(cliente);

}

void prueba_vista_clientes()
{
    CDKSCREEN *pantalla;
    initscr();
    pantalla=initCDKScreen(stdscr);
   // baja_cliente(pantalla);
    menu_clientes(pantalla);

}
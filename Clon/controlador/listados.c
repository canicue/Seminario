

#include <cdk/alphalist.h>

#include "listados.h"
#include "callbacks.h"
#include "config.h"


void listar(char *tabla)
{


}
void leer_registro(char *tabla,char *campo,char *valor)
{




}
CDKALPHALIST *listados(char *tabla){
    char *nombre="sdf";
    char *argv[]={"asdf","sdfasdf"};
 //   initscr();
//    cdkScreen=initCDKScreen(stdscr);
   // popupDialog(cdkScreen,argv,2,argv,2);
 //  listado=newCDKAlphalist(  cdkScreen,CENTER, CENTER, 0, 0, nombre, nombre, argv , 2,'_', A_REVERSE, TRUE, FALSE);
      listar_registros(tabla,callback_lista,tabla);
  //  activateCDKAlphalist(listado,0);
    return listado;


}
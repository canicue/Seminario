#include "proveedores.h"
#include <matrix.h>
#include <scroll.h>
#include <cdk/matrix.h>
CDKMATRIX *matriz;
void alta_proveedor(){
    matriz=(CDKMATRIX*)formulario_alta("proveedor");

    activateCDKMatrix(matriz,0);
    if(matriz->exitType==vNORMAL)
    {
        char *a[]={"normal"};
        popupLabel(ScreenOf(matriz),a,1);
       
    
    }


    destroyCDKMatrix(matriz);

}
void baja_proveedor(){

   
    char *columna="proveedor_id";
    char *cosa[1];
    CDKSCROLL *lista=(CDKSCROLL*)listado("proveedor",columna);
    activateCDKScroll(lista,0);
    if(lista->exitType==vNORMAL)
    {
        int elegido=getCDKScrollCurrentItem(lista);
        matriz=(CDKMATRIX*)formulario_modificacion("proveedor","proveedor_id",chtype2Char(lista->item[elegido]));
  

   //     cosa[0]=chtype2Char(lista->item[elegido]);

    }
       if (matriz->exitType==vNORMAL)
    {



        char *a[]={"asdfsdf"};
        popupLabel(ScreenOf(matriz),a,1);


    }
   destroyCDKMatrix(matriz);
 //   popupLabel(ScreenOf(lista),cosa,1);


}
void mod_proveedor(){

  CDKSCROLL *lista=(CDKSCROLL*)listado("proveedor","provedor_id");
    activateCDKScroll(lista,0);

      if(lista->exitType==vNORMAL)
    {
     int elegido=getCDKScrollCurrentItem(lista);
   matriz=(CDKMATRIX*)     formulario_modificacion("proveedor","proveedor_id",chtype2Char(lista->item[elegido]));


   //     cosa[0]=chtype2Char(lista->item[elegido]);

    }













destroyCDKMatrix(matriz);






}
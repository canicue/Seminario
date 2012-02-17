#include "persistencia.h"

int guardar_cliente(CDKMATRIX *matriz){

    char *datos[matriz->rows];
    char *columnas[matriz->rows];
    int i;
    for(i=0;i<matriz->rows;i++)
    {
        datos[i]=getCDKMatrixCell(matriz,i,1);
        columnas[i]=chtype2Char(matriz->rowtitle[i]);
    }
    
   
popupLabel(ScreenOf(matriz),columnas,matriz->rows);
    popupLabel(ScreenOf(matriz),datos,matriz->rows);

}
int guardar_tecnico(CDKMATRIX *matriz){

char *datos[matriz->rows];
    int i;
    for(i=0;i<matriz->rows;i++)
    {
        datos[i]=getCDKMatrixCell(matriz,i,1);

    }



    popupLabel(ScreenOf(matriz),datos,matriz->rows);




}
int guardar_proveedor(CDKMATRIX *matriz){

char *datos[matriz->rows];
    int i;
    for(i=0;i<matriz->rows;i++)
    {
        datos[i]=getCDKMatrixCell(matriz,i,1);

    }



    popupLabel(ScreenOf(matriz),datos,matriz->rows);


}
int guardar_insumo(CDKMATRIX *matriz){


char *datos[matriz->rows];
    int i;
    for(i=0;i<matriz->rows;i++)
    {
        datos[i]=getCDKMatrixCell(matriz,i,1);

    }



    popupLabel(ScreenOf(matriz),datos,matriz->rows);



}


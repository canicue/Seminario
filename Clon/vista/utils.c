#include "utils.h"

/*
char **leer_matriz(CDKMATRIX *matriz)
{


    char *toma[]={"asdf"};
//matriz.cell;
    return toma;

}*/
char **info_matriz(CDKMATRIX *matriz) {

    //   char *buffer[matriz->rows];
    int i;
    // buffer=(char**)malloc(matriz->rows*sizeof(char*));
    //    sprintf(buffer[0],copyChar(getCDKMatrixCell(matriz,0,1)));
    //   popupLabel(ScreenOf(matriz),merda,2);
    //  printf("%d\n",matriz->rows);
    // getch();
    for (i = 1; i < matriz->rows + 1; i++) {
        //       printf("%d\n",i);
        //  buffer[i]= getCDKMatrixCell(matriz,i,1);

        buffer[i] = getCDKMatrixCell(matriz, i, 1);

    }
    //    popupLabel(ScreenOf(matriz),merda,2);
    //return merda;
    //    popupLabel(ScreenOf(matriz),buffer,2);
    //return buffer;
    //popupLabel(ScreenOf(matriz),merda,1);
    return buffer;
}

boolean validar_matriz(CDKMATRIX matriz, CDKSCREEN *cdkScreen) {
    //char* texto[]={"asdf"};
    //popupLabel(cdkScreen,texto,1);


    return 0;
}

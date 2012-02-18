


#include "persistencia.h"

int
guardar_cliente (CDKMATRIX * matriz)
{

  char *datos[matriz->rows];
  char *columnas[matriz->rows];
  int i;
  for (i = 0; i < matriz->rows; i++)
    {

      datos[i] = getCDKMatrixCell (matriz, i, 1);
      columnas[i] = chtype2Char (matriz->rowtitle[i]);
    }


  popupLabel (ScreenOf (matriz), columnas, matriz->rows);
  popupLabel (ScreenOf (matriz), datos, matriz->rows);

}

int
guardar_tecnico (CDKMATRIX * matriz)
{

  char *datos[matriz->rows];
  int i;
  for (i = 0; i < matriz->rows; i++)
    {
      datos[i] = getCDKMatrixCell (matriz, i, 1);

    }



  popupLabel (ScreenOf (matriz), datos, matriz->rows);




}

int
guardar_proveedor (CDKMATRIX * matriz)
{
  guardar_matriz (matriz);

  char *columnas[matriz->rows];
  char *datos[matriz->rows];
  int i;
  for (i = 0; i < matriz->rows; i++)
    {
      // datos[i]=(char*)malloc(256);
      // strcpy(datos[i],getCDKMatrixCell(matriz,i+1,1));
      datos[i] = getCDKMatrixCell (matriz, i + 1, 1);
      columnas[i] = chtype2Char (matriz->rowtitle[i + 1]);

    }




  popupLabel (ScreenOf (matriz), datos, matriz->rows);
  guardar_cosa ("proveedor", columnas, datos, matriz->rows);

}

int
guardar_insumo (CDKMATRIX * matriz)
{


  char *datos[matriz->rows];
  int i;
  for (i = 0; i < matriz->rows; i++)
    {
      datos[i] = getCDKMatrixCell (matriz, i, 1);

    }



  popupLabel (ScreenOf (matriz), datos, matriz->rows);



}

int
guardar_matriz (CDKMATRIX * matriz)
{

  char *columnas[matriz->rows];
  char *datos[matriz->rows];
  int i;
  for (i = 0; i < matriz->rows; i++)
    {
      // datos[i]=(char*)malloc(256);
      // strcpy(datos[i],getCDKMatrixCell(matriz,i+1,1));
      datos[i] = getCDKMatrixCell (matriz, i + 1, 1);
      columnas[i] = chtype2Char (matriz->rowtitle[i + 1]);

    }




  popupLabel (ScreenOf (matriz), datos, matriz->rows);
  guardar_cosa (chtype2Char (matriz->coltitle[1]), columnas, datos,
		matriz->rows);


}

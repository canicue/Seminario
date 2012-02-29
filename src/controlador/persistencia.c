#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <cdk/matrix.h>
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
      columnas[i] = (char *) chtype2Char (matriz->rowtitle[i]);
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
guardar_matriz (CDKMATRIX * matriz)
{
  guardar_matriz (matriz);

  char *columnas[matriz->rows];
  char *datos[matriz->rows];
  int i;
  int tmp = 0;
  for (i = 0; i < matriz->rows; i++)
    {
      // datos[i]=(char*)malloc(256);
      // strcpy(datos[i],getCDKMatrixCell(matriz,i+1,1));
      datos[i] = getCDKMatrixCell (matriz, i + 1, 1);
      columnas[i] = (char *) chtype2Char (matriz->rowtitle[i + 1]);

    }




//  popupLabel (ScreenOf (matriz), datos, matriz->rows);

  // popupLabel (ScreenOf (matriz), datos, matriz->rows);
//  popupLabel (ScreenOf (matriz), columnas, matriz->rows);

  tmp = guardar_cosa (chtype2Char (matriz->coltitle[1]), columnas, datos,
		      matriz->rows);
  return tmp;

}

int
borrar_matriz (CDKMATRIX * matriz)
{
  char *nombre;
  char *valor;
  char *tabla;
  valor = getCDKMatrixCell (matriz, 1, 1);
  nombre = (char *) chtype2Char (matriz->rowtitle[1]);
  tabla = (char *) chtype2Char (matriz->coltitle[1]);
  return borrar_registro (tabla, nombre, valor, NULL);
}

int
modificar_matriz (CDKMATRIX * matriz)
{
  char *columnas[matriz->rows];
  char *nuevos[matriz->rows];
  char *valor;
  int i;
  int tmp = 0;

  for (i = 0; i < matriz->rows; i++)
    {
      // datos[i]=(char*)malloc(256);
      // strcpy(datos[i],getCDKMatrixCell(matriz,i+1,1));
      nuevos[i] = getCDKMatrixCell (matriz, i + 1, 1);
      columnas[i] = (char *) chtype2Char (matriz->rowtitle[i + 1]);

    }


  valor = copyChar (getCDKMatrixCell (matriz, 1, 1));
  return modificar_registro (chtype2Char (matriz->coltitle[1]), columnas,
			     (char *) chtype2Char (matriz->rowtitle[1]),
			     valor, nuevos, matriz->rows);

}


void
tratar_error (CDKSCREEN * pantalla, char *tabla)
{
  char *msg[] = { "Se produjo", "un error" };
  popupLabel (pantalla, msg, 2);


}

void
arrepentimiento (CDKMATRIX * matriz, int elegido)
{

  if (elegido == 1)
    {

      ;

    }

  if (elegido == 0)
    {

      int res;
      res = borrar_matriz (matriz);
      if (res != 0)
	{
	  tratar_error (ScreenOf (matriz),
			(char *) chtype2Char (matriz->coltitle[1]));

	}

    }

}

#include <matrix.h>
#include <scroll.h>
#include <buttonbox.h>
#include <cdk_util.h>
#include <cdk/cdk.h>
#include "drivers_pre.h"
#include "../widgets/listados.h"
#include "../widgets/templates.h"

CDKSCROLL *lista;

int
driver_borrado (EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype key)
{

  char *mierda[] = { "MIERDA ", "CARAJO" };



  CDKBUTTONBOX *buttonbox = (CDKBUTTONBOX *) clientData;
  popupLabel (ScreenOf (buttonbox), mierda, 2);
  injectCDKButtonbox (buttonbox, key);
  return (TRUE);
}

int
driver_insumo_pre (EObjectType cdktype GCC_UNUSED,
		   void *object GCC_UNUSED, void *clientData, chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int filas[1];
  filas[0] = 7;
  columna_numerica (matriz, filas, 1);



  return 1;

}

int
driver_producto_terminado_pre (EObjectType cdktype GCC_UNUSED,
			       void *object GCC_UNUSED,
			       void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int filas[1];
  filas[0] = 4;
  columna_numerica (matriz, filas, 1);

  int row = getCDKMatrixRow (matriz);
  int elegido;
 
  return 1;

}

int
driver_proveedores_pre (EObjectType cdktype GCC_UNUSED,
			void *object GCC_UNUSED, void *clientData,
			chtype input)
{

  char **cosa = (char **) clientData;
  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int filas[1];
  filas[0] = 3;
  columna_numerica (matriz, filas, 1);
  int row;
//  CDKTEMPLATE *templ;
/*  if (matriz->crow == 1)
    {
      moveToCDKMatrixCell (matriz, 2, 1);
      drawCDKMatrix (matriz, TRUE);
      refreshCDKScreen (ScreenOf (matriz));
    }*/
  /* if (input != KEY_DOWN && input != KEY_UP)
     {
     row = getCDKMatrixRow (matriz);
     switch (row)
     {
     case 5:
     templ = (CDKTEMPLATE *) template_mail (ScreenOf (matriz));
     activateCDKTemplate (templ, 0);
     break;




     }





     }
     setCDKMatrixCell (matriz, 1, 1, cosa[1]); */
/*  if (input != KEY_DOWN || input != KEY_UP)
    {

      if (matriz->crow == 1)
	{

	  char *msg[] = { "<C>NO", "<C>EDITABLE" };
	  popupLabel (ScreenOf (matriz), msg, 2);

	  //  setCDKMatrixCell(matriz,1,1,getCDKMatrixCell(matriz,1,1));


	}
    }*/
  return 1;

}





int
driver_orden_pedido_producto_pre (EObjectType cdktype GCC_UNUSED,
				  void *object GCC_UNUSED, void *clientData,
				  chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[1];
  filas[0] = 4;
  columna_numerica (matriz, filas, 1);




  return 1;

}

int
driver_clientes_pre (EObjectType cdktype GCC_UNUSED,
		     void *object GCC_UNUSED, void *clientData, chtype input)
{
  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[1];
  filas[0] = 3;
  columna_numerica (matriz, filas, 1);
  return 1;

}

int
driver_tecnicos_pre (EObjectType cdktype GCC_UNUSED,
		     void *object GCC_UNUSED, void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[1];
  filas[0] = 3;
  columna_numerica (matriz, filas, 1);
  return 1;




}

driver_RMP_pre (EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[3];
  filas[0] = 6;
  filas[1] = 7;
  filas[2] = 8;
  columna_numerica (matriz, filas, 3);
  return 1;




}

int
driver_orden_produccion_pre (EObjectType cdktype GCC_UNUSED,
			     void *object GCC_UNUSED,
			     void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[1];
  filas[0] = 4;
  columna_numerica (matriz, filas, 1);


}

int
driver_orden_pedido_proveedor_pre (EObjectType cdktype GCC_UNUSED,
				   void *object GCC_UNUSED, void *clientData,
				   chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int filas[3];
  filas[0] = 5;
  filas[1] = 6;
  filas[2] = 7;
  columna_numerica (matriz, filas, 3);

}

void
proteger_id (CDKMATRIX * matriz)
{
    if(matriz->crow==1)
    {
     matriz->colvalues[1] = vVIEWONLY;

    }

}

void
columna_numerica (CDKMATRIX * matriz, int *row, int nro)
{
  int i = 0;
  for (i = 0; i < nro; i++)
    {

      if (matriz->crow == row[i])
	{
	  matriz->colvalues[1] = vINT;
	}
    }
}

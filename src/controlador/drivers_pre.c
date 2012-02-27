#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <cdk/buttonbox.h>
#include <cdk/scroll.h>
#include <cdk/buttonbox.h>
#include "drivers_pre.h"
CDKSCROLL *lista;

int
prueba_binding (EObjectType cdkType GCC_UNUSED, void *object,
		void *clientData GCC_UNUSED, chtype input)
{

  CDKMATRIX *mat = (CDKMATRIX *) object;
  char *aa[] = { "asd", "asdf" };
  if (input == (chtype) 'g')
    {
      popupLabel (ScreenOf (mat), aa, 2);

      // getch();
    }

  return 1;

}


int
prueba_preprocess (EObjectType cdkType GCC_UNUSED, void *object,
		   void *clientData GCC_UNUSED, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;


  if (getCDKMatrixRow (matriz) == 2)
    {

      if (input == 'g')
	{

	  endCDK ();
	  printf ("mierda");
	  exit (0);


	}
    }



  return 1;

}


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

  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 14:
	  lista = (CDKSCROLL *) listado ("proveedor", "proveedor_id");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 13:
	  lista = (CDKSCROLL *) listado ("tecnico", "tecnico_id");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 10:

	  break;




	}

    }


  return 1;

}

int
driver_producto_terminado_pre (EObjectType cdktype GCC_UNUSED,
			       void *object GCC_UNUSED,
			       void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP || input != KEY_DOWN)
    {
      switch (row)
	{
	case 5:
	  lista = (CDKSCROLL *) listado ("insumo", "IR");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 6:
	  lista = (CDKSCROLL *) listado ("RMP", "producto_id");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 10:

	  break;




	}

    }
  return 1;

}

int
driver_proveedores_pre (EObjectType cdktype GCC_UNUSED,
			void *object GCC_UNUSED, void *clientData,
			chtype input)
{
  CDKMATRIX *matriz = (CDKMATRIX *) object;
  int row;
  CDKTEMPLATE *templ;
  if (input != KEY_DOWN || input != KEY_UP)
    {
      row = getCDKMatrixRow (matriz);
      switch (row)
	{
	case 5:
	  templ = template_mail (ScreenOf (matriz));
	  activateCDKTemplate (templ, 0);
	  break;




	}





    }
  //setCDKMatrixCell (matriz, 1, 1,"");
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
driver_orden_pedido_pre (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 2:
	  lista = (CDKSCROLL *) listado ("cliente", "cliente_id");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 3:
	  lista = (CDKSCROLL *) listado ("producto", "producto_id");

	  moveCDKScroll (lista, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista, 0);
	  setCDKMatrixCell (matriz, matriz->crow, 1,
			    (char *) chtype2Char (lista->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 10:

	  break;




	}

    }


  return 1;

}

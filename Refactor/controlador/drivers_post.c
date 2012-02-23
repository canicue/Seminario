#include "drivers_post.h"
int
driver_proveedores_post (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input)
{




  CDKMATRIX *matriz = (CDKMATRIX *) object;
  char *valor = copyChar (getCDKMatrixCell (matriz, 1, 1));
  /// setCDKMatrixCell(matriz,1,1,valor);

  // endCDK();
  // printf("%s",valor);
  // exit(0);


  //popupLabel(ScreenOf(matriz),matriz->info,matriz->rows);
  // setCDKMatrixCell (matriz, 1, 1, (char *) clientData);




  return 1;

}


int
driver_clientes_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData, chtype input)
{
  return 1;
}

int
driver_RMP_post (EObjectType cdktype GCC_UNUSED,
		 void *object GCC_UNUSED, void *clientData, chtype input)
{
  return 1;
}

int
driver_tecnicos_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData, chtype input)
{
  return 1;
}

int
driver_insumos_post (EObjectType cdktype GCC_UNUSED,
		     void *object GCC_UNUSED, void *clientData, chtype input)
{
  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row = getCDKMatrixRow (matriz);
  int elegido;
  char tmp[256];
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 12:



	  calen = (CDKCALENDAR *) calendario (ScreenOf (matriz));
	  activateCDKCalendar (calen, 0);
	  if (calen->exitType == vNORMAL)
	    {

	      sprintf (tmp, "%02d/%02d/%d", calen->day, calen->month,
		       calen->year);
	      setCDKMatrixCell (matriz, 12, 1, tmp);
	      destroyCDKCalendar (calen);
	      drawCDKMatrix (matriz, TRUE);
	    }
	  break;
	case 6:
	  lista_pro = (CDKSCROLL *) listado ("RMP", "producto_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 5, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 10:

	  break;




	}

    }
  return 1;

}


int
driver_orden_produccion_post (EObjectType cdktype GCC_UNUSED,
			      void *object GCC_UNUSED,
			      void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 3:
	  lista_pro = (CDKSCROLL *) listado ("RMP", "producto_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 3, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 5:
	  lista_pro = (CDKSCROLL *) listado ("producto_terminado", "lote");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 5, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 8:
	  lista_pro = (CDKSCROLL *) listado ("tecnico", "tecnico_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 5, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);

	  break;




	}

    }






  return 1;
}

int
driver_producto_terminado_post (EObjectType cdktype GCC_UNUSED,
				void *object GCC_UNUSED,
				void *clientData, chtype input)
{

  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 5:
	  lista_pro = (CDKSCROLL *) listado ("insumo", "IR");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 5, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 6:
	  lista_pro = (CDKSCROLL *) listado ("RMP", "producto_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 5, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 10:

	  break;




	}

    }
  return 1;

}

int
driver_orden_pedido_producto_post (EObjectType cdktype GCC_UNUSED,
				   void *object GCC_UNUSED,
				   void *clientData, chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;
  char tmp[256];
  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN)
    {
      switch (row)
	{
	case 2:
	  lista_pro = (CDKSCROLL *) listado ("cliente", "cliente_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 2, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);



	  break;
	case 3:
	  lista_pro = (CDKSCROLL *) listado ("RMP", "producto_id");

	  moveCDKScroll (lista_pro, CENTER, CENTER, FALSE, TRUE);
	  elegido = activateCDKScroll (lista_pro, 0);
	  setCDKMatrixCell (matriz, 3, 1,
			    (char *) chtype2Char (lista_pro->item[elegido]));
	  drawCDKMatrix (matriz, TRUE);


	  break;
	case 6:
	  calen = (CDKCALENDAR *) calendario (ScreenOf (matriz));
	  activateCDKCalendar (calen, 0);
	  if (calen->exitType == vNORMAL)
	    {

	      sprintf (tmp, "%02d/%02d/%d", calen->day, calen->month,
		       calen->year);
	      setCDKMatrixCell (matriz, 6, 1, tmp);
	      destroyCDKCalendar (calen);
	      drawCDKMatrix (matriz, TRUE);
	    }
	  break;

	case 7:
	  calen = calendario (ScreenOf (matriz));
	  activateCDKCalendar (calen, 0);
	  if (calen->exitType == vNORMAL)
	    {

	      sprintf (tmp, "%02d/%02d/%d", calen->day, calen->month,
		       calen->year);
	      setCDKMatrixCell (matriz, 7, 1, tmp);
	      destroyCDKCalendar (calen);
	      drawCDKMatrix (matriz, TRUE);
	    }
	  break;


	}

    }
  return 1;









}

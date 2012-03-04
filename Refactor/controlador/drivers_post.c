#include <cdk.h>

#include "drivers_post.h"
#include "../widgets/calendario.h"
#include "../widgets/archivos.h"
#include "../widgets/listados.h"
int
driver_proveedores_post (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input)
{

  char **cosa = (char **) clientData;
  CDKMATRIX *matriz = (CDKMATRIX *) object;
  //char *valor = copyChar (getCDKMatrixCell (matriz, 1, 1));
  setCDKMatrixCell (matriz, 1, 1, cosa[1]);

  int nros[1];
  nros[0] = 3;

  normalizar_columna (matriz, nros, 1);


  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {


    }

  return 1;

}


int
driver_clientes_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData, chtype input)
{



  CDKMATRIX *matriz = (CDKMATRIX *) object;

  int nros[1];
  nros[0] = 3;

  normalizar_columna (matriz, nros, 1);


  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);


  return 1;
}

int
driver_RMP_post (EObjectType cdktype GCC_UNUSED,
		 void *object GCC_UNUSED, void *clientData, chtype input)
{
  CDKMATRIX *matriz = (CDKMATRIX *) object;
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  int filas[3];
  filas[0] = 6;
  filas[1] = 7;
  filas[2] = 8;
  normalizar_columna (matriz, filas, 3);
  return 1;
}

int
driver_tecnicos_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData, chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  int nros[1];
  nros[0] = 3;
  normalizar_columna (matriz, nros, 1);
  return 1;
}

int
driver_insumos_post (EObjectType cdktype GCC_UNUSED,
		     void *object GCC_UNUSED, void *clientData, chtype input)
{
  CDKMATRIX *matriz = (CDKMATRIX *) object;
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  int filas[1];
  filas[0] = 7;

  normalizar_columna (matriz, filas, 1);
  int row = getCDKMatrixRow (matriz);
  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {
      switch (row)

	{
	case 5:

	  mostrar_calendario (matriz, calen);
	  break;
	case 12:
	  mostrar_calendario (matriz, calen);
	  break;
	case 13:
	  mostrar_referencias (matriz, "Tecnico", "Tecnico_id");
	  break;
	case 14:
	  mostrar_referencias (matriz, "Proveedor", "Proveedor_id");
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
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);

  int row = getCDKMatrixRow (matriz);


  int filas[1];
  filas[0] = 4;
  normalizar_columna (matriz, filas, 1);


  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {
      switch (row)
	{
	case 3:
	  mostrar_referencias (matriz, "RMP", "Producto_id");
	  break;
	case 6:
	  mostrar_referencias (matriz, "Tecnico", "Tecnico_id");
	  break;
	case 7:
	  mostrar_calendario (matriz, calen);
	  break;
	case 8:
	  mostrar_referencias (matriz, "Tecnico", "Tecnico_id");
	  break;
	case 9:
	  mostrar_calendario (matriz, calen);
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
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  int filas[1];
  filas[0] = 4;
  normalizar_columna (matriz, filas, 1);
  int row = getCDKMatrixRow (matriz);
  int elegido;
  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {
      switch (row)

	{

	case 2:
	  mostrar_referencias (matriz, "Orden_produccion", "Lote");
	  break;
	case 5:
	  mostrar_referencias (matriz, "Insumo", "IR");
	  break;
	case 6:
	  mostrar_referencias (matriz, "RMP", "Producto_id");
	  break;
	case 7:
	  elegir_archivo (matriz);
	  break;
	case 8:
	  elegir_archivo (matriz);
	  break;
	case 10:
	  mostrar_referencias (matriz, "Orden_produccion",
			       "Orden_produccion_id");
	  break;

	case 12:
	  mostrar_referencias (matriz, "Tecnico", "Tecnico_id");
	  break;
	case 14:
	  mostrar_referencias (matriz, "Tecnico", "Tecnico_id");
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
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  // char tmp[256];
  int elegido;
  int row = getCDKMatrixRow (matriz);
  int filas[1];
  filas[0] = 4;
  normalizar_columna (matriz, filas, 1);



  if (input == KEY_DOWN && matriz->crow == 5)
    {


   //   validar_cantidad (matriz);
    }


  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {
      switch (row)
	{
	case 2:
	  mostrar_referencias (matriz, "Cliente", "Cliente_id");

	  break;
	case 3:
	  mostrar_referencias (matriz, "RMP", "Producto_id");

	  break;
	case 5:

	  mostrar_calendario (matriz, calen);
	  break;

	case 6:

	  mostrar_calendario (matriz, calen);

	  break;


	}

    }
  return 1;

}


int
driver_orden_pedido_proveedor_post (EObjectType cdktype GCC_UNUSED,
				    void *object GCC_UNUSED,
				    void *clientData, chtype input)
{


  CDKMATRIX *matriz = (CDKMATRIX *) object;
  setCDKMatrixCell (matriz, 1, 1, ((char **) clientData)[1]);
  // char tmp[256];
  int row = getCDKMatrixRow (matriz);
  int filas[3];
  filas[0] = 5;
  filas[1] = 6;
  filas[2] = 7;
  normalizar_columna (matriz, filas, 3);
  if (input != KEY_UP && input != KEY_DOWN && input != KEY_LEFT
      && input != KEY_RIGHT)
    {
      switch (row)
	{
	case 2:

	  mostrar_referencias (matriz, "Orden_pedido_producto",
			       "Orden_pedido_producto_id");

	  break;
	case 3:
	  mostrar_calendario (matriz, calen);
	  break;


	}

    }
  return 1;

}


void
desproteger_id (CDKMATRIX * matriz)
{

  if (matriz->crow != 1)
    {
      matriz->colvalues[1] = vMIXED;

    }


}

void
normalizar_columna (CDKMATRIX * matriz, int *row, int nro)
{


  int i;
  for (i = 0; i <= nro; i++)
    {
      if (matriz->crow != row[i])
	{
	  matriz->colvalues[1] = vMIXED;
	}

    }

}

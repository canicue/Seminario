/* 
 * File:   drivers.h
 * Author: charlie
 *
 * Created on 16 de febrero de 2012, 01:47
 */

#ifndef _DRIVERS_H
#define	_DRIVERS_H
//#include <cdk/cdk.h>
#include <cdk/matrix.h>
//#include <curdefs.h>
#include <cdk/template.h>
int prueba_binding (EObjectType cdkType GCC_UNUSED, void *object,
		    void *clientData GCC_UNUSED, chtype input);
int prueba_preprocess (EObjectType cdkType GCC_UNUSED, void *object,
		       void *clientData GCC_UNUSED, chtype input);
int driver_borrado (EObjectType cdktype GCC_UNUSED, void *object GCC_UNUSED,
		    void *clientData, chtype key);
int driver_insumo_pre (EObjectType cdktype GCC_UNUSED,
		       void *object GCC_UNUSED, void *clientData,
		       chtype input);
int driver_producto_terminado_pre (EObjectType cdktype GCC_UNUSED,
				   void *object GCC_UNUSED, void *clientData,
				   chtype input);
int driver_proveedores_pre (EObjectType cdktype GCC_UNUSED,
			    void *object GCC_UNUSED, void *clientData,
			    chtype input);
int driver_orden_pedido_producto_pre (EObjectType cdktype GCC_UNUSED,
				      void *object GCC_UNUSED,
				      void *clientData, chtype input);
int driver_clientes_pre (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input);
int driver_tecnicos_pre (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input);
int driver_RMP_pre (EObjectType cdktype GCC_UNUSED, void *object GCC_UNUSED,
		    void *clientData, chtype input);

int driver_orden_produccion_pre (EObjectType cdktype GCC_UNUSED,
				 void *object GCC_UNUSED,
				 void *clientData, chtype input);
int driver_orden_pedido_proveedor_pre (EObjectType cdktype GCC_UNUSED,
				       void *object GCC_UNUSED,
				       void *clientData, chtype input);
void proteger_id (CDKMATRIX * matriz);
void columna_numerica (CDKMATRIX * matriz, int *row, int nro);

#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _DRIVERS_H */

/* 
 * File:   drivers_post.h
 * Author: charlie
 *
 * Created on 21 de febrero de 2012, 18:51
 */

#ifndef _DRIVERS_POST_H
#define	_DRIVERS_POST_H
#include <cdk.h>
#include <scroll.h>
#include <curdefs.h>
#include<calendar.h>
#include<matrix.h>
CDKSCROLL *lista_pro;
CDKCALENDAR *calen;
int
driver_proveedores_post (EObjectType cdktype GCC_UNUSED,
			 void *object GCC_UNUSED, void *clientData,
			 chtype input);
int
driver_clientes_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData,
		      chtype input);
int
driver_RMP_post (EObjectType cdktype GCC_UNUSED,
		 void *object GCC_UNUSED, void *clientData, chtype input);
int
driver_tecnicos_post (EObjectType cdktype GCC_UNUSED,
		      void *object GCC_UNUSED, void *clientData,
		      chtype input);
int
driver_insumos_post (EObjectType cdktype GCC_UNUSED,
		     void *object GCC_UNUSED, void *clientData, chtype input);

int
driver_producto_terminado_post (EObjectType cdktype GCC_UNUSED,
				void *object GCC_UNUSED,
				void *clientData, chtype input);
int
driver_orden_produccion_post (EObjectType cdktype GCC_UNUSED,
			      void *object GCC_UNUSED,
			      void *clientData, chtype input);
int
driver_orden_pedido_producto_post (EObjectType cdktype GCC_UNUSED,
				   void *object GCC_UNUSED,
				   void *clientData, chtype input);


#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _DRIVERS_POST_H */

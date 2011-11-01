/* 
 * File:   proveedores.h
 * Author: canicue
 *
 * Created on 31 de octubre de 2011, 00:44
 */

#ifndef _PROVEEDORES_H
#define	_PROVEEDORES_H
#include "tipos.h"
/* proveedor_id TEXT NOT NULL,
  nombre TEXT CHARACTER SET ucs2 NOT NULL,
  telefon int(11) NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,*/

void agregar_proveedor(PROVEEDOR *proveedor);
void borrar_proveedor(int proveedor_id);
void modificar_proveedor(int proveedor_id);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _PROVEEDORES_H */


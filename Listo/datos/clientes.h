/* 
 * File:   clientes.h
 * Author: canicue
 *
 * Created on 30 de octubre de 2011, 21:56
 */

#ifndef _CLIENTES_H
#define	_CLIENTES_H
#include "tipos.h"
#define AGREGAR "INSERT INTO CLIENTES(cliente_id,nombre,telefono,direccion) VALUES(%s,%s,%s,%s,%s)"
void agregar_cliente(CLIENTE *cliente);
void borrar_cliente(int cliente_id);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _CLIENTES_H */


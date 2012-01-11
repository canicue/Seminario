/* 
 * File:   clientes.h
 * Author: canicue
 *
 * Created on 30 de octubre de 2011, 21:56
 */

#ifndef _CLIENTES_H
#define	_CLIENTES_H
#include "tipos.h"

void agregar_cliente(CLIENTE *cliente);
void borrar_cliente(char *cliente_id);
void modificar_cliente(char *cliente_id,CLIENTE *nuevo);
CLIENTE *buscar_cliente(char *campo,char *valor);
CLIENTE *listar_clientes();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _CLIENTES_H */


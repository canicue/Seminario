/* 
 * File:   clientes.h
 * Author: canicue
 *
 * Created on 3 de noviembre de 2011, 12:31
 */

#ifndef _CLIENTES_H
#define	_CLIENTES_H
#include <cdk.h>
#include "../../controlador/config.h"
void menu_clientes(CDKSCREEN *cdkScreen);
void alta_cliente(CDKSCREEN *pantalla);
void baja_cliente(CDKSCREEN *pantalla);

void clientes();

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _CLIENTES_H */


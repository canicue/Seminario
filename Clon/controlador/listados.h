/* 
 * File:   listados.h
 * Author: canicue
 *
 * Created on 23 de enero de 2012, 13:44
 */

#ifndef _LISTADOS_H
#define	_LISTADOS_H
#include "../datos/datos.h"
void listar(char *tabla);
void leer_registro(char *tabla,char *campo,char *valor);
CDKALPHALIST *listados(char *tabla);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _LISTADOS_H */


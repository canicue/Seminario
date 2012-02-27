/* 
 * File:   menu.h
 * Author: charlie
 *
 * Created on 15 de febrero de 2012, 01:16
 */

#ifndef _MENU_H
#define	_MENU_H
#include <cdk.h>
#include "../controlador/clientes.h"
#include "../controlador/proveedores.h"
#include "../controlador/tecnicos.h"
void menu_clientes ();
void menu_proveedores ();
void menu_tecnicos ();
void menu_abm (char *titulo, void (*alta) (), void (*baja) (void *pantalla),
	       void (*modificacion) (void *pantalla));
char *opciones[] =
  { "Alta</B>", "Baja</B>", "Modificación</B>", "Volver</B>" };
#ifdef	__cplusplus
extern "C"
{
#endif




#ifdef	__cplusplus
}
#endif

#endif				/* _MENU_H */

/* 
 * File:   tecnicos.h
 * Author: canicue
 *
 * Created on 31 de octubre de 2011, 00:44
 */

#ifndef _TECNICOS_H
#define	_TECNICOS_H

#include "tipos.h"

void agregar_tecnico(TECNICO *tecnico);
void borrar_tecnico(char *tecnico_id);
void buscar_tecnico(char *campo,char *valor);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _TECNICOS_H */


/* 
 * File:   utils.h
 * Author: canicue
 *
 * Created on 20 de enero de 2012, 21:29
 */

#ifndef _UTILS_H
#define	_UTILS_H
#include <cdk.h>
//char **leer_matriz(CDKMATRIX *matriz);
boolean validar_matriz(CDKMATRIX matriz, CDKSCREEN *cdkScreen);
char **info_matriz(CDKMATRIX *matriz);
//char* texto[]={"asdf"};
char *buffer[100];
// char *merda[]={"mierda","carajo"};
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _UTILS_H */


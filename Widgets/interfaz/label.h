/* 
 * File:   label.h
 * Author: canicue
 *
 * Created on 30 de octubre de 2011, 00:23
 */

#ifndef _LABEL_H
#define	_LABEL_H
#include <cdk/label.h>
#include <cdk/cdk_util.h>

#include "utils.h"
CDKLABEL *crear_label (CDKSCREEN *cdkscreen,char** mensaje, int x, int y);
void demo_label();
#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* _LABEL_H */


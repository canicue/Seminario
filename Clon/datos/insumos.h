/* 
 * File:   insumos.h
 * Author: canicue
 *
 * Created on 31 de octubre de 2011, 00:44
 */

#ifndef _INSUMOS_H
#define	_INSUMOS_H
#include "tipos.h"

/*
 IR TEXT NOT NULL,
  materia_prima INTEGER NOT NULL,
  insumo_productivo INTEGER NOT NULL,
  producto_semi_elaborado INTEGER NOT NULL,
  fecha_ingreso TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad INTEGER NOT NULL,
  obsevacion_simple_vista TEXT NOT NULL,
  embalaje TEXT NOT NULL,
  transporte TEXT NOT NULL,
  documentos_material_adjunto TEXT NOT NULL,
  fecha_de _control TEXT NOT NULL,
  responsable TEXT NOT NULL,
  id_proveedor TEXT NOT NULL,


 */


void agregar_insumo(INSUMO *insumo);
void borrar_insumo(int insumo_id);
void modificar_insumo(char *insumo_id);
INSUMO *buscar_insumo(char *campo,char *valor);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _INSUMOS_H */


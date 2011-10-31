/* 
 * File:   tipos.h
 * Author: canicue
 *
 * Created on 15 de octubre de 2011, 22:45
 */

#ifndef _TIPOS_H
#define	_TIPOS_H

typedef struct t_cliente
{


  char cliente_id[15];
  char nombre[255];
  char telefono[15];
  char direccion[255];

  char email[63];
  // PRIMARY KEY (cliente_id)
} CLIENTE;

/*
 *
 *
typedef struct t_producto_terminado {
  char* producto_terminado_id[15];
  char* lote[255]; 
  char* material[255]; 
  int cantidad;
  char* IR[255]; 
  RMP TEXT NOT NULL,
  CC TEXT NOT NULL,
  IO TEXT NOT NULL,
  id_producto TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  id_orden_produccion TEXT NOT NULL,
  emision_area_productiva TEXT NOT NULL,
  responsable_area_productiva TEXT NOT NULL,
  emision_area_tecnica TEXT NOT NULL,
  responsable_area_tecnica TEXT NOT NULL,
  vencimiento TEXT NOT NULL,
  PRIMARY KEY (producto_terminado_id),
  KEY id_producto (id_producto),
  KEY id_orden_produccion (id_orden_produccion),
  CONSTRAINT producto_terminado_ibfk_1 FOREIGN KEY (id_producto) REFERENCES RMP (producto_id),
  CONSTRAINT producto_terminado_ibfk_2 FOREIGN KEY (id_orden_produccion) REFERENCES orden_produccion (orden_produccion_id)
); 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */
typedef struct t_producto
{




};
 

typedef struct t_programa_produccion {
  char* programa_produccion_id[15];
  char* id_orden_produccion[15];
  int cantidad ;
  char* fecha_comprometida[15];
  char* id_cliente[15];
  char* responsable[255] ;//TEXT NOT NULL, //ver esto
  char* produccion[255]; 
//  PRIMARY KEY (programa_produccion_id),
 // KEY af (id_orden_produccion),
 // KEY id_cliente (id_cliente),
//  CONSTRAINT af FOREIGN KEY (id_orden_produccion) REFERENCES orden_produccion (orden_produccion_id),
 // CONSTRAINT programa_produccion_ibfk_1 FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id)
  } PROGRAMA_PRODUCCION;

typedef struct t_proveedor
{
  char *proveedor_id[15];
  char *nombre[255];
  char *telefono[15];
  char *direccion[255];
  char *email[63];
  //PRIMARY KEY (proveedor_id)
} PROVEEDOR;

typedef struct t_tecnico
{
  char *tecnico_id[15];
  char *nombre[255];
  char *telefono[15];
  char *direccion[255];
  char *email[63];

  char *area[255];

} TECNICO;







typedef struct t_rmp
{
  char *producto_id[15];
  char *referencias[255];
  char *control_calidad[255];
  char *instruccion_operativa[255];
  char *descripcion[255];
  int cantidad_materia_prima;
  char *descripcion_materia_prima[255];
  int cantidad_insumo;
  char *descripcion_insumo_productivo[255];
  char *descripcion_producto_semielaborado[255];

} RMP;

#ifdef	__cplusplus
extern "C"
{
#endif
/*    CREATE TABLE RMP (
  producto_id TEXT NOT NULL,
  referencias TEXT NOT NULL,
  control_calidad TEXT NOT NULL,
  instruccion_operativa TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad_materia_prima int(11) NOT NULL,
  cantidad_insumo int(11) NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL,
  PRIMARY KEY (producto_id)
);*/



#ifdef	__cplusplus
}
#endif

#endif				/* _TIPOS_H */

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


typedef struct t_producto_terminado {
  char producto_terminado_id[15];
  char lote[255]; 
  char material[255]; 
  int cantidad;
  char IR[255]; 
  char RMP[15] ;
  char CC[255];
  char IO[255] ;
  char id_producto[15] ;
  char descripcion [510];
  char id_orden_produccion[15];
  char emision_area_productiva[510];
  char responsable_area_productiva[15];
  char emision_area_tecnica[255];
  char responsable_area_tecnica[15];
  char vencimiento[31] ;
} PRODUCTO_TERMINADO;



typedef struct t_programa_produccion {
  char programa_produccion_id[15];
  char id_orden_produccion[15];
  int cantidad ;
  char fecha_comprometida[15];
  char id_cliente[15];
  char responsable[255] ;//TEXT NOT NULL, //ver esto
  char produccion[255]; 
//  PRIMARY KEY (programa_produccion_id),
 // KEY af (id_orden_produccion),
 // KEY id_cliente (id_cliente),
//  CONSTRAINT af FOREIGN KEY (id_orden_produccion) REFERENCES orden_produccion (orden_produccion_id),
 // CONSTRAINT programa_produccion_ibfk_1 FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id)
  } PROGRAMA_PRODUCCION;

typedef struct t_proveedor
{
  char proveedor_id[15];
  char nombre[255];
  char telefono[15];
  char direccion[255];
  char email[63];
  //PRIMARY KEY (proveedor_id)
} PROVEEDOR;

typedef struct t_tecnico
{
  char tecnico_id[15];
  char nombre[255];
  char telefono[15];
  char direccion[255];
  char email[63];

  char area[255];

} TECNICO;







typedef struct t_rmp
{
  char producto_id[15];
  char referencias[255];
  char control_calidad[255];
  char instruccion_operativa[255];
  char descripcion[255];
  int cantidad_materia_prima;
  char descripcion_materia_prima[255];
  int cantidad_insumo;
  char descripcion_insumo_productivo[255];
  char descripcion_producto_semielaborado[255];

} RMP;

/*
 CREATE TABLE insumo (
  IR TEXT NOT NULL,
  materia_prima tinyint(1) NOT NULL,
  insumo_productivo tinyint(1) NOT NULL,
  producto_semi_elaborado tinyint(1) NOT NULL,
  fecha_ingreso TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad int(11) NOT NULL,
  obsevacion_simple_vista TEXT NOT NULL,
  embalaje TEXT NOT NULL,
  transporte TEXT NOT NULL,
  documentos_maerial_adjunto TEXT NOT NULL,
  fecha_de _control TEXT NOT NULL,
  responsable TEXT NOT NULL,
  id_proveedor TEXT NOT NULL,
  PRIMARY KEY (IR),
  KEY id_proveedor (id_proveedor),
  KEY fk_it (responsable),
  CONSTRAINT fk_it FOREIGN KEY (responsable) REFERENCES tecnico (tecnico_id),
  CONSTRAINT insumo_ibfk_1 FOREIGN KEY (id_proveedor) REFERENCES proveedor (proveedor_id)
);


 */
typedef struct t_insumo{
    char IR[15];
    int insumo_productivo;
     int producto_semi_elaborado;
  char fecha_ingreso[31];
  char descripcion[510];
  int cantidad;
  char obsevacion_simple_vista[510];
  char embalaje[255];
  char transporte[255];
  char documentos_material_adjunto[255];
  char fecha_de_control[31];
  char responsable[15];
  char id_proveedor[15];

} INSUMO;


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

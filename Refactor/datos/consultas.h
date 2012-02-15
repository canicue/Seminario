/* 
 * File:   consultas.h
 * Author: canicue
 *
 * Created on 14 de febrero de 2012, 23:53
 */

#ifndef _CONSULTAS_H
#define	_CONSULTAS_H
//GENERAL
#define BUSCAR_REGISTRO "SELECT * FROM %s WHERE %s='%s'"
#define LISTAR_REGISTROS "SELECT * FROM %s "
#define MODIFICAR_REGISTRO_CHAR "UPDATE %s SET %s='%s' WHERE %s='%s'"
#define  VER_TABLA "SELECT * FROM %s LIMIT=%d "
//CLIENTES

#define AGREGAR_CLIENTE "INSERT INTO CLIENTE(cliente_id,nombre,telefono,direccion,email) VALUES('%s','%s','%s','%s','%s')"
#define BORRAR_CLIENTE "DELETE FROM CLIENTE WHERE cliente_id='%s'"



//PROVEEDORES

#define AGREGAR_PROVEEDOR "INSERT INTO PROVEEDORES(proveedor_id,nombre,telefono,direccion,email) VALUES('%s','%s','%s','%s','%s')"
#define BORRAR_PROVEEDOR "DELETE FROM PROVEEDOR WHERE proveedor_id='%s'"

//TECNICOS

#define BORRAR_TECNICO "DELETE FROM TECNICO WHERE tecnico_id='%s'"


//INSUMOS

#define AGREGAR_INSUMO "INSERT INTO INSUMO(IR,insumo_productivo,\
producto_semi_elaborado,fecha_ingreso,descripcion,cantidad,\
observacion_simple_vista,embalaje,transporte,\
documentos_material_adjunto,fecha_de_control,responsable,\
id_proveedor VALUES('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s') )"
#define BORRAR_INSUMO "DELETE FROM INSUMO WHERE IR='%s"

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _CONSULTAS_H */


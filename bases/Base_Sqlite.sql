
CREATE TABLE RMP (
  producto_id TEXT NOT NULL,
  referencias TEXT NOT NULL,
  control_calidad TEXT NOT NULL,
  instruccion_operativa TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad_materia_prima INTEGER NOT NULL,
  cantidad_insumo INTEGER NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL,
  PRIMARY KEY (producto_id)
);

CREATE TABLE cliente (
  cliente_id TEXT NOT NULL,
  nombre TEXT NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  PRIMARY KEY (cliente_id)
);

CREATE TABLE insumo (
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
  PRIMARY KEY (IR),
 --KEY id_proveedor (id_proveedor),
  --KEY fk_it (responsable),
  CONSTRAINT fk_it FOREIGN KEY (responsable) REFERENCES tecnico (tecnico_id),
  CONSTRAINT insumo_ibfk_1 FOREIGN KEY (id_proveedor) REFERENCES proveedor (proveedor_id)
);

CREATE TABLE orden_pedido_producto (
  orden_pedido_producto_id TEXT NOT NULL,
  id_cliente TEXT NOT NULL,
  id_producto TEXT NOT NULL,
  cantidad INTEGER NOT NULL,
  fecha TEXT NOT NULL,
  fecha_estimada_entrega TEXT NOT NULL,
  observacion TEXT NOT NULL,
  PRIMARY KEY (orden_pedido_producto_id),
  --KEY id_cliente (id_cliente),
  --KEY id_producto (id_producto),
  CONSTRAINT fk_sdf FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id),
  CONSTRAINT orden_pedido_producto_ibfk_1 FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id),
  CONSTRAINT orden_pedido_producto_ibfk_2 FOREIGN KEY (id_producto) REFERENCES RMP (producto_id)
);

CREATE TABLE orden_pedido_proveedor (
  orden_pedido_proveedor_id TEXT NOT NULL,
  id_orden_pedido_producto TEXT NOT NULL,
  fecha TEXT NOT NULL,
  observacion TEXT NOT NULL,
  cantidad_materia_prima INTEGER NOT NULL,
  cantidad_insumo_productivo INTEGER NOT NULL,
  cantidad_producto_semielaborado INTEGER NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL,
  PRIMARY KEY (orden_pedido_proveedor_id),
--  KEY id_orden_pedido_producto (id_orden_pedido_producto),
  CONSTRAINT orden_pedido_proveedor_ibfk_1 FOREIGN KEY (id_orden_pedido_producto) REFERENCES orden_pedido_producto (orden_pedido_producto_id)
);

CREATE TABLE orden_produccion (
  orden_produccion_id TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  id_producto TEXT NOT NULL,
  cantidad INTEGER NOT NULL,
  lote TEXT NOT NULL,
  responsable_area_productiva TEXT NOT NULL,
  fecha_emision_area_productiva TEXT NOT NULL,
  responsable_area_tecnica TEXT NOT NULL,
  fecha_emision_area_tecnica TEXT NOT NULL,
  materiales_utilizados TEXT NOT NULL,
  denominacion TEXT NOT NULL,
  analisis_IR TEXT NOT NULL,
  id_programa_produccion TEXT NOT NULL,
  PRIMARY KEY (orden_produccion_id),
  --KEY fka (id_producto),
  --KEY fk (id_programa_produccion),
  --KEY fk_ot (responsable_area_tecnica),
  CONSTRAINT fk_ot FOREIGN KEY (responsable_area_tecnica) REFERENCES tecnico (tecnico_id),
  CONSTRAINT fk FOREIGN KEY (id_programa_produccion) REFERENCES programa_produccion (programa_produccion_id),
  CONSTRAINT fka FOREIGN KEY (id_producto) REFERENCES RMP (producto_id)
);

CREATE TABLE producto_terminado (
  producto_terminado_id TEXT NOT NULL,
  lote TEXT NOT NULL,
  material TEXT NOT NULL,
  cantidad INTEGER NOT NULL,
  IR TEXT NOT NULL,
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
  --KEY id_producto (id_producto),
  --KEY id_orden_produccion (id_orden_produccion),
  CONSTRAINT producto_terminado_ibfk_1 FOREIGN KEY (id_producto) REFERENCES RMP (producto_id),
  CONSTRAINT producto_terminado_ibfk_2 FOREIGN KEY (id_orden_produccion) REFERENCES orden_produccion (orden_produccion_id)
);
----







----
-- listo
CREATE TABLE programa_produccion (
  programa_produccion_id TEXT NOT NULL,
  id_orden_produccion TEXT NOT NULL,
  cantidad INTEGER NOT NULL,
  fecha_comprometida TEXT NOT NULL,
  id_cliente TEXT NOT NULL,
  responsable TEXT NOT NULL,
  produccion TEXT NOT NULL,
  PRIMARY KEY (programa_produccion_id),
  --KEY af (id_orden_produccion),
  --KEY id_cliente (id_cliente),
  CONSTRAINT af FOREIGN KEY (id_orden_produccion) REFERENCES orden_produccion (orden_produccion_id),
  CONSTRAINT programa_produccion_ibfk_1 FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id),
  CONSTRAINT responsable_fk FOREIGN KEY (responsable) REFERENCES tecnico(tecnico_id)
);
--listo
CREATE TABLE proveedor (
  proveedor_id TEXT NOT NULL,
  nombre TEXT CHARACTER  NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  PRIMARY KEY (proveedor_id)
);
--listo
CREATE TABLE tecnico (
  tecnico_id TEXT NOT NULL,
  nombre TEXT NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  area TEXT NOT NULL,
  PRIMARY KEY (tecnico_id)
);

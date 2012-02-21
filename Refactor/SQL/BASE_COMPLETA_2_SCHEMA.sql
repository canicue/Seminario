




----------------------------------------------------------------------------------------------------------------------------


PRAGMA foreign_keys=OFF;

CREATE TABLE proveedor (
  proveedor_id INTEGER PRIMARY KEY NOT NULL,
  nombre TEXT CHARACTER  NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL
);
BEGIN TRANSACTION;
CREATE TABLE RMP (
  producto_id INTEGER PRIMARY KEY NOT NULL,
  referencias TEXT NOT NULL,
  control_calidad TEXT NOT NULL,
  instruccion_operativa TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad_materia_prima INTEGER NOT NULL,
  cantidad_insumo_productivo INTEGER NOT NULL,
  cantidad_producto_semielaborado INTEGER NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL
);


CREATE TABLE orden_pedido_producto (
  orden_pedido_producto_id INTEGER PRIMARY KEY NOT NULL,
  id_cliente INTEGER NOT NULL,
  id_producto INTEGER NOT NULL,
  cantidad INTEGER NOT NULL,
  fecha TEXT NOT NULL,
  fecha_estimada_entrega TEXT NOT NULL,
  observacion TEXT NOT NULL,
  CONSTRAINT fk_sdf FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id),
  CONSTRAINT orden_pedido_producto_ibfk_1 FOREIGN KEY (id_cliente) REFERENCES cliente (cliente_id),
  CONSTRAINT orden_pedido_producto_ibfk_2 FOREIGN KEY (id_producto) REFERENCES RMP (producto_id)
);
CREATE TABLE orden_pedido_proveedor (
  orden_pedido_proveedor_id INTEGER PRIMARY KEY NOT NULL,
  id_orden_pedido_producto INTEGER NOT NULL,
  fecha TEXT NOT NULL,
  observacion TEXT NOT NULL,
  cantidad_materia_prima INTEGER NOT NULL,
  cantidad_insumo_productivo INTEGER NOT NULL,
  cantidad_producto_semielaborado INTEGER NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL,
  CONSTRAINT orden_pedido_proveedor_ibfk_1 FOREIGN KEY (id_orden_pedido_producto) REFERENCES orden_pedido_producto (orden_pedido_producto_id)
);


CREATE TABLE orden_produccion (
  orden_produccion_id INTEGER PRIMARY KEY NOT NULL,
  descripcion TEXT NOT NULL,
  id_producto INTEGER NOT NULL,
  cantidad INTEGER NOT NULL,
  lote INTEGER NOT NULL,
  responsable_area_productiva INTEGER NOT NULL,
  fecha_emision_area_productiva TEXT NOT NULL,
  responsable_area_tecnica TEXT NOT NULL,
  fecha_emision_area_tecnica TEXT NOT NULL,
  materiales_utilizados TEXT NOT NULL,
  denominacion TEXT NOT NULL,
  analisis_IR TEXT NOT NULL,
  id_programa_produccion INTEGER NOT NULL,
  CONSTRAINT fk_ot FOREIGN KEY (responsable_area_tecnica) REFERENCES tecnico (tecnico_id),
  CONSTRAINT fk_opp FOREIGN KEY (id_producto) REFERENCES RMP (producto_id),
  CONSTRAINT fk_lote FOREIGN KEY (lote) REFERENCES orden_pedido_proveedor (lote)
);
CREATE TABLE tecnico (
  tecnico_id INTEGER PRIMARY KEY  NOT NULL,
  nombre TEXT NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  area TEXT NOT NULL
);

CREATE TABLE insumo (IR INTEGER PRIMARY KEY,
	   	materia_prima INTEGER, 
		insumo_productivo INTEGER, 
		producto_semi_elaborado INTEGER, 
		fecha_ingreso TEXT, 
		descripcion TEXT, 
		cantidad INTEGER, 
		obsevacion_simple_vista TEXT, 
		embalaje TEXT, 
		transporte TEXT, 
		documentos_material_adjunto TEXT, 
		fecha_de_control _control TEXT, 
		responsable INTEGER, 
		id_proveedor INTEGER,
		CONSTRAINT fk_ip FOREIGN KEY(responsable) REFERENCES tecnico(tecnico_id),
		CONSTRAINT fk_ip FOREIGN KEY(id_proveedor) REFERENCES proveedor(proveedor_id));
CREATE TABLE cliente (Cliente_id INTEGER PRIMARY KEY, Nombre TEXT, Telefono INTEGER, Direccion TEXT, Email TEXT);


CREATE TABLE producto_terminado (producto_terminado_id INTEGER PRIMARY KEY, 
		lote INTEGER, 
		material TEXT, 
		cantidad INTEGER, 
		IR INTEGER, 
		RMP INTEGER, 
		CC TEXT, 
		IO TEXT, 
		descripcion TEXT, 
		id_orden_produccion TEXT, 
		emision_area_productiva TEXT, 
		responsable_area_productiva INTEGER, 
		emision_area_tecnica TEXT, 
		responsable_area_tecnica INTEGER, 
		vencimiento TEXT,

  CONSTRAINT fk_pt FOREIGN KEY (IR) REFERENCES insumo (IR),
  CONSTRAINT fk_rmp FOREIGN KEY (RMP) REFERENCES RMP (producto_id),
  CONSTRAINT fk_rap FOREIGN KEY (responsable_area_productiva) REFERENCES tecnico (tecnico_id),
  CONSTRAINT fk_rat FOREIGN KEY (responsable_area_tecnica) REFERENCES tecnico (tecnico_id)

);

COMMIT;

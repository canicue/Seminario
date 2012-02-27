CREATE TABLE RMP (
  Producto_id INTEGER PRIMARY KEY NOT NULL,
  Referencias TEXT NOT NULL,
  Control_calidad TEXT NOT NULL,
  Instruccion_operativa TEXT NOT NULL,
  Descripcion TEXT NOT NULL,
  Cantidad_materia_prima INTEGER NOT NULL,
  Cantidad_insumo_productivo INTEGER NOT NULL,
  Cantidad_producto_semielaborado INTEGER NOT NULL,
  Descripcion_materia_prima TEXT NOT NULL,
  Descripcion_insumo_productivo TEXT NOT NULL,
  Descripcion_producto_semielaborado TEXT NOT NULL
);
CREATE TABLE Cliente (Cliente_id INTEGER PRIMARY KEY, Nombre TEXT, Telefono INTEGER, Direccion TEXT, Email TEXT);
CREATE TABLE Insumo (IR INTEGER PRIMARY KEY,
	   	Materia_prima INTEGER, 
		Insumo_productivo INTEGER, 
		Producto_semi_elaborado INTEGER, 
		Fecha_ingreso TEXT, 
		Descripcion TEXT, 
		Cantidad INTEGER, 
		Obsevacion_simple_vista TEXT, 
		Embalaje TEXT, 
		Transporte TEXT, 
		Documentos_material_adjunto TEXT, 
		Fecha_de_control _control TEXT, 
		Responsable INTEGER, 
		Id_proveedor INTEGER,
		CONSTRAINT fk_ip FOREIGN KEY(Responsable) REFERENCES Tecnico(Tecnico_id),
		CONSTRAINT fk_ip FOREIGN KEY(Id_proveedor) REFERENCES proveedor(proveedor_id));
CREATE TABLE Orden_pedido_producto (
  Orden_pedido_Producto_id INTEGER PRIMARY KEY NOT NULL,
  Id_cliente INTEGER NOT NULL,
  Id_producto INTEGER NOT NULL,
  Cantidad INTEGER NOT NULL,
  Fecha TEXT NOT NULL,
  Fecha_estimada_entrega TEXT NOT NULL,
  Observacion TEXT NOT NULL,
  CONSTRAINT fk_sdf FOREIGN KEY (Id_cliente) REFERENCES Cliente (Cliente_id),
  CONSTRAINT Orden_pedido_producto_ibfk_1 FOREIGN KEY (Id_cliente) REFERENCES Cliente (Cliente_id),
  CONSTRAINT Orden_pedido_producto_ibfk_2 FOREIGN KEY (Id_producto) REFERENCES RMP (Producto_id)
);
CREATE TABLE Orden_pedido_proveedor (
  Orden_pedido_proveedor_id INTEGER PRIMARY KEY NOT NULL,
  Id_orden_pedido_producto INTEGER NOT NULL,
  Fecha TEXT NOT NULL,
  Observacion TEXT NOT NULL,
  Cantidad_materia_prima INTEGER NOT NULL,
  Cantidad_insumo_productivo INTEGER NOT NULL,
  Cantidad_producto_semielaborado INTEGER NOT NULL,
  Descripcion_materia_prima TEXT NOT NULL,
  Descripcion_insumo_productivo TEXT NOT NULL,
  Descripcion_producto_semielaborado TEXT NOT NULL,
  CONSTRAINT Orden_pedido_proveedor_ibfk_1 FOREIGN KEY (Id_orden_pedido_producto) REFERENCES Orden_pedido_producto (Orden_pedido_Producto_id)
);
CREATE TABLE Orden_produccion (
  Orden_produccion_id INTEGER PRIMARY KEY NOT NULL,
  Descripcion TEXT NOT NULL,
  Id_producto INTEGER NOT NULL,
  Cantidad INTEGER NOT NULL,
  Lote INTEGER NOT NULL,
  Responsable_area_productiva INTEGER NOT NULL,
  Fecha_emision_area_productiva TEXT NOT NULL,
  Responsable_area_tecnica TEXT NOT NULL,
  Fecha_emision_area_tecnica TEXT NOT NULL,
  Materiales_utilizados TEXT NOT NULL,
  Denominacion TEXT NOT NULL,
  Analisis_IR TEXT NOT NULL,
  Id_programa_produccion INTEGER NOT NULL,
  CONSTRAINT fk_ot FOREIGN KEY (Responsable_area_tecnica) REFERENCES Tecnico (Tecnico_id),
  CONSTRAINT fk_opp FOREIGN KEY (Id_producto) REFERENCES RMP (Producto_id),
  CONSTRAINT fk_lote FOREIGN KEY (Lote) REFERENCES Orden_pedido_proveedor (Lote)
);
CREATE TABLE Producto_terminado (Producto_terminado_id INTEGER PRIMARY KEY, 
		Lote INTEGER, 
		Material TEXT, 
		Cantidad INTEGER, 
		IR INTEGER, 
		RMP INTEGER, 
		CC TEXT, 
		IO TEXT, 
		Descripcion TEXT, 
		Id_orden_produccion TEXT, 
		Emision_area_productiva TEXT, 
		Responsable_area_productiva INTEGER, 
		Emision_area_tecnica TEXT, 
		Responsable_area_tecnica INTEGER, 
		Vencimiento TEXT,

  CONSTRAINT fk_pt FOREIGN KEY (IR) REFERENCES insumo (IR),
  CONSTRAINT fk_rmp FOREIGN KEY (RMP) REFERENCES RMP (Producto_id),
  CONSTRAINT fk_rap FOREIGN KEY (responsable_area_productiva) REFERENCES tecnico (tecnico_id),
  CONSTRAINT fk_rat FOREIGN KEY (Responsable_area_tecnica) REFERENCES Tecnico (Tecnico_id)

);
CREATE TABLE proveedor (
  proveedor_id INTEGER PRIMARY KEY NOT NULL,
  Nombre TEXT CHARACTER  NOT NULL,
  Telefono INTEGER NOT NULL,
  Direccion TEXT NOT NULL,
  Email TEXT NOT NULL
);
CREATE TABLE Tecnico (
  Tecnico_id INTEGER PRIMARY KEY  NOT NULL,
  Nombre TEXT NOT NULL,
  Telefono INTEGER NOT NULL,
  Direccion TEXT NOT NULL,
  Email TEXT NOT NULL,
  Area TEXT NOT NULL
);

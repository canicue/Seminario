PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE Proveedor (
  Proveedor_id INTEGER PRIMARY KEY NOT NULL,
  Nombre TEXT CHARACTER  NOT NULL,
  Telefono INTEGER NOT NULL,
  Direccion TEXT NOT NULL,
  Email TEXT NOT NULL
);
INSERT INTO "Proveedor" VALUES(2,'Andrew Campbell','(926)247-3963','897-1094 Placerat. Ave','egestas@velquamdignissim.edu');
INSERT INTO "Proveedor" VALUES(3,'Mannix Dickson','(290)234-9774','4888 Tincidunt St.','torquent.per.conubia@ultriciesornare.ca');
INSERT INTO "Proveedor" VALUES(4,'Magee Scott','(504)308-2655','2588 Luctus Avenue','ligula.Aenean.gravida@enimnisl.org');
INSERT INTO "Proveedor" VALUES(5,'Palmer Mcmahon','(795)608-0191','P.O. Box 661',' 9978 Ultrices Road urna.Nunc@arcu.com');
INSERT INTO "Proveedor" VALUES(6,'Nolan Mullins','(891)947-8053','2522 Ut Road','Etiam.imperdiet@diamluctuslobortis.com');
INSERT INTO "Proveedor" VALUES(7,'Jordan Harper','(809)474-7135','P.O. Box 911',' 9508 Pharetra St.massa.Suspendisse.eleifend@Suspendisse.org');
INSERT INTO "Proveedor" VALUES(8,'Moses Leon','(556)520-3269','8750 Venenatis Ave','Fusce@vitaesodales.com');
INSERT INTO "Proveedor" VALUES(9,'Tanner Long','(441)812-7296','415-7515 Ut Rd.','nonummy.Fusce.fermentum@acmattis.com');
INSERT INTO "Proveedor" VALUES(10,'Kenyon Cotton','(708)742-7709',' P.O. Box 770 4467 Duis St.','ut.nisi.a@pedenecante.edu');
INSERT INTO "Proveedor" VALUES(11,'Marvin Reese','(526)300-0391','Ap #321-7396 Non St.','elit@Aliquam.ca');
INSERT INTO "Proveedor" VALUES(12,'Jamal Estrada','(230)362-8293','Ap #659-6529 Dapibus St.','ipsum.Phasellus.vitae@Proindolor.org');
INSERT INTO "Proveedor" VALUES(13,'','','','');
INSERT INTO "Proveedor" VALUES(14,'','','','');
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
INSERT INTO "RMP" VALUES(1,'libero nec ligula consectetuer rhoncus. Nullam velit dui, semper et,','at','Phasellus elit pede, malesuada vel, venenatis vel, faucibus id, libero.','vulputate, risus a ultricies adipiscing, enim mi tempor lorem, eget',123,132,24,'sed pede nec ante blandit viverra. Donec tempus,','lorem tristique aliquet. Phasellus fermentum convallis ligula. Donec','fames ac turpis egestas. Fusce aliquet magna a neque. Nullam');
INSERT INTO "RMP" VALUES(2,'id enim. Curabitur massa. Vestibulum accumsan neque et nunc. Quisque','Phasellus','euismod enim. Etiam gravida molestie arcu. Sed eu nibh vulputate','vel est tempor bibendum. Donec felis orci, adipiscing non, luctus',166,137,124,'nisl. Maecenas malesuada fringilla est. Mauris eu turpis.','iaculis aliquet diam. Sed diam lorem, auctor quis,','mauris, aliquam eu, accumsan sed, facilisis vitae, orci. Phasellus dapibus');
INSERT INTO "RMP" VALUES(3,'Nunc pulvinar arcu et pede. Nunc sed orci lobortis augue','mattis.','mi felis, adipiscing fringilla, porttitor vulputate, posuere vulputate, lacus. Cras','condimentum eget, volutpat ornare, facilisis eget, ipsum. Donec sollicitudin adipiscing',42,180,186,'consectetuer adipiscing elit. Curabitur sed tortor. Integer aliquam','blandit congue. In scelerisque scelerisque dui. Suspendisse ac','ullamcorper, nisl arcu iaculis enim, sit amet ornare lectus justo');
INSERT INTO "RMP" VALUES(4,'In scelerisque scelerisque dui. Suspendisse ac metus vitae velit egestas','magna','Ut tincidunt vehicula risus. Nulla eget metus eu erat semper','netus et malesuada fames ac turpis egestas. Fusce aliquet magna',180,67,124,'risus, at fringilla purus mauris a nunc. In','nec ligula consectetuer rhoncus. Nullam velit dui, semper','elementum, dui quis accumsan convallis, ante lectus convallis est, vitae');
INSERT INTO "RMP" VALUES(5,'odio vel est tempor bibendum. Donec felis orci, adipiscing non,','sed,','magna. Praesent interdum ligula eu enim. Etiam imperdiet dictum magna.','metus eu erat semper rutrum. Fusce dolor quam, elementum at,',110,148,35,'urna. Nunc quis arcu vel quam dignissim pharetra.','Donec egestas. Duis ac arcu. Nunc mauris. Morbi','lorem, luctus ut, pellentesque eget, dictum placerat, augue. Sed molestie.');
INSERT INTO "RMP" VALUES(6,'Integer aliquam adipiscing lacus. Ut nec urna et arcu imperdiet','id,','senectus et netus et malesuada fames ac turpis egestas. Aliquam','magna. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Etiam',26,21,61,'non quam. Pellentesque habitant morbi tristique senectus et','dignissim magna a tortor. Nunc commodo auctor velit.','sit amet diam eu dolor egestas rhoncus. Proin nisl sem,');
INSERT INTO "RMP" VALUES(7,'Quisque nonummy ipsum non arcu. Vivamus sit amet risus. Donec','varius','nulla. Donec non justo. Proin non massa non ante bibendum','velit. Cras lorem lorem, luctus ut, pellentesque eget, dictum placerat,',148,122,17,'a, magna. Lorem ipsum dolor sit amet, consectetuer','In faucibus. Morbi vehicula. Pellentesque tincidunt tempus risus.','Vivamus sit amet risus. Donec egestas. Aliquam nec enim. Nunc');
INSERT INTO "RMP" VALUES(8,'','','','','','','','','','');
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
INSERT INTO "Orden_pedido_producto" VALUES(1,1000,8,35,'06/19/12','06/29/11','mi, ac');
INSERT INTO "Orden_pedido_producto" VALUES(2,1004,18,28,'08/26/12','01/20/13','mauris. Integer');
INSERT INTO "Orden_pedido_producto" VALUES(3,1005,21,14,'07/15/12','04/03/11','tincidunt dui');
INSERT INTO "Orden_pedido_producto" VALUES(4,1005,23,38,'07/09/11','06/14/12','Etiam gravida');
INSERT INTO "Orden_pedido_producto" VALUES(5,1005,10,47,'07/09/12','06/17/12','Phasellus elit');
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
INSERT INTO "Orden_pedido_proveedor" VALUES(1,1,'3/12/99','observo',12,12,23,'asdf','un insumo','un pe');
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
  CONSTRAINT fk_Lote FOREIGN KEY (Lote) REFERENCES Orden_pedido_proveedor (Lote)
);
INSERT INTO "Orden_produccion" VALUES(1,'aliquet, metus urna convallis erat,',1004,14,1000,1005,'06/21/12','1001','12/28/10','gravida. Aliquam tincidunt, nunc','urna et arcu imperdiet ullamcorper.','1000',1002);
INSERT INTO "Orden_produccion" VALUES(2,'taciti sociosqu ad litora torquent',1006,20,1003,1002,'01/12/13','1001','12/29/12','ridiculus mus. Proin vel','sit amet ultricies sem magna','1005',1006);
INSERT INTO "Orden_produccion" VALUES(3,'non, hendrerit id, ante. Nunc',1005,31,1004,1000,'01/16/11','1005','01/09/12','et arcu imperdiet ullamcorper.','Duis dignissim tempor arcu. Vestibulum','1003',1004);
INSERT INTO "Orden_produccion" VALUES(4,'in aliquet lobortis, nisi nibh',1002,25,1001,1003,'07/25/11','1003','02/22/12','eu metus. In lorem.','vitae, sodales at, velit. Pellentesque','1005',1002);
INSERT INTO "Orden_produccion" VALUES(5,'nec tempus mauris erat eget',1000,13,1005,1003,'08/12/12','1006','09/26/12','mi felis, adipiscing fringilla,','semper pretium neque. Morbi quis','1002',1002);
CREATE TABLE Tecnico (
  Tecnico_id INTEGER PRIMARY KEY  NOT NULL,
  Nombre TEXT NOT NULL,
  Telefono INTEGER NOT NULL,
  Direccion TEXT NOT NULL,
  Email TEXT NOT NULL,
  Area TEXT NOT NULL
);
INSERT INTO "Tecnico" VALUES(1,'Hayden Clemons','(877)280-2647','Ap #892-2742 Nulla Rd.','nunc@nonarcuVivamus.edu','habitant');
INSERT INTO "Tecnico" VALUES(2,'Yuli Vincent','(329)608-5946','Ap #241-9727 Fermentum St.Curae','Donec.tincidunt@nunc.edu','lorem');
INSERT INTO "Tecnico" VALUES(3,'Vaughan Russell','(804)625-0919','6213 Diam St.','Quisque@ametultriciessem.com','tellus');
INSERT INTO "Tecnico" VALUES(4,'Colorado Moss','(884)531-5292','P.O. Box 156 8921 Per Avenue','eget.tincidunt@Fuscealiquetmagna.org','Mauris');
INSERT INTO "Tecnico" VALUES(5,'Lars Hogan','(409)148-2173','8894 Penatibus Rd.','metus@rhoncus.org','dui');
INSERT INTO "Tecnico" VALUES(6,'Gary Porter','(207)752-9791','652-8772 Adipiscing Rd.','adipiscing.non@dignissimmagnaa.com','facilisis');
INSERT INTO "Tecnico" VALUES(7,'Deacon Harmon','(311)301-8673','P.O. Box 509 4552 Amet Road','quam@tincidunt.edu','Cum');
INSERT INTO "Tecnico" VALUES(8,'Addison Salazar','(451)725-2119','7019 Tristique Road','magna.a.neque@egestas.ca','Aenean');
INSERT INTO "Tecnico" VALUES(9,'Ian Mcleod','(157)411-3133','Ap #139-6362 Phasellus Av.','pellentesque@eu.org','porttitor');
INSERT INTO "Tecnico" VALUES(10,'Amos Gregory','(250)731-8874','4068 Velit Avenue','mi.lacinia@urnasuscipitnonummy.ca','enim');
INSERT INTO "Tecnico" VALUES(11,'dfd','fd','fdf','df','df');
INSERT INTO "Tecnico" VALUES(12,'','','','','');
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
INSERT INTO "Insumo" VALUES(1,644,307,790,'04/01/11','dolor dapibus gravida. Aliquam tincidunt,',140,'ac sem','Nullam','dolor. Fusce','Mauris blandit enim consequat','15/09/12',1004,721);
INSERT INTO "Insumo" VALUES(2,562,558,810,'02/05/12','Morbi accumsan laoreet ipsum. Curabitur',106,'turpis vitae','inceptos','sed orci','et, lacinia vitae, sodales','05/06/12',1005,916);
INSERT INTO "Insumo" VALUES(3,561,930,796,'04/06/11','mi lacinia mattis. Integer eu',128,'dis parturient','id','fermentum convallis','lectus pede et risus.','24/07/12',1004,541);
INSERT INTO "Insumo" VALUES(4,420,585,379,'11/27/12','nonummy ac, feugiat non, lobortis',123,'purus mauris','accumsan','libero est,','ipsum dolor sit amet,','11/10/11',1003,540);
INSERT INTO "Insumo" VALUES(5,832,168,673,'12/31/10','egestas blandit. Nam nulla magna,',109,'dolor quam,','ornare','lorem, vehicula','elit, pellentesque a, facilisis','14/10/12',1006,178);
INSERT INTO "Insumo" VALUES(6,'','','','','','','','','','','','','');
CREATE TABLE Cliente (Cliente_id INTEGER PRIMARY KEY,
	   	Nombre TEXT,
	   	Telefono INTEGER, 
		Direccion TEXT, 
		Email TEXT);
INSERT INTO "Cliente" VALUES(1,'Kasper Sandoval','(653)968-2110','8631 Eu Ave','Donec.consectetuer@et.ca');
INSERT INTO "Cliente" VALUES(2,'Jonah Murray','(958)499-6594','1896 Magna. St.','Etiam.vestibulum@ornaretortor.ca');
INSERT INTO "Cliente" VALUES(3,'Drew Grimes','(197)506-0693','Ap #642-8486 Ante Road','lobortis.mauris@laoreetposuere.com');
INSERT INTO "Cliente" VALUES(4,'Damon Noel','(802)586-0477','306-1477 Ac Rd.','turpis.Aliquam@ullamcorpereueuismod.edu');
INSERT INTO "Cliente" VALUES(5,'Logan Orr','(420)338-5694','315-8981 Enim Ave','at@leo.com');
INSERT INTO "Cliente" VALUES(6,'Hop Stuart','(270)219-7438','7895 Nullam St.','aliquet.molestie.tellus@erat.org');
INSERT INTO "Cliente" VALUES(7,'Tanner Griffith','(196)770-5322','964-5927 Vel Rd.','eu.eros@mieleifendegestas.com');
INSERT INTO "Cliente" VALUES(8,'Colby Roth','(483)301-1847','8877 Eros. Rd.','ante.Vivamus.non@lectusante.ca');
INSERT INTO "Cliente" VALUES(9,'Chadwick Erickson','(222)978-0493','P.O. Box 658 6024 At Av.','Donec.consectetuer.mauris@rutrum.ca');
INSERT INTO "Cliente" VALUES(10,'Connor Clay','(727)347-2179','879-3842 Interdum. Rd.','nisi.sem@dapibusgravida.org');
INSERT INTO "Cliente" VALUES(20,'','','','');
INSERT INTO "Cliente" VALUES(21,'','df','df','d');
INSERT INTO "Cliente" VALUES(22,'dsf','adsf','adsf','adsfds');
INSERT INTO "Cliente" VALUES(23,'qw','qw','qw','qwq');
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
  CONSTRAINT fk_rap FOREIGN KEY (Responsable_area_productiva) REFERENCES Tecnico (Tecnico_id),
  CONSTRAINT fk_rat FOREIGN KEY (Responsable_area_tecnica) REFERENCES Tecnico (Tecnico_id)

);
INSERT INTO "Producto_terminado" VALUES(1,1002,'diam dictum sapien. Aenean',14,1004,1002,'ornare','mollis.','faucibus lectus, a sollicitudin','1002','05/15/12',1002,'12/21/12',1006,'lacinia at, iaculis quis, pede. Praesent');
INSERT INTO "Producto_terminado" VALUES(2,1000,'nascetur ridiculus mus. Donec',10,1003,1003,'arcu','rhoncus.','diam eu dolor egestas','1001','06/21/12',1006,'11/17/12',1001,'Integer in magna. Phasellus dolor elit,');
INSERT INTO "Producto_terminado" VALUES(3,1006,'hendrerit a, arcu. Sed',10,1003,1006,'non,','metus','non lorem vitae odio','1005','12/14/11',1003,'07/05/11',1005,'Nunc ullamcorper, velit in aliquet lobortis,');
INSERT INTO "Producto_terminado" VALUES(4,1006,'vestibulum nec, euismod in,',18,1004,1005,'nec,','Mauris','pharetra, felis eget varius','1002','01/04/11',1003,'11/29/12',1005,'convallis ligula. Donec luctus aliquet odio.');
INSERT INTO "Producto_terminado" VALUES(5,1006,'et netus et malesuada',3,1003,1001,'mollis','a','lorem fringilla ornare placerat,','1003','05/14/11',1005,'04/16/11',1002,'fermentum metus. Aenean sed pede nec');
COMMIT;

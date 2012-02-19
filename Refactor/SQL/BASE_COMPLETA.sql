PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE RMP (
  producto_id TEXT NOT NULL,
  referencias TEXT NOT NULL,
  control_calidad TEXT NOT NULL,
  instruccion_operativa TEXT NOT NULL,
  descripcion TEXT NOT NULL,
  cantidad_materia_prima INTEGER NOT NULL,
  cantidad_insumo_productivo INTEGER NOT NULL,
  cantidad_producto_semielaborado INTEGER NOT NULL,
  descripcion_materia_prima TEXT NOT NULL,
  descripcion_insumo_productivo TEXT NOT NULL,
  descripcion_producto_semielaborado TEXT NOT NULL,
  PRIMARY KEY (producto_id)
);
INSERT INTO "RMP" VALUES('RMP001','libero nec ligula consectetuer rhoncus. Nullam velit dui, semper et,','at','Phasellus elit pede, malesuada vel, venenatis vel, faucibus id, libero.','vulputate, risus a ultricies adipiscing, enim mi tempor lorem, eget',123,132,24,'sed pede nec ante blandit viverra. Donec tempus,','lorem tristique aliquet. Phasellus fermentum convallis ligula. Donec','fames ac turpis egestas. Fusce aliquet magna a neque. Nullam');
INSERT INTO "RMP" VALUES('RMP002','id enim. Curabitur massa. Vestibulum accumsan neque et nunc. Quisque','Phasellus','euismod enim. Etiam gravida molestie arcu. Sed eu nibh vulputate','vel est tempor bibendum. Donec felis orci, adipiscing non, luctus',166,137,124,'nisl. Maecenas malesuada fringilla est. Mauris eu turpis.','iaculis aliquet diam. Sed diam lorem, auctor quis,','mauris, aliquam eu, accumsan sed, facilisis vitae, orci. Phasellus dapibus');
INSERT INTO "RMP" VALUES('RMP003','Nunc pulvinar arcu et pede. Nunc sed orci lobortis augue','mattis.','mi felis, adipiscing fringilla, porttitor vulputate, posuere vulputate, lacus. Cras','condimentum eget, volutpat ornare, facilisis eget, ipsum. Donec sollicitudin adipiscing',42,180,186,'consectetuer adipiscing elit. Curabitur sed tortor. Integer aliquam','blandit congue. In scelerisque scelerisque dui. Suspendisse ac','ullamcorper, nisl arcu iaculis enim, sit amet ornare lectus justo');
INSERT INTO "RMP" VALUES('RMP004','In scelerisque scelerisque dui. Suspendisse ac metus vitae velit egestas','magna','Ut tincidunt vehicula risus. Nulla eget metus eu erat semper','netus et malesuada fames ac turpis egestas. Fusce aliquet magna',180,67,124,'risus, at fringilla purus mauris a nunc. In','nec ligula consectetuer rhoncus. Nullam velit dui, semper','elementum, dui quis accumsan convallis, ante lectus convallis est, vitae');
INSERT INTO "RMP" VALUES('RMP005','odio vel est tempor bibendum. Donec felis orci, adipiscing non,','sed,','magna. Praesent interdum ligula eu enim. Etiam imperdiet dictum magna.','metus eu erat semper rutrum. Fusce dolor quam, elementum at,',110,148,35,'urna. Nunc quis arcu vel quam dignissim pharetra.','Donec egestas. Duis ac arcu. Nunc mauris. Morbi','lorem, luctus ut, pellentesque eget, dictum placerat, augue. Sed molestie.');
INSERT INTO "RMP" VALUES('RMP006','Integer aliquam adipiscing lacus. Ut nec urna et arcu imperdiet','id,','senectus et netus et malesuada fames ac turpis egestas. Aliquam','magna. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Etiam',26,21,61,'non quam. Pellentesque habitant morbi tristique senectus et','dignissim magna a tortor. Nunc commodo auctor velit.','sit amet diam eu dolor egestas rhoncus. Proin nisl sem,');
INSERT INTO "RMP" VALUES('RMP007','Quisque nonummy ipsum non arcu. Vivamus sit amet risus. Donec','varius','nulla. Donec non justo. Proin non massa non ante bibendum','velit. Cras lorem lorem, luctus ut, pellentesque eget, dictum placerat,',148,122,17,'a, magna. Lorem ipsum dolor sit amet, consectetuer','In faucibus. Morbi vehicula. Pellentesque tincidunt tempus risus.','Vivamus sit amet risus. Donec egestas. Aliquam nec enim. Nunc');
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
INSERT INTO "orden_pedido_producto" VALUES('OPP000','1000','8',35,'06/19/12','06/29/11','mi, ac');
INSERT INTO "orden_pedido_producto" VALUES('OPP001','1004','18',28,'08/26/12','01/20/13','mauris. Integer');
INSERT INTO "orden_pedido_producto" VALUES('OPP002','1005','21',14,'07/15/12','04/03/11','tincidunt dui');
INSERT INTO "orden_pedido_producto" VALUES('OPP003','1005','23',38,'07/09/11','06/14/12','Etiam gravida');
INSERT INTO "orden_pedido_producto" VALUES('OPP004','1005','10',47,'07/09/12','06/17/12','Phasellus elit');
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
  CONSTRAINT fk_op FOREIGN KEY (id_programa_produccion) REFERENCES programa_produccion (programa_produccion_id),
  CONSTRAINT fk_opp FOREIGN KEY (id_producto) REFERENCES RMP (producto_id)
);
INSERT INTO "orden_produccion" VALUES('OP1000','aliquet, metus urna convallis erat,','1004',14,'1000','1005','06/21/12','1001','12/28/10','gravida. Aliquam tincidunt, nunc','urna et arcu imperdiet ullamcorper.','1000','1002');
INSERT INTO "orden_produccion" VALUES('OP001','taciti sociosqu ad litora torquent','1006',20,'1003','1002','01/12/13','1001','12/29/12','ridiculus mus. Proin vel','sit amet ultricies sem magna','1005','1006');
INSERT INTO "orden_produccion" VALUES('OP002','non, hendrerit id, ante. Nunc','1005',31,'1004','1000','01/16/11','1005','01/09/12','et arcu imperdiet ullamcorper.','Duis dignissim tempor arcu. Vestibulum','1003','1004');
INSERT INTO "orden_produccion" VALUES('OP003','in aliquet lobortis, nisi nibh','1002',25,'1001','1003','07/25/11','1003','02/22/12','eu metus. In lorem.','vitae, sodales at, velit. Pellentesque','1005','1002');
INSERT INTO "orden_produccion" VALUES('OP006','nec tempus mauris erat eget','1000',13,'1005','1003','08/12/12','1006','09/26/12','mi felis, adipiscing fringilla,','semper pretium neque. Morbi quis','1002','1002');
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
CREATE TABLE proveedor (
  proveedor_id TEXT NOT NULL,
  nombre TEXT CHARACTER  NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  PRIMARY KEY (proveedor_id)
);
INSERT INTO "proveedor" VALUES('P001','Callum Lynn','(494)764-8882','544-886 Gravida Ave','mus.Aenean@Maurismolestiepharetra.edu');
INSERT INTO "proveedor" VALUES('P002','Andrew Campbell','(926)247-3963','897-1094 Placerat. Ave','egestas@velquamdignissim.edu');
INSERT INTO "proveedor" VALUES('P003','Mannix Dickson','(290)234-9774','4888 Tincidunt St.','torquent.per.conubia@ultriciesornare.ca');
INSERT INTO "proveedor" VALUES('P004','Magee Scott','(504)308-2655','2588 Luctus Avenue','ligula.Aenean.gravida@enimnisl.org');
INSERT INTO "proveedor" VALUES('P005','Palmer Mcmahon','(795)608-0191','P.O. Box 661',' 9978 Ultrices Road urna.Nunc@arcu.com');
INSERT INTO "proveedor" VALUES('P006','Nolan Mullins','(891)947-8053','2522 Ut Road','Etiam.imperdiet@diamluctuslobortis.com');
INSERT INTO "proveedor" VALUES('P007','Jordan Harper','(809)474-7135','P.O. Box 911',' 9508 Pharetra St.massa.Suspendisse.eleifend@Suspendisse.org');
INSERT INTO "proveedor" VALUES('P008','Moses Leon','(556)520-3269','8750 Venenatis Ave','Fusce@vitaesodales.com');
INSERT INTO "proveedor" VALUES('P009','Tanner Long','(441)812-7296','415-7515 Ut Rd.','nonummy.Fusce.fermentum@acmattis.com');
INSERT INTO "proveedor" VALUES('P010','Kenyon Cotton','(708)742-7709',' P.O. Box 770 4467 Duis St.','ut.nisi.a@pedenecante.edu');
INSERT INTO "proveedor" VALUES('P011','Marvin Reese','(526)300-0391','Ap #321-7396 Non St.','elit@Aliquam.ca');
INSERT INTO "proveedor" VALUES('P012','Jamal Estrada','(230)362-8293','Ap #659-6529 Dapibus St.','ipsum.Phasellus.vitae@Proindolor.org');
INSERT INTO "proveedor" VALUES('dfdf','dfd','fdfdf','dfdf','dfdf');
INSERT INTO "proveedor" VALUES('sadfadsfadsf','dfdf','4333dfa','ffdfd','ngng');
CREATE TABLE tecnico (
  tecnico_id TEXT NOT NULL,
  nombre TEXT NOT NULL,
  telefono INTEGER NOT NULL,
  direccion TEXT NOT NULL,
  email TEXT NOT NULL,
  area TEXT NOT NULL,
  PRIMARY KEY (tecnico_id)
);
INSERT INTO "tecnico" VALUES('T001','Hayden Clemons','(877)280-2647','Ap #892-2742 Nulla Rd.','nunc@nonarcuVivamus.edu','habitant');
INSERT INTO "tecnico" VALUES('T002','Yuli Vincent','(329)608-5946','Ap #241-9727 Fermentum St.Curae','Donec.tincidunt@nunc.edu','lorem');
INSERT INTO "tecnico" VALUES('T003','Vaughan Russell','(804)625-0919','6213 Diam St.','Quisque@ametultriciessem.com','tellus');
INSERT INTO "tecnico" VALUES('T004','Colorado Moss','(884)531-5292','P.O. Box 156 8921 Per Avenue','eget.tincidunt@Fuscealiquetmagna.org','Mauris');
INSERT INTO "tecnico" VALUES('T005','Lars Hogan','(409)148-2173','8894 Penatibus Rd.','metus@rhoncus.org','dui');
INSERT INTO "tecnico" VALUES('T006','Gary Porter','(207)752-9791','652-8772 Adipiscing Rd.','adipiscing.non@dignissimmagnaa.com','facilisis');
INSERT INTO "tecnico" VALUES('T007','Deacon Harmon','(311)301-8673','P.O. Box 509 4552 Amet Road','quam@tincidunt.edu','Cum');
INSERT INTO "tecnico" VALUES('T008','Addison Salazar','(451)725-2119','7019 Tristique Road','magna.a.neque@egestas.ca','Aenean');
INSERT INTO "tecnico" VALUES('T009','Ian Mcleod','(157)411-3133','Ap #139-6362 Phasellus Av.','pellentesque@eu.org','porttitor');
INSERT INTO "tecnico" VALUES('T010','Amos Gregory','(250)731-8874','4068 Velit Avenue','mi.lacinia@urnasuscipitnonummy.ca','enim');
CREATE TABLE insumo (IR TEXT PRIMARY KEY, materia_prima INTEGER, insumo_productivo INTEGER, producto_semi_elaborado INTEGER, fecha_ingreso TEXT, descripcion TEXT, cantidad INTEGER, obsevacion_simple_vista TEXT, embalaje TEXT, transporte TEXT, documentos_material_adjunto TEXT, fecha_de_control _control TEXT, responsable TEXT, id_proveedor TEXT);
INSERT INTO "insumo" VALUES('I001',644,307,790,'04/01/11','dolor dapibus gravida. Aliquam tincidunt,',140,'ac sem','Nullam','dolor. Fusce','Mauris blandit enim consequat','15/09/12','1004','721');
INSERT INTO "insumo" VALUES('I002',562,558,810,'02/05/12','Morbi accumsan laoreet ipsum. Curabitur',106,'turpis vitae','inceptos','sed orci','et, lacinia vitae, sodales','05/06/12','1005','916');
INSERT INTO "insumo" VALUES('I003',561,930,796,'04/06/11','mi lacinia mattis. Integer eu',128,'dis parturient','id','fermentum convallis','lectus pede et risus.','24/07/12','1004','541');
INSERT INTO "insumo" VALUES('I004',420,585,379,'11/27/12','nonummy ac, feugiat non, lobortis',123,'purus mauris','accumsan','libero est,','ipsum dolor sit amet,','11/10/11','1003','540');
INSERT INTO "insumo" VALUES('I005',832,168,673,'12/31/10','egestas blandit. Nam nulla magna,',109,'dolor quam,','ornare','lorem, vehicula','elit, pellentesque a, facilisis','14/10/12','1006','178');
CREATE TABLE cliente (Cliente_id TEXT PRIMARY KEY, Nombre TEXT, Telefono INTEGER, Direccion TEXT, Email TEXT);
INSERT INTO "cliente" VALUES('C001','Kasper Sandoval','(653)968-2110','8631 Eu Ave','Donec.consectetuer@et.ca');
INSERT INTO "cliente" VALUES('C002','Jonah Murray','(958)499-6594','1896 Magna. St.','Etiam.vestibulum@ornaretortor.ca');
INSERT INTO "cliente" VALUES('C003','Drew Grimes','(197)506-0693','Ap #642-8486 Ante Road','lobortis.mauris@laoreetposuere.com');
INSERT INTO "cliente" VALUES('C004','Damon Noel','(802)586-0477','306-1477 Ac Rd.','turpis.Aliquam@ullamcorpereueuismod.edu');
INSERT INTO "cliente" VALUES('C005','Logan Orr','(420)338-5694','315-8981 Enim Ave','at@leo.com');
INSERT INTO "cliente" VALUES('C006','Hop Stuart','(270)219-7438','7895 Nullam St.','aliquet.molestie.tellus@erat.org');
INSERT INTO "cliente" VALUES('C007','Tanner Griffith','(196)770-5322','964-5927 Vel Rd.','eu.eros@mieleifendegestas.com');
INSERT INTO "cliente" VALUES('C008','Colby Roth','(483)301-1847','8877 Eros. Rd.','ante.Vivamus.non@lectusante.ca');
INSERT INTO "cliente" VALUES('C009','Chadwick Erickson','(222)978-0493','P.O. Box 658 6024 At Av.','Donec.consectetuer.mauris@rutrum.ca');
INSERT INTO "cliente" VALUES('C010','Connor Clay','(727)347-2179','879-3842 Interdum. Rd.','nisi.sem@dapibusgravida.org');
CREATE TABLE producto_terminado (producto_terminado_id TEXT PRIMARY KEY, lote TEXT, material TEXT, cantidad INTEGER, IR TEXT, RMP TEXT, CC TEXT, IO TEXT, descripcion TEXT, id_orden_produccion TEXT, emision_area_productiva TEXT, responsable_area_productiva TEXT, emision_area_tecnica TEXT, responsable_area_tecnica TEXT, vencimiento TEXT);
INSERT INTO "producto_terminado" VALUES('PT001','1002','diam dictum sapien. Aenean',14,'1004','1002','ornare','mollis.','faucibus lectus, a sollicitudin','1002','05/15/12','1002','12/21/12','1006','lacinia at, iaculis quis, pede. Praesent');
INSERT INTO "producto_terminado" VALUES('PT002','1000','nascetur ridiculus mus. Donec',10,'1003','1003','arcu','rhoncus.','diam eu dolor egestas','1001','06/21/12','1006','11/17/12','1001','Integer in magna. Phasellus dolor elit,');
INSERT INTO "producto_terminado" VALUES('PT003','1006','hendrerit a, arcu. Sed',10,'1003','1006','non,','metus','non lorem vitae odio','1005','12/14/11','1003','07/05/11','1005','Nunc ullamcorper, velit in aliquet lobortis,');
INSERT INTO "producto_terminado" VALUES('PT004','1006','vestibulum nec, euismod in,',18,'1004','1005','nec,','Mauris','pharetra, felis eget varius','1002','01/04/11','1003','11/29/12','1005','convallis ligula. Donec luctus aliquet odio.');
INSERT INTO "producto_terminado" VALUES('PT005','1006','et netus et malesuada',3,'1003','1001','mollis','a','lorem fringilla ornare placerat,','1003','05/14/11','1005','04/16/11','1002','fermentum metus. Aenean sed pede nec');
COMMIT;

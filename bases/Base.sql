-- MySQL dump 10.13  Distrib 5.1.58, for debian-linux-gnu (i486)
--
-- Host: localhost    Database: Base
-- ------------------------------------------------------
-- Server version	5.1.58-1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `RMP`
--

DROP TABLE IF EXISTS `RMP`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RMP` (
  `producto_id` varchar(255) NOT NULL,
  `referencias` varchar(255) NOT NULL,
  `control_calidad` varchar(255) NOT NULL,
  `instruccion_operativa` varchar(255) NOT NULL,
  `descripcion` varchar(255) NOT NULL,
  `cantidad_materia_prima` int(11) NOT NULL,
  `cantidad_insumo` int(11) NOT NULL,
  `descripcion_materia_prima` varchar(255) NOT NULL,
  `descripcion_insumo_productivo` varchar(255) NOT NULL,
  `descripcion_producto_semielaborado` varchar(255) NOT NULL,
  PRIMARY KEY (`producto_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `RMP`
--

LOCK TABLES `RMP` WRITE;
/*!40000 ALTER TABLE `RMP` DISABLE KEYS */;
/*!40000 ALTER TABLE `RMP` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cliente`
--

DROP TABLE IF EXISTS `cliente`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cliente` (
  `cliente_id` varchar(255) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `telefono` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`cliente_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cliente`
--

LOCK TABLES `cliente` WRITE;
/*!40000 ALTER TABLE `cliente` DISABLE KEYS */;
/*!40000 ALTER TABLE `cliente` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `insumo`
--

DROP TABLE IF EXISTS `insumo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `insumo` (
  `IR` varchar(255) NOT NULL,
  `materia_prima` tinyint(1) NOT NULL,
  `insumo_productivo` tinyint(1) NOT NULL,
  `producto_semi_elaborado` tinyint(1) NOT NULL,
  `fecha_ingreso` varchar(255) NOT NULL,
  `descripcion` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `obsevacion_simple_vista` varchar(255) NOT NULL,
  `embalaje` varchar(255) NOT NULL,
  `transporte` varchar(255) NOT NULL,
  `documentos_maerial_adjunto` varchar(255) NOT NULL,
  `fecha_de _control` varchar(255) NOT NULL,
  `responsable` varchar(255) NOT NULL,
  `id_proveedor` varchar(255) NOT NULL,
  PRIMARY KEY (`IR`),
  KEY `id_proveedor` (`id_proveedor`),
  KEY `fk_it` (`responsable`),
  CONSTRAINT `fk_it` FOREIGN KEY (`responsable`) REFERENCES `tecnico` (`tecnico_id`),
  CONSTRAINT `insumo_ibfk_1` FOREIGN KEY (`id_proveedor`) REFERENCES `proveedor` (`proveedor_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `insumo`
--

LOCK TABLES `insumo` WRITE;
/*!40000 ALTER TABLE `insumo` DISABLE KEYS */;
/*!40000 ALTER TABLE `insumo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orden_pedido_producto`
--

DROP TABLE IF EXISTS `orden_pedido_producto`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orden_pedido_producto` (
  `orden_pedido_producto_id` varchar(255) NOT NULL,
  `id_cliente` varchar(255) NOT NULL,
  `id_producto` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `fecha` varchar(255) NOT NULL,
  `fecha_estimada_entrega` varchar(255) NOT NULL,
  `observacion` varchar(255) NOT NULL,
  PRIMARY KEY (`orden_pedido_producto_id`),
  KEY `id_cliente` (`id_cliente`),
  KEY `id_producto` (`id_producto`),
  CONSTRAINT `fk_sdf` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`),
  CONSTRAINT `orden_pedido_producto_ibfk_1` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`),
  CONSTRAINT `orden_pedido_producto_ibfk_2` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orden_pedido_producto`
--

LOCK TABLES `orden_pedido_producto` WRITE;
/*!40000 ALTER TABLE `orden_pedido_producto` DISABLE KEYS */;
/*!40000 ALTER TABLE `orden_pedido_producto` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orden_pedido_proveedor`
--

DROP TABLE IF EXISTS `orden_pedido_proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orden_pedido_proveedor` (
  `orden_pedido_proveedor_id` varchar(255) NOT NULL,
  `id_orden_pedido_producto` varchar(255) NOT NULL,
  `fecha` varchar(255) NOT NULL,
  `observacion` varchar(255) NOT NULL,
  `cantidad_materia_prima` int(11) NOT NULL,
  `cantidad_insumo_productivo` int(11) NOT NULL,
  `cantidad_producto_semielaborado` int(11) NOT NULL,
  `descripcion_materia_prima` varchar(255) NOT NULL,
  `descripcion_insumo_productivo` varchar(255) NOT NULL,
  `descripcion_producto_semielaborado` varchar(255) NOT NULL,
  PRIMARY KEY (`orden_pedido_proveedor_id`),
  KEY `id_orden_pedido_producto` (`id_orden_pedido_producto`),
  CONSTRAINT `orden_pedido_proveedor_ibfk_1` FOREIGN KEY (`id_orden_pedido_producto`) REFERENCES `orden_pedido_producto` (`orden_pedido_producto_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orden_pedido_proveedor`
--

LOCK TABLES `orden_pedido_proveedor` WRITE;
/*!40000 ALTER TABLE `orden_pedido_proveedor` DISABLE KEYS */;
/*!40000 ALTER TABLE `orden_pedido_proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orden_produccion`
--

DROP TABLE IF EXISTS `orden_produccion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `orden_produccion` (
  `orden_produccion_id` varchar(255) NOT NULL,
  `descripcion` varchar(255) NOT NULL,
  `id_producto` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `lote` varchar(255) NOT NULL,
  `responsable_area_productiva` varchar(255) NOT NULL,
  `fecha_emision_area_productiva` varchar(255) NOT NULL,
  `responsable_area_tecnica` varchar(255) NOT NULL,
  `fecha_emision_area_tecnica` varchar(255) NOT NULL,
  `materiales_utilizados` varchar(255) NOT NULL,
  `denominacion` varchar(255) NOT NULL,
  `analisis_IR` varchar(255) NOT NULL,
  `id_programa_produccion` varchar(255) NOT NULL,
  PRIMARY KEY (`orden_produccion_id`),
  KEY `fka` (`id_producto`),
  KEY `fk` (`id_programa_produccion`),
  KEY `fk_ot` (`responsable_area_tecnica`),
  CONSTRAINT `fk_ot` FOREIGN KEY (`responsable_area_tecnica`) REFERENCES `tecnico` (`tecnico_id`),
  CONSTRAINT `fk` FOREIGN KEY (`id_programa_produccion`) REFERENCES `programa_produccion` (`programa_produccion_id`),
  CONSTRAINT `fka` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orden_produccion`
--

LOCK TABLES `orden_produccion` WRITE;
/*!40000 ALTER TABLE `orden_produccion` DISABLE KEYS */;
/*!40000 ALTER TABLE `orden_produccion` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `producto_terminado`
--

DROP TABLE IF EXISTS `producto_terminado`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `producto_terminado` (
  `producto_terminado_id` varchar(255) NOT NULL,
  `lote` varchar(255) NOT NULL,
  `material` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `IR` varchar(255) NOT NULL,
  `RMP` varchar(255) NOT NULL,
  `CC` varchar(255) NOT NULL,
  `IO` varchar(255) NOT NULL,
  `id_producto` varchar(255) NOT NULL,
  `descripcion` varchar(255) NOT NULL,
  `id_orden_produccion` varchar(255) NOT NULL,
  `emision_area_productiva` varchar(255) NOT NULL,
  `responsable_area_productiva` varchar(255) NOT NULL,
  `emision_area_tecnica` varchar(255) NOT NULL,
  `responsable_area_tecnica` varchar(255) NOT NULL,
  `vencimiento` varchar(255) NOT NULL,
  PRIMARY KEY (`producto_terminado_id`),
  KEY `id_producto` (`id_producto`),
  KEY `id_orden_produccion` (`id_orden_produccion`),
  CONSTRAINT `producto_terminado_ibfk_1` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`),
  CONSTRAINT `producto_terminado_ibfk_2` FOREIGN KEY (`id_orden_produccion`) REFERENCES `orden_produccion` (`orden_produccion_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `producto_terminado`
--

LOCK TABLES `producto_terminado` WRITE;
/*!40000 ALTER TABLE `producto_terminado` DISABLE KEYS */;
/*!40000 ALTER TABLE `producto_terminado` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `programa_produccion`
--

DROP TABLE IF EXISTS `programa_produccion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `programa_produccion` (
  `programa_produccion_id` varchar(255) NOT NULL,
  `id_orden_produccion` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `fecha_comprometida` varchar(255) NOT NULL,
  `id_cliente` varchar(255) NOT NULL,
  `responsable` varchar(255) NOT NULL,
  `produccion` varchar(255) NOT NULL,
  PRIMARY KEY (`programa_produccion_id`),
  KEY `af` (`id_orden_produccion`),
  KEY `id_cliente` (`id_cliente`),
  CONSTRAINT `af` FOREIGN KEY (`id_orden_produccion`) REFERENCES `orden_produccion` (`orden_produccion_id`),
  CONSTRAINT `programa_produccion_ibfk_1` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `programa_produccion`
--

LOCK TABLES `programa_produccion` WRITE;
/*!40000 ALTER TABLE `programa_produccion` DISABLE KEYS */;
/*!40000 ALTER TABLE `programa_produccion` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedor`
--

DROP TABLE IF EXISTS `proveedor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `proveedor` (
  `proveedor_id` varchar(255) NOT NULL,
  `nombre` varchar(255) CHARACTER SET ucs2 NOT NULL,
  `telefon` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`proveedor_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedor`
--

LOCK TABLES `proveedor` WRITE;
/*!40000 ALTER TABLE `proveedor` DISABLE KEYS */;
/*!40000 ALTER TABLE `proveedor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tecnico`
--

DROP TABLE IF EXISTS `tecnico`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tecnico` (
  `tecnico_id` varchar(255) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `telefono` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `area` varchar(255) NOT NULL,
  PRIMARY KEY (`tecnico_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tecnico`
--

LOCK TABLES `tecnico` WRITE;
/*!40000 ALTER TABLE `tecnico` DISABLE KEYS */;
/*!40000 ALTER TABLE `tecnico` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2011-10-12 17:37:59

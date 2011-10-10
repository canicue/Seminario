-- phpMyAdmin SQL Dump
-- version 3.4.5deb1
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 10-10-2011 a las 04:34:05
-- Versión del servidor: 5.1.58
-- Versión de PHP: 5.3.8-2

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `Base`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cliente`
--

CREATE TABLE IF NOT EXISTS `cliente` (
  `cliente_id` varchar(255) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `telefono` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`cliente_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `insumo`
--

CREATE TABLE IF NOT EXISTS `insumo` (
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
  KEY `id_proveedor` (`id_proveedor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `orden_pedido_producto`
--

CREATE TABLE IF NOT EXISTS `orden_pedido_producto` (
  `orden_pedido_producto_id` varchar(255) NOT NULL,
  `id_cliente` varchar(255) NOT NULL,
  `id_producto` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `fecha` varchar(255) NOT NULL,
  `fecha_estimada_entrega` varchar(255) NOT NULL,
  `observacion` varchar(255) NOT NULL,
  PRIMARY KEY (`orden_pedido_producto_id`),
  KEY `id_cliente` (`id_cliente`),
  KEY `id_producto` (`id_producto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `orden_pedido_proveedor`
--

CREATE TABLE IF NOT EXISTS `orden_pedido_proveedor` (
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
  KEY `id_orden_pedido_producto` (`id_orden_pedido_producto`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `orden_produccion`
--

CREATE TABLE IF NOT EXISTS `orden_produccion` (
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
  KEY `fk` (`id_programa_produccion`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `producto_terminado`
--

CREATE TABLE IF NOT EXISTS `producto_terminado` (
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
  KEY `id_orden_produccion` (`id_orden_produccion`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `programa_produccion`
--

CREATE TABLE IF NOT EXISTS `programa_produccion` (
  `programa_produccion_id` varchar(255) NOT NULL,
  `id_orden_produccion` varchar(255) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `fecha_comprometida` varchar(255) NOT NULL,
  `id_cliente` varchar(255) NOT NULL,
  `responsable` varchar(255) NOT NULL,
  `produccion` varchar(255) NOT NULL,
  PRIMARY KEY (`programa_produccion_id`),
  KEY `af` (`id_orden_produccion`),
  KEY `id_cliente` (`id_cliente`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proveedor`
--

CREATE TABLE IF NOT EXISTS `proveedor` (
  `proveedor_id` varchar(255) NOT NULL,
  `nombre` varchar(255) CHARACTER SET ucs2 NOT NULL,
  `telefon` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`proveedor_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `RMP`
--

CREATE TABLE IF NOT EXISTS `RMP` (
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

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tecnico`
--

CREATE TABLE IF NOT EXISTS `tecnico` (
  `tecnico_id` varchar(255) NOT NULL,
  `nombre` varchar(255) NOT NULL,
  `telefono` int(11) NOT NULL,
  `direccion` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `area` varchar(255) NOT NULL,
  PRIMARY KEY (`tecnico_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `insumo`
--
ALTER TABLE `insumo`
  ADD CONSTRAINT `insumo_ibfk_1` FOREIGN KEY (`id_proveedor`) REFERENCES `proveedor` (`proveedor_id`);

--
-- Filtros para la tabla `orden_pedido_producto`
--
ALTER TABLE `orden_pedido_producto`
  ADD CONSTRAINT `orden_pedido_producto_ibfk_2` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`),
  ADD CONSTRAINT `fk_sdf` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`),
  ADD CONSTRAINT `orden_pedido_producto_ibfk_1` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`);

--
-- Filtros para la tabla `orden_pedido_proveedor`
--
ALTER TABLE `orden_pedido_proveedor`
  ADD CONSTRAINT `orden_pedido_proveedor_ibfk_1` FOREIGN KEY (`id_orden_pedido_producto`) REFERENCES `orden_pedido_producto` (`orden_pedido_producto_id`);

--
-- Filtros para la tabla `orden_produccion`
--
ALTER TABLE `orden_produccion`
  ADD CONSTRAINT `fk` FOREIGN KEY (`id_programa_produccion`) REFERENCES `programa_produccion` (`programa_produccion_id`),
  ADD CONSTRAINT `fka` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`);

--
-- Filtros para la tabla `producto_terminado`
--
ALTER TABLE `producto_terminado`
  ADD CONSTRAINT `producto_terminado_ibfk_2` FOREIGN KEY (`id_orden_produccion`) REFERENCES `orden_produccion` (`orden_produccion_id`),
  ADD CONSTRAINT `producto_terminado_ibfk_1` FOREIGN KEY (`id_producto`) REFERENCES `RMP` (`producto_id`);

--
-- Filtros para la tabla `programa_produccion`
--
ALTER TABLE `programa_produccion`
  ADD CONSTRAINT `programa_produccion_ibfk_1` FOREIGN KEY (`id_cliente`) REFERENCES `cliente` (`cliente_id`),
  ADD CONSTRAINT `af` FOREIGN KEY (`id_orden_produccion`) REFERENCES `orden_produccion` (`orden_produccion_id`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `app_trazabilidad` DEFAULT CHARACTER SET utf8 ;
-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `app_trazabilidad` DEFAULT CHARACTER SET utf8 ;
USE `app_trazabilidad` ;

-- -----------------------------------------------------
-- Table `app_trazabilidad`.`planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`planta` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Direccion` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`bodega_alimentos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`bodega_alimentos` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Planta_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`, `Planta_ID`),
  INDEX `fk_Alimentos_Bodega_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Alimentos_Bodega_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`lotes` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Unidades` INT(11) NOT NULL,
  `Descripcion` LONGTEXT NULL DEFAULT NULL,
  `Creacion` DATETIME NULL DEFAULT NULL,
  `Ubicacion_Actual` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`bodega_alimentos_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`bodega_alimentos_has_lotes` (
  `Bodega_Alimentos_ID` INT(11) NOT NULL,
  `Bodega_Alimentos_Planta_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Bodega_Alimentos_ID`, `Bodega_Alimentos_Planta_ID`, `Lotes_ID`),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1_idx` (`Bodega_Alimentos_ID` ASC, `Bodega_Alimentos_Planta_ID` ASC),
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1`
    FOREIGN KEY (`Bodega_Alimentos_ID` , `Bodega_Alimentos_Planta_ID`)
    REFERENCES `app_trazabilidad`.`bodega_alimentos` (`ID` , `Planta_ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`conductor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`conductor` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_distribucion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_distribucion` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Destino` VARCHAR(45) NULL DEFAULT NULL,
  `Fecha_Reparticion` DATE NULL DEFAULT NULL,
  `Gerente_Distribucion_id` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Distribucion_Gerente_Distribucion1_idx` (`Gerente_Distribucion_id` ASC),
  CONSTRAINT `fk_Distribucion_Gerente_Distribucion1`
    FOREIGN KEY (`Gerente_Distribucion_id`)
    REFERENCES `app_trazabilidad`.`gerente_distribucion` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`embarcacion` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Salida` DATETIME NULL DEFAULT NULL,
  `Llegada` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion_has_embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion_has_embarcacion` (
  `Distribucion_ID` INT(11) NOT NULL,
  `Embarcacion_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Embarcacion_ID`),
  INDEX `fk_Distribucion_has_Embarcacion_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  INDEX `fk_Distribucion_has_Embarcacion_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion_has_lotes` (
  `Distribucion_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Lotes_ID`),
  INDEX `fk_Distribucion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Distribucion_has_Lotes_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Lotes_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`finca` (
  `ID` INT(11) NOT NULL,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Dirección` LONGTEXT NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`durazno` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Color` VARCHAR(45) NULL DEFAULT NULL,
  `Tamaño` VARCHAR(45) NULL DEFAULT NULL,
  `Precio` DECIMAL(10,2) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NOT NULL,
  `Fecha_Cosecha` DATE NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Durazno_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Durazno_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`embarcacion_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`embarcacion_has_lotes` (
  `Embarcacion_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Embarcacion_ID`, `Lotes_ID`),
  INDEX `fk_Embarcacion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Embarcacion_has_Lotes_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  CONSTRAINT `fk_Embarcacion_has_Lotes_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Embarcacion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`finca_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`finca_has_lotes` (
  `Finca_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Finca_ID`, `Lotes_ID`),
  INDEX `fk_Finca_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Finca_has_Lotes_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Finca_has_Lotes_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Finca_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_finca` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Finca_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Gerente_Finca_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_logistica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_logistica` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_planta` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Planta_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Plante_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Gerente_Plante_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`inspector_calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`inspector_calidad` (
  `ID` INT(11) NOT NULL,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`inspeccion_calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`inspeccion_calidad` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Planta_ID` INT(11) NOT NULL,
  `Inspector_Calidad_ID` INT(11) NOT NULL,
  `Fehca_Hora` DATETIME NULL DEFAULT NULL,
  `Medicion_Acidez` VARCHAR(45) NULL DEFAULT NULL,
  `Prueba_Sabor_Aroma` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Inspeccion_Calidad_Planta1_idx` (`Planta_ID` ASC),
  INDEX `fk_Inspeccion_Calidad_Inspector_Calidad1_idx` (`Inspector_Calidad_ID` ASC),
  CONSTRAINT `fk_Inspeccion_Calidad_Inspector_Calidad1`
    FOREIGN KEY (`Inspector_Calidad_ID`)
    REFERENCES `app_trazabilidad`.`inspector_calidad` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Inspeccion_Calidad_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`lotes_has_durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`lotes_has_durazno` (
  `Lotes_ID` INT(11) NOT NULL,
  `Durazno_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Lotes_ID`, `Durazno_ID`),
  INDEX `fk_Lotes_has_Durazno_Durazno1_idx` (`Durazno_ID` ASC),
  INDEX `fk_Lotes_has_Durazno_Lotes_idx` (`Lotes_ID` ASC),
  CONSTRAINT `fk_Lotes_has_Durazno_Durazno1`
    FOREIGN KEY (`Durazno_ID`)
    REFERENCES `app_trazabilidad`.`durazno` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Lotes_has_Durazno_Lotes`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`planta_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`planta_has_lotes` (
  `Planta_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Planta_ID`, `Lotes_ID`),
  INDEX `fk_Planta_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Planta_has_Lotes_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Planta_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Planta_has_Lotes_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`trazabilidad_duraznos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`trazabilidad_duraznos` (
  `ID` INT(11) NOT NULL,
  `lote_id` VARCHAR(45) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NULL DEFAULT NULL,
  `Planta_ID` INT(11) NULL DEFAULT NULL,
  `Bodega_Alimentos_ID` INT(11) NULL DEFAULT NULL,
  `Embarcacion_ID` INT(11) NULL DEFAULT NULL,
  `Distribucion_ID` INT(11) NULL DEFAULT NULL,
  `fase_cosecha` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_control_calidad` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_exportacion` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_distribucion` VARCHAR(45) NULL DEFAULT 'pendiente',
  PRIMARY KEY (`ID`),
  INDEX `fk_trazabilidad_duraznos_Finca1_idx` (`Finca_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Planta1_idx` (`Planta_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Distribucion1_idx` (`Distribucion_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Bodega_Alimentos1_idx` (`Bodega_Alimentos_ID` ASC),
  CONSTRAINT `fk_trazabilidad_duraznos_Bodega_Alimentos1`
    FOREIGN KEY (`Bodega_Alimentos_ID`)
    REFERENCES `app_trazabilidad`.`bodega_alimentos` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`vehiculo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`vehiculo` (
  `Placa` INT(11) NOT NULL AUTO_INCREMENT,
  `Modelo` VARCHAR(45) NULL DEFAULT NULL,
  `Marca` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`Placa`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`viaje`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`viaje` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Vehiculo_ID` INT(11) NULL DEFAULT NULL,
  `Gerente_Logistica_ID` INT(11) NOT NULL,
  `Conductor_ID` INT(11) NOT NULL,
  `Salida` DATETIME NULL DEFAULT NULL,
  `Llegada` DATETIME NULL DEFAULT NULL,
  `Lugar_Destino` VARCHAR(45) NULL DEFAULT NULL,
  `Lugar_Salida` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Viaje_Gerente_Logistica1_idx` (`Gerente_Logistica_ID` ASC),
  INDEX `fk_Viaje_Conductor1_idx` (`Conductor_ID` ASC),
  CONSTRAINT `Vehiculo_ID`
    FOREIGN KEY (`ID`)
    REFERENCES `app_trazabilidad`.`vehiculo` (`Placa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Conductor1`
    FOREIGN KEY (`Conductor_ID`)
    REFERENCES `app_trazabilidad`.`conductor` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Gerente_Logistica1`
    FOREIGN KEY (`Gerente_Logistica_ID`)
    REFERENCES `app_trazabilidad`.`gerente_logistica` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`trazabilidad_duraznos_has_viaje`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`trazabilidad_duraznos_has_viaje` (
  `trazabilidad_duraznos_ID` INT(11) NOT NULL,
  `Viaje_ID` INT(11) NOT NULL,
  PRIMARY KEY (`trazabilidad_duraznos_ID`, `Viaje_ID`),
  INDEX `fk_trazabilidad_duraznos_has_Viaje_Viaje1_idx` (`Viaje_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_has_Viaje_trazabilidad_duraznos1_idx` (`trazabilidad_duraznos_ID` ASC),
  CONSTRAINT `fk_trazabilidad_duraznos_has_Viaje_Viaje1`
    FOREIGN KEY (`Viaje_ID`)
    REFERENCES `app_trazabilidad`.`viaje` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_has_Viaje_trazabilidad_duraznos1`
    FOREIGN KEY (`trazabilidad_duraznos_ID`)
    REFERENCES `app_trazabilidad`.`trazabilidad_duraznos` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`viaje_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`viaje_has_lotes` (
  `Viaje_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Viaje_ID`, `Lotes_ID`),
  INDEX `fk_Viaje_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Viaje_has_Lotes_Viaje1_idx` (`Viaje_ID` ASC),
  CONSTRAINT `fk_Viaje_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_has_Lotes_Viaje1`
    FOREIGN KEY (`Viaje_ID`)
    REFERENCES `app_trazabilidad`.`viaje` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;

USE `app_trazabilidad` ;

-- -----------------------------------------------------
-- Table `app_trazabilidad`.`planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`planta` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Direccion` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`bodega_alimentos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`bodega_alimentos` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Planta_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`, `Planta_ID`),
  INDEX `fk_Alimentos_Bodega_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Alimentos_Bodega_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`finca` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Dirección` LONGTEXT NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`lotes` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Unidades` INT(11) NOT NULL,
  `Descripcion` LONGTEXT NULL DEFAULT NULL,
  `Creacion` DATETIME NULL DEFAULT NULL,
  `Ubicacion_Actual` VARCHAR(45) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Lotes_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Lotes_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`bodega_alimentos_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`bodega_alimentos_has_lotes` (
  `Bodega_Alimentos_ID` INT(11) NOT NULL,
  `Bodega_Alimentos_Planta_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Bodega_Alimentos_ID`, `Bodega_Alimentos_Planta_ID`, `Lotes_ID`),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1_idx` (`Bodega_Alimentos_ID` ASC, `Bodega_Alimentos_Planta_ID` ASC),
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1`
    FOREIGN KEY (`Bodega_Alimentos_ID` , `Bodega_Alimentos_Planta_ID`)
    REFERENCES `app_trazabilidad`.`bodega_alimentos` (`ID` , `Planta_ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`conductor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`conductor` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_distribucion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_distribucion` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Destino` VARCHAR(45) NULL DEFAULT NULL,
  `Fecha_Reparticion` DATE NULL DEFAULT NULL,
  `Gerente_Distribucion_id` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Distribucion_Gerente_Distribucion1_idx` (`Gerente_Distribucion_id` ASC),
  CONSTRAINT `fk_Distribucion_Gerente_Distribucion1`
    FOREIGN KEY (`Gerente_Distribucion_id`)
    REFERENCES `app_trazabilidad`.`gerente_distribucion` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`embarcacion` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Salida` DATETIME NULL DEFAULT NULL,
  `Llegada` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion_has_embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion_has_embarcacion` (
  `Distribucion_ID` INT(11) NOT NULL,
  `Embarcacion_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Embarcacion_ID`),
  INDEX `fk_Distribucion_has_Embarcacion_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  INDEX `fk_Distribucion_has_Embarcacion_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`distribucion_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`distribucion_has_lotes` (
  `Distribucion_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Lotes_ID`),
  INDEX `fk_Distribucion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Distribucion_has_Lotes_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Lotes_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`durazno` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Color` VARCHAR(45) NULL DEFAULT NULL,
  `Tamaño` VARCHAR(45) NULL DEFAULT NULL,
  `Precio` DECIMAL(10,2) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NOT NULL,
  `Fecha_Cosecha` DATE NULL DEFAULT NULL,
  `Lote_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`, `Lote_ID`),
  INDEX `fk_Durazno_Finca1_idx` (`Finca_ID` ASC),
  INDEX `fk_Durazno_Lotes1_idx` (`Lote_ID` ASC),
  CONSTRAINT `fk_Durazno_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Durazno_Lotes1`
    FOREIGN KEY (`Lote_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 2
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`embarcacion_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`embarcacion_has_lotes` (
  `Embarcacion_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Embarcacion_ID`, `Lotes_ID`),
  INDEX `fk_Embarcacion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Embarcacion_has_Lotes_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  CONSTRAINT `fk_Embarcacion_has_Lotes_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Embarcacion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_finca` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Finca_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Gerente_Finca_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_logistica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_logistica` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`gerente_planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`gerente_planta` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  `Planta_ID` INT(11) NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Plante_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Gerente_Plante_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`inspector_calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`inspector_calidad` (
  `ID` INT(11) NOT NULL,
  `Nombre` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`inspeccion_calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`inspeccion_calidad` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Planta_ID` INT(11) NOT NULL,
  `Inspector_Calidad_ID` INT(11) NOT NULL,
  `Fehca_Hora` DATETIME NULL DEFAULT NULL,
  `Medicion_Acidez` VARCHAR(45) NULL DEFAULT NULL,
  `Prueba_Sabor_Aroma` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Inspeccion_Calidad_Planta1_idx` (`Planta_ID` ASC),
  INDEX `fk_Inspeccion_Calidad_Inspector_Calidad1_idx` (`Inspector_Calidad_ID` ASC),
  CONSTRAINT `fk_Inspeccion_Calidad_Inspector_Calidad1`
    FOREIGN KEY (`Inspector_Calidad_ID`)
    REFERENCES `app_trazabilidad`.`inspector_calidad` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Inspeccion_Calidad_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`planta_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`planta_has_lotes` (
  `Planta_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Planta_ID`, `Lotes_ID`),
  INDEX `fk_Planta_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Planta_has_Lotes_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Planta_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Planta_has_Lotes_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`trazabilidad_duraznos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`trazabilidad_duraznos` (
  `ID` INT(11) NOT NULL,
  `lote_id` VARCHAR(45) NULL DEFAULT NULL,
  `Finca_ID` INT(11) NULL DEFAULT NULL,
  `Planta_ID` INT(11) NULL DEFAULT NULL,
  `Bodega_Alimentos_ID` INT(11) NULL DEFAULT NULL,
  `Embarcacion_ID` INT(11) NULL DEFAULT NULL,
  `Distribucion_ID` INT(11) NULL DEFAULT NULL,
  `fase_cosecha` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_control_calidad` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_exportacion` VARCHAR(45) NULL DEFAULT 'pendiente',
  `fase_distribucion` VARCHAR(45) NULL DEFAULT 'pendiente',
  PRIMARY KEY (`ID`),
  INDEX `fk_trazabilidad_duraznos_Finca1_idx` (`Finca_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Planta1_idx` (`Planta_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Distribucion1_idx` (`Distribucion_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_Bodega_Alimentos1_idx` (`Bodega_Alimentos_ID` ASC),
  CONSTRAINT `fk_trazabilidad_duraznos_Bodega_Alimentos1`
    FOREIGN KEY (`Bodega_Alimentos_ID`)
    REFERENCES `app_trazabilidad`.`bodega_alimentos` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`vehiculo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`vehiculo` (
  `Placa` INT(11) NOT NULL AUTO_INCREMENT,
  `Modelo` VARCHAR(45) NULL DEFAULT NULL,
  `Marca` VARCHAR(45) NULL DEFAULT NULL,
  PRIMARY KEY (`Placa`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`viaje`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`viaje` (
  `ID` INT(11) NOT NULL AUTO_INCREMENT,
  `Vehiculo_ID` INT(11) NULL DEFAULT NULL,
  `Gerente_Logistica_ID` INT(11) NOT NULL,
  `Conductor_ID` INT(11) NOT NULL,
  `Salida` DATETIME NULL DEFAULT NULL,
  `Llegada` DATETIME NULL DEFAULT NULL,
  `Lugar_Destino` VARCHAR(45) NULL DEFAULT NULL,
  `Lugar_Salida` DATETIME NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Viaje_Gerente_Logistica1_idx` (`Gerente_Logistica_ID` ASC),
  INDEX `fk_Viaje_Conductor1_idx` (`Conductor_ID` ASC),
  CONSTRAINT `Vehiculo_ID`
    FOREIGN KEY (`ID`)
    REFERENCES `app_trazabilidad`.`vehiculo` (`Placa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Conductor1`
    FOREIGN KEY (`Conductor_ID`)
    REFERENCES `app_trazabilidad`.`conductor` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Gerente_Logistica1`
    FOREIGN KEY (`Gerente_Logistica_ID`)
    REFERENCES `app_trazabilidad`.`gerente_logistica` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`trazabilidad_duraznos_has_viaje`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`trazabilidad_duraznos_has_viaje` (
  `trazabilidad_duraznos_ID` INT(11) NOT NULL,
  `Viaje_ID` INT(11) NOT NULL,
  PRIMARY KEY (`trazabilidad_duraznos_ID`, `Viaje_ID`),
  INDEX `fk_trazabilidad_duraznos_has_Viaje_Viaje1_idx` (`Viaje_ID` ASC),
  INDEX `fk_trazabilidad_duraznos_has_Viaje_trazabilidad_duraznos1_idx` (`trazabilidad_duraznos_ID` ASC),
  CONSTRAINT `fk_trazabilidad_duraznos_has_Viaje_Viaje1`
    FOREIGN KEY (`Viaje_ID`)
    REFERENCES `app_trazabilidad`.`viaje` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_trazabilidad_duraznos_has_Viaje_trazabilidad_duraznos1`
    FOREIGN KEY (`trazabilidad_duraznos_ID`)
    REFERENCES `app_trazabilidad`.`trazabilidad_duraznos` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`viaje_has_lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`viaje_has_lotes` (
  `Viaje_ID` INT(11) NOT NULL,
  `Lotes_ID` INT(11) NOT NULL,
  PRIMARY KEY (`Viaje_ID`, `Lotes_ID`),
  INDEX `fk_Viaje_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Viaje_has_Lotes_Viaje1_idx` (`Viaje_ID` ASC),
  CONSTRAINT `fk_Viaje_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_has_Lotes_Viaje1`
    FOREIGN KEY (`Viaje_ID`)
    REFERENCES `app_trazabilidad`.`viaje` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

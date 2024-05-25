-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema app_trazabilidad
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `app_trazabilidad` DEFAULT CHARACTER SET utf8 ;
USE `app_trazabilidad` ;

-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Finca` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  `Dirección` LONGTEXT NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Durazno` (
  `ID` INT NOT NULL,
  `Color` VARCHAR(45) NULL,
  `Tamaño` VARCHAR(45) NULL,
  `Precio` DECIMAL(10,2) NULL,
  `Finca_ID` INT NOT NULL,
  `Fecha_Cosecha` DATE NULL,
  `Ubucacion_Actual` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Durazno_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Durazno_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`Finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Lotes` (
  `ID` INT NOT NULL,
  `Unidades` INT NOT NULL,
  `Descripcion` LONGTEXT NULL,
  `Creacion` DATETIME NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Lotes_has_Durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Lotes_has_Durazno` (
  `Lotes_ID` INT NOT NULL,
  `Durazno_ID` INT NOT NULL,
  PRIMARY KEY (`Lotes_ID`, `Durazno_ID`),
  INDEX `fk_Lotes_has_Durazno_Durazno1_idx` (`Durazno_ID` ASC),
  INDEX `fk_Lotes_has_Durazno_Lotes_idx` (`Lotes_ID` ASC),
  CONSTRAINT `fk_Lotes_has_Durazno_Lotes`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Lotes_has_Durazno_Durazno1`
    FOREIGN KEY (`Durazno_ID`)
    REFERENCES `app_trazabilidad`.`Durazno` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Gerente_Finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Gerente_Finca` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  `Finca_ID` INT NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Finca_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Gerente_Finca_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`Finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Vehiculo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Vehiculo` (
  `Placa` INT NOT NULL,
  `Modelo` VARCHAR(45) NULL,
  `Marca` VARCHAR(45) NULL,
  PRIMARY KEY (`Placa`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Gerente_Logistica`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Gerente_Logistica` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Conductor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Conductor` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Viaje`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Viaje` (
  `ID` INT NOT NULL,
  `Vehiculo_ID` INT NULL,
  `Gerente_Logistica_ID` INT NOT NULL,
  `Conductor_ID` INT NOT NULL,
  `Salida` DATETIME NULL,
  `Llegada` DATETIME NULL,
  `Lugar_Destino` VARCHAR(45) NULL,
  `Lugar_Salida` DATETIME NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Viaje_Gerente_Logistica1_idx` (`Gerente_Logistica_ID` ASC),
  INDEX `fk_Viaje_Conductor1_idx` (`Conductor_ID` ASC),
  CONSTRAINT `Vehiculo_ID`
    FOREIGN KEY (`ID`)
    REFERENCES `app_trazabilidad`.`Vehiculo` (`Placa`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Gerente_Logistica1`
    FOREIGN KEY (`Gerente_Logistica_ID`)
    REFERENCES `app_trazabilidad`.`Gerente_Logistica` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_Conductor1`
    FOREIGN KEY (`Conductor_ID`)
    REFERENCES `app_trazabilidad`.`Conductor` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Viaje_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Viaje_has_Lotes` (
  `Viaje_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Viaje_ID`, `Lotes_ID`),
  INDEX `fk_Viaje_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Viaje_has_Lotes_Viaje1_idx` (`Viaje_ID` ASC),
  CONSTRAINT `fk_Viaje_has_Lotes_Viaje1`
    FOREIGN KEY (`Viaje_ID`)
    REFERENCES `app_trazabilidad`.`Viaje` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Viaje_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Planta` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  `Direccion` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Gerente_Planta`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Gerente_Planta` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  `Planta_ID` INT NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Gerente_Plante_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Gerente_Plante_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`Planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Inspector_Calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Inspector_Calidad` (
  `ID` INT NOT NULL,
  `Nombre` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Inspeccion_Calidad`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Inspeccion_Calidad` (
  `ID` INT NOT NULL,
  `Planta_ID` INT NOT NULL,
  `Inspector_Calidad_ID` INT NOT NULL,
  `Fehca_Hora` DATETIME NULL,
  `Medicion_Acidez` VARCHAR(45) NULL,
  `Prueba_Sabor_Aroma` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Inspeccion_Calidad_Planta1_idx` (`Planta_ID` ASC),
  INDEX `fk_Inspeccion_Calidad_Inspector_Calidad1_idx` (`Inspector_Calidad_ID` ASC),
  CONSTRAINT `fk_Inspeccion_Calidad_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`Planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Inspeccion_Calidad_Inspector_Calidad1`
    FOREIGN KEY (`Inspector_Calidad_ID`)
    REFERENCES `app_trazabilidad`.`Inspector_Calidad` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Bodega_Alimentos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Bodega_Alimentos` (
  `ID` INT NOT NULL,
  `Planta_ID` INT NOT NULL,
  PRIMARY KEY (`ID`, `Planta_ID`),
  INDEX `fk_Alimentos_Bodega_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Alimentos_Bodega_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`Planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Bodega_Alimentos_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Bodega_Alimentos_has_Lotes` (
  `Bodega_Alimentos_ID` INT NOT NULL,
  `Bodega_Alimentos_Planta_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Bodega_Alimentos_ID`, `Bodega_Alimentos_Planta_ID`, `Lotes_ID`),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1_idx` (`Bodega_Alimentos_ID` ASC, `Bodega_Alimentos_Planta_ID` ASC),
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Bodega_Alimentos1`
    FOREIGN KEY (`Bodega_Alimentos_ID` , `Bodega_Alimentos_Planta_ID`)
    REFERENCES `app_trazabilidad`.`Bodega_Alimentos` (`ID` , `Planta_ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Bodega_Alimentos_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Embarcacion` (
  `ID` INT NOT NULL,
  `Salida` DATETIME NULL,
  `Llegada` DATETIME NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Distribucion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Distribucion` (
  `ID` INT NOT NULL,
  `Destino` VARCHAR(45) NULL,
  `Fecha_Reparticion` DATE NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Distribucion_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Distribucion_has_Lotes` (
  `Distribucion_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Lotes_ID`),
  INDEX `fk_Distribucion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Distribucion_has_Lotes_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Lotes_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`Distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Finca_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Finca_has_Lotes` (
  `Finca_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Finca_ID`, `Lotes_ID`),
  INDEX `fk_Finca_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Finca_has_Lotes_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Finca_has_Lotes_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `app_trazabilidad`.`Finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Finca_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Planta_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Planta_has_Lotes` (
  `Planta_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Planta_ID`, `Lotes_ID`),
  INDEX `fk_Planta_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Planta_has_Lotes_Planta1_idx` (`Planta_ID` ASC),
  CONSTRAINT `fk_Planta_has_Lotes_Planta1`
    FOREIGN KEY (`Planta_ID`)
    REFERENCES `app_trazabilidad`.`Planta` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Planta_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Distribucion_has_Embarcacion`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Distribucion_has_Embarcacion` (
  `Distribucion_ID` INT NOT NULL,
  `Embarcacion_ID` INT NOT NULL,
  PRIMARY KEY (`Distribucion_ID`, `Embarcacion_ID`),
  INDEX `fk_Distribucion_has_Embarcacion_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  INDEX `fk_Distribucion_has_Embarcacion_Distribucion1_idx` (`Distribucion_ID` ASC),
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Distribucion1`
    FOREIGN KEY (`Distribucion_ID`)
    REFERENCES `app_trazabilidad`.`Distribucion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Distribucion_has_Embarcacion_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`Embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `app_trazabilidad`.`Embarcacion_has_Lotes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `app_trazabilidad`.`Embarcacion_has_Lotes` (
  `Embarcacion_ID` INT NOT NULL,
  `Lotes_ID` INT NOT NULL,
  PRIMARY KEY (`Embarcacion_ID`, `Lotes_ID`),
  INDEX `fk_Embarcacion_has_Lotes_Lotes1_idx` (`Lotes_ID` ASC),
  INDEX `fk_Embarcacion_has_Lotes_Embarcacion1_idx` (`Embarcacion_ID` ASC),
  CONSTRAINT `fk_Embarcacion_has_Lotes_Embarcacion1`
    FOREIGN KEY (`Embarcacion_ID`)
    REFERENCES `app_trazabilidad`.`Embarcacion` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Embarcacion_has_Lotes_Lotes1`
    FOREIGN KEY (`Lotes_ID`)
    REFERENCES `app_trazabilidad`.`Lotes` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

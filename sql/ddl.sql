-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`Finca`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Finca` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL,
  `Direccion` VARCHAR(45) NULL,
  PRIMARY KEY (`ID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Lote`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Lote` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `Unidades` INT NOT NULL,
  `Ubicacion_Actual` VARCHAR(45) NULL,
  `Creacion` DATETIME NULL,
  `Finca_ID` INT NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Lote_Finca1_idx` (`Finca_ID` ASC),
  CONSTRAINT `fk_Lote_Finca1`
    FOREIGN KEY (`Finca_ID`)
    REFERENCES `mydb`.`Finca` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Durazno`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Durazno` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `Color` VARCHAR(45) NULL,
  `Tamaño` VARCHAR(45) NULL,
  `fecha_cosecha` DATETIME NULL,
  `Precio` DECIMAL(10,2) NULL,
  `Lote_ID` INT NOT NULL,
  PRIMARY KEY (`ID`),
  INDEX `fk_Durazno_Lote_idx` (`Lote_ID` ASC),
  CONSTRAINT `fk_Durazno_Lote`
    FOREIGN KEY (`Lote_ID`)
    REFERENCES `mydb`.`Lote` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

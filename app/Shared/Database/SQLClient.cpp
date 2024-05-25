#include "SQLClient.h"
#include <mysql_driver.h>
#include <cppconn/exception.h>
#include <iostream>

SQLClient::SQLClient() {
    connect(); // Llama al método connect al crear una instancia de SQLClient
}

SQLClient::~SQLClient() {
    // La conexión se cerrará automáticamente cuando se destruya el shared_ptr
}

SQLClient& SQLClient::getInstance() {
    static SQLClient instance; // Instancia única de SQLClient
    return instance;
}

void SQLClient::connect() {
    try {
        // Obtener el driver de MySQL
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        
        // Establecer la conexión con la base de datos
        connection = std::shared_ptr<sql::Connection>(driver->connect("tcp://127.0.0.1:3306", "root", ""));
        
        // Seleccionar la base de datos
        connection->setSchema("app_trazabilidad");
    } catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::shared_ptr<sql::Connection> SQLClient::getConnection() {
    return connection; // Devuelve la conexión establecida
}

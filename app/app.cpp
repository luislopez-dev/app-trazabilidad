#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

int main() {
    try {
        // Crear instancia del driver
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;

        driver = sql::mysql::get_mysql_driver_instance();

        // Conectar a la base de datos
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");

        // Conectar a una base de datos específica
        con->setSchema("mydb");

        // Crear un objeto Statement
        stmt = con->createStatement();

        // Crear una tabla
        stmt->execute("CREATE TABLE IF NOT EXISTS MiTabla ("
                      "id INT AUTO_INCREMENT, "
                      "nombre VARCHAR(255) NOT NULL, "
                      "edad INT NOT NULL, "
                      "PRIMARY KEY (id))");
        std::cout << "Tabla creada exitosamente." << std::endl;

        // Insertar datos en la tabla
        pstmt = con->prepareStatement("INSERT INTO MiTabla(nombre, edad) VALUES (?, ?)");
        pstmt->setString(1, "Juan");
        pstmt->setInt(2, 30);
        pstmt->execute();

        pstmt->setString(1, "Maria");
        pstmt->setInt(2, 25);
        pstmt->execute();

        pstmt->setString(1, "Carlos");
        pstmt->setInt(2, 35);
        pstmt->execute();

        std::cout << "Datos insertados exitosamente." << std::endl;

        // Consultar datos de la tabla
        res = stmt->executeQuery("SELECT id, nombre, edad FROM MiTabla");

        // Imprimir los datos
        while (res->next()) {
            std::cout << "ID: " << res->getInt("id") 
                      << ", Nombre: " << res->getString("nombre") 
                      << ", Edad: " << res->getInt("edad") << std::endl;
        }

        // Limpiar
        delete res;
        delete pstmt;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

#include "DuraznoDAO.h"
#include <cppconn/statement.h>

#include "../../Shared/Database/SQLClient.h"

void DuraznoDAO::save(Durazno& durazno)
{
    try {
        // Obtener la conexión desde SQLClient
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance().getConnection();
        
        // Crear un statement para ejecutar consultas
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());

        // Ejecutar una consulta SQL para crear una tabla si no existe
        stmt->execute("CREATE TABLE IF NOT EXISTS MiTabla ("
                      "id INT AUTO_INCREMENT, "
                      "nombre VARCHAR(255) NOT NULL, "
                      "edad INT NOT NULL, "
                      "PRIMARY KEY (id))");

        std::cout << "Tabla creada exitosamente." << std::endl;
    } catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Durazno DuraznoDAO::findById(int id)
{
}

vector<Durazno> DuraznoDAO::findAll()
{
}

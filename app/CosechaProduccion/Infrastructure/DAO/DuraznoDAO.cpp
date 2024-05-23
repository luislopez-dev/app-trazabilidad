#include "DuraznoDAO.h"
#include <cppconn/statement.h>
#include "../Data/SQLClient.h"

void DuraznoDAO::save(Durazno durazno)
{
    sql::Statement *stmt;

    stmt = SQLClient::connect()->createStatement();

    // Crear una tabla
    stmt->execute("CREATE TABLE IF NOT EXISTS MiTablaxxxxxx ("
                  "id INT AUTO_INCREMENT, "
                  "nombre VARCHAR(255) NOT NULL, "
                  "edad INT NOT NULL, "
                  "PRIMARY KEY (id))");
    std::cout << "Tabla creada exitosamente." << std::endl;

    delete stmt;
    delete SQLClient::connect();
}

Durazno DuraznoDAO::findById(int id)
{
}

vector<Durazno> DuraznoDAO::findAll()
{
}

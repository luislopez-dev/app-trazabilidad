#include "EmbarcacionDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

#include "../../Shared/Database/SQLClient.h"

void EmbarcacionDAO::saveEmbarcacion(Embarcacion* embarcacion)
{
    try
    {
        // Registrar embarcación
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();
        
        std::unique_ptr<sql::PreparedStatement> durazno_pstmt(conn
            ->prepareStatement("INSERT INTO Embarcacion (Puerto_Base, Fecha_Salida) VALUES (?, ?)"));
        
        durazno_pstmt->setString(1, embarcacion->get_puerto_base());
        durazno_pstmt->setString(2, embarcacion->get_fecha_salida());
        durazno_pstmt->executeUpdate();
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

int EmbarcacionDAO::findLastId()
{
    try
    {
        // Registrar embarcación
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();
        
        // Obtener ID de la nueva embarcación
        std::unique_ptr<sql::Statement> stmt(conn->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT LAST_INSERT_ID()"));
        
        return res->getInt(1);
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

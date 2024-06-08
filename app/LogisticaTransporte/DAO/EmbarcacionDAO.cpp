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

Embarcacion EmbarcacionDAO::getLast()
{
    try
    {
        Embarcacion * embarcacion = new Embarcacion;
    
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance().getConnection();
    
        sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Embarcacion ORDER BY id DESC LIMIT 1");

        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next())
        {
            embarcacion->set_id(res->getInt("ID"));
            embarcacion->set_puerto_base(res->getString("Puerto_Base"));
            embarcacion->set_fecha_salida(res->getString("Fecha_Salida"));
            
            return *embarcacion;
        }
        else
        {
            std::cout << "ERROR: AUN NO HAY INSPECCIONES REGISTRADAS" << std::endl;
        }
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

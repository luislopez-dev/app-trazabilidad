#include "DistribucionDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

#include "../../Shared/Database/SQLClient.h"

void DistribucionDAO::save(Distribucion* distribucion)
{
    try
    {
        // Registrar Distribucion
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();
            
        std::unique_ptr<sql::PreparedStatement> pstmt(conn
            ->prepareStatement("INSERT INTO Distribución (Tienda_Destino_Nombre, Tienda_Destino_Direccion, Fecha_Reparticion) VALUES (?, ?, ?)"));
            
        pstmt->setString(1, distribucion->get_tienda_destino_nombre());
        pstmt->setString(2, distribucion->get_tienda_destino_direccion());
        pstmt->setString(3, distribucion->get_fecha_reparticion());
        pstmt->executeUpdate();
    }
    
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

Distribucion DistribucionDAO::getLast()
{
    try
    {
        Distribucion * distribucion = new Distribucion;
    
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance().getConnection();
    
        sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Embarcacion ORDER BY id DESC LIMIT 1");

        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next())
        {
            distribucion->set_id(res->getInt("ID"));

            distribucion->set_tienda_destino_nombre(res->getString("Tienda_Destino_Nombre"));

            distribucion->set_tienda_destino_direccion(res->getString("Tienda_Destino_Direccion"));

            distribucion->set_fecha_reparticion(res->getString("Fecha_Reparticion"));
            
            return *distribucion;
        }
        else
        {
            std::cout << "ERROR: AUN NO HAY DISTRIBUCIONES REGISTRADAS." << std::endl;
        }
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

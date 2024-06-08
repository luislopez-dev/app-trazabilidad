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

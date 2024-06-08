#include "PlantaControlCalidadDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> 

#include "../../Shared/Database/SQLClient.h"
#include "../Models/PlantaControlCalidad.h"

PlantaControlCalidad PlantaControlCalidadDAO::get()
{
    try
    {
        PlantaControlCalidad* planta = new PlantaControlCalidad;
        
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();

        std::unique_ptr<sql::PreparedStatement> pstmt(conn
            ->prepareStatement("SELECT * FROM Planta_Control_Calidad WHERE ID = ?"));
        
        pstmt->setInt(1, 1);

        sql::ResultSet* res = pstmt->executeQuery();

        while (res->next())
        {
            planta->set_nombre(res->getString("Nombre"));
            planta->set_direccion(res->getString("Direccion"));
        }
        return *planta;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
}

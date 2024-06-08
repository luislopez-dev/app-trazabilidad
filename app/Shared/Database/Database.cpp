#include "Database.h"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>

#include "SQLClient.h"

void Database::init()
{
    // Get SQL Client Instance
    std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
       .getConnection();


    // Verificar si ya existe una finca
    std::unique_ptr<sql::PreparedStatement> check_finca_pstmt(conn->prepareStatement("SELECT * FROM FINCA"));

    std::unique_ptr<sql::ResultSet> finca_res(check_finca_pstmt->executeQuery());

    if (!finca_res->next())
    {
        // Registrar finca
        std::unique_ptr<sql::PreparedStatement> finca_pstmt(conn
            ->prepareStatement("INSERT INTO Finca (Nombre, Direccion) VALUES (?, ?)"));
        
        finca_pstmt->setString(1, "Finca Lopez");
        finca_pstmt->setString(2, "Guatemla, Guatemla, KM 19 Carretera Interamericana");
        finca_pstmt->executeUpdate();
    }
    
    // Verificar si ya existe una planta de control de calidad
    std::unique_ptr<sql::PreparedStatement> check_planta_pstmt(conn->prepareStatement("SELECT * FROM Planta_Control_Calidad"));

    std::unique_ptr<sql::ResultSet> planta_res(check_planta_pstmt->executeQuery());

    if (!planta_res->next())
    {
        // Registrar planta de control de calidad
        std::unique_ptr<sql::PreparedStatement> planta_pstmt(conn
            ->prepareStatement("INSERT INTO Planta_Control_Calidad (Nombre, Direccion) VALUES (?, ?)"));
        
        planta_pstmt->setString(1, "Planta de Control de Calida #1");
        planta_pstmt->setString(2, "Chimaltenango, Chimaltenango KM 55 Carretera Interamericana");
        planta_pstmt->executeUpdate();
    }
}

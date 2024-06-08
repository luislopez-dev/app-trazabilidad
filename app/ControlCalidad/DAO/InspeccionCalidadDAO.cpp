#include "InspeccionCalidadDAO.h"
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> 
#include "../../Shared/Database/SQLClient.h"

void InspeccionCalidadDAO::save(InspeccionCalidad* inspeccion)
{
    try
    {
        // DB connection
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
               .getConnection();
    
        std::unique_ptr<sql::PreparedStatement> pstmt(conn
                ->prepareStatement("INSERT INTO "
                                   "Inspeccion_Calidad ("
                                   "Lote_ID, "
                                   "Planta_Control_Calidad_ID, "
                                   "Medicion_Acidez, "
                                   "Medicion_Dulzura, "
                                   "Prueba_Aroma, "
                                   "Fecha) VALUES (?, ?, ?, ?, ?, ?)"));
        
        pstmt->setInt(1, inspeccion->get_lote_id());
        pstmt->setInt(2, inspeccion->get_planta_control_calidad_id());
        pstmt->setString(3, inspeccion->get_medicion_acidez());
        pstmt->setString(4, inspeccion->get_medicion_dulzura());
        pstmt->setString(5, inspeccion->get_prueba_aroma());
        pstmt->setDateTime(6, inspeccion->get_fecha());
        pstmt->executeUpdate();
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

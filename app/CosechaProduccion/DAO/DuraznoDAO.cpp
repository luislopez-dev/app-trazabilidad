#include "DuraznoDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> 
#include "LoteDAO.h"
#include "../../Shared/Database/SQLClient.h"

void DuraznoDAO::save(Durazno* durazno)
{
    try
    {
        // Consulta para obtener el ID o crear un lote en Finca
        int lote_id = LoteDAO::findLoteEnFincaID();
        
        shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();
        
        // Si no hay lotes disponibles, se crea uno nuevo
        if (lote_id == 0)
        {
            Lote* nuevo_lote_id = new Lote();
            nuevo_lote_id->set_ubicacion_actual("Cosecha_Produccion");
            LoteDAO::save(nuevo_lote_id);

           lote_id = LoteDAO::findLoteEnFincaID();
        }
        
        // Consulta para registrar durazno con su respectivo lote
        unique_ptr<sql::PreparedStatement> durazno_pstmt(conn
            ->prepareStatement("INSERT INTO Durazno (color, tamaño, precio, fecha_cosecha, Lote_ID) VALUES (?, ?, ?, ?, ?)"));
        
        durazno_pstmt->setString(1, durazno->get_color());
        durazno_pstmt->setString(2, durazno->get_tamano());
        durazno_pstmt->setDouble(3, durazno->get_precio());
        durazno_pstmt->setString(4, durazno->get_fecha_cosecha());
        durazno_pstmt->setInt(5, lote_id);
        durazno_pstmt->executeUpdate();
    }
    catch (sql::SQLException& e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
}
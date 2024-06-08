#include "LoteDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> 

#include "../../Shared/Database/SQLClient.h"

using namespace std;

void LoteDAO::save(Lote* lote)
{
    try
    {
        shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();

        unique_ptr<sql::PreparedStatement> pstmt(conn
            ->prepareStatement("INSERT INTO Lote (creacion, Finca_ID, Ubicacion_Actual) VALUES (?, ?, ?)"));
        
        pstmt->setString(1, lote->get_creacion());
        pstmt->setInt(2, lote->get_finca_id());
        pstmt->setString(3, "Cosecha_Produccion");
        pstmt->executeUpdate();
    }
    catch (sql::SQLException& e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
}

Lote LoteDAO::findById(int id)
{
    Lote lote;
    
    try {
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance().getConnection();
        
        std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("SELECT * FROM Lote WHERE id = ?"));
        
        pstmt->setInt(1, id);
        
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        
        if (res->next()) {
            lote.set_id(res->getInt("id"));
            lote.set_descripcion(res->getString("descipcion"));
            lote.set_creacion(res->getString("date"));
        }
        return lote;
        
    } catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return lote;
}

std::list<Lote> LoteDAO::findAll()
{
}

void LoteDAO::updateUbicacion(Lote* lote)
{
    try
    {
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance().getConnection();

        std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("UPDATE Lote SET Ubicacion_Actual = ? WHERE ID = ?"));

        pstmt->setString(1, lote->get_ubicacion_actual());
        pstmt->setInt(2, lote->get_id());
        pstmt->executeUpdate();
    }
    catch (sql::SQLException& e) {
        
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int LoteDAO::findLoteEnFincaID()
{
    int lote_id = 0;

    shared_ptr<sql::Connection> conn = SQLClient::getInstance()
   .getConnection();
    
    unique_ptr<sql::PreparedStatement> lote_pstmtg(conn
    ->prepareStatement("SELECT ID FROM Lote WHERE Ubicacion_Actual = ?"));

    lote_pstmtg->setString(1, "Cosecha_Produccion");

    sql::ResultSet* res = lote_pstmtg->executeQuery();

    if (res->next())
    {
        lote_id = res->getInt("ID");
    }
    return lote_id;
}

int LoteDAO::findLoteEnPlantaInspeccionID()
{
    int lote_id = 0;

    shared_ptr<sql::Connection> conn = SQLClient::getInstance()
   .getConnection();
    
    unique_ptr<sql::PreparedStatement> lote_pstmtg(conn
    ->prepareStatement("SELECT ID FROM Lote WHERE Ubicacion_Actual = ?"));

    lote_pstmtg->setString(1, "Control_Calidad");

    sql::ResultSet* res = lote_pstmtg->executeQuery();

    if (res->next())
    {
        lote_id = res->getInt("ID");
    }
    return lote_id;
}

int LoteDAO::findLoteListoParaEmbarcacionID()
{
    int lote_id = 0;

    shared_ptr<sql::Connection> conn = SQLClient::getInstance()
   .getConnection();
    
    unique_ptr<sql::PreparedStatement> lote_pstmtg(conn
    ->prepareStatement("SELECT ID FROM Lote WHERE Ubicacion_Actual = ?"));

    lote_pstmtg->setString(1, "Listo Para Embarcacion");

    sql::ResultSet* res = lote_pstmtg->executeQuery();

    if (res->next())
    {
        lote_id = res->getInt("ID");
    }
    return lote_id;
}

int LoteDAO::findLoteExportadoID()
{
    int lote_id = 0;

    shared_ptr<sql::Connection> conn = SQLClient::getInstance()
   .getConnection();
    
    unique_ptr<sql::PreparedStatement> lote_pstmtg(conn
    ->prepareStatement("SELECT ID FROM Lote WHERE Ubicacion_Actual = ?"));

    lote_pstmtg->setString(1, "EXPORTADO");

    sql::ResultSet* res = lote_pstmtg->executeQuery();

    if (res->next())
    {
        lote_id = res->getInt("ID");
    }
    return lote_id;
}


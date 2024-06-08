#include "FincaDAO.h"
#include <iostream>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h> 
#include "../../Shared/Database/SQLClient.h"

using namespace std;

Finca FincaDAO::get()
{
    try
    {
        Finca* finca = new Finca;
        
        std::shared_ptr<sql::Connection> conn = SQLClient::getInstance()
           .getConnection();

        unique_ptr<sql::PreparedStatement> pstmt(conn
            ->prepareStatement("SELECT * FROM Finca WHERE ID = ?"));
        
        pstmt->setInt(1, 1);

        sql::ResultSet* res = pstmt->executeQuery();

        while (res->next())
        {
            finca->set_nombre(res->getString("Nombre"));
            finca->set_direccion(res->getString("Direccion"));
        }
        return *finca;
    }
    catch (sql::SQLException& e)
    {
        cerr << "ERROR: " << e.what() << endl;
    }
}

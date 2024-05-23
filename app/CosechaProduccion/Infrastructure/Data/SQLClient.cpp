#include "SQLClient.h"

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>

Connection* SQLClient::connect()
{
    try {
        
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        
        driver = sql::mysql::get_mysql_driver_instance();

        con = driver->connect("tcp://127.0.0.1:3306", "root", "");

        con->setSchema("mydb");

        return con;
       
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

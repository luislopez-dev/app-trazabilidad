#pragma once
#include <cppconn/connection.h>
using namespace sql;

class SQLClient
{
    public:
        static Connection* connect();
};

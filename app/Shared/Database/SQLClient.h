#include <cppconn/connection.h>
#include <memory>

class SQLClient {
public:
    // Método estático para obtener la única instancia de SQLClient
    static SQLClient& getInstance();

    // Método para obtener la conexión a la base de datos
    std::shared_ptr<sql::Connection> getConnection();

private:
    SQLClient(); // Constructor privado para evitar la creación de instancias
    ~SQLClient(); // Destructor privado para evitar la destrucción manual
    SQLClient(const SQLClient&) = delete; // Deshabilitar la copia
    SQLClient& operator=(const SQLClient&) = delete; // Deshabilitar la asignación

    std::shared_ptr<sql::Connection> connection; // Instancia única de la conexión
    void connect(); // Método privado para establecer la conexión
};

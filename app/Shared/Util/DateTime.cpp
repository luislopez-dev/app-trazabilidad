#include "DateTime.h"
#include <iomanip>
#include <sstream>

#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

// Función para obtener la fecha y hora actuales en formato MySQL DATETIME
std::string DateTime::getCurrentDateTime() {
    std::time_t now = std::time(nullptr); // Obtener el tiempo actual
    std::tm tm = {}; // Crear una estructura tm

    #ifdef _WIN32
    localtime_s(&tm, &now); // Utilizar localtime_s en Windows
    #else
    localtime_r(&now, &tm); // Utilizar localtime_r en otros sistemas (Unix-like)
    #endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S"); // Formatear el tiempo

    return oss.str(); // Devolver como string
}



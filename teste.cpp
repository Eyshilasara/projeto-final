

// arquivo de teste (testes.cpp)
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "include\Gerenciador_de_arquivos.hpp"
//Método que irá realizar uma sequência testes de acordo com os resultados esperados

std::string getCurrentDateAsString() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), " %Y-%m-%d");

    return oss.str();
}

TEST_CASE("GetCurrentDateAsString") {
CHECK(getCurrentDateAsString());
CHECK(getCurrentDateAsString());
CHECK(getCurrentDateAsString());
}


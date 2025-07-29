cmake_minimum_required(VERSION 3.31)
project(lista_tarefas)

set(CMAKE_CXX_STANDARD 20)

add_executable(lista_tarefas main.cpp
        GestorTarefas.cpp
        ServicoTarefas.cpp
        Tarefa.cpp)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(lista_tarefas PRIVATE fmt::fmt)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(lista_tarefas PRIVATE nlohmann_json::nlohmann_json)
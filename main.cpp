#include <iostream>
#include <fmt/printf.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <locale>
#include "GestorTarefas.h"

int main() {
    std::locale::global(std::locale(""));
#ifdef WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    fmt::print("Lista de Tarefas!\n");
    bool sair = false;
    GestorTarefas gestor;
    gestor.carregarTarefas();
    while (!sair) {
        fmt::print("Escolha uma opção:\n");
        fmt::print("1. Adicionar Tarefa\n");
        fmt::print("2. Listar Tarefas\n");
        fmt::print("3. Marcar/Desmarcar Tarefa como Finalizada\n");
        fmt::print("4. Alterar Tarefa\n");
        fmt::print("5. Remover Tarefa\n");
        fmt::print("0. Sair\n");
        int opcao;
        fmt::print("Digite sua opção: ");
        std::cin >> opcao;
        std::cin.ignore();
        switch (opcao) {
            case 1: {
                gestor.adicionarTarefa();
                break;
            }
            case 2:
                gestor.listarTarefas();
                break;
            case 3: {
                gestor.alternarTarefaFinalizada();
                break;
            }
            case 4: {
                gestor.alterarTarefa();
                break;
            }
            case 5: {
                gestor.removerTarefa();
                break;
            }
            case 0:
                sair = true;
                gestor.salvarTarefas();
                fmt::print("Saindo do programa...\n");
                break;
            default:
                fmt::print("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}

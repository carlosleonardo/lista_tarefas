//
// Created by S861321135 on 28/07/2025.
//

#include "GestorTarefas.h"

#include <iostream>
#include <fmt/printf.h>

GestorTarefas::GestorTarefas() {
    servicoTarefas = std::make_unique<ServicoTarefas>();
    proximoId = 1; // Inicia o ID das tarefas a partir de 1
}

void GestorTarefas::adicionarTarefa() {
    std::string titulo;
    while (titulo.empty()) {
        fmt::print("Digite o título da tarefa: ");
        std::getline(std::cin, titulo);
    }
    servicoTarefas->adicionar(proximoId++, titulo);
    fmt::print("Tarefa '{}' adicionada com sucesso!\n", titulo);
}

void GestorTarefas::listarTarefas() const {
    const auto tarefas = servicoTarefas->obterTarefas();
    if (tarefas.empty()) {
        fmt::print("Nenhuma tarefa encontrada.\n");
        return;
    }
    fmt::print("Lista de Tarefas:\n");
    for (const auto &[id, titulo, finalizada]: tarefas) {
        fmt::print("ID: {}, Título: '{}', Finalizada: {}\n",
                   id, titulo, finalizada ? "Sim" : "Não");
    }
}

void GestorTarefas::alternarTarefaFinalizada() const {
    int id = 0;
    while (id < 1) {
        fmt::print("Digite o ID da tarefa para alternar o status de finalização: ");
        std::cin >> id;
        std::cin.ignore(); // Limpa o buffer de entrada
        // Verifica se a tarefa existe
        verificaExistencia(id);
    }
    servicoTarefas->alternarFinalizada(id);
}

void GestorTarefas::verificaExistencia(int &id) const {
    if (!servicoTarefas->obterTarefaPorId(id).has_value()) {
        fmt::print("Tarefa com ID {} não encontrada.\n", id);
        id = 0; // Reseta o ID para continuar o loop
    }
}

void GestorTarefas::removerTarefa() const {
    int id = 0;
    while (id < 1) {
        fmt::print("Digite o ID da tarefa para remover: ");
        std::cin >> id;
        std::cin.ignore(); // Limpa o buffer de entrada
        // Verifica se a tarefa existe
        verificaExistencia(id);
    }
    servicoTarefas->remover(id);
    fmt::print("Tarefa com ID {} removida com sucesso!\n", id);
}

void GestorTarefas::alterarTarefa() const {
    int id = 0;
    while (id < 1) {
        fmt::print("Digite o ID da tarefa para alterar: ");
        std::cin >> id;
        std::cin.ignore(); // Limpa o buffer de entrada
        // Verifica se a tarefa existe
        verificaExistencia(id);
    }
    std::string novoTitulo;
    while (novoTitulo.empty()) {
        fmt::print("Digite o novo título da tarefa: ");
        std::getline(std::cin, novoTitulo);
    }
    servicoTarefas->alterar(id, novoTitulo);
    fmt::print("Tarefa com ID {} alterada para '{}'.\n", id, novoTitulo);
}

void GestorTarefas::salvarTarefas() const {
    servicoTarefas->salvarTarefas();
    fmt::print("Tarefas salvas com sucesso!\n");
}

void GestorTarefas::carregarTarefas() {
    servicoTarefas->carregarTarefas();
    proximoId = servicoTarefas->obterTarefas().size() + 1; // Reseta o ID para o próximo uso
    fmt::print("Tarefas carregadas com sucesso!\n");
}

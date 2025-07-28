//
// Created by S861321135 on 28/07/2025.
//

#include "ServicoTarefas.h"

#include <optional>
#include <stdexcept>

void ServicoTarefas::adicionar(int id, const std::string &titulo) {
    Tarefa tarefa;
    tarefa.id = id;
    tarefa.titulo = titulo;
    tarefa.finalizada = false;
    tarefas.push_back(tarefa);
}

void ServicoTarefas::alternarFinalizada(int id) {
    for (auto &tarefa: tarefas) {
        if (tarefa.id == id) {
            tarefa.finalizada = !tarefa.finalizada;
            return;
        }
    }
}

void ServicoTarefas::remover(int id) {
    std::erase_if(tarefas,
                  [id](const Tarefa &tarefa) { return tarefa.id == id; });
}

void ServicoTarefas::alterar(int id, const std::string &titulo) {
    for (auto &tarefa: tarefas) {
        if (tarefa.id == id) {
            tarefa.titulo = titulo;
            return;
        }
    }
}

std::vector<Tarefa> ServicoTarefas::obterTarefas() {
    return tarefas;
}

std::optional<Tarefa> ServicoTarefas::obterTarefaPorId(int id) const {
    for (const auto &tarefa: tarefas) {
        if (tarefa.id == id) {
            return tarefa;
        }
    }
    return std::nullopt;
}

//
// Created by S861321135 on 28/07/2025.
//

#include "ServicoTarefas.h"

#include <fstream>
#include <optional>

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
    auto tarefa = tarefas | std::ranges::views::filter([id](const Tarefa &t)-> bool {
        return t.id == id;
    });

    if (tarefa.empty()) {
        return std::nullopt; // Retorna std::nullopt se a tarefa não for encontrada
    }
    return tarefa.front(); // Retorna a primeira tarefa encontrada
}

void ServicoTarefas::salvarTarefas() {
    nlohmann::json json = tarefas;
    std::ofstream arquivo("tarefas.json");
    if (arquivo.is_open()) {
        arquivo.imbue(std::locale(""));
        arquivo << json.dump(4, ' ', false, nlohmann::json::error_handler_t::replace);
        // Formata o JSON com 4 espaços de indentação
        arquivo.close();
    }
}

void ServicoTarefas::carregarTarefas() {
    nlohmann::json json;
    std::ifstream arquivo("tarefas.json");
    tarefas.clear(); // Limpa a lista de tarefas antes de carregar
    if (arquivo.is_open()) {
        arquivo.imbue(std::locale(""));
        arquivo >> json;
        tarefas = json.get<std::vector<Tarefa> >(); // Converte o JSON de volta
        arquivo.close();
    }
}

//
// Created by S861321135 on 28/07/2025.
//

#ifndef SERVICOTAREFAS_H
#define SERVICOTAREFAS_H
#include <optional>
#include <vector>

#include "Tarefa.h"


class ServicoTarefas {
private:
    std::vector<Tarefa> tarefas;

public:
    void adicionar(int id, const std::string &titulo);

    void alternarFinalizada(int id);

    void remover(int id);

    void alterar(int id, const std::string &titulo);

    std::vector<Tarefa> obterTarefas();

    [[nodiscard]] std::optional<Tarefa> obterTarefaPorId(int id) const;

    void salvarTarefas();

    void carregarTarefas();
};


#endif //SERVICOTAREFAS_H

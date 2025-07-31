//
// Created by S861321135 on 28/07/2025.
//

#ifndef GESTORTAREFAS_H
#define GESTORTAREFAS_H
#include <memory>

#include "ServicoTarefas.h"


/** * @file GestorTarefas.h
 * @brief Header file for the GestorTarefas class.
 *
 * This file contains the declaration of the GestorTarefas class, which is responsible for managing tasks.
 */
class GestorTarefas {
private:
    std::unique_ptr<ServicoTarefas> servicoTarefas; ///< Pointer to the service that manages tasks.
    size_t proximoId{}; ///< The next available ID for a new task.
    void verificaExistencia(int &id) const;

public:
    GestorTarefas();

    void adicionarTarefa();

    void listarTarefas() const;

    void alternarTarefaFinalizada() const;


    void removerTarefa() const;

    void alterarTarefa() const;

    void salvarTarefas() const;

    void carregarTarefas();
};


#endif //GESTORTAREFAS_H

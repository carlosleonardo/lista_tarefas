//
// Created by S861321135 on 28/07/2025.
//

#ifndef TAREFA_H
#define TAREFA_H
#include <string>
#include <nlohmann/json.hpp>

struct Tarefa {
	int id;
	std::string titulo;
	bool finalizada;
	NLOHMANN_DEFINE_TYPE_INTRUSIVE(Tarefa, id, titulo, finalizada)
};


#endif //TAREFA_H

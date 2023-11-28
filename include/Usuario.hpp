//TODO - Incluir colaborações
#pragma once
#include <string>
#include "BancoDeDados.hpp"

class Usuario {
public:
// TODO - Incluir métodos de usuário
Usuario(const std::string &nome, const std::string senha, const std::string tipoUsuario);

private:
// TODO - Incluir atributos de usuário
BancoDeDados &banco;
const std::string nome;
const std::string senha;
const std::string tipoUsuario;
};

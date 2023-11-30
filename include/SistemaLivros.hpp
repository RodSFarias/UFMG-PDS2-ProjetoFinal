#pragma once

#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "Livro.hpp"
#include "BancoDeDados.hpp"

/// @brief Estrutuda de dado utilizada para salvar livros no banco de dados.
struct LivroDB{
    std::string nome;
    std::string autor;
    std::string assunto;
    unsigned anoPublicacao;
    unsigned copias;
};

class SistemaLivros {
public:

    /// @brief Inclui livro nas listas e adciona ao banco de dados.
    /// @details Esta função adciona às listas da própria classe 
    /// (_biblioteca, _byAno, etc) e salva as informações no banco de dados.
    /// @param livro Instancia de Livro
    /// @return True se bem sucedido e False caso haja falha
    bool adcionarLivro(Livro livro);

    /// @brief Cria uma cópia do livro ter que incluir tudo
    /// @details Esta função incrementa o número de cópias à 
    /// lista _biblioteca e salva as informações no banco de dados.
    /// @param isbn Código de livro
    /// @return True se bem sucedido e False caso haja falha
    bool adcionarLivro(CodISBN isbn);

    /// @brief Edita as informações de um livro já existente no sistema
    /// @details Esta função edita as informações de um livro já existente em 
    /// lista _biblioteca e salva as informações no banco de dados.
    /// @param isbn Código ISBN do livro
    /// @param livro Parâmetros do livro
    /// @return True se bem sucedido e False caso haja falha
    bool editarLivro(CodISBN isbn, LivroDB livro);

    /// @brief Remove livro das listas e do banco de dados
    /// @details Esta função remove o livro das listas da classe
    /// (_biblioteca, _byAno, etc) e salva as informações no banco de dados 
    /// @param livro Instância de Livro
    /// @return True se bem sucedido e False caso haja falha
    bool removerLivro(Livro livro);

    /// @brief Salva todas as listas do sistema de biblioteca no banco de dados.
    /// @details Salva as listas _biblioteca, _byAno, _byAssunto e _byAutor 
    /// chamando as respectivas funções de BancoDeDados para cada.
    /// @return True se bem sucedido e False caso haja falha
    bool salvarListas();

    /// @brief Retira um livro do sistema de biblioteca
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e False caso haja falha 
    bool emprestarLivro(CodISBN isbn);

    /// @brief Retorna um livro ao sistema de biblioteca
    /// @param isbn Código ISBN do livro
    /// @return True se bem sucedido e False caso haja falha 
    bool devolverLivro(CodISBN isbn);
    
private:

    /// @brief Instância de BancoDeDados para armazenar listas em arquivo.
    BancoDeDados bd;

    /// @brief Armazena os livros da biblioteca (por ISBN) e o suas características.
    std::map<CodISBN, LivroDB> _biblioteca;

    /// @brief Livros emprestados por código ISBN e nome de usuário
    std::vector<std::pair<CodISBN, std::string>> _livrosEmprestados;
    
    /// @brief Armazena os ISBN dos livros por ano.
    /// @details O formato está a seguir:
    /// {
    ///     2020:       [9781234567897, 9781234567847],
    /// }
    std::map<unsigned, std::set<CodISBN>> _byAno;

    /// @brief Armazena os ISBN dos livros por assunto.
    /// @details O formato está a seguir:
    /// {
    ///     "Letras":   [9781234567897, 9781234567847],
    /// }
    std::map<std::string, std::set<CodISBN>> _byAssunto;
    
    /// @brief Armazena os ISBN dos livros por assunto.
    /// @details O formato está a seguir:
    /// {
    ///     "John Doe": [9781234567897, 9781234567847],
    /// }
    std::map<std::string, std::set<CodISBN>> _byAutor;
};

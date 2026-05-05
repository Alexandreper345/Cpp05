#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // 1. Inicializa a semente do rand para o Robotomy funcionar de verdade
    std::srand(std::time(NULL));

    std::cout << "--- TESTE 1: O BUROCRATA DE ELITE (ZAPHOD) ---" << std::endl;
    try 
    {
        Bureaucrat president("Zaphod Beeblebrox", 1);
        PresidentialPardonForm form("Arthur Dent");

        std::cout << president << std::endl;
        std::cout << form << std::endl;

        president.signForm(form);
        president.executeForm(form);
    }
    catch (std::exception &e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 2: O ESTAGIÁRIO TENTANDO PODER ---" << std::endl;
    try 
    {
        Bureaucrat intern("Estagiario", 150);
        RobotomyRequestForm robot("Bender");

        std::cout << intern << std::endl;
        
        // Tentativa de assinar (vai falhar, nota 150 < 72)
        intern.signForm(robot);
        
        // Tentativa de executar (vai falhar, nota 150 < 45)
        intern.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cerr << "Capturado no main: " << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 3: SHRUBBERY (A ÁRVORE) ---" << std::endl;
    try 
    {
        Bureaucrat gardener("Jardineiro", 130);
        ShrubberyCreationForm shrub("home");

        gardener.signForm(shrub);
        gardener.executeForm(shrub); // Deve criar o arquivo home_shrubbery
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 4: ROBOTOMY (SORTEIO DE 50%) ---" << std::endl;
    try 
    {
        Bureaucrat boss("Chefe", 30);
        RobotomyRequestForm robot("Wall-E");

        boss.signForm(robot);
        std::cout << "Executando 3 vezes para testar a sorte:" << std::endl;
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TESTE 5: EXECUTAR SEM ASSINAR ---" << std::endl;
    try 
    {
        Bureaucrat boss("Chefe Supremo", 1);
        PresidentialPardonForm form("Culpado");

        // Note que NÃO chamamos signForm aqui
        boss.executeForm(form); 
    }
    catch (std::exception &e) {
        std::cout << "Sucesso no erro: Não deixou executar sem assinatura!" << std::endl;
    }

    return 0;
}
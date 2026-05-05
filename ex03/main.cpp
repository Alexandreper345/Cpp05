#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp" // Novo include

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- TESTE 1: O INTERN TRABALHANDO (SUCESSO) ---" << std::endl;
    {
        Intern someRandomIntern;
        Bureaucrat boss("Zaphod", 1);
        AForm* rrf;

        // O estagiário cria o formulário
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        if (rrf) 
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf; // IMPORTANTE: Deletar a memória alocada pelo Intern
        }
    }

    std::cout << "\n--- TESTE 2: INTERN CRIANDO OS OUTROS TIPOS ---" << std::endl;
    {
        Intern someRandomIntern;
        AForm* f1;
        AForm* f2;

        f1 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        f2 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        if (f1) {
            std::cout << "Formulário 1: " << f1->get_name() << " criado com sucesso." << std::endl;
            delete f1;
        }
        if (f2) {
            std::cout << "Formulário 2: " << f2->get_name() << " criado com sucesso." << std::endl;
            delete f2;
        }
    }

    std::cout << "\n--- TESTE 3: INTERN ERRANDO O NOME ---" << std::endl;
    {
        Intern someRandomIntern;
        AForm* unknown;

        // Tentando criar um formulário que não existe
        unknown = someRandomIntern.makeForm("coffee request", "Intern");

        if (!unknown) {
            std::cout << "Como esperado, o ponteiro retornou NULL." << std::endl;
        } else {
            delete unknown;
        }
    }

    std::cout << "\n--- TESTE 4: FLUXO COMPLETO (INTERN + BUREAUCRAT) ---" << std::endl;
    try 
    {
        Intern stagi;
        Bureaucrat bobby("Bobby", 5);
        AForm* form;

        form = stagi.makeForm("presidential pardon", "Ford Prefect");
        if (form)
        {
            bobby.signForm(*form);
            bobby.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
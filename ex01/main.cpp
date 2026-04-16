#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Função auxiliar para deixar o output bonitinho
void printTitle(std::string title) {
    std::cout << "\n\033[33m=== " << title << " ===\033[0m" << std::endl;
}

int main() {
    // --- TESTE 1: Tentando criar formulários inválidos ---
    printTitle("TESTE 1: Construtores de Form (Exceções)");
    try {
        Form f1("Muito Alto", 0, 50);
    } catch (std::exception &e) {
        std::cout << "Erro capturado (Grade 0): " << e.what() << std::endl;
    }

    try {
        Form f2("Muito Baixo", 151, 150);
    } catch (std::exception &e) {
        std::cout << "Erro capturado (Grade 151): " << e.what() << std::endl;
    }


    // --- TESTE 2: Burocrata tentando assinar sem ter cargo ---
    printTitle("TESTE 2: Assinatura negada (Grau Insuficiente)");
    try {
        Bureaucrat intern("Estagiário", 150);
        Form topSecret("Contrato de Fusão", 1, 1);

        std::cout << intern << std::endl;
        std::cout << topSecret << std::endl;
        
        intern.signForm(topSecret); // Deve dar erro, mas o programa continua
        
        std::cout << topSecret << std::endl; // Deve continuar como false
    } catch (std::exception &e) {
        std::cout << "Erro crítico no main: " << e.what() << std::endl;
    }


    // --- TESTE 3: Burocrata com cargo exato e cargo superior ---
    printTitle("TESTE 3: Assinatura com Sucesso");
    try {
        Bureaucrat boss("Diretor", 10);
        Form f1("Aumento de Salário", 10, 20); // Grau exato
        Form f2("Compra de Café", 100, 100);    // Grau superior

        std::cout << boss << std::endl;
        
        boss.signForm(f1);
        boss.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }


    // --- TESTE 4: Tentativa de assinar um formulário já assinado ---
    printTitle("TESTE 4: Re-assinatura");
    try {
        Bureaucrat god("Presidente", 1);
        Form tax("Imposto de Renda", 50, 50);

        god.signForm(tax);
        std::cout << "Status após primeira assinatura: " << (tax.get_is_assign() ? "true" : "false") << std::endl;
        
        god.signForm(tax); // Apenas chama de novo, deve continuar true
        std::cout << "Status após segunda assinatura: " << (tax.get_is_assign() ? "true" : "false") << std::endl;
    } catch (std::exception &e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    printTitle("FIM DOS TESTES");
    return 0;
}
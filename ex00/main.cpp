#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Teste 1: Criando grades válidas ===\n";
    try {
        Bureaucrat bob("Bob", 42);
        Bureaucrat alice("Alice", 1);
        Bureaucrat charlie("Charlie", 150);
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 2: Criando grades inválidas ===\n";
    try {
        Bureaucrat invalidHigh("InvalidHigh", 0); // Grade muito alta
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    try {
        Bureaucrat invalidLow("InvalidLow", 151); // Grade muito baixa
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 3: Incremento e decremento ===\n";
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.increment(); // deve ir para 1
        std::cout << "Após incremento: " << bob << std::endl;
        bob.increment(); // deve lançar GradeTooHighException
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 149);
        std::cout << charlie << std::endl;
        charlie.decrement(); // deve ir para 150
        std::cout << "Após decremento: " << charlie << std::endl;
        charlie.decrement(); // deve lançar GradeTooLowException
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 4: Construtor de cópia ===\n";
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n=== Teste 5: Operador << ===\n";
    try {
        Bureaucrat test("Tester", 100);
        std::cout << test << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    return 0;
}
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <variant>

using namespace std;

class Environment {
private:
    std::map<std::string, std::variant<int, double, std::string>> symbolTable;

public:
    template <typename T>
    void insert(const std::string& name, T value) {
        if (symbolTable.find(name) != symbolTable.end()) {
            throw std::runtime_error("Symbol already exists");
        }
        symbolTable[name] = value;
    }

    std::variant<int, double, std::string> lookup(const std::string& name) {
        if (symbolTable.find(name) == symbolTable.end()) {
            throw std::runtime_error("Symbol does not exist");
        }
        return symbolTable[name];
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Environment env;

    env.insert("x", 10);
    env.insert("y", 20.5);
    env.insert("z", "Hola");

    std::cout << "x es " << std::get<int>(env.lookup("x")) << std::endl;
    std::cout << "y es " << std::get<double>(env.lookup("y")) << std::endl;
    std::cout << "z es " << std::get<std::string>(env.lookup("z")) << std::endl;

    
    try {
        std::cout << "w es " << std::get<int>(env.lookup("w")) << std::endl;  // Debería lanzar una excepción
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;  // Debería imprimir "Symbol does not exist"
    }

    return 0;
}

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    void insert(const std::string& name, int value) {
        if (symbolTable.find(name) != symbolTable.end()) {
            throw std::runtime_error("No existe el simbolo");
        }
        symbolTable[name] = value;
    }

    int lookup(const std::string& name) {
    if (symbolTable.find(name) == symbolTable.end()) {
        throw std::runtime_error("No existe el simbolo");
    }
    return symbolTable[name];
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Environment env;

    env.insert("x", 10);
    env.insert("y", 20);

    cout << "x es " << env.lookup("x") << endl;
    cout << "y es " << env.lookup("y") << endl;
    
    try {
        cout << "z es " << env.lookup("z") << endl;  // Debería lanzar una excepción
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;  // Debería imprimir "No existe el simbolo"
    }

    return 0;
}

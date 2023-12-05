#include <iostream>
#include <map>
#include <string>

using namespace std;

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    void insert(std::string symbol, int value) {
        symbolTable.insert(std::pair<std::string, int>(symbol, value));
    }

    int getSymbol(const std::string& name) {
        return symbolTable[name];
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Environment env;

    env.insert("x", 10);
    env.insert("y", 20);

    cout << "x es " << env.getSymbol("x") << endl;
    cout << "y es " << env.getSymbol("y") << endl;

    return 0;
}

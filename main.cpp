#include <iostream>
#include <map>
#include <string>

using namespace std;

class Environment {
private:
    std::map<std::string, int> symbolTable;

public:
    Environment() {}

    void set(std::string var, int val) {
        symbolTable[var] = val;
    }

    int get(std::string var) {
        return symbolTable[var];
    }
};


int main()
{
    cout << "Hello World!" << endl;

    Environment env;

    env.set("x", 1);
    env.set("y", 2);

    cout << env.get("x") << endl;
    cout << env.get("y") << endl;

    return 0;
}

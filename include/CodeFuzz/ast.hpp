#pragma once

#include <list>
#include <vector>
#include <set>
#include <string>


#include "bytestream.hpp"

namespace CodeFuzz {

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual std::string gen(ByteStream&& bytes) const = 0;
};

struct Variable {
    std::string name;
    std::string type;
};

struct Constant {
    std::string value;
    std::string type;
};

struct Function {
    std::string name;
    std::vector<std::string> param_types;
    std::string return_type;
};

struct Scope {
    std::set<Variable> variables;
    std::set<Function> functions;
};

class Context {
public:
    Context() = default;
    ~Context() = default;
    void declare(const Variable& variable);
    void declare(const Constant& constant);
    void declare(const Function& function);
    void enter();
    void exit();
    std::set<Variable> get_variables(std::string type);
    std::set<Variable> get_constants(std::string type);
private:
    std::list<Scope> scopes;
    std::set<Variable> constants;
};
}
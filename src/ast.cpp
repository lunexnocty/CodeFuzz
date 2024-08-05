#include "ast.hpp"

namespace CodeFuzz {
void Context::declare(const Variable& variable) {
    this->scopes.front().variables.add(variable);
}

void Context::declare(const Constant& constant) {
    this->scopes.front().constants.add(constant);
}

void Context::declare(const Function& function) {
    this->scopes.front().functions.add(function);
}

void Context::exit() {
    this->scopes.pop_front();
}

void Context::enter() {
    this->scopes.push_front(Scope());
}

auto Context::get_variables(std::string type) {
    auto variables = set<Variable>();
    for(auto scope : this->scopes) {
        for(auto variable : scope.variables) {
            if (variable.type == type) {
                variables.insert(variable);
            }
        }
    }
    return variables;
}

auto Context::get_constants(std::string type) {
    auto constants = set<Constant>();
    std::copy_if(
        this->constants.begin(), this->constants.end(),
        std::inserter(constants, constants.end()),
        [&](const Constant& constant) { return constant.type == type; }
    );
    return constants;
}

}
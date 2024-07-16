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
}
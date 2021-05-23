#include<iostream>
#include "state.h"

Context::Context(State *st)
{
    state = st;
}
void Context::set_state(State *st)
{
    state = st;
}
State *Context::get_state()
{
    return state;
}

void Context::request()
{
    state->handle(this);
}


void ConcreteStateA::handle(Context *context)
{
    context->set_state(new ConcreteStateB());
    std::cout<<"state change to ConcreteStateB"<<std::endl;
}


void ConcreteStateB::handle(Context *context)
{
    context->set_state(new ConcreteStateA());
    std::cout<<"state change to ConcreteStateA"<<std::endl;
}

//test
int main(int argc, char const *argv[])
{
    Context *context = new Context(new ConcreteStateA());
    context->request();
    context->request();
    context->request();
    context->request();
    return 0;
}



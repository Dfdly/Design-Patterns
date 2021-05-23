#include<iostream>

class Implementor
{
public:
    virtual void operation_action() = 0;
};

class ConcreteImplementorA:public Implementor
{
public:
    void operation_action();
};
void ConcreteImplementorA::operation_action()
{
    std::cout<<"method of ConcreteImplementorA"<<std::endl;
}

class ConcreteImplementorB:public Implementor
{
public:
    void operation_action();
};
void ConcreteImplementorB::operation_action()
{
    std::cout<<"method of ConcreteImplementorB"<<std::endl;
}

class Abstraction
{
protected:
    Implementor *m_impl;
public:
    void set_implementor(Implementor *impl);
    virtual void operation_action();

};

void Abstraction::operation_action()
{
    m_impl->operation_action();
}
void Abstraction::set_implementor(Implementor *impl)
{
    m_impl = impl;
}

class RedefinedAbstraction:public Abstraction
{
public:
    void operation_action();
};

void RedefinedAbstraction::operation_action()
{
    m_impl->operation_action();
}

//test
int main(int argc, char const *argv[])
{
    Abstraction *abs = new RedefinedAbstraction();
    abs->set_implementor(new ConcreteImplementorA());
    abs->operation_action();

    abs->set_implementor(new ConcreteImplementorB());
    abs->operation_action();
    return 0;
}

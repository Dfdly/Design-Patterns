#include<iostream>

//interface needed
class Target
{
public:
    virtual void request();
};

void Target::request()
{
    std::cout<<"normal request"<<std::endl;
}

//real interface
class Adaptee
{
public:
    virtual void special_request();
};

void Adaptee::special_request()
{
    std::cout<<"special request"<<std::endl;
}

//adapter:transform real interface to real interface
class Adapter:public Target
{
private:
    Adaptee *adaptee;
public:
    void request();
    Adapter();
    ~Adapter();
};
Adapter::Adapter()
{
    adaptee = new Adaptee();
}

Adapter::~Adapter()
{
    delete(adaptee);
}

void Adapter::request()
{
    adaptee->special_request();
}

//test
int main(int argc, char const *argv[])
{
    Target *target = new Adapter();
    target->request();
    return 0;
}


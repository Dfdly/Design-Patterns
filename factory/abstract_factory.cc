#include<iostream>

//design of products
class AbstractPhone
{
public:
    virtual void norm_function()=0;
};

class AbstractRouter
{
public:
    virtual void norm_routing()=0;
};

class MiPhone:public AbstractPhone
{
    void norm_function();
};

void MiPhone::norm_function()
{
    std::cout<<"mi phone"<<std::endl;
}

class HuaweiPhone:public AbstractPhone
{
    void norm_function();
};

void HuaweiPhone::norm_function()
{
    std::cout<<"huawei phone"<<std::endl;
}

class MiRouter:public AbstractRouter
{
    void norm_routing();
};

void MiRouter::norm_routing()
{
    std::cout<<"mi router"<<std::endl;
}

class HuaweiRouter:public AbstractRouter
{
    void norm_routing();
};

void HuaweiRouter::norm_routing()
{
    std::cout<<"huawei router"<<std::endl;
}


//design of factory
class AbstractFactory
{
public:
    virtual AbstractPhone * get_phone()= 0;
    virtual AbstractRouter * get_router()= 0;
};

class MiFactory:public AbstractFactory
{
public:
    AbstractPhone * get_phone();
    AbstractRouter * get_router();
};

AbstractPhone *MiFactory::get_phone()
{
    return new MiPhone();
}

AbstractRouter *MiFactory::get_router()
{
    return new MiRouter();
}

class HuaweiFactory:public AbstractFactory
{
public:
    AbstractPhone * get_phone();
    AbstractRouter * get_router();
};

AbstractPhone *HuaweiFactory::get_phone()
{
    return new HuaweiPhone();
}
AbstractRouter *HuaweiFactory::get_router()
{
    return new HuaweiRouter();
}

//test
int main(int argc, char const *argv[])
{
    AbstractFactory *factory = new MiFactory();
    AbstractPhone *phone =  factory->get_phone();
    AbstractRouter *router = factory->get_router();
    phone->norm_function();
    router->norm_routing();

    return 0;
}

#include<iostream>
#include<map>
#include<string>
using namespace std;

class FlyWeight
{
public:
    virtual void do_operation(int extrinsicstate)=0;
};

class ConcreteFlyWeight:public FlyWeight
{
public:
    void do_operation(int extrinsicstate);
};

void ConcreteFlyWeight::do_operation(int extrinsicstate)
{
    std::cout<<"concrete flyweight "<<extrinsicstate<<std::endl;
}

class UnsharedConcreteFlyWeight:public FlyWeight
{
public:
    void do_operation(int extrinsicstate);
};

void UnsharedConcreteFlyWeight::do_operation(int extrinsicstate)
{
    std::cout<<"unshared concrete flyweight "<<extrinsicstate<<std::endl;
}

class FlyweightFactory
{
private:
    map<string,FlyWeight*> flyweights;
public:
    FlyweightFactory();
    FlyWeight* get_flyweight(string key);
};

FlyweightFactory::FlyweightFactory()
{
    flyweights.insert(make_pair("X",new ConcreteFlyWeight()));
    flyweights.insert(make_pair("Y",new ConcreteFlyWeight()));
    flyweights.insert(make_pair("Z",new ConcreteFlyWeight()));
}

FlyWeight *FlyweightFactory::get_flyweight(std::__cxx11::string key)
{
    return flyweights[key];
}

//test
int main(int argc, char const *argv[])
{
    int extrinsicstate = 22;
    FlyweightFactory *factory = new FlyweightFactory();

    FlyWeight *fx = factory->get_flyweight("X");
    fx->do_operation(--extrinsicstate);

    FlyWeight *fy = factory->get_flyweight("Y");
    fy->do_operation(--extrinsicstate);

    FlyWeight *fz = factory->get_flyweight("Z");
    fz->do_operation(--extrinsicstate);

    UnsharedConcreteFlyWeight *uf = new UnsharedConcreteFlyWeight();
    uf->do_operation(--extrinsicstate);
    return 0;
}

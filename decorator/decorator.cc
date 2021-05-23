#include<iostream>

//base class Person(concreteConponent)
class Person
{
private:
    /* data */
    const char * m_name;
public:
    Person(const char* name);
    Person();
    virtual void show();
    ~Person();
};

Person::Person(const char* name)
{
    m_name = name;
}

void Person::show()
{
    std::cout<<"decorate "<<m_name<<std::endl;
}
Person::Person()
{}
Person::~Person()
{
}

//base Decorator
class Finery:public Person
{
protected:
    Person *m_component;
private:
    /* data */
public:
    void decorate(Person *component);
    ~Finery();
    void show();
};


Finery::~Finery()
{
}

void Finery::decorate(Person *component)
{
    m_component = component;
}

void Finery::show()
{
    if(m_component != NULL)
    {
        m_component->show();
    }
}

//ConcreteDecorator
class TShirt:public Finery
{
private:
    /* data */
public:
    void show();
};

void TShirt::show()
{
    std::cout<<"TShirt\t";
    Finery::show();
}

class Pants:public Finery
{
private:
    /* data */
public:
    void show();
};

void Pants::show()
{
    std::cout<<"Pants\t";
    Finery::show();
}




//test
int main(int argc, char const *argv[])
{
    Person *p = new Person("dfd");
    TShirt *ts = new TShirt();
    Pants *pts = new Pants();
    ts->decorate(p);
    pts->decorate(ts);

    pts->show();
    return 0;
}

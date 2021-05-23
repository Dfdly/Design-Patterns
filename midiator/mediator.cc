#include<iostream>
#include<string>
#include "mediator.h"


void ConcreteMediator::set_colleague1(Colleague *c1)
{
    colleague1 = c1;
}
void ConcreteMediator::set_colleague2(Colleague *c2)
{
    colleague2 = c2;
}

void ConcreteMediator::send(std::string message, Colleague *clg)
{
    if(clg == colleague1)
    {
        colleague2->notify(message);
    }
    else if(clg == colleague2)
    {
        colleague1->notify(message);
    }
}


Colleague::Colleague(Mediator *mda)
{
    m_meidator = mda;
}


ConcreteColleague1::ConcreteColleague1(Mediator *mda):Colleague(mda)
{
}

void ConcreteColleague1::send(std::string message)
{
    m_meidator->send(message,this);
}

void ConcreteColleague1::notify(std::string message)
{
    std::cout<<"college1 received message "<<message<<std::endl;
}


ConcreteColleague2::ConcreteColleague2(Mediator *mda):Colleague(mda)
{
}

void ConcreteColleague2::send(std::string message)
{
    m_meidator->send(message,this);
}

void ConcreteColleague2::notify(std::string message)
{
    std::cout<<"college2 received message "<<message<<std::endl;
}

//test
int main(int argc, char const *argv[])
{
    ConcreteMediator *mda = new ConcreteMediator();
    ConcreteColleague1 *c1 = new ConcreteColleague1(mda);
    ConcreteColleague2 *c2 = new ConcreteColleague2(mda);
    mda->set_colleague1(c1);
    mda->set_colleague2(c2);
    c1->send("hello");
    return 0;
}

#include<string>

class Colleague;
class Mediator
{
public:
    virtual void send(std::string message,Colleague *clg)=0;
};

class ConcreteMediator:public Mediator
{
private:
    Colleague *colleague1;
    Colleague *colleague2;
public:
    void send(std::string message,Colleague *clg);
    void set_colleague1(Colleague *c1);
    void set_colleague2(Colleague *c2);
};


class Colleague
{
protected:
    Mediator *m_meidator;
public:
    Colleague(Mediator *mda);
    virtual void notify(std::string message)=0;
};

class ConcreteColleague1:public Colleague
{
public:
    ConcreteColleague1(Mediator *mda);
    void send(std::string message);
    void notify(std::string message);
};

class ConcreteColleague2:public Colleague
{
public:
    ConcreteColleague2(Mediator *mda);
    void send(std::string message);
    void notify(std::string message);
};
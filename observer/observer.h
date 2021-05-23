#include<list>
#include<string>
using namespace std;

class Observer;
//class Notifier(abstract notifier)
class Notifier
{
public:
    virtual void attach(Observer *ob)=0;
    virtual void detach(Observer *ob)=0;
    virtual void notify()=0;
};

//ConcreteNotifier
class ConcreteNotifier:public Notifier
{
private:
    list<Observer*> observers;
    string notifier_state;
public:
    void attach(Observer *ob);
    void detach(Observer *ob);
    void notify();
    void set_state(string state);
    string get_state();
};

//class Observer(abstract Observer)
class Observer
{
public:
    virtual void update(string state)=0;
};


//class ConcreteObserver
class ConcreteObserver:public Observer
{
private:
    string m_name;
    string m_observe_state;
public:
    void update(string state);
    ConcreteObserver();
    ConcreteObserver(string name);
};


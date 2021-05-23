#include<iostream>
#include<vector>
#include<list>
#include"observer.h"
using namespace std;

void ConcreteNotifier::set_state(string state)
{
    notifier_state = state;
}

string ConcreteNotifier::get_state()
{
    return notifier_state;
}

void ConcreteNotifier::attach(Observer *ob)
{
    observers.push_back(ob);
}

void ConcreteNotifier::detach(Observer *ob)
{
    for(list<Observer*>::iterator it = observers.begin();it!=observers.end();it++)
    {
        if(*it = ob)
        {
            observers.remove(ob);
            break;
        }
    }
}

void ConcreteNotifier::notify()
{
    for(list<Observer*>::iterator it = observers.begin();it!=observers.end();it++)
    {
        (*it)->update(notifier_state);
    }
}


ConcreteObserver::ConcreteObserver()
{
}

ConcreteObserver::ConcreteObserver(string name)
{
    m_name = name;
}
void ConcreteObserver::update(string state)
{
    m_observe_state = state;
    cout<<"new state of onserver "<<m_name<<" is "<<m_observe_state<<endl;
}



int main(int argc, char const *argv[])
{
    ConcreteNotifier *ntf = new ConcreteNotifier();

    Observer *ob = new ConcreteObserver("observer1");
    ntf->set_state("test");
    ntf->attach(ob);
    ntf->attach(new ConcreteObserver("observer2"));
    
    ntf->notify();
    
    return 0;
}

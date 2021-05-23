#include<iostream>
#include<string>
using namespace std;
class Memento
{
private:
    string state;
public:
    Memento(string st);
    string get_state();
};
Memento::Memento(string st)
{
    state = st;
}
string Memento::get_state()
{
    return state;
}

class Orignator
{
private:
    string state; 
public:
    string get_state();
    void set_state(string st);
    Memento * create_memento();
    void set_memento(Memento *me);
    void show();
};

string Orignator::get_state()
{
    return state;
}
void Orignator::set_state(string st)
{
    state = st;
}
Memento *Orignator::create_memento()
{
    return new Memento(state);
}
void Orignator::set_memento(Memento *me)
{
    state = me->get_state();
}
void Orignator::show()
{
    cout<<"state= "<<state<<endl;
}

class Caretaker
{
private:
    Memento *memento;
public:
    Memento * get_memento();
    void set_memento(Memento* me);
};

Memento *Caretaker::get_memento()
{
    return memento;
}
void Caretaker::set_memento(Memento *me)
{
    memento = me;
}

//test
int main(int argc, char const *argv[])
{
    Orignator *orignator = new Orignator();
    orignator->set_state("On");
    orignator->show();

    Caretaker *caretaker = new Caretaker();
    caretaker->set_memento(orignator->create_memento());

    orignator->set_state("OFF");
    orignator->show();

    orignator->set_memento(caretaker->get_memento());
    orignator->show();
    return 0;
}

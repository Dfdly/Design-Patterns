#include<iostream>
#include<vector>
using namespace std;

template <class Item>
class Iterator
{
public:
    virtual Item first()=0;
    virtual Item next()=0;
    virtual bool is_done()=0;
    virtual Item *current_item()=0;
};

template <class Item>
class Aggregate
{
public:
    virtual Iterator<Item>* create_iterator() = 0;
    virtual Item& operator[](int index)=0;
    virtual int get_size()=0;
    virtual void pushData(Item item)=0;
};

template <class Item>
class ConcreteIterator:public Iterator<Item>
{
private:
    Aggregate<Item> *aggregate;
    int current;
public:
    ConcreteIterator(Aggregate<Item> *ag);
    Item first();
    Item next();
    bool is_done();
    Item *current_item();
};

template<class Item> ConcreteIterator<Item>::ConcreteIterator(Aggregate<Item> *ag)
{
    aggregate = ag;
    current = 0;
}

template<class Item> Item ConcreteIterator<Item>::first()
{
    current = 0;
}

template<class Item> Item ConcreteIterator<Item>::next()
{
    if (current < aggregate->get_size())
        current++;
}

template<class Item> bool ConcreteIterator<Item>::is_done()
{
    return current >= aggregate->get_size();
}
template<class Item> Item *ConcreteIterator<Item>::current_item()
{
    if (current < aggregate->get_size())
    {
        return &(*aggregate)[current];
    }
    else
    {
        return NULL;
    }
}



template <class Item>
class ConcreteAggregate:public Aggregate<Item>
{
private:
    vector<Item> items;
    int count;

public:
    Iterator<Item>* create_iterator();
    Item& operator[](int index);
    int get_size();
    void pushData(Item item);
};

template<class Item> Item &ConcreteAggregate<Item>::operator[](int index)
{
    return items[index];
}
template<class Item> int ConcreteAggregate<Item>::get_size()
{
    return items.size();
}

template<class Item> Iterator<Item> *ConcreteAggregate<Item>::create_iterator()
{
    return new ConcreteIterator<Item>(this);
}

template<class Item> void ConcreteAggregate<Item>::pushData(Item item)
{
    items.push_back(item);
}

int main(int argc, char const *argv[])
{
    Aggregate<int> *ag = new ConcreteAggregate<int>();
    ag->pushData(2);
    ag->pushData(3);
    ag->pushData(5);
    Iterator<int> *it = ag->create_iterator();
    for(it->first();!(it->is_done());it->next())
    {
        cout<<*(it->current_item())<<endl;
    }
    delete(it);
    delete(ag);
    return 0;
}

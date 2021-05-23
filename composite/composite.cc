#include<iostream>
#include<string>
#include<list>
using namespace std;

//Common interface of all components
class Component
{
protected:
    string m_name;
public:
    Component(string name);
    virtual void add(Component *c)=0;
    virtual void remove(Component *c)=0;
    virtual void display(int depth)=0;
};
Component::Component(string name)
{
    m_name = name;
}

//leaf node
class Leaf:public Component
{
public:
    Leaf(string name);
    void add(Component *c);
    void remove(Component *c);
    void display(int depth);
};

Leaf::Leaf(string name):Component(name)
{}

void Leaf::add(Component *c)
{
    cout<<"can't add to a leaf!"<<endl;
}

void Leaf::remove(Component *c)
{
    cout<<"can't remove from a leaf!"<<endl;
}

void Leaf::display(int depth)
{
    string s(depth,'-');
    cout<<s<<m_name<<endl;
}

//composite node
class Composite:public Component
{
private:
    list<Component*> children;
public:
    Composite(string name);
    void add(Component *c);
    void remove(Component *c);
    void display(int depth);
};

Composite::Composite(string name):Component(name)
{

}

void Composite::add(Component *c)
{
    children.push_back(c);
}

void Composite::remove(Component *c)
{
    // children.remove(c);
    for(list<Component*>::iterator it = children.begin();it!=children.end();it++)
    {
        if(*it = c)
        {
            children.remove(c);
            // cout<<"find c"<<endl;
            break;
        }
    }
}

void Composite::display(int depth)
{
    string s(depth,'-');
    cout<<s<<m_name<<endl;
    for(list<Component*>::iterator it = children.begin();it!=children.end();it++)
    {
        (*it)->display(depth+2);
    }
}

//test
int main(int argc, char const *argv[])
{
    Component *root = new Composite("root");
    root->add(new Leaf("LeafA"));
    root->add(new Leaf("LeafB"));
    
    Component *compX = new Composite("Composite X");
    compX->add(new Leaf("LeafXA"));
    compX->add(new Leaf("LeafXB"));

    Component *compY = new Composite("Composite Y");
    compY->add(new Leaf("LeafYA"));
    compY->add(new Leaf("LeafYB"));

    root->add(compX);
    root->add(compY);
    root->display(1);
    cout<<endl;
    root->remove(compY);
    root->display(1);
    return 0;
}

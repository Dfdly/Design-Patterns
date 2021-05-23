#include<iostream>
#include<list>
#include"visitor.h"
class Element;



void ConcreteVisitor1::visit_concrete_elementA(ConcreteElementA *element)
{
    std::cout<<"ConcreteElementA is visited by ConcreteVisitor1";
}

void ConcreteVisitor1::visit_concrete_elementB(ConcreteElementB *element)
{
    std::cout<<"ConcreteElementB is visited by ConcreteVisitor1";
}


void ConcreteVisitor2::visit_concrete_elementA(ConcreteElementA *element)
{
    std::cout<<"ConcreteElementA is visited by ConcreteVisitor2";
}

void ConcreteVisitor2::visit_concrete_elementB(ConcreteElementB *element)
{
    std::cout<<"ConcreteElementB is visited by ConcreteVisitor2";
}


void ConcreteElementA::accept(Visitor *visitor)
{
    visitor->visit_concrete_elementA(this);
}


void ConcreteElementB::accept(Visitor *visitor)
{
    visitor->visit_concrete_elementB(this);
}

void ObjectStructure::attach(Element *ele)
{
    elements.push_back(ele);
}
void ObjectStructure::detach(Element *ele)
{
    for(std::list<Element*>::iterator it = elements.begin();it!= elements.end();it++)
    {
        if(*it == ele)
        {
            elements.remove(ele);
            break;
        }
    }
}

void ObjectStructure::accept(Visitor *vst)
{
    for(std::list<Element*>::iterator it = elements.begin();it!= elements.end();it++)
    {
        (*it)->accept(vst);
    }
}

int main(int argc, char const *argv[])
{
    ObjectStructure *ob = new ObjectStructure();
    ob->attach(new ConcreteElementA());
    ob->attach(new ConcreteElementB());
    ConcreteVisitor1 *v1 = new ConcreteVisitor1();
    ob->accept(v1);
    return 0;
}


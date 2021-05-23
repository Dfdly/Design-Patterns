#include<list>

class Visitor;
class Element
{
public:
    virtual void accept(Visitor* visitor)=0;
};

class ConcreteElementA:public Element
{
public:
    void accept(Visitor* visitor);
    void other_operation(){};
};


class ConcreteElementB:public Element
{
public:
    void accept(Visitor* visitor);
    void other_operation(){};
};

class Visitor
{
public:
    virtual void visit_concrete_elementA(ConcreteElementA* element)=0;
    virtual void visit_concrete_elementB(ConcreteElementB* element)=0;
};

class ConcreteVisitor1:public Visitor
{
public:
    void visit_concrete_elementA(ConcreteElementA* element);
    void visit_concrete_elementB(ConcreteElementB* element);
};

class ConcreteVisitor2:public Visitor
{
public:
    void visit_concrete_elementA(ConcreteElementA* element);
    void visit_concrete_elementB(ConcreteElementB* element);
};





class ObjectStructure
{
private:
    std::list<Element*> elements;
public:
    void attach(Element* ele);
    void detach(Element* ele);
    void accept(Visitor* vst);
};
#include "design_patterns.h"
#include<iostream>

//base class
class Operation
{
private:
    /* data */
    double num_a;
    double num_b;
public:
    double get_num_a();
    double set_num_a(double value);
    double get_num_b();
    double set_num_b(double value);
    virtual double get_result()=0;
};

double Operation::get_num_a()
{
    return num_a;
}

double Operation::set_num_a(double value)
{
    num_a = value;
}

double Operation::get_num_b()
{
    return num_b;
}

double Operation::set_num_b(double value)
{
    num_b = value;
}

//sub class(OperationAdd/OperationSub/OperationMulti/OperationDevide)

class OperationAdd:public Operation
{
private:
    /* data */
public:
    double get_result();
};

double OperationAdd::get_result()
{
    double result = get_num_a() + get_num_b();
    return result;
}

class OperationSub:public Operation
{
private:
    /* data */
public:
    double get_result();
};

double OperationSub::get_result()
{
    double result = get_num_a() - get_num_b();
    return result;
}

class OperationMulti:public Operation
{
private:
    /* data */
public:
    double get_result();
};

double OperationMulti::get_result()
{
    double result = get_num_a() * get_num_b();
    return result;
}

class OperationDevide:public Operation
{
private:
    /* data */
public:
    double get_result();
};

double OperationDevide::get_result()
{
    double result = get_num_a() / get_num_b();
    return result;
}





//factory class
class OperationFactory
{
private:
    /* data */
public:
    Operation* creation_operation(const char *op);
};

Operation* OperationFactory::creation_operation(const char *op)
{
    Operation * operation;
    if(op == "+")
    {
        operation = new OperationAdd();
    }
    else if(op == "-")
    {
        operation = new OperationSub();
    }
    else if(op == "*")
    {
        operation = new OperationMulti();
    }
    else if(op == "/")
    {
        operation = new OperationDevide();
    }
    return operation;
}

//test
int main(int argc, char const *argv[])
{
    OperationFactory opf;
    Operation *opr = opf.creation_operation("/");
    opr->set_num_a(12);
    opr->set_num_b(15);
    std::cout<<opr->get_result()<<std::endl;
    return 0;
}


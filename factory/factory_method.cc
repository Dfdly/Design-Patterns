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

//factory interface
class IFactory
{
private:
    /* data */
public:
    virtual Operation *create_operation()=0;
};

//concrete math factory
class AddFactory:public IFactory
{
public:
    Operation *create_operation();
};
Operation *AddFactory::create_operation()
{
    return new OperationAdd();
}

class SubFactory:public IFactory
{
public:
    Operation *create_operation();
};
Operation *SubFactory::create_operation()
{
    return new OperationSub();
}

class MultiFactory:public IFactory
{
public:
    Operation *create_operation();
};
Operation *MultiFactory::create_operation()
{
    return new OperationMulti();
}

class DevideFactory:public IFactory
{
public:
    Operation *create_operation();
};
Operation *DevideFactory::create_operation()
{
    return new OperationDevide();
}

//test
int main(int argc, char const *argv[])
{
    IFactory *ift = new AddFactory();
    Operation *opr = ift->create_operation();
    opr->set_num_a(12);
    opr->set_num_b(13);
    std::cout<<opr->get_result();
    return 0;
}

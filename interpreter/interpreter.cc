#include<iostream>
#include<string>
class Context
{
private:
    std::string m_input;
    std::string m_output;
public:
    std::string get_input();
    void set_input(std::string input);
    std::string get_output();
    void set_output(std::string output);
};

std::string Context::get_input()
{
    return m_input;
}

void Context::set_input(std::string input)
{
    m_input = input;
}

std::string Context::get_output()
{
    return m_output;
}

void Context::set_output(std::string output)
{
    m_output = output;
}

class AbstractExpression
{
public:
    virtual void interpret(Context *context)=0;
};

class TerminalExpression:public AbstractExpression
{
public:
    void interpret(Context *context);
};

void TerminalExpression::interpret(Context *context)
{
    std::cout<<"terminal expression!"<<std::endl;
}

class NonTerminalExpression:public AbstractExpression
{
public:
    void interpret(Context *context);
};

void NonTerminalExpression::interpret(Context *context)
{
    std::cout<<"non terminal expression!"<<std::endl;
}

int main(int argc, char const *argv[])
{
    Context *context = new Context();
    AbstractExpression *ae = new TerminalExpression();
    ae->interpret(context);

    return 0;
}



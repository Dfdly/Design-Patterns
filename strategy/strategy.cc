#include<iostream>
#include<cmath>

//base class
class CashSuper
{
private:
    /* data */
public:
    virtual double accept_cash(double money)=0;
};

//Normal charge
class CashNormal:public CashSuper
{
private:
    /* data */
public:
    double accept_cash(double money);
};

double CashNormal::accept_cash(double money)
{
    return money;
}

//20% discount
class CashRebate:public CashSuper
{
private:
    /* data */
public:

    double accept_cash(double money);
};
double CashRebate::accept_cash(double money)
{
    return money*0.8;
}

//Over 300 minus 100
class CashReturn:public CashSuper
{
private:
    /* data */
public:
    double accept_cash(double money);
};

double CashReturn::accept_cash(double money)
{
    double result = money;
    if(money >= 300)
    {
        result = money - floor(money/300)*100;
    }
    return result;
}

//context class
class CashContext
{
private:
    CashSuper *cs = NULL;
public:
    CashContext(const char* type);
    double get_result(double money);
    ~CashContext();
};

CashContext::CashContext(const char *type)
{  
    int n_type = -1;
    if(type == "normal")
    {
        n_type = 0;
    }else if(type == "discount")
    {
        n_type = 1;
    }else if(type == "return")
    {
        n_type = 2;
    }
    switch (n_type)
    {
    case 0:
        cs = new CashNormal();
        break;
    case 1:
        cs = new CashRebate();
        break;
    case 2:
        cs = new CashReturn();
        break;

    default:
        break;
    }
}

CashContext::~CashContext()
{
    if (cs!=NULL)
    {
        delete(cs);
    }
    
}

double CashContext::get_result(double money)
{
    return cs->accept_cash(money);
}

//test
int main(int argc, char const *argv[])
{
    CashContext *cc = new CashContext("normal");
    std::cout<<cc->get_result(10);
    delete(cc);

    return 0;
}




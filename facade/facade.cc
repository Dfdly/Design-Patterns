#include<iostream>

//class Stock1/Stock2/Stock3 (different sub system)
class Stock1
{
public:
    void buy();
    void sell();
};

void Stock1::buy()
{
    std::cout<<"buy stock1"<<std::endl;
}
void Stock1::sell()
{
    std::cout<<"sell stock1"<<std::endl;
}

class Stock2
{
public:
    void buy();
    void sell();
};

void Stock2::buy()
{
    std::cout<<"buy stock2"<<std::endl;
}
void Stock2::sell()
{
    std::cout<<"sell stock2"<<std::endl;
}

class Stock3
{
public:
    void buy();
    void sell();
};

void Stock3::buy()
{
    std::cout<<"buy stock3"<<std::endl;
}
void Stock3::sell()
{
    std::cout<<"sell stock3"<<std::endl;
}

class Fund
{
private:
    Stock1 *stk1;
    Stock2 *stk2;
    Stock3 *stk3;

public:
    Fund();
    ~Fund();
    void buy_fund();
    void sell_fund();

};
Fund::Fund()
{
    stk1 = new Stock1();
    stk2 = new Stock2();
    stk3 = new Stock3();
}

Fund::~Fund()
{
    delete(stk1);
    delete(stk2);
    delete(stk3);
}

void Fund::buy_fund()
{
    stk1->buy();
    stk2->buy();
    stk3->buy();
}
void Fund::sell_fund()
{
    stk1->sell();
    stk2->sell();
    stk3->sell();
}

//test
int main(int argc, char const *argv[])
{
    Fund *myFund = new Fund();
    myFund->buy_fund();
    myFund->sell_fund();
    delete(myFund);
    return 0;
}

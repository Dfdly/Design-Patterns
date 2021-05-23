#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class Product,consist of different products
class Product
{
private:
    vector<string> parts;
public:
    void add_part(string part);
    void show();
};

void Product::add_part(string part)
{
    parts.push_back(part);
}

void Product::show()
{
    cout<<"product build--"<<endl;
    for(vector<string>::iterator it = parts.begin();it<parts.end();it++)
    {
        cout<<*it<<endl;
    }
}

//abstract class Builder
class Builder
{
public:
    virtual void build_part_a()=0;
    virtual void build_part_b()=0;
    virtual Product * get_result()=0;
};

//concrete Builder(implement of interface of builder)
class ContreteBuilderA:public Builder
{
private:
    Product *product;
public:
    void build_part_a();
    void build_part_b();
    Product * get_result();
    ContreteBuilderA();
    ~ContreteBuilderA();
};
ContreteBuilderA::ContreteBuilderA()
{
    product = new Product();
}
ContreteBuilderA::~ContreteBuilderA()
{
    delete(product);
}
void ContreteBuilderA::build_part_a()
{
    product->add_part("partA");
}
void ContreteBuilderA::build_part_b()
{
    product->add_part("partB");
}

Product *ContreteBuilderA::get_result()
{
    return product;
}

class ContreteBuilderB:public Builder
{
private:
    Product *product;
public:
    ContreteBuilderB();
    ~ContreteBuilderB();
    void build_part_a();
    void build_part_b();
    Product * get_result();
};
ContreteBuilderB::ContreteBuilderB()
{
    product = new Product();
}
ContreteBuilderB::~ContreteBuilderB()
{
    delete(product);
}
void ContreteBuilderB::build_part_a()
{
    product->add_part("partX");
}
void ContreteBuilderB::build_part_b()
{
    product->add_part("partY");
}

Product *ContreteBuilderB::get_result()
{
    return product;
}

//class Dirctor
class Director
{
public:
    void contruct(Builder *builder);
};

void Director::contruct(Builder *builder)
{
    builder->build_part_a();
    builder->build_part_b();
}

//test
int main(int argc, char const *argv[])
{
    Director *director = new Director();
    Builder *p1 = new ContreteBuilderA();
    director->contruct(p1);
    Product *product_1 = p1->get_result();
    product_1->show();

    return 0;
}


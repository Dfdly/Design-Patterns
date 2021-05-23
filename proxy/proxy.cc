#include<iostream>
#include<cstring>

//base class
class GiveGift
{
public:
    virtual void give_dolls()=0;
    virtual void give_flowers()=0;
    virtual void give_chocolates()=0;
};

class SchoolGirl
{
private:
    char * girl_name;
public:
    SchoolGirl(/* args */);
    SchoolGirl(const char * name);
    char * get_name();
    ~SchoolGirl();
};

SchoolGirl::SchoolGirl(/* args */)
{
}

SchoolGirl::~SchoolGirl()
{
}

SchoolGirl::SchoolGirl(const char *name)
{
    girl_name = new char[sizeof(name)];
    memcpy(girl_name,name,sizeof(name));
}
char *SchoolGirl::get_name()
{
    return girl_name;
}

//class Persuit
class Persuit:public GiveGift
{
private:
    SchoolGirl *mm_persuit;
public:
    void give_dolls();
    void give_flowers();
    void give_chocolates();
    Persuit(SchoolGirl *mm);
};

void Persuit::give_dolls()
{
    std::cout<<mm_persuit->get_name()<<" give you dolls"<<std::endl;
}

void Persuit::give_flowers()
{
    std::cout<<mm_persuit->get_name()<<" give you dolls"<<std::endl;
}

void Persuit::give_chocolates()
{
    std::cout<<mm_persuit->get_name()<<" give you dolls"<<std::endl;
}

Persuit::Persuit(SchoolGirl *mm)
{
    mm_persuit = mm;
}


//class proxy
class proxy:public GiveGift
{
private:
    Persuit *gg;
public:
    proxy(SchoolGirl *mm);
    void give_dolls();
    void give_flowers();
    void give_chocolates();

};
proxy::proxy(SchoolGirl *mm)
{
    gg = new Persuit(mm);
}

void proxy::give_dolls()
{
    gg->give_dolls();
}

void proxy::give_flowers()
{
    gg->give_flowers();
}
void proxy::give_chocolates()
{
    gg->give_chocolates();
}

//test
int main(int argc, char const *argv[])
{
    SchoolGirl *sg = new SchoolGirl("lili");
    proxy *daili = new proxy(sg);
    daili->give_dolls();
    daili->give_chocolates();
    delete(sg);
    delete(daili);
    return 0;
}

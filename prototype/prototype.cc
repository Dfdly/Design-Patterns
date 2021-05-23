#include<iostream>
#include<string>
using namespace std;

//class Resume(prototype)
class Resume
{
protected:
    string m_name;
    string m_sex;
    int m_age;
    string m_timearea;
    string m_company;
    
public:
    Resume(const Resume &re);
    virtual Resume * clone()=0;
    Resume();
    Resume(string name);
    void set_personal_info(string sex,int age);
    void set_work_info(string timearea,string company);
    void display();
};

Resume::Resume(const Resume &re)
{
    cout<<"Resume copy"<<endl;
}

Resume::Resume()
{

}
Resume::Resume(string name)
{
    m_name = name;
}

void Resume::set_personal_info(string sex,int age)
{
    m_sex = sex;
    m_age = age;
}

void Resume::set_work_info(string timearea,string company)
{
    m_timearea = timearea;
    m_company = company;
}

void Resume::display()
{
    cout<<m_name<<" "<<m_sex<<" "<<m_age<<" "<<endl;
    cout<<"work experience: "<<m_timearea<<" "<<m_company<<endl;
}

class ResumeA:public Resume
{
private:
    

public:
    ResumeA();
    ResumeA(const ResumeA& rsm);
    ResumeA(string name);
    Resume * clone();

};

ResumeA::ResumeA(string name):Resume(name)
{

}

ResumeA::ResumeA(const ResumeA &rsm)
{
    cout<<"ResumeA copy"<<endl;
    m_name = rsm.m_name;
    m_sex = rsm.m_sex;
    m_timearea = rsm.m_timearea;
    m_company = rsm.m_company;
    m_age = rsm.m_age;
}

Resume *ResumeA::clone()
{
    return new ResumeA(*this);
}

//test
int main(int argc, char const *argv[])
{
    Resume *re = new ResumeA("dfd");
    re->set_personal_info("male",12);
    re->set_work_info("shenzhen","tencent");
    

    Resume *b1 = (ResumeA*)re->clone();
    Resume *b2 = (ResumeA*)re->clone();
    b1->set_work_info("home","byte");
    b2->set_work_info("school","netease");
    b1->display();

    b2->display();
    return 0;
}

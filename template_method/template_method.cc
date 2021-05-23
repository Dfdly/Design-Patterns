#include<iostream>
#include<string>
using namespace std;

//class testPaper(template)
class TestPaper
{
protected:
    virtual string answer_1();
    virtual string answer_2();
    virtual string answer_3();
public:
    void test_question_1();
    void test_question_2();
    void test_question_3();
};

void TestPaper::test_question_1()
{
    cout<<"1+1=()\na.1 b.2 c.3 d.4"<<endl;
    cout<<"answer:"<<answer_1()<<endl;
}
void TestPaper::test_question_2()
{
    cout<<"2+2=()\na.1 b.2 c.3 d.4"<<endl;
    cout<<"answer:"<<answer_2()<<endl;
}
void TestPaper::test_question_3()
{
    cout<<"3+3=()\na.9 b.8 c.6 d.4"<<endl;
    cout<<"answer:"<<answer_3()<<endl;
}
string TestPaper::answer_1()
{
    return "";
}
string TestPaper::answer_2()
{
    return "";
}
string TestPaper::answer_3()
{
    return "";
}

//test paper copy by student(concrete class)
class TestPapaerA:public TestPaper
{
    string answer_1();
    string answer_2();
    string answer_3();
};

string TestPapaerA::answer_1()
{
    return "b";
}
string TestPapaerA::answer_2()
{
    return "d";
}
string TestPapaerA::answer_3()
{
    return "c";
}

//test
int main(int argc, char const *argv[])
{
    TestPaper *tp = new TestPapaerA();
    tp->test_question_1();
    tp->test_question_2();
    tp->test_question_3();
    return 0;
}

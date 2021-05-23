#include<iostream>

class Handler
{
protected:
    Handler *successor;
public:
    void set_successor(Handler *handler);
    virtual void handle_request(int request)=0;
};

void Handler::set_successor(Handler *handler)
{
    successor = handler;
}

class ConcreteHandler1:public Handler
{
public:
    void handle_request(int request) override;
};

void ConcreteHandler1::handle_request(int request)
{
    if(request>0 && request<=10)
    {
        std::cout<<"ConcreteHandler1 handle request"<<std::endl;
    }
    else if(successor!=NULL)
    {
        std::cout<<"ConcreteHandler1 can't handle request,forwarding..."<<std::endl;
        successor->handle_request(request);
    }
}

class ConcreteHandler2:public Handler
{
public:
    void handle_request(int request) override;
};

void ConcreteHandler2::handle_request(int request)
{
    if(request>10 && request<=20)
    {
        std::cout<<"ConcreteHandler2 handle request"<<std::endl;
    }
    else if(successor!=NULL)
    {
        std::cout<<"ConcreteHandler2 can't handle request,forwarding..."<<std::endl;
        successor->handle_request(request);
    }
}

class ConcreteHandler3:public Handler
{
public:
    void handle_request(int request) override;
};

void ConcreteHandler3::handle_request(int request)
{
    if(request>20 && request<=30)
    {
        std::cout<<"ConcreteHandler3 handle request"<<std::endl;
    }
    else if(successor!=NULL)
    {
        std::cout<<"ConcreteHandler3 can't handle request,forwarding..."<<std::endl;
        successor->handle_request(request);
    }
}

//test
int main(int argc, char const *argv[])
{
    Handler *handler1 = new ConcreteHandler1();
    Handler *handler2 = new ConcreteHandler2();
    Handler *handler3 = new ConcreteHandler3();
    handler1->set_successor(handler2);
    handler2->set_successor(handler3);
    int requests[3] = {2,15,26};
    for(int i = 0;i< 3;i++)
    {
        handler1->handle_request(requests[i]);
        std::cout<<"\n";
    }
    
    return 0;
}




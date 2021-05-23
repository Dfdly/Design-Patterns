#include<iostream>
class Receiver
{
public:
    void action();
};
void Receiver::action()
{
    std::cout<<"carry out requests"<<std::endl;
}


class Command
{
protected:
    Receiver *rcv;
public:
    Command(Receiver *rcver);
    virtual void execute()=0;
};

Command::Command(Receiver *rcver)
{
    rcv = rcver;
}

class ConreteCommand:public Command
{
public:
    ConreteCommand(Receiver *rcver);
    void execute();
};

ConreteCommand::ConreteCommand(Receiver *rcver):Command(rcver)
{}

void ConreteCommand::execute()
{
    rcv->action();
}

//class Invoker(receive request and instruct receiver to do command)
class Invoker
{
private:
    Command *m_command;
public:
    void set_command(Command *cmd);
    void exec_command();
};

void Invoker::set_command(Command *cmd)
{
    m_command = cmd;
}

void Invoker::exec_command()
{
    m_command->execute();
}

int main(int argc, char const *argv[])
{
    Receiver *rcv = new Receiver();
    Command *cmd = new ConreteCommand(rcv);
    Invoker *invoker = new Invoker();
    invoker->set_command(cmd);
    invoker->exec_command();
    return 0;
}




class State;
//Maintain a ConcreteState class instance
class Context
{
private:
    State *state;
public:
    Context(State *st);
    void set_state(State *st);
    State* get_state();
    void request();
};
//class State(interface)
class State
{
public:
    virtual void handle(Context *context)=0;
};

//concrete state class
class ConcreteStateA:public State
{
public:
    void handle(Context *context);
};

class ConcreteStateB:public State
{
public:
    void handle(Context *context);
};
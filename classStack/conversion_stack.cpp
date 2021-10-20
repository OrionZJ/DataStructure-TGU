#include <bits/stdc++.h>
using namespace std;

#define INITSIZE 100
#define INCREMENT 10
typedef int Datatype;

class Stack
{
public:
    Stack();
    void showMenu();
    bool push(Datatype data);
    Datatype pop();

    bool empty();
    bool full();
    bool test(Stack testStack);
    ~Stack();

private:
    Datatype *_base;
    Datatype *_top;
    int _StackSize;
};

Stack::Stack()    //constructor initialize Stack
{
    cout << "initializing...\n";
    _base=new Datatype[INITSIZE];
    if(!_base)
    {
        cerr << "Error! Can't initialize stack.\n";
        exit(1);
    } 
    _top=_base;
    _StackSize=INITSIZE;
}

Stack::~Stack()     //destructor clean Stack
{
    if(empty()) delete []_base;
}

bool Stack::push(Datatype data)
{
    if(full())
    {
        Datatype *newbase=new Datatype[INITSIZE+INCREMENT];
        delete []_base;
        _base=newbase;
        _StackSize+=INCREMENT;
    }
    *_top=data;
    _top++;
    return true;
}

Datatype Stack::pop()
{
    if(empty())
    {
        cerr << "Empty stack already!\n";
        exit(0);
    }
    _top--;
    return *_top;
}

bool Stack::empty()
{
    if(_top==_base) return true;
    else return false;
}

bool Stack::full()
{
    if(_top-_base>_StackSize) return true;
    else return false;
}

void Stack::showMenu()
{
    cout << "1.Push in data to the stack.\n"
         << "2.Pop out data to the stack.\n"
         << "0.Exit.\n"
         << "--------------------------------------------\n"
         << "Please enter your choise:";
}

bool Stack::test(Stack testStack)
{
    int instruction;
    int data;
    testStack.showMenu();
    while (cin >> instruction)
    {
        switch (instruction)
        {
        case 1:
            cout << "Data:";
            cin >> data;
            testStack.push(data);
            break;

        case 2:
            cout << "The data you pop out is " << testStack.pop() << endl; 
            break;

        default:
            exit(0);
            break;
        }
        testStack.showMenu();
    }
    return true;
}

void conversion(Stack &s)
{
    int N;
    int decimalBaseNum;
    int carrySystem;
    cout << "Decimal base number:";
    cin >> decimalBaseNum;
    cout << "Carry system must lower than 10 for now!\n"
         << "Carry system:";
    cin >> carrySystem;
    s.push(decimalBaseNum%carrySystem);
    N = decimalBaseNum/carrySystem;
    while(N)
    {
        s.push(N%carrySystem);
        N /= carrySystem; 
    }
    cout << "The number based on carry system " << carrySystem << " is:";
    while (!s.empty())
    {
        cout << s.pop();
    }
    cout << endl;
}

int main()
{
    Stack s;
    conversion(s);
    system("pause");
    return 0;
}

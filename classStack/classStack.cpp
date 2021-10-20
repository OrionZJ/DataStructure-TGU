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
    bool pop(Datatype &data);
    bool getTop(Stack S,Datatype &data);

    bool empty();
    bool full();
    bool test(Stack testStack);
    ~Stack();

private:
    Datatype *_base;
    Datatype *_top;
    int _StackSize;
};

Stack::Stack()    //构造函数初始化栈
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

Stack::~Stack()     //析构函数清空栈
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

bool Stack::pop(Datatype &data)
{
    if(empty())
    {
        cerr << "Empty stack already!\n";
        return false;
    }
    _top--;
    data=*_top;
    return true;
}

bool Stack::getTop(Stack S,Datatype &data)
{
    if(S.empty()) return false;
    data=*(S._top-1);
    return true;
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
            testStack.pop(data);
            cout << "The data you pop out is " << data << endl; 
            break;

        default:
            exit(0);
            break;
        }
        testStack.showMenu();
    }
    return true;
}

int main()
{
    Stack s;
    s.test(s);
    return 0;
}

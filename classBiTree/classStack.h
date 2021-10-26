using namespace std;
#define INITSIZE 100
#define INCREMENT 10

template <class ElemType>
class Stack
{
public:
    Stack();
    void showMenu();
    bool push(ElemType data);
    bool pop(ElemType &data);
    bool getTop(Stack S,ElemType &data);

    bool empty();
    bool full();
    bool test(Stack testStack);
    ~Stack();

private:
    ElemType *_base;
    ElemType *_top;
    int _StackSize;
};

template <class ElemType>
Stack<ElemType>::Stack()    //构造函数初始化栈
{
    // cout << "initializing...\n";
    _base=new ElemType[INITSIZE];
    if(!_base)
    {
        cerr << "Error! Can't initialize stack.\n";
        exit(1);
    } 
    _top=_base;
    _StackSize=INITSIZE;
}

template <class ElemType>
Stack<ElemType>::~Stack()     //析构函数清空栈
{
    if(empty()) delete []_base;
}

template <class ElemType>
bool Stack<ElemType>::push(ElemType data)
{
    if(full())
    {
        ElemType *newbase=new ElemType[INITSIZE+INCREMENT];
        delete []_base;
        _base=newbase;
        _StackSize+=INCREMENT;
    }
    *_top=data;
    _top++;
    return true;
}

template <class ElemType>
bool Stack<ElemType>::pop(ElemType &data)
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

template <class ElemType>
bool Stack<ElemType>::getTop(Stack S,ElemType &data)
{
    if(S.empty()) return false;
    data=*(S._top-1);
    return true;
}

template <class ElemType>
bool Stack<ElemType>::empty()
{
    if(_top==_base) return true;
    else return false;
}

template <class ElemType>
bool Stack<ElemType>::full()
{
    if(_top-_base>=_StackSize) return true;
    else return false;
}

template <class ElemType>
void Stack<ElemType>::showMenu()
{
    cout << "1.Push in data to the stack.\n"
         << "2.Pop out data to the stack.\n"
         << "0.Exit.\n"
         << "--------------------------------------------\n"
         << "Please enter your choise:";
}

template <class ElemType>
bool Stack<ElemType>::test(Stack testStack)
{
    int instruction;
    ElemType data;
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

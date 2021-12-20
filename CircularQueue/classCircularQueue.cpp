#include <bits/stdc++.h>
#define MAX_SIZE 3  //in order to test border situation 
typedef int Datatype;
using namespace std;

class CircularQueue
{
private:
    Datatype *_base;
    Datatype *_front;
    Datatype *_rear;
    // int currentSize=0;

public:
    CircularQueue();      //Constructor initialize the Circular Queue
    bool Qempty();
    bool Qfull();
    int QLength();
    bool EnQueue(Datatype data);
    bool DeQueue(Datatype &data);
    void showMenu();
    bool test(CircularQueue Q);
    ~CircularQueue();       //Destructor clean the Queue if it's empty
};

CircularQueue::CircularQueue()
{
    cout << "initializing...\n";
    _base=(Datatype *)malloc(MAX_SIZE*sizeof(Datatype));
    if (!_base)
    {
        cerr << "Inicilize Error!";
        exit(-1);
    }
    _front=_base;
    _rear=_front;
}

bool CircularQueue::Qempty()
{
    if(_rear==_front) return true;
    else return false;
}

bool CircularQueue::Qfull()
{
    if(_rear-_front==-1||_rear-MAX_SIZE+1==_front) return true;    //if front is on the next position(circle) of rear, full
    else return false;
}

int CircularQueue::QLength()
{
    return (_rear-_front+MAX_SIZE)%MAX_SIZE;
}

bool CircularQueue::EnQueue(Datatype data)
{
    if(Qfull()){     
        cerr << "Already full!\n";
        return false;
    }
    *_rear=data;
    if(_rear-MAX_SIZE+1>=_base) _rear=_base;
    else _rear++;
    return true;
}

bool CircularQueue::DeQueue(Datatype &data)
{
    if(Qempty()){
        cerr << "Already empty!\n";
        return false;
    }
    data=*_front;
    if(_front-MAX_SIZE+1>=_base) _front=_base;
    else _front++;
    return true;
}

CircularQueue::~CircularQueue()
{
    if(Qempty()){
        free(_base);
    }
}

void CircularQueue::showMenu()
{
    cout << "--------------------------------------------\n"
         << "1.Enter data to the stack.\n"
         << "2.Delete data from the stack.\n"
         << "0.Exit.\n"
         << "--------------------------------------------\n"
         << "Please enter your choise:";
}

bool CircularQueue::test(CircularQueue Q)
{
    int instruction;
    int data;
    Q.showMenu();
    while (cin >> instruction)
    {
        switch (instruction)
        {
        case 1:
            cout << "Data:";
            cin >> data;
            Q.EnQueue(data);
            break;

        case 2:
            Q.DeQueue(data);
            if(!Q.Qempty()) cout << "The data you delete out is " << data << endl; 
            break;

        default:
            exit(0);
            break;
        }
        Q.showMenu();
    }
    return true;
}

int main(void)
{
    CircularQueue q;
    q.test(q);
    return 0;
}

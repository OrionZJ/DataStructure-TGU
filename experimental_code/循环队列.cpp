#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
#define dataType int
typedef struct {
    dataType *base;
    int front;
    int rear;
}SqQueue;

bool InitQueue(SqQueue &q){
    q.base=(dataType*)malloc(MAXSIZE*sizeof(dataType));
    if(!q.base){
        cerr << "ERROR!";
        exit(-1);
    }
    q.front=q.rear=0;
    return true;
}

bool EnQueue(SqQueue &q,dataType &e){
    if((q.rear+1)%MAXSIZE==q.front){
        cerr << "ERROR!";
        exit(-1);
    }
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%MAXSIZE;
    return true;
}

bool EnMutiQueue(SqQueue &q,dataType &e){
    int num;
    cout << "How many data:";
    cin >> num;
    if(num>MAXSIZE){
        cerr << "OVERFLOW!";
        exit(-1);
    } 
    for (int i = 0; i < num; i++)
    {
        cout << "The " << i+1 << " data is:";
        cin >> e;
        EnQueue(q,e);
    }
    return true;
}

bool DeQueue(SqQueue &q,dataType &e){
    if(q.front==q.rear){
        cerr << "ERROR!";
        exit(-1);
    }
    e=q.base[q.front];
    q.front=(q.front+1)%MAXSIZE;
    return true;
}

int main(){
    SqQueue q;
	int choise;
	dataType e;
	cout << "Initializing...\n";
	InitQueue(q);
	cout << "1.Enter multiple numbers.\n"
		 << "2.Enter one data.\n"
		 << "3.Delete number from queue.\n"
		 << "--------------------------------------\n";
	while (cin >> choise)
	{
		switch (choise)
		{
		case 1:
			EnMutiQueue(q,e);
			break;
		
		case 2:
			cout << "Please input the data you want to enter:";
			cin >> e;
			EnQueue(q,e);
			break;

		case 3:
			DeQueue(q,e);
			cout << "The data you delete is " << e << ".\n";
			break;
		}
	cout << "--------------------------------------\n"
		 << "1.Enter multiple numbers.\n"
		 << "2.Enter one data.\n"
		 << "3.Delete number from queue.\n"
		 << "--------------------------------------\n";
	}	
	return 0;
}
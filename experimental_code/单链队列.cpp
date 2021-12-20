#include <bits/stdc++.h>
#define dataType int
using namespace std;
typedef struct QNode{
	dataType data;
	struct QNode *next;	
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//初始化队列
bool InitQueue(LinkQueue &q){
	q.front=q.rear=(QueuePtr)malloc(sizeof(QueuePtr));
	if(!q.front){
		cerr << "ERROR!\n";
		exit(-1);
	}	
	q.front->next=NULL;
	return true;
}

//插入队尾
bool EnterQueue(LinkQueue &q,dataType &e){
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p){
		cerr << "ERROR!\n";
		exit(-1);
	}
	q.rear->next=p;
	p->next=NULL;
	p->data=e;
	q.rear=p;
	return true;
}

//多个元素入队
bool MultiEnterQueue(LinkQueue &q,dataType &e){
	int num=0;
	cout << "How many numbers do you want to enter:";
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "The " << i+1 << " data:";
		cin >> e;
		EnterQueue(q,e);
	}
	return true;
}

//队头出队
bool  DeletQueue(LinkQueue &q,dataType &e){
	if(q.front==q.rear){
		cerr << "ERROR!";
		exit(-1);
	}
	QueuePtr p=q.front->next;
	e=p->data;
	q.front->next=p->next;
	if(q.rear==p) q.rear=q.front;
	free(p);
	return true;
}
 int main(){
	LinkQueue q;
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
			MultiEnterQueue(q,e);
			break;
		
		case 2:
			cout << "Please input the data you want to enter:";
			cin >> e;
			EnterQueue(q,e);
			break;

		case 3:
			DeletQueue(q,e);
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
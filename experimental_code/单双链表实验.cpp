/*虽然C++已有list容器
本程序依旧使用类C语言的方式声明并初始化链表结构
实现对链表的创建、插入、访问、删除功能*/
#include <bits/stdc++.h>
using namespace std;
typedef int datatype;

//声明单向链表
typedef struct ONode{
    datatype data;
    struct ONode *next;
}ONode,*pointer;
//声明双向链表
typedef struct DNode{
	struct DNode *previous;
	datatype data;
	struct DNode *next;
}DNode,*DuPointer;

pointer InitHead();	//初始化头指针
DuPointer InitHeadForDu();
bool GetData(pointer l,int i,datatype &e);	//获取链表内数据
bool GetData(DuPointer l,int i,datatype &e);
template <typename structType>
bool InsertMutiData(structType l,int i,datatype &e);//插入多个数据	
bool InsertData(pointer &l,int i,datatype &e);	//插入数据
bool InsertData(DuPointer &l,int i,datatype &e);
bool DeleteData(pointer &l,int i,datatype &e);	//删除数据
bool DeleteData(DuPointer &l,int i,datatype &e);

int main(){
	int NodeType = 0;
	int instruction = 0;
	int i = 1;
	int e = 0;
	cout << "What kind of LinkedList do you want to create?" << endl
		 << "1.One-way LinkedList." << endl
		 << "2.Double LinkedList." << endl
		 << "Please input the instruction:";
	cin >> NodeType;
	switch (NodeType) {
		case 1:
		{
			cout << "Initualizing..." << endl;
			pointer head = InitHead();	
			InsertMutiData(head,i,e);
			cout << "-----------------------------------------" << endl
				 << "1.Insert the LinkedList." << endl
			     << "2.Get the data from LinkedList." << endl
			   	 << "3.Delete from LinkedList." << endl
				 << "0.Exit" << endl;
			cout << "Please input the instruction:";
		    while(cin >> instruction){
					switch (instruction) {
						case 1:
							cout << "Please enter the data:";
							cin >> e;
							cout << "Which position do you want to insert:";
							cin >> i;
							InsertData(head,i,e);
							break;
						case 2:
							cout << "Which position do you want to get:";
							cin >> i;
							GetData(head,i,e);
							cout << "The data you get is " << e << endl;
							break;
						case 3:
							cout << "Which position do you want to delete:";
							cin >> i;
							DeleteData(head,i,e);
							cout << "The data you delete is " << e << endl;
							break;
						case 0:
							exit(0);
							break;
					}
					cout << "-----------------------------------------" << endl
						 << "1.Insert the LinkedList." << endl
						 << "2.Get the data from LinkedList." << endl
						 << "3.Delete from LinkedList." << endl
						 << "0.Exit" << endl
						 << "Please input the instruction:";
			}	 
			break;
		}
		case 2:
		{
			cout << "Initualizing..." << endl;
			DuPointer headDu = InitHeadForDu();	
			InsertMutiData(headDu,i,e);
			cout << "-----------------------------------------" << endl
				 << "1.Insert the LinkedList." << endl
			     << "2.Get the data from LinkedList." << endl
			   	 << "3.Delete from LinkedList." << endl
				 << "0.Exit" << endl;
			cout << "Please input the instruction:";
			while(cin >> instruction){
				switch (instruction) {
					case 1:
						cout << "Please enter the data:";
						cin >> e;
						cout << "Which position do you want to insert:";
						cin >> i;
						InsertData(headDu,i,e);
						break;
					case 2:
						cout << "Which position do you want to get:";
						cin >> i;
						GetData(headDu,i,e);
						cout << "The data you get is " << e << endl;
						break;
					case 3:
						cout << "Which position do you want to delete:";
						cin >> i;
						DeleteData(headDu,i,e);
						cout << "The data you delete is " << e << endl;
						break;
					case 0:
						exit(0);
						break;
				}
				cout << "-----------------------------------------" << endl
					 << "1.Insert the LinkedList." << endl
					 << "2.Get the data from LinkedList." << endl
					 << "3.Delete from LinkedList." << endl
					 << "0.Exit" << endl
					 << "Please input the instruction:";
			}
			break;
		}
	} 
	return 0;
}

//创建单向链表头指针
pointer InitHead(){
	pointer head;
    head = (ONode *)malloc(sizeof(ONode));
   	if(head==NULL){
	   	cerr << "Unable to Initualize!" << endl;
	   	exit(-1);
	}
   	head->next=NULL;
   	head->data=0;
   	return head;
}

//创建双向链表头指针
DuPointer InitHeadForDu(){
	DuPointer head;
	head = (DNode *)malloc(sizeof(DNode));
	if(head==NULL){
	   	cerr << "Unable to Initualize!" << endl;
	   	exit(-1);
	}
	head->previous=NULL;
	head->data=0;
	head->next=NULL;
	return head;                           
}

//读入多个数据
template <typename structType>
bool InsertMutiData(structType l,int i,datatype &e){		//此处i为将多个数据插在i位置前
	int num;
	cout << "How many data do you want to add:";
	cin >> num;
	for (int j = 0; j<num; j++){
		cout << "The " << j+1 << " data:";
		cin >> e;
		InsertData(l,j+1,e);
	}
	return true;
}

//获取链表第i个位置的值    
bool GetData(pointer l,int i,datatype &e){
    pointer p = l->next;
    int j = 1;
    while(p&&j<i){
        p = p->next;
        ++j;
    }     
    if(!p||j>i){
		cerr << "The number crossed the line!" << endl;		////如果第i个元素不存在则退出
		exit(-1);
	}
    e = p->data;
    return 1;
}
bool GetData(DuPointer l,int i,datatype &e){
	DuPointer p = l->next;
	int j = 1;
	while(p&&j<i){
        p = p->next;
        ++j;
    }     
    if(!p||j>i){
		cerr << "The number crossed the line!" << endl;
		exit(-1);
	}
    e = p->data;
    return 1;
}

//在i位置前插入数据
bool InsertData(pointer &l,int i,datatype &e){
    pointer p = l;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
        ++j;
    }
    if(!p||j>i-1){
		cerr << "The number crossed the line!" << endl;
		exit(-1);
	} 
    pointer s = (ONode *)malloc(sizeof(ONode));
    s->next = p->next;
    s->data = e;
    p->next = s;
    return 1;
}
bool InsertData(DuPointer &l,int i,datatype &e){
	DuPointer p = l;
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
	    ++j;
	}
    if(!p||j>i-1){
		cerr << "The number crossed the line!" << endl;
		exit(-1);
	} 
	DuPointer s = (DNode *)malloc(sizeof(DNode));
	s->next = p->next;
	s->previous = p;
	s->data = e;
	if(!(p->next==NULL)) p->next->previous = s;
	p->next = s;
	return 1;
}

//删除i位置的数据
bool DeleteData(pointer &l,int i,datatype &e){
	pointer p = l;
	pointer s = NULL;
	int j = 0;
	while(p&&j<i-1){	//p指针指向待删除数据
		p = p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		cerr << "The number crossed the line!" << endl;		
		exit(-1);
	}
	s = p->next;	
	p->next = s->next;
	e = s->data;
	free(s);
	return 1;
}
bool DeleteData(DuPointer &l,int i,datatype &e){
	DuPointer p = l;
	DuPointer s = NULL;
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
		++j;
	}
	if(!(p->next)||j>i-1){
		cerr << "The number crossed the line!" << endl;
		exit(-1);
	}
	s = p->next;
	p->next = s->next;
	p->next->previous = p;
	e = s->data;
	free(s);
	return 1;
}    

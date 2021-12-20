#include <iostream>
using namespace std;
typedef int datatype;

typedef struct ONode{
    datatype data;
    struct ONode *next;
}ONode,*pointer;
pointer InitHead();
int GetData(pointer l,int i,datatype &e);
int InsertData(pointer &l,int i,datatype &e);
int	DeleteData(pointer &l,int i,datatype &e);

int main(){
	int instruction = 0;
	cout << "Initualizing..." << endl;
    pointer head = InitHead();	
    cout << "Press 1 to insert the link list." << endl
    	 << "Press 2 to get the data from link list." << endl
    	 << "Press 3 to delete from te link list." << endl
		 << "Exit press 0." << endl;
	cout << "Please input the instruction:";
    while(cin >> instruction){
		switch (instruction) {
				case 1:
					int i,e;
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
				default:
					return 0;
		}
		cout << "Please input the instruction:";
	}	 
	return 0;
}

pointer InitHead(){
	   pointer head;
    head = (ONode *)malloc(sizeof(ONode));
   	if(head==NULL) exit(-1);
   	head->next=NULL;
   	head->data=0;	//可无此操作，因为不读取头指针数据域
   	return head;
}
    
int GetData(pointer l,int i,datatype &e){
    pointer p = l->next;
    int j = 1;
    while(p&&j<i){
        p = p->next;
        ++j;
    }     
    if(!p||j>i) exit(-1);		//如果第i个元素不存在则退出
    e = p->data;
    return 1;
}

int InsertData(pointer &l,int i,datatype &e){
    pointer p = l;
    pointer s = NULL;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
        ++j;
    }
    if(!p||j>i-1) exit(-1);
    s = (ONode *)malloc(sizeof(ONode));
    s->next = p->next;
    s->data = e;
    p->next = s;
    return 1;
}

int	DeleteData(pointer &l,int i,datatype &e){
	pointer p = l;
	pointer s = NULL;
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
		++j;
	}
	if(!(p->next)||j>i-1) exit(-1);
	s = p->next;
	p->next = s->next;
	e = s->data;
	free(s);
	s = NULL;
	return 1;
}
    

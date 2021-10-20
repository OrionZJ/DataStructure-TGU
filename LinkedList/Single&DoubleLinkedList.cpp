//使用尾插法插入单链表
#include <bits/stdc++.h>
using namespace std;
typedef int datatype;

typedef struct ONode{
    datatype data;
    struct ONode *next;
}ONode,*pointer;
pointer InitHead();
template <typename structType>
bool InsertMutiData(structType l,int i,int num);	//插入多个数据
int GetData(pointer l,int i,int &e);
int InsertData(pointer &l,int i,int e);
int	DeleteData(pointer &l,int i,datatype &e);
int	DeleteNextData(pointer &head,pointer &p,datatype &e);
pointer appendDataAfterPointer(pointer head,pointer p,datatype e,int times);

int test();	//用于测试数据结构
// static int count=0;

int main(){
	cin.tie(0); 
	cout.tie(0); 
	// ios::sync_with_stdio(false);
	int n = 0;
	int k = 0;
	datatype e;
	vector<int> storeResult;
	while(cin >> n && n!=0){
		cin >> k;
		datatype change;
		pointer Head=InitHead();
		InsertMutiData(Head,1,n);	//初始单向循环链表1,2,...,n
		pointer p1=Head->next;		//p1指向头节点
		pointer p2=NULL;
		pointer p3=NULL;
		int last=0;
		int begin=0;
		int times = n-1;
		while(Head->next!=Head&&times>0){
			// if(times==3) {
			// 	cout << "debug point";
			// 	cout << "\n";
			// 	}
			for(int i=0;i<k-2;i++){		//p1指向要out的人的前一人
				p1=p1->next;
				if(p1==Head) p1=p1->next;
			}
			if(p1==Head) p1=p1->next;
			DeleteNextData(Head,p1,e);	//out人
			p2=p1->next;
			if(p2==Head) p2=p2->next;
			for(int i=0;i<k-2;i++){		//p2指向要换位人的前一人！！！！！！！！！！！
				p2=p2->next;
				if(p2==Head) p2=p2->next;
			}
			if(p2->next!=p1&&p2->next!=Head){
				DeleteNextData(Head,p2,e);	//换位者出圈!!
				p3=appendDataAfterPointer(Head,p1,e,times);	//换位者入圈
				p1=p3->next;	//继续循环
			}
			if(p2->next==p1||(p2->next==Head&&Head->next==p1)) p1=p1->next;//若p1换位后回到原位则不换！！
			if(p1==Head) p1=p1->next;  
			p2=NULL;
			p3=NULL;
			times--;

		}
		last=Head->next->data;
		// begin=1+n-(last-1);
		begin= (n - last + 1) % n + 1;
		if(last==1) begin=1;
		storeResult.push_back(begin);
	}

for (auto  it = storeResult.begin(); it!=storeResult.end(); it++)
{
	cout << *it ;
	cout << "\n";
}
	
system("pause");
return 0;
}

pointer InitHead(){
	pointer head = (pointer)malloc(sizeof(ONode));
   	if(head==NULL) exit(-1);
	// pointer headNode = (ONode *)malloc(sizeof(ONode));
	// if(headNode==NULL) exit(-1);
   	head->next=head;
   	// head->data=0;	//可无此操作，因为不读取头指针数据域
   	return head;
}

// pointer InitNode(pointer head){
// 	pointer headNode = (ONode *)malloc(sizeof(ONode));
// 	if(headNode==NULL) exit(-1);
// 	headNode->next=head;
	
// }
    
int GetData(pointer l,int i,datatype &e){
    pointer p = l->next;
    int j = 1;
    while(p&&j<i){
        p = p->next;
		if(p==l) p = p->next;	//如果经循环指回头指针，则next到头节点
        ++j;
    }     
    if(!p||j>i) exit(-1);		//如果第i个元素不存在则退出
	// if(p==l&&p->next!=p) p=p->next;		//如果经循环指回头指针，则next到头节点，错！！！
	if(p->next==p) cerr << "Empty list!(GetData)";
    e = p->data;
    return p->data;
}

int InsertData(pointer &l,int i,int e){		//实现方法为在i-1的位置后面追加
    pointer p = l;
    pointer s = NULL;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
		if(p==l) p = p->next;		//如果经循环指回头指针，则next到头节点
        ++j;
    }
    if(!p||j>i-1) exit(-1);
	// if(p==l&&p->next!=p) p=p->next;		//如果经循环指回头指针，则next到头节点。后续debug此语句错误
	// if(p->next==p) cout << "Empty list!(InsertData)";
    s = (ONode *)malloc(sizeof(ONode));
    s->next = p->next;
    s->data = e;
    p->next = s;
	// count++;
    return i;
}

pointer appendDataAfterPointer(pointer head,pointer p,datatype e,int times){		//在指针所指数据后添加给定数据
	if(p->next==head) p=p->next;
	pointer s=(ONode *)malloc(sizeof(ONode));
	// if(p->next==p)  s = (ONode *)malloc(sizeof(ONode));
	s->next=p->next;
	s->data=e;
	p->next=s;
	return s;
}

int	DeleteData(pointer &l,int i,datatype &e){
	pointer p = l;
	pointer s = NULL;		//指向要删除的数据
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
		if(p==l) p = p->next;		//如果经循环指回头指针，则next到头节点
		++j;
	}
	if(!(p->next)||j>i-1) exit(-1);
	if(p->next==l) p=p->next;		//如果经循环指回头指针，则next到头节点
	s = p->next;
	// if(s==l&&s->next!=s) s=s->next;		//如果经循环指回头指针，则next到头节点，错！
	if(s->next==s){
		cerr << "Empty list!(DeleteData)";
		return -1;
	}
	p->next = s->next;
	e = s->data;
	free(s);
	// count--;		//若不慎删去头指针，则count出现负值
	// cout << "count is " << count << "\n";		
	s = NULL;
	return 1;
}

int	DeleteNextData(pointer &head,pointer &p,datatype &e){	 //删除指针所指数据的后一数据
	pointer s=NULL;
	if(p->next==head) p=p->next;
	s=p->next;
	e=s->data;
	p->next=s->next;
	free(s);
	return 1;
}
    
template <typename structType>
bool InsertMutiData(structType l,int i,int num){		//此处i为将多个数据插在i位置前
	// cout << "How many data do you want to add:";
	// cin >> num;
	for (int j = 0; j<num; j++){
		// cout << "The " << j+1 << " data:";
		// cin >> e;
		InsertData(l,j+1,j+1);
	}
	return true;
}

int test(){
	int instruction = 0;
	cout << "Initualizing..." << "\n";
    pointer head = InitHead();	
    cout << "Press 1 to insert the link list." << "\n"
    	 << "Press 2 to get the data from link list." << "\n"
    	 << "Press 3 to delete from te link list." << "\n"
		 << "Exit press 0." << "\n";
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
					cout << "The data you get is " << e << "\n";
					break;
				case 3:
					cout << "Which position do you want to delete:";
					cin >> i;
					DeleteData(head,i,e);
					cout << "The data you delete is " << e << "\n";
					break;
				case 0:
					return 0;
					break;
				default:
					continue;
		}
		cout << "Please input the instruction:";
	}	
	system("pause");
	return 0;
}

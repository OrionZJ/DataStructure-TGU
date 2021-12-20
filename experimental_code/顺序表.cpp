#include <bits/stdc++.h>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int dataType;
typedef struct {
	dataType *data;
	int length;
	int listsize;
}Sqlist;
bool InitList(Sqlist &l);
bool InsertData(Sqlist &l,int i,dataType e);
bool InsertMutiData(Sqlist &l,int i,dataType &e);
bool DeleteData(Sqlist &l,int i,dataType &e);

int main(){
	int construction;
	dataType e,i;
	cout << "Initializing...\n";
	Sqlist SeqList;
	InitList(SeqList);
	InsertMutiData(SeqList,i,e);
	cout << "1.Insert the SeqList.\n"
		 << "2.Delete from SeqList.\n"
		 << "-----------------------\n";
	while(cin >> construction,construction){
		switch (construction) {
			case 1:
				cout << "Please enter the data:";
				cin >> e;
				cout << "Which position do you want to insert:";
				cin >> i;
				InsertData(SeqList,i,e);
				break;
			case 2:
				cout << "Which position do you want to delete:";
				cin >> i;
				DeleteData(SeqList,i,e);
				cout << "The data you delete is " << e << endl;
				break;
		}
		cout << "Choise:";
	} 
	return 0;	
}

//初始化顺序表
bool InitList(Sqlist &l){
	l.data=(dataType*)malloc(LIST_INIT_SIZE*sizeof(dataType));
	if(!l.data) cerr << "Overflow!\n";
	l.length=0;
	l.listsize=LIST_INIT_SIZE;
	return true;
}

bool InsertMutiData(Sqlist &l,int i,dataType &e){		//此处i为将多个数据插在i位置前
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

//插入数据
bool InsertData(Sqlist &l,int i,dataType e){
	if(i<1||i>l.length+1){
		 cerr << "Illigal position!\n";
		 exit(-1);
	}
	if(l.length>=l.listsize){
		dataType *newbase=(dataType*)realloc(l.data,(l.listsize+LISTINCREMENT)*sizeof(dataType));
		if(!newbase) cerr << "Overflow!\n";
		l.data=newbase;
		l.listsize+=LISTINCREMENT;
	}
	dataType *p= &(l.data[i-1]);
	for(dataType *i=&(l.data[l.length-1]);i>p;i--){
		*(i+1)=*i;
	}
	*p=e;
	l.length++;
	return true;
}

//删除某数据
bool DeleteData(Sqlist &l,int i,dataType &e){
	if((i<1)||(i>l.length)){
		cerr << "Illigal position!\n";
		exit(-1);
	}
	dataType *p=&(l.data[i-1]);		//指针指向待删除数据
	e=*p;
	dataType *q=&(l.data[l.length-1]);
	for(++p;p<=q;p++) *(p-1)=*p;
	l.length--;
	return true;
}

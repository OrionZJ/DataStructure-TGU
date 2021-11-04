#include <bits/stdc++.h>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define dataType int
typedef struct{
  dataType *base;
  dataType *top;
  int stackSize;
}Sqstack;
//初始化栈
bool initStack(Sqstack &s){
  s.base=(dataType*)malloc(STACK_INIT_SIZE*sizeof(dataType));
  if(!s.base){
    cerr << "OVERFLOW!";
    exit(-1);
  }
  s.top=s.base;
  s.stackSize=STACK_INIT_SIZE;
  return true;
}
//push入数据
bool push(Sqstack &s,dataType e){
  if(s.top-s.base>s.stackSize){
    s.base=(dataType*)realloc(s.base,(s.stackSize+STACKINCREMENT)*sizeof(dataType));
    if(!s.base) {
      cerr << "OVERFLOW";
      exit(-1);
    }
    s.top=s.base+STACKINCREMENT;
    s.stackSize+=STACKINCREMENT;
  }
  *s.top=e;
  s.top++;
  return true;
}
//push入多个数据
bool PushMutiData(Sqstack &s,dataType &e){		
	int num;
	cout << "How many data do you want to push:";
	cin >> num;
	for (int j = 0; j<num; j++){
		cout << "The " << j+1 << " data:";
		cin >> e;
		(s,e);
	}
	return true;
}
//pop出数据
bool pop(Sqstack &s,dataType &e){
  if (s.top==s.base){
    cerr << "No data already!";
    exit(-1);
  }
  s.top--;
  e=*s.top;
  return true;
}

int main(){
  int instruction;
  dataType e;
  cout << "Initializing...\n";
  Sqstack s;
  initStack(s);
  PushMutiData(s,e);
  cout << "1.Push in data to the stack.\n"
    << "2.Pop out data to the stack.\n"
    << "--------------------------------------------\n"
    << "Please enter your choise:";
  while(cin >> instruction,instruction){
    switch(instruction){
      case 1 :
        cout << "Please input the data:";
        cin >> e;
        push(s,e);
        break;
      case 2 :
        cout << "Poping out...\n";
        pop(s,e);
        cout << "The data poped out is " << e << ".\n";
        break;
    }
    cout << "Please enter your choise:";
  }
  return 0;
}
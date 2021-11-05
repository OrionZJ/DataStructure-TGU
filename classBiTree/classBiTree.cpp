//头文件栈使用Class Template以满足程序出入栈需要
#include <bits/stdc++.h>
#include "classStack.h"
using namespace std;
#define elemType char

class BiTree
{
private:
     typedef struct BiTNode {
        elemType _data;
        BiTNode *_lchild,*_rchild;
    }BiTNode,*biTree;
    
public:
    biTree _root;
    bool createBiTNode(biTree &node);   //先序读入，若无子树则输入' '（空格）
    bool printElem(biTree t);   //因为使用了C++类的概念，既可直接使用类中的prinElem函数，也可通过函数指针visit调用
    bool preOrderTraverse_1(biTree t,bool (BiTree::*visit)(biTree t));    //先序递归遍历
    bool preOrderTraverse_2(biTree t,bool (BiTree::*visit)(biTree t));    //先序递归遍历
    bool inOrderTraverse_1(biTree t,bool (BiTree::*visit)(biTree t));   //中序非递归实现遍历_1
    bool inOrderTraverse_2(biTree t,bool (BiTree::*visit)(biTree t));   //中序非递归实现遍历_2
    bool postOrderTraverse(biTree t,bool (BiTree::*visit)(biTree t));
};

bool BiTree::printElem(biTree t)    //空指针则返回false
{
    if(!t) return false;
    cout << t->_data << "\n";
    return true;
}

bool BiTree::createBiTNode(biTree &node)    //先序读入，若无子树则输入' '（空格）
{
    elemType data=cin.get();
    if(data==' ') node=NULL;
    else{
        node=new BiTNode;
        node->_data=data;
        createBiTNode(node->_lchild);
        createBiTNode(node->_rchild);
    }
    return true;
}

bool BiTree::preOrderTraverse_1(biTree t,bool (BiTree::*visit)(biTree t))
{
    if(t){      //本层嵌套为必须的，否则无法访问右子树
        if(printElem(t)){
            if(preOrderTraverse_1(t->_lchild,printElem)){
                if(preOrderTraverse_1(t->_rchild,printElem)){
                    return true;
                }
            }
        }
        return false;
    }
    else return true;
}

bool BiTree::preOrderTraverse_2(biTree t,bool (BiTree::*visit)(biTree t))
{
    if(!t) return false;
    printElem(t);
    preOrderTraverse_2(t->_lchild,printElem);
    preOrderTraverse_2(t->_rchild,printElem);
    return true;
}

bool BiTree::inOrderTraverse_1(biTree t,bool (BiTree::*visit)(biTree t))
{
    Stack<BiTNode*> S;
    biTree p=t;
    S.push(p);
    while (!S.empty())
    {
        while (S.getTop(S,p)&&p) S.push(p->_lchild);    //getTop更改t->data得以向左下走到底
        S.pop(p);     //退栈出一个空结点
        if(!S.empty()){
            S.pop(p);
            if(!printElem(p)) return false;     
            S.push(p->_rchild);       //访问右子树
        }
    }
    return true;    
}

bool BiTree::inOrderTraverse_2(biTree t,bool (BiTree::*visit)(biTree t))
{
    Stack<BiTNode*> S;
    biTree p=t;
    while (p||!S.empty()){
        if(p){
            S.push(p);   //一直前进到最左下
            // if(!printElem(p)) return false;
            p=p->_lchild;
        }else{
            S.pop(p);
            if(!printElem(p)) return false;
            p=p->_rchild;
        }
    }
    return true;
}

bool BiTree::postOrderTraverse(biTree t,bool (BiTree::*visit)(biTree t))
{
    if(!t) return false;
    postOrderTraverse(t->_lchild,visit);
    postOrderTraverse(t->_rchild,visit);
    printElem(t);
    return true;
}

bool test(BiTree biTree)
{
    cout << "Create BiTree:[abc--de-g--f---]";
    biTree.createBiTNode(biTree._root);
    cout << "preOrderTraverse_1:\n";
    biTree.preOrderTraverse_1(biTree._root,BiTree::printElem);
    cout << "preOrderTraverse_2:\n";
    biTree.preOrderTraverse_2(biTree._root,BiTree::printElem);
    cout << "inOrderTraverse_1:\n";
    biTree.inOrderTraverse_1(biTree._root,BiTree::printElem);
    cout << "inOrderTraverse_2:\n";
    biTree.inOrderTraverse_2(biTree._root,BiTree::printElem);
    cout << "postOrderTraverse_2:\n";
    biTree.postOrderTraverse(biTree._root,BiTree::printElem);
    return true;
}

int main(void)
{
    BiTree biTree;
    test(biTree);
    return 0;
}
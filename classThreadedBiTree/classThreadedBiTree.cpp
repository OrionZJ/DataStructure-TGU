#include <bits/stdc++.h>
using namespace std;
#define ElemType char

class BiThrTree
{
private:
    typedef enum PointerTag{Link,Thread}PointerTag;
    typedef struct BiThrNode
    {
        ElemType _data;
        BiThrNode *_lchild,*_rchild;
        PointerTag _lTag=Link;      //先默认为有子树，若无子树，后续再线索化
        PointerTag _rTag=Link;
    }BiThrNode,*biThrTree;
    biThrTree _head;
public:
    biThrTree _root;
    bool createBiThrTree(biThrTree &node);
    void inThreading(biThrTree p,biThrTree &pre);
    bool inOrderThreading();
    bool inOrderTraverse();
    bool visit(biThrTree node);
};

bool BiThrTree::createBiThrTree(biThrTree &node)    //使用先序遍历创建并读入二叉树，等待线索化
{
    ElemType data=cin.get();
    if(data==' ') node = NULL;
    else{
        node = new BiThrNode;
        node->_data=data;
    createBiThrTree(node->_lchild);
    createBiThrTree(node->_rchild);
    }
    return true;
}

void BiThrTree::inThreading(biThrTree p,biThrTree &pre)     //节点线索化
{
    if(p){
        inThreading(p->_lchild,pre);    //线索化左子树
        if(!p->_lchild){        //当前节点前驱线索化
            p->_lTag=Thread;
            p->_lchild=pre;
        }
        if(!pre->_rchild){      //前一节点后继线索化
            pre->_rTag=Thread;
            pre->_rchild=p;
        }
        pre=p;
        inThreading(p->_rchild,pre);        //线索化右子树
    }
}

bool BiThrTree::inOrderThreading()
{
    if(!(_head=(biThrTree)malloc(sizeof(BiThrNode)))) return false;     //建立头结点
    _head->_lTag=Link; _head->_rTag=Thread;
    _head->_rchild=_head;
    if(!_root) _head->_lchild=_head;
    else{
        _head->_lchild=_root;
        biThrTree pre=_head;
        inThreading(_root,pre);     //中序遍历方式线索化
        pre->_rTag=Thread;
        pre->_rchild=_head;      //线索化最后一个结点
        _head->_rchild=pre;
    }
    return true;
}

bool BiThrTree::inOrderTraverse()
{
    biThrTree p=_head->_lchild;     //p指向根结点
    while (p!=_head){       //若根结点不为空或回到头结点，则继续循环
        while (p->_lTag==Link){     //p指向当前子树的最左下结点
            p=p->_lchild;
        }
        if(!visit(p)) return false;
        while (p->_rchild!=_head&&p->_rTag==Thread){     //指向最左下子树的后继结点
            p=p->_rchild;
            visit(p);
        }
        p=p->_rchild;       //访问右子树或回到头结点
    }
    return true;
}

bool BiThrTree::visit(biThrTree node)
{   
    if(!node->_data) return false;
    else{
        cout << node->_data << endl;
        return true;
    }  
}

void test(BiThrTree T)
{
    cout << "Create BiTree:[abc--de-g--f---]";
    T.createBiThrTree(T._root);
    T.inOrderThreading();
    cout << "inOrderTraverse:\n";
    T.inOrderTraverse();
}

int main(void)
{
    BiThrTree T;
    test(T);
    system("pause");
    return 0;
}

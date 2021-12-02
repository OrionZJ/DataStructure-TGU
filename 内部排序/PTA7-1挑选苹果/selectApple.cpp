#include <bits/stdc++.h>
using namespace std;

class Apple {
    public:
        int _basketId = -1;
        string _appleId = "";
        int _weight = 0;
        int _diameter = 0;
        Apple() {}
        Apple(int basketId, string appleId, int weight, int diameter) {
            this->_basketId = basketId;
            this->_appleId = appleId;
            this->_weight = weight;
            this->_diameter = diameter;
        }

        void show() {
            cout << this->_appleId << " " 
                 << this->_weight << " " 
                 << this->_diameter;
        }
        //重载=运算符，对Apple赋值时拷贝另一Apple类的全部属性
        // void operator=(const Apple &a) {
        //     this->_basketId = a._basketId;
        //     this->_appleId = a._appleId;
        //     this->_weight = a._weight;
        //     this->_diameter = a._diameter;
        // }

};

class Basket {
    public:
        int _basketId = 0;
        vector<Apple> _applesInBasket = {};
        Apple heaviestApple;
        Basket() {}
        Basket(int basketId, vector<Apple> &apples) {
            this->_basketId = basketId;
            for (int i = 0; i < apples.size(); i++) {
                if (apples[i]._basketId == this->_basketId)
                    this->_applesInBasket.push_back(apples[i]);
            }
        }

        void selectHeaviest() {
            this->heaviestApple = this->_applesInBasket[0];
            for (int i = 0; i < _applesInBasket.size(); i++) {
                if (_applesInBasket[i]._weight > heaviestApple._weight) {
                    this->heaviestApple = this->_applesInBasket[i];
                }
            }
        }
        //重载<运算符，比较Basket时比较成员变量_basketId的大小
        bool operator<(const Basket &a) const {
            if (this->_basketId < a._basketId) return true;
            else return false;
        }
        //重载=运算符，对Basket赋值时拷贝另一Basket类的全部属性
        void operator=(const Basket &a) {
            this->_basketId = a._basketId;
            this->_applesInBasket.assign(a._applesInBasket.begin(),a._applesInBasket.end());
            this->heaviestApple = a.heaviestApple;
        }
};

template <typename ListType>
void InsertSort(ListType &L) {    //使用插入排序算法进行排序
    for (int i = 2; i < L.size(); i++) {
        if (L[i] < L[i - 1]) {    //若比较类，则需重载<运算符
            L[0] = L[i];    //复制为哨兵
            L[i] = L[i - 1];
            int j;
            for (j = i - 2; L[0] < L[j]; j--) {
                L[j + 1] = L[j];    //记录后移
            } 
            L[j + 1] = L[0];    //复制到正确的位置
        }
    }
}

template <typename ListType>
void BInsertSort (ListType &L) {    //折半插入排序算法
    for (int i = 2; i < L.size(); i++) {
        L[0] = L[i];    //复制到哨兵位
        int low = 1; int high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (L[0] < L[mid]) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j >= high + 1; j--) {   
            L[j + 1] = L[j];    //逐个移动腾出位置
        }
        L[high + 1] = L[0];    //此时high+1恰好为插入位置
    }
}

int main(void) {
    int appleNum;
    vector<Apple> apples;
    vector<Basket> baskets;
    baskets.push_back(Basket());    //添加排序用的哨兵位置baskets[0]
    cin >> appleNum;
    for (int i = 0; i < appleNum; i++) {
        int basketId;
        string appleId;
        int weight;
        int diameter;
        cin >> basketId;
        cin >> appleId;
        cin >> weight;
        cin >> diameter;
        apples.push_back(Apple(basketId,appleId,weight,diameter));
        //如果没有对应的篮子，则添加新的篮子
        int cnt = 0;
        for (int i = 0; i < baskets.size(); i++) {
            if (basketId == baskets[cnt]._basketId) break;
            cnt++;
        }
        if (cnt >= baskets.size() )
            baskets.push_back(Basket(basketId, apples));
    }
    // InsertSort(baskets);    //使用插入排序算法对篮子进行排序
    BInsertSort(baskets);    //折半插入排序算法
    //每个篮子选出最重的苹果并且输出
    cout << "The heaviest apple in each basket:\n";
    for (int i = 1; i < baskets.size(); i++) {
        cout << baskets[i]._basketId << " ";
        baskets[i].selectHeaviest();
        baskets[i].heaviestApple.show();
        if (i < baskets.size() - 1) cout << "\n";        
    }
    return 0;
}
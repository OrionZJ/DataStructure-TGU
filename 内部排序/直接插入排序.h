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
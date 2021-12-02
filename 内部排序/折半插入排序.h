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
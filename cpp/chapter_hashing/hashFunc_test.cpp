#include "../utils/common.hpp"

/* 哈希函数 */
int hashFunc(int key) {
    int index = key % 100;
    return index;
}

// 通过扩容哈希表来减少哈希冲突
int hashFunc2(int key) {
    int index = key % 200;
    return index;
}

int main(){
    cout << hashFunc(12836) << endl; //36
    cout << hashFunc(20336) << endl; //36
    cout << hashFunc2(20336) << endl; //36
    return 0;
}
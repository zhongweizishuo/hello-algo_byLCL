/**
 * File: print_utils.hpp
 * Created Time: 2021-12-19
 * Author: Krahets (krahets@163.com), msk397 (machangxinq@gmail.com), LoneRanger(836253168@qq.com)
 */

#pragma once

#include "list_node.hpp"
#include "tree_node.hpp"
#include <climits>
#include <iostream>
#include <sstream>
#include <string>

/* Find an element in a vector */
template <typename T> int vecFind(const vector<T> &vec, T ele) {
    int j = INT_MAX;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == ele) {
            j = i;
        }
    }
    return j;
}

/* Concatenate a vector with a delim */
// 有意思：输入一个符号delim ,和一个vector ，按遍历输出 delim+vector里面的每一个元素
template <typename T> string strJoin(const string &delim, const T &vec) {
    ostringstream s;
    for (const auto &i : vec) {
        if (&i != &vec[0]) {
            s << delim;
        }
        s << i;
    }
    return s.str();
}

/* Repeat a string for n times */
string strRepeat(string str, int n) {
    ostringstream os;
    for (int i = 0; i < n; i++)
        os << str;
    return os.str();
}

/* Print an Array */
template <typename T> void printArray(T *arr, int n) {
    cout << "[";
    for (int i = 0; i < n - 1; i++) { //打印前n个和 “,”
        cout << arr[i] << ", ";
    }
    if (n >= 1) // 打印最后一个元素和 “]”
        cout << arr[n - 1] << "]" << endl;
    else //n = 0
        cout << "]" << endl;
}

/* Get the Vector String object */
template <typename T> string getVectorString(vector<T> &list) {
    return "[" + strJoin(", ", list) + "]";
}

/* Print a vector */
template <typename T> void printVector(vector<T> list) {
    cout << getVectorString(list) << '\n';
}

/* Print a vector matrix */
template <typename T> void printVectorMatrix(vector<vector<T>> &matrix) {
    cout << "[" << '\n';
    for (vector<T> &list : matrix)
        cout << "  " + getVectorString(list) + "," << '\n';
    cout << "]" << '\n';
}

/* Print a linked list  打印链表*/
void printLinkedList(ListNode *head) {
    vector<int> list;
    while (head != nullptr) {
        // 往前遍历，将节点的值压入 list
        list.push_back(head->val);
        head = head->next;
    }

    cout << strJoin(" -> ", list) << '\n';
}

/**
 * This tree printer is borrowed from TECHIE DELIGHT
 * https://www.techiedelight.com/c-program-print-binary-tree/
 */
struct Trunk {
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

/* Helper function to print branches of the binary tree */
void showTrunks(Trunk *p) {
    if (p == nullptr) {
        return;
    }

    showTrunks(p->prev);
    cout << p->str;
}

/* Print a binary tree */
void printTree(TreeNode *root, Trunk *prev, bool isLeft) {
    if (root == nullptr) {
        return;
    }

    string prev_str = "    ";
    Trunk trunk(prev, prev_str);

    printTree(root->right, &trunk, true);

    if (!prev) {
        trunk.str = "———";
    } else if (isLeft) {
        trunk.str = "/———";
        prev_str = "   |";
    } else {
        trunk.str = "\\———";
        prev->str = prev_str;
    }

    showTrunks(&trunk);
    cout << " " << root->val << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk.str = "   |";

    printTree(root->left, &trunk, false);
}

/* The interface of the tree printer */
void printTree(TreeNode *root) {
    printTree(root, nullptr, false);
}

/* Print a stack */
// 模板函数
template <typename T> void printStack(stack<T> stk) {
    // Reverse the input stack
    stack<T> tmp;
    while (!stk.empty()) {
        tmp.push(stk.top());
        stk.pop();
        // 将stack 翻转存入栈 tmp
    }
    // Generate the string to print
    // 这段代码用于生成并打印一个包含堆栈（stack）中元素的字符串，\
       格式为以逗号分隔的方括号包围的元素列表
    ostringstream s; // 创建了一个 ostringstream 对象s，它用于构建字符串
    bool flag = true;
    while (!tmp.empty()) {
        if (flag) { // flag == true，表示这是第一个元素，不需要在前面插入逗号
            s << tmp.top();
            flag = false;
        } else // 表示下一个元素之前需要插入逗号
            s << ", " << tmp.top();
        tmp.pop();
    }
    cout << "[" + s.str() + "]" << '\n';
}

/* Print a queue */
template <typename T> void printQueue(queue<T> queue) {
    // Generate the string to print
    ostringstream s;
    bool flag = true;
    while (!queue.empty()) {
        if (flag) {
            s << queue.front();
            flag = false;
        } else
            s << ", " << queue.front();
        queue.pop();
    }
    cout << "[" + s.str() + "]" << '\n';
}

/* Print a deque */
template <typename T> void printDeque(deque<T> deque) {
    // Generate the string to print
    ostringstream s;
    bool flag = true;
    while (!deque.empty()) {
        if (flag) {
            s << deque.front();
            flag = false;
        } else
            s << ", " << deque.front();
        deque.pop_front();
    }
    cout << "[" + s.str() + "]" << '\n';
}

/* Print a HashMap */
// 定义模板参数 TKey 和 TValue ，用于指定键值对的类型
template <typename TKey, typename TValue> void printHashMap(unordered_map<TKey, TValue> map) {
    for (auto kv : map) {
        cout << kv.first << " -> " << kv.second << '\n';
    }
}

/* Expose the underlying storage of the priority_queue container */
template <typename T, typename S, typename C> S &Container(priority_queue<T, S, C> &pq) {
    struct HackedQueue : private priority_queue<T, S, C> {
        static S &Container(priority_queue<T, S, C> &pq) {
            return pq.*&HackedQueue::c;
        }
    };
    return HackedQueue::Container(pq);
}

/* Print a Heap (PriorityQueue) */
template <typename T, typename S, typename C> void printHeap(priority_queue<T, S, C> &heap) {
    vector<T> vec = Container(heap);
    cout << "堆的数组表示：";
    printVector(vec);
    cout << "堆的树状表示：" << endl;
    TreeNode *root = vectorToTree(vec);
    printTree(root);
    freeMemoryTree(root);
}

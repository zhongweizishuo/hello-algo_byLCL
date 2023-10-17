/**
 * File: linkedlist_stack.cpp
 * Created Time: 2022-11-28
 * Author: qualifier1024 (2539244001@qq.com)
 */

#include "../utils/common.hpp"

/* 基于链表实现的栈 */
class LinkedListStack {
  private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

  public:
    LinkedListStack() {
        stackTop = nullptr;
        stkSize = 0;
    }

    ~LinkedListStack() {
        // 遍历链表删除节点，释放内存
        freeMemoryLinkedList(stackTop);
    }

    /* 获取栈的长度 */
    int size() {
        return stkSize;
    }

    /* 判断栈是否为空 */
    bool isEmpty() {
        return size() == 0;
    }

    /* 入栈 */
    void push(int num) {
        ListNode *node = new ListNode(num);

        node->next = stackTop; // 新new的node 指向栈顶
        stackTop = node; // 新node被指定为新的栈顶
        stkSize++;
    }

    /* 出栈 */
    void pop() {
        int num = top();
        
        ListNode *tmp = stackTop; // 头结点暂存待删除；新的头结点是他的下一个
        stackTop = stackTop->next;
        // 释放内存
        delete tmp;
        stkSize--;
    }

    /* 访问栈顶元素 */
    int top() {
        if (isEmpty())
            throw out_of_range("栈为空");
        return stackTop->val;
    }

    /* 将 List 转化为 Array 并返回 */
    vector<int> toVector() { // 函数返回值是vector<int>
        ListNode *node = stackTop; // 定义一个链表节点node 
        vector<int> res(size()); // 定义一个vector容器res，大小是size()
        
        for (int i = res.size() - 1; i >= 0; i--) {
            res[i] = node->val;
            node = node->next; // 遍历节点
        }
        return res;
    }
};

/* Driver Code */
int main() {
    /* 初始化栈 */
    LinkedListStack *stack = new LinkedListStack();

    /* 元素入栈 */
    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "栈 stack = ";
    printVector(stack->toVector());

    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "栈顶元素 top = " << top << endl;

    /* 元素出栈 */
    stack->pop();
    cout << "出栈元素 pop = " << top << "，出栈后 stack = ";
    printVector(stack->toVector());

    /* 获取栈的长度 */
    int size = stack->size();
    cout << "栈的长度 size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack->isEmpty();
    cout << "栈是否为空 = " << empty << endl;

    // 释放内存
    delete stack;

    return 0;
}

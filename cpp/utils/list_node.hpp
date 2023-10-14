/**
 * File: list_node.hpp
 * Created Time: 2021-12-19
 * Author: Krahets (krahets@163.com)
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std;

/* Definition for a singly-linked list node */
struct ListNode {
    int val;
    ListNode *next;
    // 构造函数
    
    ListNode(int x) : val(x), next(nullptr) {}
    // 等价于下面的写法----------------------------------------
    // ListNode(int x ){
    //     val = x;
    //     next = nullptr;
    // }
};

/* Generate a linked list with a vector */
ListNode *vecToLinkedList(vector<int> list) {
    ListNode *dum = new ListNode(0);
    ListNode *head = dum;
    for (int val : list) {
        head->next = new ListNode(val);
        head = head->next;
    }
    return dum->next;
}

/* Get a list node with specific value from a linked list */
ListNode *getListNode(ListNode *head, int val) {
    while (head != nullptr && head->val != val) {
        head = head->next;
    }
    return head;
}

/* Free the memory allocated to a linked list */
void freeMemoryLinkedList(ListNode *cur) {
    // 释放内存
    ListNode *temp; // 暂存并删除节点
    while (cur != nullptr) {
        temp = cur;
        cur = cur->next;
        delete temp;
    }
}

// Source : https://leetcode.com/problems/design-linked-list/
// Author : Zhonghuan Gao
// Date   : 2019-07-25

/**********************************************************************************
*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. If index is negative, the node will be inserted at the head of the list.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*
**********************************************************************************/

/*
 * 解法一：
 * 节点构造单链表
 */
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node *cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *t = new Node(val, head);
        head = t;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = head;
        while (cur->next) cur = cur->next;
        cur->next = new Node(val, NULL);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) { addAtHead(val); return; }
        Node *cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node *t = new Node(val, cur->next);
        cur->next = t;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            head = head->next;
            size--;
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        cur->next = cur->next->next;
        size--;
    }

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
private:
    struct Node {
        int val;
        Node *next;
        Node(int x, Node* n): val(x), next(n) {};
    };
    Node *head;
    int size;
};


/**
 * 解法二：
 * 双端队列 deque 实现
 */
class MyLinkedList {
public:
    MyLinkedList() {}

    int get(int index) {
        return (index >= 0 && index < data.size()) ? data[index] : -1;
    }
    void addAtHead(int val) {
        data.push_front(val);
    }
    void addAtTail(int val) {
        data.push_back(val);
    }
    void addAtIndex(int index, int val) {
        if (index < 0) { addAtHead(val); return; }
        if (index > data.size()) return;
        data.insert(data.begin() + index, val);
    }
    void deleteAtIndex(int index) {
        if (index < 0 || index >= data.size()) return;
        data.erase(data.begin() + index);
    }

private:
    deque<int> data;
};


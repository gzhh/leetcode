// Source : https://leetcode.com/problems/copy-list-with-random-pointer/
// Author : Zhonghuan Gao
// Date   : 2019-07-23

/********************************************************************************** 
*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

Example 1:
Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
 
Note:
You must return the copy of the given head as a reference to the cloned list.
*               
***********************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

/*
拷贝带有随机指针的链表
*/
class Solution {
public:
    /**
     * 解法一：
     * 如果给每个节点的随机指针赋值都要去遍历链表，那么会超时；
     * 所以可以用 HashMap 来减少给随机指针赋值时查找链表所耗的时间；
     * 第一遍遍历生成所有新节点时同时建立一个原节点和新节点的 HashMap，
     * 第二遍给随机指针赋值时，查找时间是常数级。
     */
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *res = new Node(head->val, nullptr, nullptr);
        Node *node = res, *cur = head->next;
        unordered_map<Node*, Node*> m;
        m[head] = res;
        while (cur) {
            Node *t = new Node(cur->val, nullptr, nullptr);
            node->next = t;
            m[cur] = t;
            node = node->next;
            cur = cur->next;
        }
        node = res; cur = head;
        while (cur) {
            node->random = m[cur->random];
            node = node->next;
            cur = cur->next;
        }
        return res;
    }

    /**
     * 解法二：递归解法
     */
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        return helper(head, m);
    }
    Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node) return nullptr;
        if (m.count(node)) return m[node];
        Node *res = new Node(node->val, nullptr, nullptr);
        m[node] = res;
        res->next = helper(node->next, m);
        res->random = helper(node->random, m);
        return res;
    }
};

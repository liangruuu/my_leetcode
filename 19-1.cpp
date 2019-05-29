/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead->next;
    int length = 0;
    while (cur != NULL) {
      length++;
      cur = cur->next;
    }
    int k = length - n;
    cur = dummyHead;
    for (int i = 0; i < k; i++) {
      cur = cur->next;
    }
    ListNode *delNode = cur->next;
    cur->next = delNode->next;
    delete delNode;

    ListNode *retNode = dummyHead->next;
    delete dummyHead;
    return retNode;
  }
};
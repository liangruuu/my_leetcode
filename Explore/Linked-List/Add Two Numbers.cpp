/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(-1);
    ListNode *tail = dummyHead;
    int extra = 0, sum;
    while (l1 || l2 || extra) {
      sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
      extra = sum / 10;
      tail->next = new ListNode(sum % 10);
      tail = tail->next;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }
    return dummyHead->next;
  }
};
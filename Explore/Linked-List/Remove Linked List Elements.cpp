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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode *pre = dummyHead;
    while (pre->next != NULL) {
      if (pre->next->val == val)
        pre->next = pre->next->next;
      else
        pre = pre->next;
    }
    return dummyHead->next;
  }
};
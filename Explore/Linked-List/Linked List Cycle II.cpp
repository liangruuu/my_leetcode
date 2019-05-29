// https://www.jianshu.com/p/1c59b153308c

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
  ListNode *detectCycle(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *slow = dummyHead;
    ListNode *fast = dummyHead;
    while (fast->next != NULL && fast->next->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        ListNode *first = dummyHead->next;
        while (first != slow) {
          slow = slow->next;
          first = first->next;
        }
        return first;
      }
    }
    return NULL;
  }
};
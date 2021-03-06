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
  ListNode *oddEvenList(ListNode *head) {
    if (head == NULL)
      return NULL;
    ListNode *odd = head, *even = head->next, *evenhead = even;
    while (even != NULL && even->next != NULL) { 
      even->next = even->next->next;
      odd->next = odd->next->next;
      even = even->next;
      odd = odd->next;
    }
    odd->next = evenhead;
    return head;
  }
};
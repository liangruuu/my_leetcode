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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyHead = new ListNode(-1);
    ListNode *tail = dummyHead;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummyHead->next;
  }
};

// 递归做法
// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//   if (l1 == NULL)
//     return l2;
//   if (l2 == NULL)
//     return l1;
//   if (l1->val < l2->val) {
//     l1->next = mergeTwoLists(l1->next, l2);
//     return l1;
//   } else {
//     l2->next = mergeTwoLists(l1, l2->next);
//     return l2;
//   }
// }
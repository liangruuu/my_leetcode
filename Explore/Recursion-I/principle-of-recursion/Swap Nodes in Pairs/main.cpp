#include <iostream>

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    ListNode *first, *second;
    while(cur->next != NULL && cur->next->next != NULL){
      first = cur->next;
      second = cur->next->next;
      first->next = second->next;
      cur->next = second;
      cur->next->next = first;
      cur = first;
    }
    return dummyHead->next;
  }
};

int main() {
  return 0;
}
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if(head == NULL && head->next == NULL)
      return 0;
    ListNode *p = head->next;
    head->next = swapPairs(p->next);
    p->next = head;
    return p;
  }
};

int main() {
  cout << "hello" << endl;
  return 0;
}
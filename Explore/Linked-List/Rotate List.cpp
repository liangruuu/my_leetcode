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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode *slow = dummyHead, *fast = dummyHead;
    int length = 0;
    while (fast->next != NULL) {
      fast = fast->next;
      length++;
    }
    for (int i = length - k % length; i > 0; i--) {
      slow = slow->next;
    }
    // 先把整个环构成
    fast->next = dummyHead->next;
    dummyHead->next = slow->next;
    slow->next = NULL;
    return dummyHead->next;
  }
};

// 下次遇到这种旋转链表的题目先把整个链表元素重复写一遍构造一个一维的'环'
// 5 . 1相连的部分需要用代码特别表示
// 类似'tail->next(链表尾节点->next) = dummyHead->next(链表头结点->next)'
// 1 2 3 4 5 . 1 2 3 4 5
// 此题的意思是向右平移k个单位, 即slow指针向右移动(length - k % length)个单位
// s
//   1 2 3 4 5
//       1 2 3 4 5
//       s
// slow指针向右移动了3(5-2)个单位
// 从而找到dummyHead的下一个节点
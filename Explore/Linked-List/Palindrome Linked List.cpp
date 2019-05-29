// https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/discuss/64501/Java-easy-to-understand

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
private:
  ListNode *reverse(ListNode *head) {
    ListNode *prev = NULL;
    while (head != NULL) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }

public:
  bool isPalindrome(ListNode *head) {
    ListNode *fast = head, *slow = head;
    // 获取链表中间节点元素的方法是：使用两个指针不同step长度的指针
    // 一个step=2, 一个step=1, 同时遍历则当step=2的指针遍历完链表后,step=1的指针还处在链表中间
    while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast != NULL) {
      slow = slow->next;
    }
    slow = reverse(slow);
    fast = head;
    while (slow != NULL) {
      if (fast->val != slow->val) {
        return false;
      }
      fast = fast->next;
      slow = slow->next;
    }
    return true;
  }
};

// 因为单链表无法获得某个节点之前的节点元素,所以不能按照数组那样子判断回文数
// 其中一个方法是对于链表后一半部分转置链表,然后逐位判断各个节点上的元素值是否相同
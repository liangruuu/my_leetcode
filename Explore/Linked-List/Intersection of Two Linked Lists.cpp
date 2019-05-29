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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL)
      return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;

      if (p1 == p2)
        return p1;

      if (p1 == NULL)
        p1 = headB;
      if (p2 == NULL)
        p2 = headA;
    }

    return p1;
  }
};

// 如果两个List相交, 那么从相交点开始, 后面的Node是公共的,
// 想象着把两个List从后面开始对齐, 解题思路就比较清晰了:
// 需要把长链表前面的多余部分过滤掉, 然后逐个比较Node的地址.
// 先遍历两个List找到两者的长度, 然后长链表的指针先走|lenA-lenB|,
// 接着两个指针一起走, 边走边比较.

// 我们的目的是让两个指针差距两个列表长度差,
// 一个方法是让两个指针都遍历一遍各自的链表,短的链表先被访问完,
// 此时处于短链表上的指针转向长链表的头结点,再等长链表上的指针遍历完转向短链表的头结点,
// 此时两指针后面的节点个数相同

// 还有一种方法就是先计算两个链表的长度,先让长链表的指针先动length个位置,之后一起遍历
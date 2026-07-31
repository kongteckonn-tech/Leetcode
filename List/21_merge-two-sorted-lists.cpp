/*
Pattern: Two Pointers (In-place Merge)

Approach:
- Handle the edge case where one list is empty.
- Choose the smaller head as the merged list's head.
- Use `cur` to traverse the merged list.
- Use `next` to represent the head of the other list.
- If `next->val` is smaller than `cur->next->val`,
  insert `next` before `cur->next`.
- Otherwise, move `cur` forward.
- After one list is exhausted, attach the remaining nodes.

Key Insight:
- Reuse the original nodes instead of creating new ones.
- Always keep one list as the main list and insert nodes
  from the other list into the correct position.

Complexity:
- Time: O(m + n)
    - Each node is visited at most once.
- Space: O(1)
    - No extra list is created.

Takeaway:
- For merging sorted linked lists,
  think → Two Pointers + In-place Merge.
- A dummy node solution is usually simpler,
  but in-place insertion achieves the same result
  with O(1) extra space.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL || list2 == NULL)
            return list1 == NULL ? list2 : list1;
        ListNode* head;
        int size;
        head = list1->val < list2->val ? list1 : list2;
        ListNode* cur = head;
        ListNode* next = list1->val < list2->val ? list2 : list1;
        while (cur->next != NULL && next != NULL)
        {
            if (next->val <= cur->next->val)
            {
                ListNode* tmp = cur->next;
                cur->next = next;
                next = tmp;
            }
            cur = cur->next;
        }
        if (next != NULL)
            cur->next = next;
        return head;
    }
};

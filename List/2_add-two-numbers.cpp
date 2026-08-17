/*
Pattern: Linked List (Addition + Carry)

Approach:
- First, calculate the lengths of `l1` and `l2`.
- Use the longer linked list as the result list, so we can
  reuse its existing nodes instead of creating a new list.
- Create a dummy node pointing to the longer list.
- Traverse `l1` and `l2` together and add their values
  together with the carry `more`.
- If the sum is greater than or equal to 10, subtract 10
  and set `more = 1`.
- Continue processing the remaining nodes of the longer list.
- After all nodes are processed, if there is still a carry,
  create one additional node with value `1`.
- Return `dummy->next`.

Key Insight:
- The numbers are stored in reverse order, so we can add
  them from the head directly, just like normal addition
  from right to left.
- `more` stores the carry from the previous digit.
- Reuse the longer linked list to store the result, reducing
  the number of new nodes needed.
- The dummy node makes it easier to return the resulting list.

Complexity:
- Time: O(n + m)
    - Traverse both linked lists to calculate their lengths
      and perform the addition.
- Space: O(1) extra space
    - Only a few pointers and variables are used.
    - Only one extra node may be created for the final carry.

Takeaway:
- Linked List Addition
  → Find the longer list → Reuse it as the result.
- Add corresponding digits with `carry`.
- Sum >= 10 → subtract 10 and carry `1`.
- After processing everything, if carry remains,
  create a new node.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int more = 0;
        int len1 = 0, len2 = 0;
        ListNode* tmp = l1;
        while (tmp)
        {
            len1++;
            tmp = tmp->next;
        }
        tmp = l2;
        while (tmp)
        {
            len2++;
            tmp = tmp->next;
        }
        ListNode* dummy = new ListNode(-1, len1 > len2 ? l1 : l2);
        tmp = dummy;
        while (l1 && l2)
        {
            tmp->next->val = l1->val + l2->val + more;
            if (tmp->next->val >= 10)
            {
                tmp->next->val -= 10;
                more = 1;
            }
            else more = 0;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            tmp->next->val = l1->val + more;
            if (tmp->next->val >= 10)
            {
                tmp->next->val -= 10;
                more = 1;
            }
            else more = 0;
            tmp = tmp->next;
            l1 = l1->next;
        }
        while (l2)
        {
            tmp->next->val = l2->val + more;
            if (tmp->next->val >= 10)
            {
                tmp->next->val -= 10;
                more = 1;
            }
            else more = 0;
            tmp = tmp->next;
            l2 = l2->next;
        }
        if (more == 1)
        {
            ListNode* node = new ListNode(1);
            tmp->next = node; 
        }
        return dummy->next;
    }
};

/*
Pattern: Stack (LIFO)

Approach:
- Traverse the linked list and push every node's
  value into a stack.
- Traverse the list again from the head.
- Compare each node's value with the top of the stack.
- If any pair of values differs, return false.
- If all values match, the linked list is a palindrome.

Key Insight:
- A stack reverses the order of elements naturally.
- Comparing the original traversal with the reversed
  order determines whether the list is a palindrome.

Complexity:
- Time: O(n)
    - The list is traversed twice.
- Space: O(n)
    - The stack stores all node values.

Takeaway:
- For palindrome linked list problems,
  think → Stack for reverse-order comparison.
- A stack provides a simple solution, though it
  requires O(n) extra space.
*/
 #include<stack>
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> check;
        ListNode* tmp = head;
        while (tmp)
        {
            check.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp)
        {
            if (tmp->val != check.top())
                return false;
            check.pop();
            tmp = tmp->next;
        }
        return true;
    }
};

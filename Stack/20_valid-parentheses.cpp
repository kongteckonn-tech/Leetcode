/*
Pattern: Stack
Idea:
- Use a stack to store opening brackets.
- Brackets must be closed in the reverse order they appear.
- Stack follows LIFO (Last In First Out), which matches the requirement.
- Use a hashmap to store matching pairs:
    ')' -> '('
    ']' -> '['
    '}' -> '{'

My Approach:
- First tried using an array to count each type of bracket.
- Counted opening brackets and decreased when encountering closing brackets.
- This approach failed because it only checks the quantity, not the order.
- Example:
    "([)]"
    The counts are correct, but the bracket order is invalid.
- Improved the solution by using stack + hashmap.

Optimal Approach:
- Traverse the string from left to right.
- If the character is an opening bracket:
    Push it into the stack.
- If the character is a closing bracket:
    - Check if the stack is empty.
        Return false because there is no matching opening bracket.
    - Compare the top of the stack with the expected opening bracket.
        If they do not match, return false.
    - Otherwise, pop the opening bracket.
- At the end:
    The stack must be empty to be valid.

Key Insight:
- Matching brackets require checking the most recent unmatched opening bracket.
- LIFO behavior makes stack the natural data structure for this problem.
- Counting brackets is not enough because order matters.
- Hashmap avoids writing multiple conditions for matching pairs.

Key STL:
stack<char>
unordered_map<char, char>

Time:
- Optimal approach: O(n)
    - Each character is processed once.
Space:
- Optimal approach: O(n)
    - In the worst case, all characters are opening brackets and stored in the stack.

Mistakes:
- Initially used counting array to track brackets.
- ASCII comparison is less readable and can introduce unexpected issues.

Takeaway:
- When a problem requires matching pairs in reverse order:
    Think → Stack.
- Always check whether order matters, not only frequency.
- Use hashmap to simplify pair matching logic.
- Choose data structures based on the behavior required by the problem.
*/
#include<stack>
class Solution {
public:
    bool isValid(string s) { 
        if (s.empty())
            return false;
        stack<char> st;
        unordered_map<char,char> mp = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        for (char ch : s)
        {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}')
            {
                if (st.size() == 0)
                    return false;
                else if (mp[ch] == st.top())
                    st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

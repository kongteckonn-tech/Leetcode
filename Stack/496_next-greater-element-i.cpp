/*
Pattern: Monotonic Decreasing Stack + HashMap
Approach:
- Use nums2 to build the relationship:
    number -> next greater element
- Traverse nums2 from left to right.
- Store numbers that have not found their next greater element
  in a stack.
- When the current number is greater than the stack top:
    - The stack top has found its next greater element.
    - Store the result in hashmap.
    - Pop the resolved number.
- After traversing nums2:
    - Remaining numbers in the stack do not have a greater element.
    - Their answer is -1.
- Traverse nums1 and use hashmap to get the result.

Key Insight:
- The stack stores unresolved numbers.
- A larger future number can solve multiple previous numbers.
- HashMap avoids searching nums2 repeatedly.
- Monotonic stack reduces repeated scanning.

Complexity:
- Time: O(n + m)
    - n = nums2 size
    - m = nums1 size
    - Each element is pushed and popped at most once.
- Space: O(n)
    - Stack and hashmap store nums2 information.

Takeaway:
- For "next greater element" problems:
    Think → Monotonic Stack.
- If the answer needs to be reused for another array:
    Build a HashMap first, then query.
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> mp;
        vector<int> ret;
        for (int cur : nums2)
        {
            if (st.empty())
            {
                st.push(cur);
                continue;
            }
            while (!(st.empty()) && cur > st.top())
            {
                mp[st.top()] = cur;
                st.pop();
            }
            st.push(cur);
        }
        for (int cur : nums1)
        {
            if (mp.find(cur) == mp.end())
                ret.push_back(-1);
            else
                ret.push_back(mp[cur]);
        }
        return ret;
    }
};

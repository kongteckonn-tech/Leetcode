/*
Pattern: Sliding Window / Two Pointers

Problem:
- Find the length of the longest substring without repeating characters.

Idea:
- Use a sliding window to maintain a substring with unique characters.
- Expand the window by moving the right pointer.
- If a duplicate character appears:
    - Shrink the window by moving the left pointer.
    - Remove characters from the set until the duplicate is gone.
- Keep updating the maximum window size.

My Approach:
- Used a set to store all unique characters in the current window.
- Used two pointers:
    - `right` to expand the window.
    - `left` to shrink the window when a duplicate is found.
- If the current character does not exist in the set:
    - Insert it and move `right`.
- Otherwise:
    - Remove `s[left]` and move `left`.
- Update the maximum size after each operation.

Optimal Approach:
- Same sliding window idea.
- A faster implementation uses:
    unordered_set<char>
    instead of
    set<char>
- An even better approach uses:
    unordered_map<char, int>
    to store the last occurrence of each character.
- Instead of removing one character at a time, jump `left` directly:
    left = max(left, lastIndex + 1);
- This reduces unnecessary operations and keeps O(n) time.

Key Insight:
- The window must always contain unique characters.
- Expand whenever possible.
- Shrink only when a duplicate appears.
- Every character enters and leaves the window at most once.
- The current window length can be calculated by:
    right - left

Key STL:
set<char>
unordered_set<char>
unordered_map<char, int>
max()

Time:
- My approach: O(n log n)
    - Each insert, erase, and contains operation on a set takes O(log n).
- Optimal approach: O(n)
    - Using unordered_set or unordered_map gives average O(1) operations.

Space:
- My approach: O(min(n, charset))
- Optimal approach: O(min(n, charset))

Mistakes:
- Used set instead of unordered_set, causing unnecessary O(log n) operations.
- Didn't realize a hash map can jump the left pointer directly instead of removing characters one by one.
- Used the special case:
    left == right
  which is unnecessary because the duplicate check alone is sufficient.

Takeaway:
- For substring problems involving uniqueness:
    Think → Sliding Window + Hash Set / Hash Map.
- If only checking existence:
    Use unordered_set.
- If needing the last position of a character:
    Use unordered_map<char, int>.
- Prefer hash-based containers over tree-based containers when ordering is unnecessary.
*/
#include<set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxSub = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            if (left == right || !(st.contains(s[right])))
            {
                st.insert(s[right++]);
            }
            else
            {
                st.erase(s[left++]);
            }
            maxSub = std::max((int)st.size(), maxSub);
        }
        return maxSub;
    }
};

/*
Pattern: Sliding Window (Two Pointers + Frequency Count)

Approach:
- Use two frequency arrays:
    - `need` stores the required count of each character in `t`.
    - `window` stores the current count of each character in the window.
- Expand the window by moving the right pointer.
- When a required character is added, update the matched count.
- Once all characters in `t` are covered, try shrinking
  the window by moving the left pointer.
- Update the minimum window whenever a smaller valid
  window is found.
- Continue until the right pointer reaches the end.

Key Insight:
- The window is valid when all required characters
  (including duplicates) are matched.
- Expand the window to satisfy the requirement.
- Shrink the window to find the shortest valid substring.

Complexity:
- Time: O(n)
    - Each character is visited at most twice
      (once by the right pointer and once by the left pointer).
- Space: O(1)
    - Two fixed-size frequency arrays (ASCII 128).

Takeaway:
- For minimum window substring,
  think → Expand to satisfy, shrink to optimize.
- Frequency arrays allow O(1) character lookup,
  making the sliding window efficient.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char c : t)
            need[c]++;
        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (window[c] <= need[c])
                count++;
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char remove = s[left];
                if (window[remove] <= need[remove])
                    count--;
                window[remove]--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

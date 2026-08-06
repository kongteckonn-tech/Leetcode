/*
Pattern: Fixed Sliding Window (Frequency Count)

Approach:
- Count the frequency of each character in `p`.
- Use a fixed-size sliding window with length `p.size()`.
- Expand the window by moving the right pointer and
  updating the current frequency.
- If the window exceeds the target length, remove the
  leftmost character and move the left pointer.
- When the window size equals `p.size()`, compare the
  current frequency with the target frequency.
- If they match, record the starting index.

Key Insight:
- The window size is always fixed to `p.size()`.
- Every expansion may require one shrink to keep
  the window valid.
- Two strings are anagrams if their character
  frequencies are identical.

Complexity:
- Time: O(n)
    - Each character enters and leaves the window once.
    - Comparing two frequency arrays of size 26 is O(1).
- Space: O(1)
    - Two fixed-size frequency arrays.

Takeaway:
- For anagram problems with a fixed substring length,
  think → Fixed Sliding Window + Frequency Count.
- A frequency array provides constant-time updates
  and easy anagram comparison.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};
        vector<int> freP(26, 0);
        vector<int> meet(26, 0);
        vector<int> ret;
        int left = 0, right = 0;
        for (char cur : p)
            freP[cur - 'a']++;
        while (right < s.length())
        {
            if (right - left <= p.length() - 1)
            {
                meet[s[right] - 'a']++;
                right++;
            }
            else
            {
                meet[s[left] - 'a']--;
                left++;
            }
            if (freP == meet)
                ret.push_back(left);
        }
        return ret;
    }
};

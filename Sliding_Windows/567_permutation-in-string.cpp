/*
Pattern: Sliding Window + Frequency Array (Hash Table)

Idea:
      First idea:
      - Generate every permutation of s1 and check whether it appears in s2.
      - Time complexity is O(m! * n), impossible for large input.

      Second idea:
      - For every substring of length s1.size() in s2, recount the frequency
        of all characters and compare with s1.
      - Works correctly but repeatedly counting frequencies costs O(26*n).

      Best idea (Fixed Sliding Window):
      - Count the frequency of each character in s1 using a frequency array.
      - Maintain a fixed-size sliding window (length = s1.size()) over s2.
      - As the window moves:
            * Remove the left character if the window becomes too large.
            * Add the new right character.
      - After each move, compare the window frequency array with the target
        frequency array.
      - If all 26 counts match, a permutation exists.

Key STL:
      - None (fixed-size int[26] arrays)
      - (Alternative: vector<int>(26))

Time:
      - Brute Force (generate permutations): O(m! * n)
      - Recount frequency every window: O(26 * n)
      - Sliding Window + Frequency Array: O(26 * n) ≈ O(n)

Space:
      - Frequency arrays: O(26) ≈ O(1)

Mistakes:
      - Forgetting the window size must always equal s1.size().
      - Removing the left character after adding the right one in the wrong order.
      - Comparing frequencies before the window reaches the correct size.
      - Trying to generate permutations instead of comparing character counts.

Takeaway:
      - If order doesn't matter but character composition does,
        compare frequency counts instead of strings.
      - Fixed-size sliding windows are ideal when every valid answer
        has the same length.
      - When the alphabet size is fixed (26 lowercase letters),
        comparing two frequency arrays is constant time.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int need[26] = { 0 };
        int windows[26] = { 0 };
        int right = 0, left = 0;
        for (char cur : s1)
            need[cur - 'a']++;
        for (; right < s2.size(); right++)
        {
            if (right - left >= s1.size())
                windows[s2[left++] - 'a']--;
            windows[s2[right] - 'a']++;
            int i = 0; 
            for (i = 0; i < 26; i++)
            {
                if (need[i] != windows[i])
                    break;
            }
            if (i == 26)
                return true;
        }
        return false;
    }
};

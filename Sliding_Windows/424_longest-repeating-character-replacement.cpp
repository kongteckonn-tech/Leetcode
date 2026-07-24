/*
Pattern: Sliding Window + Frequency Array
Idea:
      First idea:
      - Enumerate every possible substring.
      - Count the frequency of each character in the substring.
      - If (substring length - highest frequency) <= k,
        update the answer.
      - Time complexity is O(n² * 26), too slow.
      
      Best idea (Sliding Window + Max Frequency):
      - Maintain a sliding window and a frequency array.
      - Keep track of the highest frequency (maxFreq) inside the window.
      - A window is valid if:
            windowSize - maxFreq <= k
        because the remaining characters can all be replaced.
      - If the window becomes invalid, shrink it from the left.
      - Update the maximum valid window length.

Key STL:
      - vector<int>
Time:
      - Brute Force: O(n² * 26)
      - Sliding Window (maintain maxFreq): O(n)
Space:
      - Frequency array: O(26) ≈ O(1)
Mistakes:
      - Forgetting that the replacement cost is:
            windowSize - maxFreq
        instead of counting all different characters.
      - Trying to decrease maxFreq when shrinking the window.
        It is intentionally kept as the historical maximum because
        it never affects correctness and preserves O(n) complexity.
      - Updating the answer before restoring the window to a valid state.

Takeaway:
      - For "replace at most k characters" problems,
        the key is identifying the dominant character.
      - A window is valid when all non-dominant characters can be
        replaced within k operations.
      - Sometimes maintaining a historical maximum (maxFreq) is enough;
        it doesn't need to exactly match the current window, which
        simplifies the implementation and keeps the algorithm O(n).
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxFreq = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

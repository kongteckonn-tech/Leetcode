/*
Pattern: Sliding Window (Queue)

Approach:
- Use a queue to represent the current substring
  without repeating characters.
- Traverse the string one character at a time.
- If the current character already exists in the queue,
  repeatedly remove characters from the front until
  the duplicate is removed.
- Add the current character to the queue.
- Update the maximum length after each insertion.

Key Insight:
- The queue always stores a substring with
  unique characters.
- Removing characters from the front shrinks
  the window until it becomes valid again.

Complexity:
- Time: O(n²)
    - `queue.contains()` takes O(n), making the
      overall complexity quadratic in the worst case.
- Space: O(n)
    - The queue stores at most all unique characters
      in the current window.

Takeaway:
- For longest substring without repeating characters,
  think → Sliding Window.
- A queue provides an intuitive solution, but using
  a HashSet or HashMap can optimize the lookup to O(1),
  reducing the overall time complexity to O(n).
*/
import java.util.LinkedList;
import java.util.Queue;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLen = 0;
        Queue<Character> queue = new LinkedList<>();
        for (int i = 0; i < s.length(); i++)
        {
            while (queue.contains(s.charAt(i)))
            {
                queue.remove();
            }
            queue.add(s.charAt(i));
            maxLen = maxLen > queue.size() ? maxLen : queue.size();
        }
        return maxLen;
    }
}

/*
Pattern: Variable Sliding Window (Hash Map)

Approach:
- Use a sliding window to represent the current
  subarray of fruits.
- Use a Hash Map to count the frequency of each fruit
  type inside the window.
- Expand the window by moving the right pointer.
- If the window contains more than 2 different fruit
  types, shrink the window by moving the left pointer.
- Remove a fruit type from the map when its frequency
  becomes 0.
- After the window becomes valid, update the maximum
  window length.

Key Insight:
- The window can contain at most 2 different fruit types.
- When there are more than 2 types, move `left` until
  the window becomes valid again.
- `right - left` represents the current window length
  because `right` points to the next position to process.

Complexity:
- Time: O(n)
    - Each fruit enters and leaves the window at most once.
- Space: O(1)
    - The Hash Map stores at most 3 fruit types during
      the shrinking process, so the extra space is constant.

Takeaway:
- For longest subarray with at most K different elements,
  think → Variable Sliding Window + Hash Map.
- Expand the window, shrink when the condition is violated,
  then update the maximum length.
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        unordered_map<int, int> mp;
        int maxTree = 0;
        while (right < fruits.size())
        {
            mp[fruits[right]]++;
            right++;
            while (mp.size() > 2)
            {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            maxTree = maxTree > right - left ? maxTree : right - left;
        }
        return maxTree;
    }
};

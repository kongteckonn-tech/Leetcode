/*
Pattern: Two Pointers + Greedy

Idea:
- Place one pointer at the left end and one at the right end.
- The container's area is determined by:
    - Height = min(height[left], height[right])
    - Width = right - left
- Calculate the current area and update the maximum area.
- Move the pointer with the shorter height inward because the shorter wall limits the current area.
- Moving the taller wall only decreases the width while the limiting height remains unchanged, so it cannot produce a larger area.

Optimal Approach:
- Initialize two pointers:
    - left = 0
    - right = n - 1
- While left < right:
    1. Calculate the current area.
    2. Update the maximum area.
    3. Move the pointer with the smaller height inward.
- Continue until the two pointers meet.

Key Insight:
- The shorter wall always limits the container's height.
- Width decreases every move, so the only chance to increase the area is to find a taller shorter wall.
- There is no need to check every pair because moving the taller pointer can never produce a better result.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- I initially used `while (left <= right)` instead of `while (left < right)`.
  When left == right, the width is 0, so this iteration is unnecessary.
- I initialized `MaxArea` with `INT_MIN`.
  Since area is never negative, initializing it to 0 is cleaner.
- I declared an unused variable (`h`) that should be removed.

Takeaway:
- Two pointers can reduce a brute-force O(n²) solution to O(n).
- In greedy two-pointer problems, always identify which pointer cannot contribute to a better answer.
- When one factor (width) always decreases, focus on improving the other factor (height).
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int MaxArea = 0, area = 0;
        while (left <= right) /* -> while (left < right) */
        {
            area = min(height[left], height[right]) * (right - left);
            MaxArea = max(MaxArea, area);
            if (height[right] < height[left])
                right--;
            else left++;
        }
        return MaxArea;
    }
};

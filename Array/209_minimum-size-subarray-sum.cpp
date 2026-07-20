/*
Pattern: Sliding Window / Two Pointers

Problem:
- Find the minimum length of a contiguous subarray whose sum is greater than or equal to target.

Idea:
- Use a sliding window to maintain a current subarray.
- Expand the window by moving the right pointer.
- When the sum becomes >= target:
    - Update the minimum length.
    - Shrink the window by moving the left pointer.
- Continue until all possible windows are checked.

My Approach:
- Tried to maintain the window size manually using a variable `sub`.
- Used two pointers:
    - `right` to expand the window.
    - `left` to remove elements when the sum reaches the target.
- The idea was correct, but manually updating the window length caused logic problems.

Problems:
- Initialized `sub` incorrectly because the window starts empty.
- Window length tracking became difficult to maintain.
- The loop condition stopped before checking all possible shrinking cases.
- Needed an additional while loop to handle remaining valid windows.

Optimal Approach:
- Use `right - left + 1` to calculate the current window length directly.
- Use a variable `ans` to store the smallest valid window size.
- For each element:
    - Add nums[right] into sum.
    - While sum >= target:
        - Update answer.
        - Remove nums[left].
        - Move left forward.
- Return 0 if no valid subarray exists.

Key Insight:
- Sliding window works because all numbers are positive.
- Expanding the window increases the sum.
- Shrinking the window decreases the sum.
- Once the sum reaches target, try removing unnecessary elements to get the smallest length.
- Avoid manually tracking window size when it can be calculated by:
    right - left + 1

Key STL:
vector<int>
min()

Time:
- My approach: O(n)
- Optimal approach: O(n)
    - Each element is added and removed at most once.

Space:
- My approach: O(1)
- Optimal approach: O(1)
    - Only uses variables for pointers and sum.

Mistakes:
- Tried to manually increase/decrease the window length.
- Did not fully understand that the left pointer should keep moving while the condition is satisfied.
- Used extra logic to handle remaining windows instead of integrating it into the main loop.

Takeaway:
- For sliding window problems:
    Think → Expand first, then shrink when the condition is satisfied.
- Do not manually track window length; calculate it using:
    right - left + 1
- When the array contains only positive numbers, sliding window is usually a good approach.
- Always look for opportunities to shrink the window and make the answer optimal.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int ans = nums.size() + 1;
        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while (sum >= target)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};

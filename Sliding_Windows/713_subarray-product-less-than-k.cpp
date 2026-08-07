/*
Pattern: Variable Sliding Window (Two Pointers)

Approach:
- Maintain a sliding window whose product is always
  less than `k`.
- Expand the window by moving the right pointer and
  multiplying the current element into the product.
- While the product is greater than or equal to `k`,
  shrink the window by dividing out the leftmost
  element and moving the left pointer.
- Once the window is valid, every subarray ending at
  `right` is valid.
- Add `right - left + 1` to the answer.

Key Insight:
- The window always satisfies `product < k`.
- If the entire window is valid, then every suffix
  of the window ending at `right` is also valid.
- The number of valid subarrays ending at `right`
  is exactly `right - left + 1`.

Complexity:
- Time: O(n)
    - Each element enters and leaves the window once.
- Space: O(1)
    - Only constant extra variables are used.

Takeaway:
- For subarray problems with a product/sum constraint,
  think → Variable Sliding Window.
- Instead of checking every subarray, count all valid
  subarrays ending at each `right` pointer.
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int product = 1;
        int right = 0, left = 0;
        for (right = 0; right < nums.size(); right++)
        {
            product *= nums[right];
            while (product >= k && left < nums.size())
            {
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

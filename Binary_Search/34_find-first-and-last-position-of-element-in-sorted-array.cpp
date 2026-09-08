/*
Pattern: Binary Search + Boundary Search

Approach:
- Perform Binary Search twice.

1. Find First Position:
- Normal Binary Search.
- If `nums[mid] < target`
    → go right.
- If `nums[mid] > target`
    → go left.
- If `nums[mid] == target`
    → save `mid` as `first`.
    → continue searching left with `right = mid - 1`.
- This finds the leftmost occurrence.

2. Find Last Position:
- Reset `left` and `right`.
- Perform Binary Search again.
- If `nums[mid] < target`
    → go right.
- If `nums[mid] > target`
    → go left.
- If `nums[mid] == target`
    → save `mid` as `last`.
    → continue searching right with `left = mid + 1`.
- This finds the rightmost occurrence.

Key Insight:
- Finding any target is not enough.
- First → when found, continue LEFT.
- Last → when found, continue RIGHT.
- `first` and `last` store the best position found so far.

Complexity:
- Time: O(log n)
    - Two Binary Searches:
      O(log n) + O(log n) = O(log n)
- Space: O(1)

Takeaway:
- 704 → Find target.
- 34 → Find target's boundaries.
- First:
    `target found → save → right = mid - 1`
- Last:
    `target found → save → left = mid + 1`

Pattern:
- Binary Search
- Find First / Last
- Boundary Search
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int first = -1, last = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
            else 
            {
                first = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target > nums[mid])
                left = mid + 1;
            else if (target < nums[mid])
                right = mid - 1;
            else 
            {
                last = mid;
                left = mid + 1;
            }
        }
        return {first, last};
    }
};

/*
Pattern: Binary Search

Approach:
- First solution:
    - Use Linear Search.
    - Check every element and keep the smallest value.
    - Time: O(n).

- Improved solution:
    - Use Binary Search.
    - Set `left`, `right`, and `mid`.
    - Check whether the left side is sorted:
        `nums[left] <= nums[mid]`
    - If the left side is sorted:
        - `nums[left]` is a possible minimum.
        - Save `nums[left]`.
        - Search the right side.
    - Otherwise:
        - The minimum is in the rotated part.
        - `nums[mid]` is a possible minimum.
        - Save `nums[mid]`.
        - Search the left side.
    - Keep updating `mini`.

Key Insight:
- The array is sorted but rotated.
- One side can be identified as sorted.
- If the left side is sorted:
    → `nums[left]` is a minimum candidate.
- Otherwise:
    → `nums[mid]` is a minimum candidate.
- Use Binary Search to eliminate half of the search space.

Complexity:
- First solution:
    - Time: O(n)
    - Space: O(1)

- Improved solution:
    - Time: O(log n)
    - Space: O(1)

Takeaway:
- Linear Search → check every element.
- Binary Search → use the rotated sorted property.
- `nums[left] <= nums[mid]`
    → left side is sorted
    → save `nums[left]`
    → go right.

- Otherwise
    → minimum is in the rotated part
    → save `nums[mid]`
    → go left.

Pattern:
- 704 → Basic Binary Search.
- 33 → Rotated Array + Binary Search.
- 153 → Rotated Array + Binary Search + Find Minimum.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // int mini = INT_MAX;
        // for (int i = 0; i < nums.size(); i++)
        //     mini = std::min(mini, nums[i]);
        // return mini; 
        int mini = INT_MAX;
        int left = 0;
        int right =  nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid])
            {
                mini = std::min(mini, nums[left]);
                left = mid + 1;
            }
            else
            {
                mini = std::min(mini, nums[mid]);
                right = mid - 1;
            }
        }
        return mini;
    }
};

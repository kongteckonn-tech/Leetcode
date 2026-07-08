/*
Pattern: Two Pointers (Fast & Slow Pointer)

Idea:
- My first idea was to use swapping.
- For each zero element, find the next non-zero element and swap them.
- This works, but repeated searching may cause unnecessary operations.
- After observing the pattern, I realized that we only need to keep track of the position where the next non-zero element should be placed.
- Use two pointers:
    - fast pointer scans the entire array.
    - slow pointer stores the position for the next non-zero element.

Key Insight:
- Move all non-zero elements to the front while maintaining their relative order.
- After placing all non-zero elements, fill the remaining positions with zeros.
- The array can be modified in-place without using extra space.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- My first approach used nested searching to find the next non-zero element.
- I did not initially recognize that this problem can be solved by separating:
    1. Moving valid elements.
    2. Filling remaining positions.

Takeaway:
- When modifying an array in-place, consider using two pointers.
- Fast pointer is usually used for scanning, while slow pointer tracks the position to update.
- The fast & slow pointer pattern is useful for array rearrangement problems.
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int j = i + 1;
        //     while (j < nums.size() && nums[j] == 0)
        //         j++;
        //     if (j < nums.size() && nums[i] == 0)
        //     {
        //         nums[i] = nums[j];
        //         nums[j] = 0;
        //     }
        // }
        int fast = 0, slow = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
                nums[slow++] = nums[fast];
        }
        for (; slow < nums.size(); slow++)
            nums[slow] = 0;
    }
};

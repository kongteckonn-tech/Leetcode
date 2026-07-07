/*
Pattern: Dynamic Programming (Kadane's Algorithm)

Idea:
- My first idea was to use brute force.
- For each starting index, keep extending the subarray to the right and calculate the sum.
- This requires checking all possible subarrays, resulting in O(n²).
- After observing the calculations, I realized only the current subarray sum is needed.
- At each element, compare:
    - Continue the current subarray.
    - Start a new subarray from the current element.
- Keep the larger one as the current sum and update the global maximum.

Key Insight:
- If the previous sum is negative, discard it and start a new subarray.
- cur = maximum subarray sum ending at the current index.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- I only thought about checking every subarray at first.
- I didn't realize the previous negative sum should be discarded.

Takeaway:
- When the previous result becomes a burden, start over from the current element.
- Kadane's Algorithm is a classic DP pattern for maximum subarray problems.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        int max = -10000, cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cur = 0;
            for (int j = i; j < nums.size(); j++)
            {
                cur += nums[j];
                if (cur > max)
                    max = cur;
            }
        }
        return max;
        */
        int max = INT_MIN, cur = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cur + nums[i] > nums[i])
                cur += nums[i];
            else cur = nums[i];
            max = cur > max ? cur : max;
        }
        return max;
    }
};

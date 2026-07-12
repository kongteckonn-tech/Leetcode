/*
Pattern: Sorting + Two Pointers

Idea:
- My first idea was to use priority_queue with greater<int> to sort the array.
- After sorting, fix one number as the first element of the triplet.
- Use two pointers to find the other two numbers:
    - left starts from i + 1.
    - right starts from the end of the array.
- Calculate:
    nums[i] + nums[left] + nums[right]
- If the sum is:
    - Greater than 0:
        Move right left because the sum is too large.
    - Smaller than 0:
        Move left right because the sum is too small.
    - Equal to 0:
        Store the triplet and move both pointers.

Optimal Approach:
- Sort the array first.
- Iterate through each possible first number:
    1. Skip duplicate values of i to avoid duplicate triplets.
    2. Initialize left and right pointers.
    3. Use two pointers to search for pairs that make the total sum equal to 0.
    4. After finding a valid triplet:
        - Move left and right inward.
        - Skip duplicate left/right values.
- Continue until all possible triplets are checked.

Key Insight:
- Sorting allows the two-pointer technique because:
    - Moving left increases the sum.
    - Moving right decreases the sum.
- Fixing one number reduces the problem from finding three numbers to finding two numbers.
- Duplicate handling is important because the answer requires unique triplets.

Key STL:
priority_queue<int, vector<int>, greater<int>>
vector<vector<int>>

Time: O(n²)
- Building priority_queue: O(n)
- Extracting all elements: O(n log n)
- Two pointer search: O(n²)

Space: O(n)
- Extra sortedNums vector is used to store the sorted array.

Mistakes:
- Initially used the original nums array for duplicate checking after sorting.
- Need to use sortedNums for all comparisons after sorting.
- Must skip duplicate values for i, left, and right to avoid repeated answers.
- Combining pointer movement inside push_back makes the code harder to read.

Takeaway:
- For 3Sum problems, think:
    Sort → Fix one number → Two pointers.
- Sorting is useful when we need to find unique combinations.
- When searching for pairs with a target sum, two pointers can reduce brute force O(n³) to O(n²).
- Always handle duplicates carefully when the problem asks for unique results.
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        vector<int> sortedNums = {};
        vector<vector<int>> ret = {};
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sortedNums.push_back(q.top());
            q.pop();
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && sortedNums[i] == sortedNums[i - 1])
                continue;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                if (sortedNums[i] + sortedNums[left] + sortedNums[right] == 0)
                {
                    ret.push_back({ sortedNums[i], sortedNums[left++], sortedNums[right--] });
                    while (left < right && (sortedNums[left] == sortedNums[left - 1]))
                        left++;
                    while (left < right && (sortedNums[right] == sortedNums[right + 1]))
                        right--;
                }
                else if (sortedNums[i] + sortedNums[left] + sortedNums[right] > 0)
                    right--;
                else left++;
            }
        }
        return ret;
    }
};

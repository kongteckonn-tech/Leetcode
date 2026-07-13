/*
Pattern: Prefix Sum + HashMap
Idea:
- My first idea was to use brute force:
    - Fix the starting index.
    - Expand the ending index.
    - Calculate the subarray sum.
    - If the sum equals k, increase the count.
- However, this takes O(n²) because many subarray sums are recalculated.
Optimal Approach:
- Use Prefix Sum and HashMap to reduce the time complexity to O(n).
- Prefix Sum represents the sum of elements from the beginning of the array to the current index.
- For each prefix sum:
    1. Update current prefix sum:
        prefix += nums[i]
    2. Check whether (prefix - k) exists in the HashMap.
    3. If it exists:
        - It means there is a previous prefix sum such that:
            prefix - previousPrefix = k
        - Therefore, the subarray between them has sum k.
        - Add the frequency of (prefix - k) to the answer.
    4. Store the current prefix sum into the HashMap.
Key Insight:
- A subarray sum can be calculated by:
    currentPrefix - previousPrefix = k
- Rearrange the equation:
    previousPrefix = currentPrefix - k
- Therefore, instead of checking every subarray,
  we only need to check whether (prefix - k) appeared before.
- HashMap stores:
    prefix sum : frequency
- Frequency is needed because the same prefix sum can appear multiple times,
  and each occurrence represents a different valid subarray.
Key STL:
unordered_map<int, int>
Time: O(n)
- Traverse the array once.
- HashMap lookup and insertion are O(1) average.
Space: O(n)
- HashMap stores all prefix sums and their frequencies.
Mistakes:
- Initially tried to use two pointers/sliding window.
- Sliding window does not work because the array may contain negative numbers,
  which breaks the monotonic property of the window sum.
- Need to initialize:
    mp[0] = 1
  to handle subarrays starting from index 0.
- Must store the current prefix sum after checking prefix - k.
- Need to add the frequency:
    ans += mp[prefix - k]
  instead of only increasing by 1 because the same prefix sum can appear multiple times.
Takeaway:
- For subarray sum problems, think:
    Prefix Sum → Find previousPrefix → HashMap
- If we need to find whether a continuous segment has a target sum,
  prefix sum can convert the problem into finding two prefix sums.
- HashMap helps store previous prefix sums and achieve O(n) time.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int sub = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int sum = 0;
        //     for (int j = i; j < nums.size(); j++)
        //     {
        //         sum += nums[j];
        //         if (sum == k)
        //             sub++;
        //     }
        // }
        // return sub;
        unordered_map<int, int> mp;
        mp[0]++;
        int sub = 0, prefix = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix += nums[i];
            if (mp[prefix - k] != 0)
                sub += mp[prefix - k];
            mp[prefix]++;
        }
        return sub;
    }
};

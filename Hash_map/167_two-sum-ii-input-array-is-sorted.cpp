/*
Pattern: Hash Map / Two Pointers (Best)
Idea:
      First idea:
      - Use brute force and check every pair of numbers.
      - Time complexity is O(n²), which is too slow.

      Second idea:
      - Use an unordered_map to store (number -> index).
      - Traverse the array again and check whether (target - nums[i]) exists.
      - If it exists and is not the current index, return the two indices.
      - This reduces the time complexity to O(n).

      Best solution:
      - Since the array is already sorted, use Two Pointers.
      - One pointer starts from the left, another from the right.
      - If the sum is too small, move the left pointer right.
      - If the sum is too large, move the right pointer left.
      - When the sum equals target, return both indices.
Key STL: unordered_map, vector
Time:
      - Brute Force: O(n²)
      - Hash Map: O(n)
      - Two Pointers (Best): O(n)
Space:
      - Brute Force: O(1)
      - Hash Map: O(n)
      - Two Pointers: O(1)
Mistakes:
      - Think two pointers method 
Takeaway:
      - Always check whether the input array is sorted.
      - For sorted arrays, think of Two Pointers before HashMap.
      - HashMap is a good choice for unsorted Two Sum problems.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      /* First Idea */
        // for (int i = 0; i < numbers.size(); i++)
        // {
        //     for (int j = i + 1; j < numbers.size(); j++)
        //     {
        //         if (numbers[i] + numbers[j] == target)
        //             return {i + 1, j + 1};
        //     }
        // }
        // return {1};
      /* Second Idea */
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i + 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[target - nums[i]] != 0 && mp[target - nums[i]] != i + 1)
                return {
                    i < mp[target - nums[i]] ? i + 1: mp[target - nums[i]], 
                    i > mp[target - nums[i]] ? i + 1: mp[target - nums[i]]
                    };
        }
        return {};
    }
};
// Best 
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1};
            else if (sum < target)
                left++;
            else
                right--;
        }
        return {};
    }
};
*/

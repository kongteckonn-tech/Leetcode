/*
Pattern: Greedy Algorithm (Boyer-Moore Voting Algorithm)

Idea:
- My first idea was to count the frequency of each number using unordered_map.
- For each number:
    - Store how many times it appears.
    - Find the number whose frequency is greater than n / 2.
- This solution works, but it requires extra space to store all frequencies.
- After observing the pattern, I realized that:
    - The majority element appears more than half of the array.
    - It cannot be completely cancelled by other elements.
    - We only need to track the current candidate and its vote count.

Optimal Approach:
- Traverse the array once using Boyer-Moore Voting Algorithm.
- Maintain:
    - candidate: the current possible majority element.
    - count: the current candidate's balance.
- For each number:
    1. If count becomes 0, choose the current number as the new candidate.
    2. If the number equals candidate:
        - Increase count.
    3. Otherwise:
        - Decrease count because different numbers cancel each other.
- The remaining candidate will be the majority element.

Key Insight:
- Majority element has more than n / 2 occurrences.
- Pairing it with all other elements cannot remove all of its occurrences.
- Different elements cancel each other out, and the majority element will remain.
- We do not need the actual frequency of every number.

Why It Works:
- count represents the balance between the candidate and other numbers.
- count > 0 means the candidate currently has an advantage.
- count == 0 means all previous candidates are cancelled, so we can choose a new candidate.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- My first approach stored every number's frequency using unordered_map.
- I did not initially realize that the majority element property allows cancellation.
- I kept unnecessary information instead of tracking only the current best candidate.

Takeaway:
- Greedy algorithms often keep only the best current state.
- When one element has a guaranteed advantage, we can use cancellation instead of counting.
- Always look for ways to reduce stored information:
    - Frequency map: O(n) space.
    - Boyer-Moore: O(1) space.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // int ave = nums.size() / 2;
        // for (auto it : nums)
        //     mp[it]++;
        // for (int it : nums)
        // {
        //     if (mp[it] > ave)
        //         return it;
        // }
        // return 0;
        int count = 0, candidate = 0;
        for (int num : nums)
        {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                count++;
            else count--;
        }
        return candidate;
    }

};

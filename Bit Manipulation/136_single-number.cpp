/*
Pattern: Bit Manipulation (XOR Operation)

Idea:
- My first idea was to use a frequency counting method such as unordered_map.
- For each number:
    - Count how many times it appears.
    - Return the number that appears only once.
- This solution works, but it requires extra space to store all frequencies.
- After observing the pattern, I realized that XOR has special properties:
    - A number XOR itself equals 0.
    - A number XOR 0 remains unchanged.
    - XOR operation is commutative, so the order does not matter.

Optimal Approach:
- Traverse the array once.
- Use XOR to cancel out duplicate numbers.
- Since every duplicated number appears twice:
    - num ^ num = 0
- The remaining number after all cancellations is the single number.
Key Insight:
- XOR automatically removes pairs of identical numbers.
- Example:
    [4,1,2,1,2]

    4 ^ 1 ^ 2 ^ 1 ^ 2

    (1 ^ 1) = 0
    (2 ^ 2) = 0

    Remaining:
    4
- We do not need to store frequency information.
- Only the current XOR result is needed.
Why It Works:
- XOR properties:
    1. x ^ x = 0
    2. x ^ 0 = x
    3. x ^ y ^ x = y
- All duplicate numbers cancel each other, leaving only the unique element.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- My first approach would focus on counting occurrences.
- I did not initially realize XOR can replace frequency counting.
- I stored unnecessary information instead of using the mathematical property of XOR.

Takeaway:
- Bit manipulation can reduce memory usage by using mathematical properties.
- When elements appear in pairs and one element is different, consider XOR.
- Always look for operations that naturally cancel unnecessary information.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = nums[0]; 
        for (int i = 1; i < nums.size(); i++)
        {
            single ^= nums[i];
        }
        return single;
    }
};

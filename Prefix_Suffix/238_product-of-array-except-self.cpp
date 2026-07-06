/*
Pattern: Prefix_Suffix
Idea: 
- My first idea was to multiply every element except nums[i].
- This requires checking every other element for each index, resulting in O(n²).
- I also considered using a hash map, but it was not suitable for this problem.
- After learning the solution, I realized the repeated calculations were the products of the left and right sides.
- Instead of recomputing them every time, we can preprocess:
    - Prefix product: product of all elements to the left.
    - Suffix product: product of all elements to the right.
- The answer for each index is:
    answer[i] = prefix[i] × suffix[i].

Optimization:
- Initially, this requires three arrays:
    - prefix[]
    - suffix[]
    - answer[]
- Since the final answer only needs the prefix values first, we can store the prefix products directly in answer[].
- During the second pass (right to left), maintain a variable right to represent the current suffix product.
- Multiply answer[i] by right, then update right *= nums[i].
- This removes the need for a suffix array and achieves O(1) extra space.

Example:
nums = [1, 2, 3, 4]

Prefix:
[1, 1, 2, 6]

Suffix:
[24, 12, 4, 1]

Answer:
Prefix × Suffix
= [24, 12, 8, 6]

Key STL: vector<int>, int 
Time: O(n)
Space: O(1)
Mistakes:
- I couldn't identify the Prefix/Suffix pattern.
- I didn't notice the repeated calculations.

Takeaway:
- Look for repeated calculations.
- Consider Prefix/Suffix when each answer depends on the left and right sides.
*/
class Solution {
public:
// first idea 
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret = {};
        for (int i = 0; i < nums.size(); i++)
        {
            int pro = 1;
            for (int j = 0;j < nums.size(); j++)
            {
                if (i == j)
                    continue;
                pro *= nums[j];
            }
            ret.push_back(pro);
        }
        return ret;
    }
    */

// ask for chat GPT
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer = {1};
        int right = 1;
        // Prefix
        for (int i = 1; i < nums.size(); i++)
        {
            answer.push_back(answer[i - 1] * nums[i - 1]);
        }
        // Suffix
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            answer[i] *= right;
            right *= nums[i];        
        }
        return answer;
    }
};

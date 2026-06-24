/*
Approach (First Idea):
- My initial thinking: two pointer and add two different values and find fixed target and return it
--------------------------------------------------
Optimal Approach:
- Key idea: Hesh Map (haven't learned)
- Why it works: don't know

Steps:
1.
2.
3.

Pattern / Concept:
- Hash Map 
- When to use this pattern:
- Trigger keywords:

Complexity:
Time: O(n2)
Space: O(1)

Mistakes / Lessons:
- What I got wrong: return value instead of index (the question request index)
- How to avoid it next time: read question properlly
*/
class Solution {
public:
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret{};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret{};
        for (int i = 0, j = 1; i < nums.size(); i++)
        {
            if (i == j)
            {    
                i = 0;
                j++;
            }
            if (nums[i] + nums[j] == target)
            {
                ret.push_back(i);
                ret.push_back(j);
                break;
            }
        }
        return ret;
    }
};

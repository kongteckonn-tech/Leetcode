/*
Approach (First Idea):
- My initial thinking: two pointer to point current and next pointer then combine two pointer values and find is it equal, if yes then true, otherwise false
--------------------------------------------------
Optimal Approach:
- Key idea: Hesh Map 
- Why it works: store and find

Steps:
1.store current value with a key(index) in map
2.find key with current value on map
3.if found return true, otherwise return false 

Pattern / Concept:
- Hash Map 
- When to use this pattern:
- Trigger keywords:

Complexity:
Time: O(n)
Space: O(n)

Mistakes / Lessons:
- What I got wrong: run time error when first solution 
- How to avoid it next time: think another solution 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /* Run Time Error
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
        */
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i];
            if (mp.count(tmp))
                return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};

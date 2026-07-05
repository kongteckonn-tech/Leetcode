/*
Pattern: Array
Idea: When I see the question I think I can use function in question 242 leetcode. In my opinion:
      - create STL to store return STL
      - nested for loop to determine and push string STL in return STL
      - Return ret
Key STL: vector<string>, vector<vector<string>>, string, int[]
Time: O(n2)
Space: O(1)
Mistakes: Not proficient in using STL
Takeaway: Using STL
*/
// Mine
class Solution {
public:
    bool isAnagram(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;
        int arr[26] = { 0 };
        for (int i = 0; i < s1.size(); i++)
            arr[s1[i] - 'a']++;
        for (int i = 0; i < s2.size(); i++)
        {
            if (arr[s2[i] - 'a'] == 0)
                return false;
            else arr[s2[i] - 'a']--;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret = {};
        for (int i = 0; i < strs.size(); i++)
        {
            for (int j = 0; j < ret.size(); j++)
            {
                if (isAnagram(ret[j][0], strs[i]))
                {
                    ret[j].push_back(strs[i]);
                    break;
                }
                if (j == ret.size() - 1)
                {
                    vector<string> tmp = { strs[i] };
                    ret.push_back(tmp);
                    break;
                }
            }
            if (i == 0)
                ret.push_back({ strs[i] });
        }
        return ret;
    }
};

// Best solution 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string str : strs)
        {
            int cnt[26] = {0};
            for (char c : str)
                cnt[c - 'a']++;
            string key;
            for (int i = 0; i < 26; i++)
            {
                key += '#';
                key += to_string(cnt[i]);
            }
            mp[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto& [key, value] : mp)
            ans.push_back(value);
        return ans;
    }
};

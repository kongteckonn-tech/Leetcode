/*
Pattern: Array
Idea: When I see this question, ia to use function in string class (string::find(), string::npos). And assume the length of both string can be defferent. Then I got stuck.
      And I reffered the official solution:
      - the both value must be same
      - since the characters only appear (a - z), create int array in size 26 to store how many times the charecters appear 
      - store how many character appear string s
      - check is the string t using same frequency with string s
      - if not return false, otherwise decrese that frequency
      - if everything good, then return true
Key STL: string, int[]
Time: O(n)
Space: O(1)
Mistakes: do not think that both string length are the same 
Takeaway: frequency
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        int arr[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a']++; 
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (arr[t[i] - 'a'] == 0)
                return false;
            else arr[t[i] - 'a']--;
        }
        return true;
    }
};

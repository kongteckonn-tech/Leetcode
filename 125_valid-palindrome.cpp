#include<cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (left < s.size() && (!isalnum(s[left])) )
                left++;
            while (right > -1 && (!isalnum(s[right])) )
                right--;
            if (left == s.size() || right == -1)
                break;
            if (s[left] >= 'A' && s[left] <= 'Z')
                s[left] = tolower(s[left]);
            if (s[right] >= 'A' && s[right] <= 'Z')
                s[right] = tolower(s[right]);
            if (s[left] != s[right])
                break;
            left++;
            right--;
        }
        if (left >= right)
            return true;
        else return false;
    }
};

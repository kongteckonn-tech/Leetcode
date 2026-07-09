/*
Pattern: Two Pointers
Idea: Use two pointers from both ends of the string.
      Skip all non-alphanumeric characters.
      Compare the lowercase version of both characters.
      If they are different, return false.
      Otherwise, continue moving both pointers until they meet.
Key STL: isalnum(), tolower(), string
Time: O(n)
Space: O(1)
Mistakes:
      - Initially converted uppercase letters manually instead of using tolower().
      - Used break and checked the result after the loop instead of returning false immediately.
      - Added unnecessary boundary checks because the while conditions already prevent out-of-range access.
Takeaway:
      - Two Pointers are useful when comparing elements from both ends.
      - Use isalnum() to skip unwanted characters.
      - Use tolower() directly when comparing characters.
*/
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
    // Cleaner version 
    /*
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
    */
};

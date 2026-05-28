class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if (rowIndex < 0)
            return ans;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> tmp(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                tmp[j] = ans[j-1] + ans[j];
            }
            ans = tmp;
        }
        return ans;
    }
};

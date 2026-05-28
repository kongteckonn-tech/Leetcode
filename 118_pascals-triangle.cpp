class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector <int>> v = {};
        if (numRows <= 0)
            return v;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> cur(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                cur[j] = v[i - 1][j - 1] + v[i - 1][j];
            }
            v.push_back(cur);
        }
        return v;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>::iterator buyday = prices.begin();
        vector<int>::iterator sellday = prices.begin();
        int max = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            buyday = *buyday < prices[i] ? buyday : prices.begin() + i;
            sellday = *sellday > prices[i] ? sellday : prices.begin() + i;
            if (buyday <= sellday)
                max = max >= *sellday - *buyday ? max : *sellday - *buyday;
            else
                sellday = buyday;
        }
        return max;
    }
};

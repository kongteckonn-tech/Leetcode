/*
Pattern: Greedy Algorithm (Track Minimum Price)

Idea:
- My first idea was to track the buying day and selling day using iterators.
- For each day, update:
    - The lowest price as the best buying opportunity.
    - The highest selling price after buying.
- Calculate the profit whenever the selling day is after the buying day.
- This solution works, but it keeps unnecessary information such as the exact buy day and sell day.
- After observing the pattern, I realized that we only need:
    - The minimum price seen so far.
    - The maximum profit possible.

Optimal Approach:
- Traverse the array once.
- For each price:
    1. Update the minimum buying price.
    2. Calculate the profit if selling today.
    3. Update the maximum profit.
- The best profit always comes from buying at the lowest price before today and selling at today's price.

Key Insight:
- The order of days matters:
    - Buy day must always happen before sell day.
- We do not need to know the actual buy/sell days.
- Only the best previous state (minimum price) is needed to make the current decision.

Key STL:
vector<int>

Time: O(n)
Space: O(1)

Mistakes:
- My first approach focused on tracking both buy day and sell day.
- I did not initially realize that the selling price only needs to compare with the lowest price before it.
- I stored more information than necessary.

Takeaway:
- Greedy problems often require keeping only the best previous state.
- For stock problems, always track the minimum buying price and calculate possible profit at each step.
- When future decisions only depend on the best previous value, avoid storing unnecessary information.
*/
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
// best
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minPrice = INT_MAX;
//         int maxProfit = 0;
//         for (int price : prices)
//         {
//             minPrice = min(minPrice, price);
//             maxProfit = max(maxProfit, price - minPrice);
//         }
//         return maxProfit;
//     }
// };

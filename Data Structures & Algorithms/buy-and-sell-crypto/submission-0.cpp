class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_till_now = INT_MAX, ans = 0;
        for (int i : prices) {
            min_till_now = min(i, min_till_now);
            ans = max(ans, i - min_till_now);
        }
        return ans;
    }
};

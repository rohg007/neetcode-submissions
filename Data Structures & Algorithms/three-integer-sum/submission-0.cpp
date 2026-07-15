class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int b = i;
            int a = 0, c = n -1;
            while (a < b && b < c) {
                int sum = nums[a] + nums[b] + nums[c];
                if (sum == 0) {
                    vector<int> res = {nums[a], nums[b], nums[c]};
                    if (s.find(res) == s.end())
                        ans.push_back(res);
                    s.insert(res);
                    a++;
                    c--;
                }
                else if (sum < 0) {
                    a++;
                } else {
                    c--;
                }
            }
        }
        return ans;
    }
};

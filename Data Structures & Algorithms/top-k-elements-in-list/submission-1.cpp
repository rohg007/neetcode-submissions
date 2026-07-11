class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<vector<int>> freq(n + 1, vector<int>(0));
        for(int i : nums) mp[i]++;
        for (auto p : mp) {
            freq[p.second].push_back(p.first);
        }
        for (int i = n; i >= 0; i--) {
            if (freq[i].empty()) continue;
            for (int j : freq[i]) {
                ans.push_back(j);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_set<int> s;
        unordered_set<int> explored;
        for (int i : nums) s.insert(i);
        for (int i : nums) {
            if (explored.find(i) != explored.end()) continue;
            if (s.find(i-1) == s.end()) {
                int temp = i;
                while(s.find(temp+1) != s.end()) {
                    temp++;
                    explored.insert(temp);
                }
                ans = max(ans, temp - i + 1);
                explored.insert(i);
            }
        }
        return ans;
    }
};


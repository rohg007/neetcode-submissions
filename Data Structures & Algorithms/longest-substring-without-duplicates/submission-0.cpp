class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        unordered_map<char, int> mp;
        int l = 0, r = 1, ans = 0;
        mp[s[l]]++;
        while (r < n) {
            mp[s[r]]++;
            while(l < r && mp[s[r]] > 1) {
                mp[s[l++]]--;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};

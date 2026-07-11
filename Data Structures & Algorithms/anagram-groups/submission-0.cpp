class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        for (string s : strs) {
            vector<int> v(26);
            for (char c : s) {
                v[c-'a']++;
            }
            mp[v].push_back(s);
        }
        for(auto v : mp) {
            ans.push_back(v.second);
        }
        return ans;
    }
};

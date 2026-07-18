class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp, tmp;
        for(char c : t) mp[c]++;
        int minSize = INT_MAX, l = 0, r = 0, ans = 0;
        int need = mp.size(), curr = 0;
        pair<int, int> res;
        for (int r = 0; r < s.size(); r++) {
            tmp[s[r]]++;
            if (mp.count(s[r]) && mp[s[r]] == tmp[s[r]]) curr++;
            while (need == curr) {
                if ((r - l + 1) < minSize) {
                    minSize = r - l + 1;
                    res = {l, r};
                }

                tmp[s[l]]--;
                if (mp.count(s[l]) && tmp[s[l]] < mp[s[l]]) {
                    curr--;
                }
                l++;
            } 
        }
        cout << l << " " << r << "\n";
        return minSize == INT_MAX ? "" : s.substr(res.first, minSize);
    }
};

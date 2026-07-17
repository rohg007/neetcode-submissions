class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> count(26), currCount(26);
        int i;
        for (i = 0; i < s1.size(); i++) {
            count[s1[i]-'a']++;
            currCount[s2[i]-'a']++;
        }
        if (count == currCount) return true;
        for (i = s1.size(); i < s2.size(); i++) {
            currCount[s2[i-s1.size()]-'a']--;
            currCount[s2[i] - 'a']++;
            if (count == currCount) return true;
        }
        return false;
    }
};

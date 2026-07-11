class Solution {
    int computeLCP(string s1, string s2) {
        int i = 0, j = 0;
        if (s1[0] != s2[0]) return -1;
        while (i + 1 < s1.size() && j + 1 < s2.size() && s1[i + 1] == s2[j + 1]) {
            ++i, ++j;
        }
        return i;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string smallest = strs[0];
        int lcp = INT_MAX;

        for (string s : strs) {
            lcp = min(lcp, computeLCP(s, smallest));
        }
        if (lcp == -1) return "";
        return smallest.substr(0, lcp + 1);
    }
};
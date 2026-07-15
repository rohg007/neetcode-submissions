class Solution {
    string clean(string s) {
        string res = "";
        for (char c : s) {
            if (c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
                res += c;
        }
        return res;
    }
public:
    bool isPalindrome(string s) {
        s = clean(s);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};

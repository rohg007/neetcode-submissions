class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> mp;
        mp['}'] = '{';
        mp[']'] = '[';
        mp[')'] = '(';
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else if (st.empty() || st.top() != mp[c]) return false;
            else st.pop();
        }
        return st.empty();
    }
};

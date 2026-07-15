class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (string t : strs) {
            int n = t.size();
            s+=to_string(n);
            s+='#';
            s+=t;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            string size = "";
            while(s[i] != '#') {
                size += s[i++];
            }
            i++;
            int len = stoi(size);
            res.push_back(s.substr(i, len));
            i += len;
        }
        return res;
    }
};
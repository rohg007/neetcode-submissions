class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int left = 0;
        int max_freq = 0;
        unordered_map<char, int> freq;
        
        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            max_freq = max(max_freq, freq[s[right]]);
            
            int current_len = right - left + 1;
            if (current_len - max_freq > k) {
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
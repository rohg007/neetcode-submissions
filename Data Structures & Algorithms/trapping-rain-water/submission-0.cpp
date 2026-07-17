class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n+1), right(n+1);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i = n-1; i>=0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        for(int i = 1; i <= n; i++) {
            ans += max(0, min(left[i], right[i-1]) - height[i-1]);
        }
        return ans;
    }
};

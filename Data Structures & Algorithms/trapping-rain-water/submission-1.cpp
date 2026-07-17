class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[0], rightMax = height[height.size() - 1];
        int ans = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                ans += max(0, leftMax - height[l]);
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                ans += max(0, rightMax - height[r]);
            }
        }
        return ans;
    }
};

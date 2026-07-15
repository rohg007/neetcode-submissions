class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1, 1), right(n+1, 1);
        for (int i = 0; i < n; i++) {
            left[i+1] = left[i] * nums[i];
        }
        for (int i = n-1; i >= 0; i--) {
            right[i] = right[i+1] * nums[i];
        }
        for (int i = 0; i <= n; i++) {
            cout << left[i] <<" ";
        }
        cout <<"\n";
        for (int i = 0; i <= n; i++) {
            cout << right[i] <<" ";
        }
        cout <<"\n";
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            ans.push_back(left[i] * right[i+1]);
        }
        return ans;
    }
};

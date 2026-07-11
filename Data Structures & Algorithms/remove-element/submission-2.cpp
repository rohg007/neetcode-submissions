class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1, k = 0;
        while (i <= j) {
            if (nums[i] == val) {
                swap(nums[i], nums[j--]);
            } else {
                i++;
                k++;
            }
            cout << i << " " << j << "\n";
        }
        if (i == 0) return 0;
        return k;
    }
};
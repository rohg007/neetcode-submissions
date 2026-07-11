class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != candidate) {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            } else {
                count++;
            }
        }
        return candidate;
    }
};
class Solution {
    vector<int> mergeSorted(vector<int>& v1, vector<int>& v2, int n, int m) {
        vector<int> ret(n + m);
        int i = 0, j = 0, k = 0;
        while (i < n && j < m) {
            if (v1[i] < v2[j])
                ret[k++] = v1[i++];
            else
                ret[k++] = v2[j++];
        }
        while (i < n) {
            ret[k++] = v1[i++];
        }
        while (j < m) {
            ret[k++] = v2[j++];
        }
        return ret;
    }

    vector<int> mergeSort(vector<int>& nums, int left, int right) {
        if (left > right) return {};
        if (left == right) return {nums[left]};
        int mid = (left + right) / 2;
        vector<int> v1 = mergeSort(nums, left, mid);
        vector<int> v2 = mergeSort(nums, mid + 1, right);
        int n = v1.size(), m = v2.size();
        vector<int> v3 = mergeSorted(v1, v2, n, m);
        return v3;
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};
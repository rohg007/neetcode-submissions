class Solution {
    int getRowId(vector<vector<int>>& v, int& target) {
        int top = 0, bottom = v.size() - 1;
        while(top <= bottom) {
            int row = (top + bottom) / 2;
            if (target > v[row].back()) top = row + 1;
            else if (target < v[row].front()) bottom = row - 1;
            else return row;
        }
        return -1;
    }

    bool checkInRow(vector<int>& v, int& target) {
        int left = 0, right = v.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid] == target) return true;
            else if (v[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowId = getRowId(matrix, target);
        if (rowId == -1) return false;
        return checkInRow(matrix[rowId], target); 
    }
};

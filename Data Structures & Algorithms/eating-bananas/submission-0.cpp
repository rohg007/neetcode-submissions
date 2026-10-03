class Solution {
    int maxElement(vector<int>& piles) {
        int maxi = 0;
        for (int i : piles) {
            maxi = max(maxi, i);
        }
        return maxi;
    }
    bool isPossible(vector<int>& piles, int& k, int& h) {
        if (k == 0) return false;
        int turns = 0;
        for(int i : piles) {
            turns += (i/k) + ((i % k) != 0);
            if (turns > h) return false; 
        }
        return true;
    } 
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k = maxElement(piles);
        int ans = k;
        int left = 1, right = k;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (isPossible(piles, mid, h)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            cout << ans << "\n";
        }
        return ans;
    }
};

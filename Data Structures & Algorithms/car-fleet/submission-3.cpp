class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        stack<float> st;
        for(int i = 0; i < position.size(); i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        for(int i = 0; i < position.size(); i++) {
            float time = ((float)target - (float)v[i].first)/(float)v[i].second;
            // cout<<time<<"\n";
            if (st.empty() || st.top() < time) {
                st.push(time);
            }
        }
        return st.size();
    }
};

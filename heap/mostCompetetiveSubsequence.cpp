class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N = nums.size();
        int len = N - k;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i <= len; i++) 
            pq.push({nums[i], i});
        
        pair<int, int> t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int minIdx = t.second;
        for (int i = len+1; i < N; i++) { 
            pq.push({nums[i], i});
            t = pq.top();
            while (t.second < minIdx) { 
                pq.pop();
                t = pq.top();
            }
            pq.pop();
            res.push_back(t.first);
            minIdx = t.second;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});

        pair<int, int> curr = pq.top();

        ans.push_back(curr.first);

        for (int i = k; i < n; i++) {
            pq.push({nums[i], i});
            curr = pq.top();
            while (curr.second <= (i-k)) {
                pq.pop();
                curr = pq.top();
            }

            ans.push_back(curr.first);
        }

        return ans;
    }
};
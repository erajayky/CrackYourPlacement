struct FenwickTree {
    vector<int> bit; 
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<pair<long,int>>a;
        int n = nums.size(),ans = 0;
        long sum = 0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            a.push_back({sum,i});
        }
        sort(a.begin(),a.end());
        
        FenwickTree t(n);
        int L = 0,R=0;
        for(int i = 0;i<n;i++){
            
            while(R<n && (a[i].first - a[R].first) >= (1ll*lower)){
                t.add(a[R].second,1);
                R++;
            }
            while(L<n && (a[i].first - a[L].first) > (1ll*upper)){
                t.add(a[L].second,-1);
                L++;
            }
            
            ans+=t.sum(a[i].second-1);
            if(a[i].first >= lower && a[i].first <= upper)ans++;
        }

        return ans;
    }
};
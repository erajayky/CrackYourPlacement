class Solution {
private:
    bool isValid(int n, int k, vector<int>& stalls, int distance){
        int curr = stalls[0];
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(abs(stalls[i] - curr)  >=  distance)
                cnt++, curr = stalls[i];
        }
        
        return cnt >= k;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        int start = 1;
        int end = *max_element(stalls.begin(), stalls.end());
        sort(stalls.begin(), stalls.end());
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(isValid(n, k, stalls, mid))
                start = mid+1;
            else
                end = mid-1;
        }
        
        return end;
    }
};
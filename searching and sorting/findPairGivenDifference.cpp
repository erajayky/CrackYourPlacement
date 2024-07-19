class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            int low = 0;
            int high = n - 1;
            int pair = (arr[i] + x);
            
            while (low <= high){
                int mid = low + (high - low) / 2;
                if (arr[mid] == pair && mid != i)
                    return 1;
        
                if (arr[mid] < pair)
                    low = mid + 1;
        
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(1);

        for(int i=0; i<n-1; i++){
            int val = pq.top();
            pq.pop();

            while(pq.size() > 0 && pq.top() == val) pq.pop(); // remove duplicates;
            
            pq.push(val*2);
            pq.push(val*3);
            pq.push(val*5);
        }

        return pq.top();
    }
};
class Solution {
  public:
    
    long long findPages(int N, int A[], int M) {
        if(M > N)
        return -1;
        int s=*max_element(A,A+N);
        int e=accumulate(A,A+N,0);
        while(s<=e){
            int m=s+((e-s)/2);
            int sum=0;
            int count=1;
            int i=0;
            while(i<N){
                sum+=A[i];
                if(sum>m) count++,sum=A[i];
                i++;
            }
            if(count>M) s=m+1;
            else e=m-1;
        }
        return s;
    }
};

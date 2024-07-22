class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i=0;
        int j=n-1;
        
        while(i<j){
            if(M[i][j]==1)
                i++;
            else
                j--;
        }
        
        for(int k=0;k<n;k++)
            if(k!=i)
                if(!M[k][i] || M[i][k])
                    return(-1);
        
        return(i);
    }
};
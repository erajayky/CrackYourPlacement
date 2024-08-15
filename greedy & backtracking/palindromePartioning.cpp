class Solution {
public:

    bool check(string s){
        int n=s.length()-1;
        int i=0;
        while(i<n){
            if(s[i] != s[n]) return false;
            i++;
            n--;
        }
        return true;
    }

    void util(string s, vector<vector<string>> &ans, vector<string> &temp, int i){
        int n = s.length();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            string t = s.substr(i, j-i+1);
            if(check(t)){
                temp.push_back(t);
                util(s, ans, temp, j+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        util(s, ans, temp, 0);
        return ans;
    }
};
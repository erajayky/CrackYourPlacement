class Solution {
public:
    string removeKdigits(string num, int k) {

        if(k >= num.length()) return "0";
        if(k == 0) return num;

        stack<char> st;

        for(int i=0; i<num.size(); i++){
            while(k && !st.empty() && num[i] < st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0'){
                st.pop();
            }
        }

        while(k && !st.empty()){
            k--;
            st.pop();
        }
        
        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        if(ans.length() == 0)
            return "0";

        return ans;
    }
};
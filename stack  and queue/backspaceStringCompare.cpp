class Solution {
public:
    bool backspaceCompare(const string& S, const string& T) {
        return buildFinalString(S) == buildFinalString(T);
    }
    string buildFinalString(const string& str) {
        stack<char> s;
        for (char ch : str) {
            if (ch != '#') {
                s.push(ch);
            } else if (!s.empty()) {
                s.pop();
            }
        }
        string result;
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
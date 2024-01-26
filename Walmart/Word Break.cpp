class Solution {
public:
    unordered_map<int, bool> st;
    unordered_set<string> wordSet;

    bool funcCall(int pos, string s) {
        if (pos == s.size()) return true;
        if (st.find(pos) != st.end()) return st[pos];

        for (int i = pos; i < s.size(); i++) {
            string temp = s.substr(pos, i - pos + 1);
            if (wordSet.find(temp) != wordSet.end() && funcCall(i + 1, s)) {
                return st[pos] = true;
            }
        }
        return st[pos] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true; // Added check for an empty string
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return funcCall(0, s);
    }
};

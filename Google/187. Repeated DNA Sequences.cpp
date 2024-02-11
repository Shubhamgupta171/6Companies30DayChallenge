class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>mp;
        int n = s.length();
        string str = "";
        for(int i=0;i<10;i++){
            str.push_back(s[i]);
        }
        mp[str]++;
        int j=10;
        while(j<n){
            str.erase(str.begin());
            str.push_back(s[j++]);
            mp[str]++;
        }

        vector<string>ans;
        for(auto it:mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        set<int>takens, takeng;
        int bulls = 0;
        int cows = 0;
        for(int i=0; i<secret.size(); ++i){
            if(secret[i] == guess[i]){
                bulls++;
                takens.insert(i);
                takeng.insert(i);
            }
        }
        for(int i=0; i<guess.size(); ++i){
            for(int j=0; j<secret.size(); ++j){
                if (guess[i] == secret[j] && takens.find(j) == takens.end() && takeng.find(i) == takeng.end()) {
                    cows++;
                    takens.insert(j);
                    takeng.insert(i);
                }
            }
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};

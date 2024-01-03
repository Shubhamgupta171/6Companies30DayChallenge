

class Solution {
    bool within(string& a,string& b){
        if(a.substr(0,2)=="23"&&b.substr(0,2)=="23")
        return true;
        int diff=stoi(b)-stoi(a);
        if(diff>=100)return false;
        return true;
    }
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(),access_times.end());
        int i=0,count=1,n=access_times.size(),j=1;
        vector<string>ans;
        for(int i=0;i<n;i++){
            count=1;
    for(int j=i+1;j<n&&access_times[i][0]==access_times[j][0];j++){
                if(within(access_times[i][1],access_times[j][1]))
                count++;
                else
                break;
            }
        if(count>=3){
        if(ans.empty()||(!ans.empty()&&ans.back()!=access_times[i][0]))
            ans.push_back(access_times[i][0]);
        }
        }
        return ans;
    }
};

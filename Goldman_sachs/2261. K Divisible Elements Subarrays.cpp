class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
    set<vector<int>>s;  
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>v;
       int cnt=0;
        for(int l=i;l<=j;l++){
            v.push_back(nums[l]);
            if(nums[l]%p==0){
                cnt++;
            }
            
        }
        if(cnt<=k)
            s.insert(v);
            }
        }
        return s.size();
    }
};

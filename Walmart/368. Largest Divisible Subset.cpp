      class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(nums.size());
        vector<int> r;
        for (int i = 0;i < nums.size();++i) {
            for (int j = 0;j < i;++j) {
                if (nums[i] % nums[j] == 0 && result[j].size() > result[i].size()) {
                    result[i] = result[j];
                }
            }
            result[i].push_back(nums[i]);
            if (r.size() < result[i].size()) r = result[i];
        }
        return r;
    }
}; 

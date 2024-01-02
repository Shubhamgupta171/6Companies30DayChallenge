//216. Combination Sum III(medium)

//solving approach--->
// In this code, combinationSum3Helper is a recursive function that explores all possible combinations.
// It keeps track of the current combination in the current vector and updates the result vector when a valid combination is found.
// The start parameter is used to avoid duplicates and ensure that each number is used only once in a combination.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      
        vector<vector<int>> result;
        vector<int> current;
        combinationSum3Helper(k, n, 1, current, result);//it is recursive function
        return result;
    }
    private:
    void combinationSum3Helper(int k, int n, int start, vector<int>& current,vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) {
                break; 
            }
             current.push_back(i);
            combinationSum3Helper(k - 1, n - i, i + 1, current, result);
            current.pop_back();
        }
    }
};

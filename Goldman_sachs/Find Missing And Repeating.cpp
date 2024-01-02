//Find Missing And Repeating(medium)
// Approach:
// 1..isme sbse phle hm  counting array ko zero se initialize krenge. (vector<int>v(n,0);
// 2.har ek elment kitne baaar occur kr rha usko count krenge.
// 3.iske baad hm loop chla ke check krenge agar hmara counting array zero(v[i]==0)ke brabar hi to missing hi vo aur counting array 2(v[i]==2) hi to duplicate ..
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // Initialize a counting array with zeros
           vector<int> v(n, 0); 
       int duplicate = 0, missing = 0;
        // Count occurrences of each element in arr
        for (int i = 0; i < n; i++) {
            v[arr[i]-1]++;
        }
       // Find the duplicate and missing elements
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                missing = i + 1; // Missing element
            } else if (v[i] == 2) {
                duplicate = i + 1; // Duplicate element
            }
        }
       return {duplicate, missing};
    }
};

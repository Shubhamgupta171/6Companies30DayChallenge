//2513. Minimize the Maximum of Two Arrays(medium)
Problem no.1 

class Solution {
public:
   int minimizeSet(int d1, int d2, int cnt1, int cnt2) {
    long long ans = LLONG_MAX;
    long long low = 1, high = LLONG_MAX;

    while (low <= high) {
        long long mid = low+( high-low) / 2;
        long long c1 = mid - mid / d1;
        long long c2 = mid - mid / d2;
        long long temp = mid - mid / ((static_cast<long long>(d1) * d2) / __gcd(d1, d2));

        if (c1 >= static_cast<long long>(cnt1) && c2 >= static_cast<long long>(cnt2) && temp >= cnt1 + cnt2) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return static_cast<int>(ans);
}
        
    
};

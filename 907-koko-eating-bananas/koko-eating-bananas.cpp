#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid); // Change data type to long long
            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }   
        }
        return low;
    }

private:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &v, int hourly) { // Change data type to long long
        long long totalH = 0;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            totalH += ceil(static_cast<double>(v[i]) / static_cast<double>(hourly));
            if (totalH > INT_MAX) return LLONG_MAX; // Check for potential overflow
        }
        return totalH;
    }
};

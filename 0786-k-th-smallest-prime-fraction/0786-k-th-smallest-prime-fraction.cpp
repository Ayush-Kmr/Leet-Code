class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double low = 0.0, high = 1.0;
        int p = 0, q = 1, count = 0;
        while (low < high) {
            double mid = (low + high) / 2;
            count = 0;
            p = 0;
            for (int i = 0, j = 1; i < arr.size() - 1; ++i) {
                while (j < arr.size() && arr[i] >= arr[j] * mid) {
                    ++j;
                }
                count += arr.size() - j;
                if (j < arr.size() && p * arr[j] < q * arr[i]) {
                    p = arr[i];
                    q = arr[j];
                }
            }
            if (count == k) {
                break;
            } else if (count < k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return {p, q};
    }
};

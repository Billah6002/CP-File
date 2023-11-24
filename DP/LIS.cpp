//restored lis in nlogn
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> generateLIS(const vector<int>& a) {
    int n = a.size();
    if (n == 0) {
        return {};
    }

    vector<int> piles;
    vector<int> indices(n);

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(piles.begin(), piles.end(), a[i]);
        auto index = it - piles.begin();


        if (it == piles.end()) {
            piles.push_back(a[i]);
        } else {
            *it = a[i];
        }

        indices[i] = index;
    }

    // Find the length of the LIS
    int lisLength = *max_element(indices.begin(), indices.end()) + 1;

    // Reconstruct the LIS
    vector<int> lis(lisLength);
    for (int i = n - 1; i >= 0; --i) {
        if (indices[i] == lisLength - 1) {
            lis[--lisLength] = a[i];
        }
    }

    return lis;
}

int main() {
    // Example usage with the provided array:
    vector<int> nums = {77, 0, -2, 25, 1, 70};
    vector<int> lis = generateLIS(nums);

    // Output the LIS
    cout << "Longest Increasing Subsequence: ";
    for (const auto& element : lis) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

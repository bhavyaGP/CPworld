#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;
    int n = arr.size();

    if (n < k) {
        cout << "Array size is smaller than subarray size k." << endl;
        return 0;
    }

    vector<int> result;

    // Calculate the sum of each subarray of size k
    for (int i = 0; i <= n - k; i++) {
        int window_sum = 0;
        for (int j = i; j < i + k; j++) {
            window_sum += arr[j];
        }
        result.push_back(window_sum);
    }

    // Output the result
    cout << "Sums of all subarrays of size " << k << " are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
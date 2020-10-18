// * Description :
// Given an array of integers nums and the length of subarrays
// print all medians of each subarrays
// * Example :
// Array : [5,2,2,7,3,7,9,0,2,3], Subarray length : 5
// Should print : 3 3 7 7 3 3
// The first subarray is [5, 2, 2, 7, 3], then the median is 3
// * Complexity :
// O(N log K) time, O(N) space, N = array.size(), K = subarray.size()

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Method :
// Firstly initialize two heaps, lower and upper such that
// abs(lower.size() - upper.size()) <= 1 &&
// median >= lower[i] && median <= upper[i]
// The median is either the average of the two top values
// or the top value of the greatest heap.
// To add a value add it to the smallest heap and swap tops
// if lower and upper don't follow the first condition.
// To remove a value we find it, remove it and add the top of
// the other heap to the updated heap (sizes are now the same).
// We just remove and then add an item for each index of [0, N-k)
// to simulate a sliding window.
vector<double> medianSubarray(vector<int>& values, int k) {
    // We use long long instead of int to avoid overflows
    // median >= lower[i] && median <= upper[i]
    multiset<long long, greater<long long>> lower;
    multiset<long long> upper;
    vector<double> medians;

    // Initialize lower and upper
    for (int i = 0; i < k; ++i) {
        if (lower.size() <= upper.size())
            lower.insert(values[i]);
        else
            upper.insert(values[i]);

        // Swap values if heaps aren't balanced
        if (!lower.empty() && !upper.empty() &&
                *lower.begin() > *upper.begin()) {
            long long tmp = *lower.begin();
            lower.erase(lower.begin());
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
            upper.insert(tmp);
        }
    }

// To get the median inline
#define GET_MEDIAN (lower.size() == upper.size() ? \
        (*lower.begin() + (*upper.begin() - *lower.begin()) * .5) : \
        lower.size() > upper.size() ?  *lower.begin() : *upper.begin())

    medians.push_back(GET_MEDIAN);

    for (int i = 0; i < values.size() - k; ++i) {
        // Remove the i item
        bool removed = false;
        if (!lower.empty() && values[i] <= *lower.begin()) {
            // Remove it
            auto target = lower.find(values[i]);
            if (target != lower.end()) {
                lower.erase(target);
                removed = true;

                // Insert the top of the other heap to the updated heap
                if (!upper.empty()) {
                    lower.insert(*upper.begin());
                    upper.erase(upper.begin());
                }
            }
        }

        if (!removed) {
            // Remove it
            upper.erase(upper.find(values[i]));

            // Insert the top of the other heap to the updated heap
            if (!lower.empty()) {
                upper.insert(*lower.begin());
                lower.erase(lower.begin());
            }
        }

        // Add the i + k item
        if (lower.size() <= upper.size())
            lower.insert(values[i + k]);
        else
            upper.insert(values[i + k]);

        // Swap values if heaps aren't balanced
        if (!lower.empty() && !upper.empty() &&
                *lower.begin() > *upper.begin()) {
            long long tmp = *lower.begin();
            lower.erase(lower.begin());
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
            upper.insert(tmp);
        }

        medians.push_back(GET_MEDIAN);
    }

    return medians;
}

int main() {
    vector<pair<int, vector<int>>> dataset = {
            {5, {5,2,2,7,3,7,9,0,2,3}},
            {3, {1,3,-1,-3,5,3,6,7}},
            {1, {1,2}},
            {2, {2147483647,2147483647}},
        };

    // Should be :
    // 3 3 7 7 3 3
    // 1 -1 -1 3 5 6
    // 1 2
    // 2.14748e+09
    for (auto test : dataset) {
        auto y = medianSubarray(test.second, test.first);
        for (double median : y)
            cout << median << " ";

        cout << endl;
    }

    return 0;
}

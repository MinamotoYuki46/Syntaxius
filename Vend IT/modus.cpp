#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void findLargestModes(const vector<int>& arr, set<int>& modes) {
    unordered_map<int, int> freqMap;
    int maxCount = 0; // Initialize the maximum count with 0

    for (int num : arr) {
        freqMap[num]++; // Increment the count for the current element

        // Check if the current element has a higher count than the current maximum count
        if (freqMap[num] > maxCount) {
            modes.clear(); // Clear the existing modes
            modes.insert(num); // Set the current element as the mode
            maxCount = freqMap[num]; // Update the maximum count
        } else if (freqMap[num] == maxCount) {
            modes.insert(num); // Add the current element to the modes
        }
    }
}

int main() {
    vector<int> arr;
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> k;
        arr.push_back(k); // Use push_back to add elements to the vector
    }
    set<int> modes;
    findLargestModes(arr, modes);

    int highestMode = *modes.rbegin(); // Get the highest mode value
    cout <<  highestMode << endl;
    return 0;
}
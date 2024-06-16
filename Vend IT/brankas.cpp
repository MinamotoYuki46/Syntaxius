#include <iostream>
#include <vector>

using namespace std;

void generateCombinations(const vector<int>& arr, int r, vector<int>& combination, int index) {
    if (r == 0) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }
    for (int i = index; i < arr.size(); ++i) {
        combination.push_back(arr[i]);
        generateCombinations(arr, r - 1, combination, i + 1);
        combination.pop_back();
    }
}

int main() {
    int i, n, r; 
    cin >> n >> r;
    vector<int> arr = {};

    for (i = 0;i < n; i++){
        arr.insert(arr.end(), i+1);
    }

    vector<int> combination;
    generateCombinations(arr, r, combination, 0);
    return 0;
}
#include <iostream>
#include <vector>
#include <tuple>

// Helper function to compute nCr (combinations)
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    r = std::min(r, n - r); // Use symmetry property
    int c = 1;
    for (int i = 0; i < r; ++i) {
        c *= (n - i);
        c /= (i + 1);
    }
    return c;
}

// Recursive function to find the k-th sequence
void findKthSequence(int n, int k, int index, int start, std::vector<int>& result) {
    if (k == 0) return;

    for (int i = start; i <= 30 + (n - k); ++i) {
        int numCombinations = nCr(30 + (n - k) - i, k - 1);
        
        if (index <= numCombinations) {
            result.push_back(i);
            findKthSequence(n, k - 1, index, i + 1, result);
            return;
        }
        
        index -= numCombinations;
    }
}

std::vector<int> getKthSequence(int n, int k, int index) {
    std::vector<int> result;
    findKthSequence(n, k, index, 0 + (n - k), result);
    return result;
}

int main() {
    int n = 4;    // Number of ball types
    int k = 4;    // Number of balls to pick
    int index = 27404; // The given index to find the sequence
    
    std::vector<int> sequence = getKthSequence(n, k, index);
    
    std::cout << "The " << index << "th sequence of " << k << " balls is: {";
    for (int i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i];
        if (i < sequence.size() - 1) std::cout << ", ";
    }
    std::cout << "}" << std::endl;

    return 0;
}

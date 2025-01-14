#include <iostream>
#include <string>
#include <cctype> // For isdigit function
#include <sstream> // For stringstream
#include <algorithm> // For max function

using namespace std;

int largestEvenNumberInString(const string& s) {
    stringstream ss;
    int largestEven = -1;
    
    for (char c : s) {
        if (isdigit(c)) {
            ss << c;
        } else {
            if (!ss.str().empty()) {
                int number;
                ss >> number;
                if (number % 2 == 0) {
                    largestEven = max(largestEven, number);
                }
                ss.clear();
                ss.str("");
            }
        }
    }
    
    // Check the last sequence of digits in case the string ends with digits
    if (!ss.str().empty()) {
        int number;
        ss >> number;
        if (number % 2 == 0) {
            largestEven = max(largestEven, number);
        }
    }
    
    return largestEven;
}

int main() {
    string inputString = "abc1234def56789ghi0";
    int largestEven = largestEvenNumberInString(inputString);
    
    if (largestEven == -1) {
        cout << "No even number found in the string." << endl;
    } else {
        cout << "Largest even number in the string: " << largestEven << endl;
    }
    
    return 0;
}

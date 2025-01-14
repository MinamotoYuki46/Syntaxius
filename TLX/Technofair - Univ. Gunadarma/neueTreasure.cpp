// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;

// Function to return the maximum
// even number that can be formed
// with any number of digit swaps
string getMaxEven(string str, int len)
{

	// To store the frequencies of
	// all the digits
	int freq[MAX] = { 0 };

	// To store the minimum even digit
	// and the minimum overall digit
	int i, minEvenDigit = MAX;
	for (i = 0; i < len; i++) {
		int digit = str[i] - '0';
		freq[digit]++;

		// If digit is even then update
		// the minimum even digit
		if (digit % 2 == 0)
			minEvenDigit = min(digit, minEvenDigit);
	}

	// If there is no even digit then
	// it is not possible to generate
	// an even number with swaps
	if (minEvenDigit == MAX)
		return "-1";

	// Decrease the frequency of the
	// digits that need to be swapped
	freq[minEvenDigit]--;

	i = 0;
	// Take every digit starting from the maximum
	// in order to maximize the number
	for (int j = MAX - 1; j >= 0; j--) {

		// Take current digit number of times
		// it appeared in the original number
		for (int k = 0; k < freq[j]; k++)
			str[i++] = (char)(j + '0');
	}

	// Append once instance of the minimum
	// even digit in the end to make the number even
	str[i] = (char)(minEvenDigit + '0');

	return str;
}

// Driver code
int main()
{
	string str = "000343179";
	int len = str.length();

	// Function call
	cout << getMaxEven(str, len);

	return 0;
}

// A Naive Recursive C++ program to count even
// length binary sequences such that the sum of
// first and second half bits is same
#include <bits/stdc++.h>
using namespace std;

// diff is difference between sums first n bits
// and last n bits respectively
int countSeq(int n, int diff)
{
	// We can't cover difference of more
	// than n with 2n bits
	if (abs(diff) > n)
		return 0;

	// n == 1, i.e., 2 bit long sequences
	if (n == 1 && diff == 0)
		return 2;
	if (n == 1 && abs(diff) == 1)
		return 1;

	int res = // First bit is 0 & last bit is 1
		countSeq(n - 1, diff + 1) +

		// First and last bits are same
		2 * countSeq(n - 1, diff) +

		// First bit is 1 & last bit is 0
		countSeq(n - 1, diff - 1);

	return res;
}

// Driver program
int main()
{
	int n = 2;
	cout << "Count of sequences is "
		 << countSeq(2, 0);
	return 0;
}
